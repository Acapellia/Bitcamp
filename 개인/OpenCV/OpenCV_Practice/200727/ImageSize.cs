using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
// 확대와 축소는 입력 이미지의 크기를 단계적으로 변화시켜 원하는 단계에 도달할 때까지 진행하는 이미지 피라미드를 사용.
// 이미지 피라미드는 가우시안 피라미드(Gaussian Pyramid)와 라플라시안 피라미드(Laplacian pyramid)를 활용
// 보간법
// InterpolationFlags.Nearest 가장 가까운 이웃 보간법
// InterpolationFlags.Linear   쌍 선형 보간법
// InterpolationFlags.Area 영역 보간법
// InterpolationFlags.Cubic    4×4 바이 큐빅 보간법
// InterpolationFlags.Lanczos4 8×8 란초스 보간법
    class ImageSize {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../tree.jpg", ImreadModes.ReducedColor2);
            Mat pyrUp = new Mat();
            Mat pyrDown = new Mat();

            Cv2.PyrUp(src, pyrUp);
            Cv2.PyrDown(src, pyrDown);

            Cv2.ImShow("pyrUp", pyrUp);
            Cv2.ImShow("pyrDown", pyrDown);
            Cv2.WaitKey(0);
        }
    }
}
