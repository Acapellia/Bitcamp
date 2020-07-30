using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200730 {
    // 원근 변환
    class PerspectiveTransformation {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/plate.jpg");
            Mat dst = new Mat();

            List<Point2f> src_pts = new List<Point2f>()
            {
                new Point2f(0.0f, 0.0f),
                new Point2f(0.0f, src.Height),
                new Point2f(src.Width, src.Height),
                new Point2f(src.Width, 0.0f)
            };

            List<Point2f> dst_pts = new List<Point2f>()
            {
               new Point2f(300.0f, 100.0f),
               new Point2f(300.0f, src.Height),
               new Point2f(src.Width - 400.0f, src.Height - 200.0f),
               new Point2f(src.Width - 200.0f, 200.0f)
            };

            Mat matrix = Cv2.GetPerspectiveTransform(src_pts, dst_pts); // Perspective : 원근법 
            Cv2.WarpPerspective(src, dst, matrix, new Size(src.Width, src.Height));

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
        }
    }
}
