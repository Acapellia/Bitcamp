using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
    // Blur : 각 픽셀에 대해 커널을 적용 후 단순 평균을 구함
    // BoxFilter : 커널의 내부 값이 모두 같은 값
    // MedianBlur : 중간값 흐림, 중심 픽셀 주변으로 이웃한 픽셀들의 중간값을 사용, 고정점 사용 안함
    // GaussianBlur : 각 지점에 가우시안 커널을 사용
    // BilateralFilter : 가장자리(Edge)를 선명하게 보존하면서 노이즈를 우수하게 제거하는 흐림 효과 함수
    class ImageBlur {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../sparkler.jpg");
            Mat blur = new Mat();
            Mat box_filter = new Mat();
            Mat median_blur = new Mat();
            Mat gaussian_blur = new Mat();
            Mat bilateral_filter = new Mat();

            Cv2.Blur(src, blur, new Size(9, 9), new Point(-1, -1), BorderTypes.Default);
            Cv2.BoxFilter(src, box_filter, MatType.CV_8UC3, new Size(9, 9), new Point(-1, -1), true, BorderTypes.Default);
            Cv2.MedianBlur(src, median_blur, 9);
            Cv2.GaussianBlur(src, gaussian_blur, new Size(9, 9), 1, 1, BorderTypes.Default); // 1 : x.y표준 편차
            Cv2.BilateralFilter(src, bilateral_filter, 9, 3, 3, BorderTypes.Default); // 지름, 색상공간, 좌표 공간

            Cv2.ImShow("blur", blur);
            Cv2.ImShow("box_filter", box_filter);
            Cv2.ImShow("median_blur", median_blur);
            Cv2.ImShow("gaussian_blur", gaussian_blur);
            Cv2.ImShow("bilateral_filter", bilateral_filter);
            Cv2.WaitKey(0);
        }
    }
}
