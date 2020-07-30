using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
    class ImageColor {
        static void Main(string[] args) {
            Mat src = Cv2.ImRead("../../../../desert.jpg");
            Mat dst = new Mat(src.Size(), MatType.CV_8UC1); // unsigned int8 channel 1

            Cv2.CvtColor(src, dst, ColorConversionCodes.BGR2GRAY); // gray

            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
