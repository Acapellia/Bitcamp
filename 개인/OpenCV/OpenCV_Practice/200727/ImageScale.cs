using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
    //이미지를 확대하는 경우에는 픽셀에 대한 보간법, 이미지를 축소하는 경우에는 픽셀에 대한 병합법이 수행됩니다
    class ImageScale {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../plane.png");
            Mat dst = new Mat();

            Cv2.Resize(src, dst, new Size(500, 250));

            Cv2.ImShow("src", src);
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
        }
    }
}
