using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200731 {
    class DetectCircle {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/birds_ball.jpg");
            Mat dst = new Mat();
            Cv2.CvtColor(src, dst, ColorConversionCodes.BGR2GRAY);
            Cv2.ImShow("GrayScale", dst);
            Cv2.GaussianBlur(dst, dst, new Size(9, 9), 1, 1, BorderTypes.Default); // 1 : x.y표준 편차
            Cv2.ImShow("GaussianBlur", dst);
            //minDist – 검출한 원의 중심과의 최소거리. 값이 작으면 원이 아닌 것들도 검출이 되고, 너무 크면 원을 놓칠 수 있음.
            //param1 – 내부적으로 사용하는 canny edge 검출기에 전달되는 Paramter
            //param2 – 이 값이 작을 수록 오류가 높아짐. 크면 검출률이 낮아짐.
            //minRadius – 원의 최소 반지름.
            //maxRadius – 원의 최대 반지름.

            CircleSegment[] circles = Cv2.HoughCircles(dst, HoughMethods.Gradient, 1, 100, 150, 50, 30, 80);

            //Console.WriteLine(circles.Length);
            foreach(CircleSegment circle in circles) {
                Cv2.Circle(src, (int)circle.Center.X, (int)circle.Center.Y, (int)circle.Radius, new Scalar(255, 0, 0), 3);
            }

            Cv2.ImShow("FindCircle", src);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
