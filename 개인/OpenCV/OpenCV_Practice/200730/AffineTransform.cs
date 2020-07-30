using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200730 {
    class AffineTransform {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/snow.jpg");
            Mat dst = new Mat();

            List<Point2f> src_pts = new List<Point2f>()
            {
                new Point2f(0.0f, 0.0f),
                new Point2f(0.0f, src.Height),
                new Point2f(src.Width, src.Height)
            };

            List<Point2f> dst_pts = new List<Point2f>()
            {
               new Point2f(300.0f, 300.0f),
               new Point2f(300.0f, src.Height),
               new Point2f(src.Width - 400.0f, src.Height - 200.0f)
            };

            Mat matrix = Cv2.GetAffineTransform(src_pts, dst_pts); // 아핀 맵 행렬 생성
            Cv2.WarpAffine(src, dst, matrix, new Size(src.Width, src.Height)); // 아핀 변환 진행

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
        }
    }
}
