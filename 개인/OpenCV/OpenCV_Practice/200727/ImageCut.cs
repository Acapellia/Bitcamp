using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
    class ImageCut {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../transport.jpg");
            Mat dst = src.SubMat(new Rect(300, 300, 500, 300));

            Cv2.ImShow("src", src);
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
        }
    }
}
