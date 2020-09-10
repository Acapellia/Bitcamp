using System;
using System.Threading;

namespace _61_Thread {
    class Program {
        static void threadProc(object obj) {
            int cnt = (int)obj;
            for(int i = 0; i < cnt; i++) {
                Console.WriteLine(i);
                Thread.Sleep(500);
            }
        }
        static void Main(string[] args) {
            Thread thread = new Thread(new ParameterizedThreadStart(threadProc));
            thread.Start(10);
            Console.WriteLine("메인 스레드 대기");
            thread.Join();
            Console.WriteLine("메인 스레드 종료");
        }
    }
}
