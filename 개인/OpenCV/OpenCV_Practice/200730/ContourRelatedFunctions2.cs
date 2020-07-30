using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200730 {
    // 윤곽선 객체의 중심점, 길이, 넓이, 최소 사각형 등 윤곽선 정보를 통해 계산할 수 있는 정보들을 쉽게 구할 수 있다.
    class ContourRelatedFunctions2 {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images//hex.jpg");
            Mat yellow = new Mat();
            Mat dst = src.Clone();

            Point[][] contours;
            HierarchyIndex[] hierarchy;

            Cv2.InRange(src, new Scalar(0, 127, 127), new Scalar(100, 255, 255), yellow);
            Cv2.FindContours(yellow, out contours, out hierarchy, RetrievalModes.Tree, ContourApproximationModes.ApproxTC89KCOS);

            foreach(Point[] p in contours) {
                double length = Cv2.ArcLength(p, true);
                double area = Cv2.ContourArea(p, true);

                if(length < 100 && area < 1000 && p.Length < 5)
                    continue;

// 볼록성 시험 함수(Cv2.IsContourConvex)는 윤곽선의 볼록한 형태인지 확인합니다.
// 볼록한 형태는 볼록한 형태나 수직한 형태를 갖는 것을 의미합니다.
// 볼록한 형태라면 단순한 다각형 형태를 지니고 있습니다.
// 즉, 교차하는 점이 없는 형태가 되어 하나의 윤곽선 그룹안에 하나의 다각형만 존재하게 됩니다.
// 볼록하다면 참 값을 반환하며, 볼록하지 않다면 거짓 값을 반환합니다.
                bool convex = Cv2.IsContourConvex(p); // 볼록한 형태인지 확인
                //윤곽선의 경계면을 둘러싸는 다각형을 반환
                Point[] hull = Cv2.ConvexHull(p,true); // 참 : 시계 거짓 : 반시계
// 모멘트 함수는 공간 모멘트(Spatial Moments), 중심 모멘트(Central Moments) 정규화된 중심 모멘트(Normalized Central Moments)를 계산합니다.
// 모멘트 값을 활용하면, 윤곽선의 질량 중심을 계산할 수 있습니다.
// 이 값을 주로, 객체의 중심점으로 활용합니다.
                Moments moments = Cv2.Moments(p, false);
                Cv2.FillConvexPoly(dst, p ,Scalar.Yellow);
                Cv2.DrawContours(dst, new Point[][] { hull }, -1, Scalar.Blue, 3);
                Cv2.Circle(dst,(int)(moments.M10 / moments.M00), (int)(moments.M01 / moments.M00), 5, Scalar.Black, -1);
            }
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
        }
    }
}
