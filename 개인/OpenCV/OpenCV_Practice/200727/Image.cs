using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;

namespace _200727 {
    class Image {
        static void Main() {
            Mat image = Cv2.ImRead("../../../../cat.jpg", 0);
            Cv2.ImShow("image", image);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}
