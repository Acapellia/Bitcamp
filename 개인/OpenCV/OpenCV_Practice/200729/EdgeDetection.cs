using System;
using OpenCvSharp;
namespace _200729 {
    // 전경과 배경 사이에서 밝기가 큰 폭으로 변하는 지점이 객체의 가장자리가 된다.
    // 가장자리는 픽셀의 밝기가 급격하게 변하는 부분이다.
    // 가장자리 검출 함수는 크게, 소벨 미분, 샤르 필터, 라플라시안, 캐니 엣지가 있다.
    //소벨 미분의 경우 커널의 크기가 작으면 정확도가 떨어진다.
    // 라플라시안 함수는 가장자리가 밝은 부분에서 발생한 것인지, 어두운 부분에서 발생한 것인지 알 수 있다.
    class EdgeDetection {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../wintry.jpg");
            Mat blur = new Mat();

            Mat sobel = new Mat();
            Mat scharr = new Mat();
            Mat laplacian = new Mat();
            Mat canny = new Mat();

            Cv2.GaussianBlur(src, blur, new Size(3, 3), 1, 0, BorderTypes.Default);

            Cv2.Sobel(blur, sobel, MatType.CV_32F, 1, 0, ksize: 3, scale: 1, delta: 0, BorderTypes.Default);
            sobel.ConvertTo(sobel, MatType.CV_8UC1);

            Cv2.Scharr(blur, scharr, MatType.CV_32F, 1, 0, scale: 1, delta: 0, BorderTypes.Default);
            scharr.ConvertTo(scharr, MatType.CV_8UC1);

            Cv2.Laplacian(blur, laplacian, MatType.CV_32F, ksize: 3, scale: 1, delta: 0, BorderTypes.Default);
            laplacian.ConvertTo(laplacian, MatType.CV_8UC1);

            Cv2.Canny(blur, canny, 100, 200, 3, true);

            Cv2.ImShow("sobel", sobel);
            Cv2.ImShow("scharr", scharr);
            Cv2.ImShow("laplacian", laplacian);
            Cv2.ImShow("canny", canny);
            Cv2.WaitKey(0);
        }
    }
}
