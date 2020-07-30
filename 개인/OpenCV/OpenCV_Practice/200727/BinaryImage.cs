using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
// 영상이나 이미지의 어느 지점을 기준으로 픽셀을 분류해 제외합니다.
// 특정 값을 기준으로 값이 높거나 낮은 픽셀을 검은색 또는 흰색의 값으로 변경합니다.
//임계값 형싱
// ThresholdTypes.Binary 임곗값을 초과할 경우 최댓값, 아닐 경우 0
// ThresholdTypes.BinaryInv 임곗값을 초과할 경우 0, 아닐 경우 최댓값
// ThresholdTypes.Trunc    임곗값을 초과할 경우 임곗값, 아닐 경우 변형 없음
// ThresholdTypes.Tozero 임곗값을 초과할 경우 변형 없음, 아닐 경우 0
// ThresholdTypes.TozeroInv 임곗값을 초과할 경우 0, 아닐 경우 변형 없음
// ThresholdTypes.Mask 검은색 이미지로 변경(마스크용)
// ThresholdTypes.Otsu 오츠 알고리즘 적용(단일 채널 이미지에만 적용 가능)
// ThresholdTypes.Triangle 삼각형(Triangle) 알고리즘 적용(단일 채널 이미지에만 적용 가능)
    class BinaryImage {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../rose.jpg");
            Mat gray = new Mat();
            Mat binary = new Mat();

            Cv2.CvtColor(src, gray, ColorConversionCodes.BGR2GRAY);
            Cv2.Threshold(gray, binary, 150, 255, ThresholdTypes.Binary); // 임계값, 최대값 임계값보다 낮으면 0 높으면 최대값

            Cv2.ImShow("src", src);
            Cv2.ImShow("dst", binary);
            Cv2.WaitKey(0);
        }
    }
}
