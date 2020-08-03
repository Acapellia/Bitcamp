using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200731 {
    class DetectLine {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/birds_ball.jpg");
            Mat dst = new Mat();

            Cv2.CvtColor(src, dst, ColorConversionCodes.BGR2GRAY);
            //Cv2.Threshold(dst, dst, 120, 255, ThresholdTypes.Binary);
            Cv2.GaussianBlur(dst, dst, new Size(3, 3), 1, 0, BorderTypes.Default);
            Cv2.Canny(dst, dst, 100, 200, 3, true);

// image – 8bit, single - channel binary image, canny edge를 선 적용.
// rho – r 값의 범위(0 ~1 실수)
// theta – 𝜃 값의 범위(0 ~180 정수)
// threshold – 만나는 점의 기준, 숫자가 작으면 많은 선이 검출되지만 정확도가 떨어지고, 숫자가 크면 정확도가 올라감.
            LineSegmentPolar[] lines = Cv2.HoughLines(dst, 1, Math.PI / 180, 250);
            Console.WriteLine(lines.Length);
            float max = 0;
            for(int i = 0; i < lines.Length; i++) {
                float rho = lines[i].Rho;
                //if(rho < 500)
                //    continue;
                if(max < rho)
                    max = rho;
             
                float theta = lines[i].Theta;
                double c = Math.Cos(theta);
                double s = Math.Sin(theta);
                int x0 = (int)(c * rho);
                int y0 = (int)(s * rho);
                int x1 = (int)(x0 + 1000 * (-s));
                int y1 = (int)(y0 + 1000 * (c));
                int x2 = (int)(x0 - 1000 * (-s));
                int y2 = (int)(y0 - 1000 * (c));
                Cv2.Line(src, x1, y1, x2, y2, Scalar.Blue,2);
            }
            Cv2.ImShow("dst", src);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
