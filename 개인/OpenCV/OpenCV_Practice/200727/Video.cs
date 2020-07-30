using System;
using System.Collections.Generic;
using System.Text;
using OpenCvSharp;
namespace _200727 {
    class Video {
        static void Main(string[] args) {
            VideoCapture video = new VideoCapture("ocean.mp4"); // video 가져오기
            Mat frame = new Mat();
            while(video.PosFrames != video.FrameCount) { // 현재 프레임 != video의 전체 프레임
                video.Read(frame);// video의 현재 프레임을 읽어서 frame에 저장
                Cv2.ImShow("frame", frame);
                Cv2.WaitKey(0);
            }
            frame.Dispose();
            video.Release();
            Cv2.DestroyAllWindows();
        }
    }
}