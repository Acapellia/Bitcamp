using System;
using System.Collections.Generic;
using OpenCvSharp;
namespace _200730 {
// 다각형 근사는 검출된 윤곽선의 형상을 분석할 때 정점(Vertex)의 수가 적은 다각형으로 표현할 수 있게 다각형 곡선을 근사하는 방법
// 다각형 근사는 더글라스-패커(Douglas-Peucker) 알고리즘을 사용
// 반복과 끝점을 이용해 선분으로 구성된 윤곽선들을 더 적은 수의 윤곽점으로 동일하거나 비슷한 윤곽선으로 데시메이트(Decimate) 합니다.
// 더글라스-패커 알고리즘은 근사치 정확도(Epsilon) 의 값으로 기존의 다각형과 윤곽점이 압축된 다각형의 최대 편차를 고려해 다각형을 근사하게 됩니다.
// 데시메이트(Decimate) 란 일정 간격으로 샘플링된 데이터를 기존 간격보다 더 큰 샘플링 간격으로 다시 샘플링하는 것을 의미
    class ApproxPoly {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/hex.jpg");
            Mat yellow = new Mat();
            Mat dst = src.Clone();

            Point[][] contours;
            HierarchyIndex[] hierarchy;

            Cv2.InRange(src, new Scalar(0, 127, 127), new Scalar(100, 255, 255), yellow);
            Cv2.FindContours(yellow, out contours, out hierarchy, RetrievalModes.Tree, ContourApproximationModes.ApproxTC89KCOS);

            List<Point[]> new_contours = new List<Point[]>();

// Cv2.ApproxPolyDP(원본 배열, 근사치 정확도, 폐곡선 여부)로 다각형 근사를 적용합니다.
// 원본 배열에서 근사치 정확도값으로 다각형 근사를 진행합니다.
// 폐곡선 여부는 시작점과 끝점의 연결 여부를 의미합니다.
// 참 값을 사용할 경우, 마지막 점과 시작 점이 연결된 것으로 간주합니다.
// 다각형 근사 함수에서 가장 중요한 매개변수는 근사치 정확도입니다.
// 일반적으로 전체 윤곽선 길이의 1 % ~5 % 의 값을 사용합니다.
            foreach(Point[] p in contours) {
                double length = Cv2.ArcLength(p, true);
                if(length < 100)
                    continue;
                new_contours.Add(Cv2.ApproxPolyDP(p, length * 0.02, true)); // 다각형 근사
            }
            // 3번 인자 = 계층  >> -1 : 모든 윤곽선 0~ : 높이??
            Cv2.DrawContours(dst, new_contours, -1, new Scalar(255, 255, 0), 2, LineTypes.AntiAlias, null, 1);
            Cv2.ImShow("dst",dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
