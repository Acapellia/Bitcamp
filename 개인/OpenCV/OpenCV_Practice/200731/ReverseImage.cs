using System;
using OpenCvSharp;
namespace _200731 {
    class ReverseImage {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/abocado.png");
            Mat dst = new Mat();
            Cv2.BitwiseNot(src, dst);
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
