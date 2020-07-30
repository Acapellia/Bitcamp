using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
using OpenCvSharp.Dnn;
namespace _200729 {
// 가장자리 검출 알고리즘은 검출된 객체들의 세그먼트(Segment) 구성 요소가 구분돼 있지 않아 어떤 형태인지 알 수 없었습니다.
// 윤곽선 검출 알고리즘은 전처리가 진행된 이미지에서 가장자리로 검출된 픽셀을 대상으로 세그먼테이션(Segmentation) 작업을 진행합니다.
// 윤곽선 검출은 검출된 객체들을 값으로 반환해 사용할 수 있습니다.
// 검출된 윤곽선은 형상의 분석과 물체 감지 및 인식에 가장 효과적인 방법 중 하나입니다.

// 세그먼트(Segment) 란 서로 다른 두 점을 연결하는 가장 짧은 선을 의미합니다.
// 세그먼테이션(Segmentation) 이란 이미지에서 각각의 픽셀들을 분류해 그룹화하는 것을 의미합니다.
    class ContoursDetection {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../hex.jpg");
            Mat yellow = new Mat();
            Mat dst = src.Clone();

            Point[][] contours; // 윤곽선들의 값
            HierarchyIndex[] hierarchy; // 윤곽선들의 계층구조
            
            Cv2.InRange(src, new Scalar(0, 127, 127), new Scalar(100, 255, 255), yellow); // 두 값 사이만 추출
            //Cv2.ImShow("Yellow", yellow);
             //Cv2.BitwiseOr(dst2, dst3, result); 구분이 여러개여서 다시 합칠 때

            // 원본 배열, 검출된 윤곽선, 계층 구조, 검색 방법, 근사 방법, 오프셋
            // RetrievalModes.External 최외곽 윤곽선만 검색
            //RetrievalModes.List 모든 윤곽선을 검출하며, 계층 구조를 형성하지 않음(모든 윤곽선을 동일 레벨로 간주)
            //RetrievalModes.CComp 모든 윤곽선을 검색해서 2단계 계층 구조로 구성(최상위 레벨은 외곽, 두 번째 레벨은 내곽(홀))
            //RetrievalModes.Tree 모든 윤곽선을 검출하고 트리 구조로 구성
            Cv2.FindContours(yellow, out contours, out hierarchy, RetrievalModes.Tree, ContourApproximationModes.ApproxTC89KCOS);

            // 불필요한 윤곽선 제거
            List<Point[]> new_contours = new List<Point[]>();
            foreach(Point[] p in contours) {
                double length = Cv2.ArcLength(p, true); // 윤곽선 길이 함수
                if(length > 100) {
                    new_contours.Add(p);
                }
            }
            // 결과 배열, 검출된 윤곽선, 윤곽선 번호, 색상, 두께, 선형 타입, 계층 구조, 계층 구조 최대 레벨
            // -1은 모든 윤곽선
            Cv2.DrawContours(dst, new_contours, -1, new Scalar(255, 0, 0), 2, LineTypes.AntiAlias, null, 1);
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
        }
    }
}
