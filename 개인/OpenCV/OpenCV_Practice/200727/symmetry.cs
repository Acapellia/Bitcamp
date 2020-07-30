using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
    class symmetry {
        static void Main(string[] args) {
            Mat src = Cv2.ImRead("../../../../bird.jpg");
            Mat dst = new Mat(src.Size(), MatType.CV_8UC3);

            Cv2.Flip(src, dst, FlipMode.Y); // y축 대칭 

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
