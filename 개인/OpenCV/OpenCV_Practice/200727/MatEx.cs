using System;
using OpenCvSharp;
namespace _200727 {
    // Mat 구성요소
    // 행렬의 크기, 데이터 타입, 깊이(채널)입니다
    // 행렬의 크기 : 행(높이) 과 열(너비) 크기
    // 데이터 타입 : 행렬의 각 요소에 대한 데이터 타입
    // 깊이(채널) : 행렬의 깊이(채널)
    class MatEx {
        static void Main(string[] args) {
            Mat src = new Mat();
            Mat src1 = new Mat(new Size(640, 480), MatType.CV_8UC3);
            Mat src2 = new Mat(480, 640, MatType.CV_8UC3);
        }
    }
}
