using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200730 {
    // 형태학적 변환
    class MorphologicalTransformation {
        static void Main(string[] args) {
            Mat src = new Mat("../../../../Images/nape.jpg");
            Mat dilate = new Mat();
            Mat erode = new Mat();
            Mat dst = new Mat();

            //커널의 형태(shape)와 커널의 크기(size), 고정점(anchor)
            Mat element = Cv2.GetStructuringElement(MorphShapes.Ellipse, new Size(5, 5),new Point(0,0));
            // Cv2.Dilate(원본 배열, 결과 배열, 구조 요소, 고정점, 반복 횟수, 테두리 외삽법, 테두리 색상)로 팽창 연산을 진행합니다.
            // Cv2.Erode(원본 배열, 결과 배열, 구조 요소, 고정점, 반복 횟수, 테두리 외삽법, 테두리 색상)로 침식 연산을 진행합니다.
            Cv2.Dilate(src, dilate, element, new Point(2, 2), 3);
            Cv2.Erode(src, erode, element, new Point(-1, -1), 5);

            Cv2.HConcat(new Mat[] { dilate, erode }, dst);
            Cv2.ImShow("dst", dst);
            Cv2.WaitKey(0);
        }
    }
}
