using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200731 {
    class Moment {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/moments.png");
            Mat dst = new Mat();
            Cv2.CvtColor(src, dst, ColorConversionCodes.BGR2GRAY);
            Cv2.Threshold(dst, dst, 150, 255, ThresholdTypes.Binary);

            Point[][] contours;
            HierarchyIndex[] hierarchy;

            Cv2.FindContours(dst, out contours, out hierarchy, RetrievalModes.Tree, ContourApproximationModes.ApproxTC89KCOS);

            List<Point[]> new_contours = new List<Point[]>();
            int cnt=1;
            foreach(Point[] p in contours) {
                double length = Cv2.ArcLength(p, true);
                double area = Cv2.ContourArea(p, true);
                Console.WriteLine($"{length} / {area} / {p.Length}");
                if(length < 50 || area < 500)
                    continue;
                new_contours.Add(p);
                Moments moment = Cv2.Moments(p, false);
                int x = (int)(moment.M10 / moment.M00);
                int y = (int)(moment.M01 / moment.M00);
                Cv2.Circle(src, x, y, 5, Scalar.Black, -1);
                Cv2.PutText(src, "label " + (cnt++).ToString(), new Point(x-50, y-10), HersheyFonts.HersheyPlain, 2, Scalar.Red, 2);
            }
            Cv2.DrawContours(src, new_contours, -1, new Scalar(255, 0, 0), 2, LineTypes.AntiAlias, null, 1);
            Cv2.ImShow("moment", src);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
