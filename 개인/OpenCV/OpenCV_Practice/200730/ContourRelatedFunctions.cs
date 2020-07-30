using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200730 {
    class ContourRelatedFunctions {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/hex.jpg");
            Mat yellow = new Mat();
            Mat dst = src.Clone();

            Point[][] contours;
            HierarchyIndex[] hierachy;

            Cv2.InRange(src, new Scalar(0, 127, 127), new Scalar(100, 255, 255), yellow);
            Cv2.FindContours(yellow, out contours, out hierachy, RetrievalModes.Tree, ContourApproximationModes.ApproxTC89KCOS);

            List<Point[]> new_contours = new List<Point[]>();
            foreach(Point[] p in contours) {
                double length = Cv2.ArcLength(p, true); // 윤곽선길이함수 true : 폐곡선 여부(시작점 끝점을 연결)
                double area = Cv2.ContourArea(p, true); // 윤곽선넓이함수

                if(length < 100 && area < 1000 && p.Length < 5)
                    continue;

                Point2f center;
                float radius;
                Rect boundingRect = Cv2.BoundingRect(p); // 윤곽선 경계면을 둘러싸는 사각형
                RotatedRect rotatedRect = Cv2.MinAreaRect(p); // 윤곽선 경계면을 둘러싸는 최소크기 사각형
                RotatedRect ellipse = Cv2.FitEllipse(p); //윤곽선 경계면을 둘러싸는 최소크기 원(타원)
                Cv2.MinEnclosingCircle(p, out center, out radius); // 윤곽선에 가장 근사한 원

                Cv2.Rectangle(dst, boundingRect, Scalar.Red,2);
                Cv2.Ellipse(dst, rotatedRect, Scalar.Blue, 2);
                Cv2.Ellipse(dst, ellipse, Scalar.Green, 2);
                Cv2.Circle(dst, (int)center.X, (int)center.Y, (int)radius, Scalar.Yellow, 2);
            }
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
