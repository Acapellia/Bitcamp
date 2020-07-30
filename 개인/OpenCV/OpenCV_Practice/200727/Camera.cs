using System;
using OpenCvSharp;

namespace _200727 {
    class Camera {
        static void Main(string[] args) {
            VideoCapture video = new VideoCapture(0); // 내장 카메라 혹은 카메라를 하나 추가하면 기본적으로 0 / 더 추가하면 1...2...
            Mat frame = new Mat();

            while(Cv2.WaitKey(33) != 'q') {
                video.Read(frame); // 카메라로 부터 읽음
                Cv2.ImShow("frame", frame);
            }

            frame.Dispose(); // 메모리 해제
            video.Release(); // 해제
            Cv2.DestroyAllWindows();
        }
    }
}