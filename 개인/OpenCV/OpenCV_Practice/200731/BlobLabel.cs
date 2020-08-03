using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
using OpenCvSharp.Blob;
namespace _200731 {
    class BlobLabel {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/blob.png");
            Mat dst = new Mat();
            Cv2.CvtColor(src, dst, ColorConversionCodes.BGR2GRAY);
            Cv2.Threshold(dst, dst, 0, 255, ThresholdTypes.Binary);
            Cv2.ImShow("src", src);
            Mat result = new Mat(src.Size(), MatType.CV_8UC3);
            CvBlobs blobs = new CvBlobs();
            blobs.Label(dst);
            blobs.RenderBlobs(src, result);
            foreach(var item in blobs) { 
                CvBlob b = item.Value; 
                Cv2.Circle(result, b.Contour.StartingPoint, 4, Scalar.Red, 2, LineTypes.AntiAlias);
                Cv2.PutText(result, b.Label.ToString(), new Point(b.Centroid.X, b.Centroid.Y), HersheyFonts.HersheyComplex, 1, Scalar.Yellow, 2, LineTypes.AntiAlias); 
            }
            Cv2.ImShow("result", result);
            Cv2.WaitKey(0);
            Cv2.DestroyAllWindows();
        }
    }
}//10.89.31.221
