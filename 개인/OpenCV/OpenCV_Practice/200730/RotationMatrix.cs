using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200730 {
    class RotationMatrix {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/wine.jpg");
            Mat dst = new Mat();

            Mat matrix = Cv2.GetRotationMatrix2D(new Point2f(src.Width / 2, src.Height / 2), 45.0, 0.5); // 회전행렬 생성(중심점,각도,스케일)
            Cv2.WarpAffine(src, dst, matrix, new Size(src.Width, src.Height)); // 아핀 변환

            Cv2.ImShow("dst",dst);
            Cv2.WaitKey(0);
        }
    }
}
