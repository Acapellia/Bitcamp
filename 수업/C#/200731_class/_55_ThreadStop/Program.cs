using System;
using System.Threading;

namespace _55_ThreadStop {
    class Program {
        static Random r = new Random();
        static bool isRun = true;
        static void ThreadProc() {
            while(isRun) {
                switch(r.Next(20)) {
                    case 0:
                        Console.WriteLine("집에 간다");
                        break;
                    case 1:
                        Console.WriteLine("몰래 사라진다");
                        break;
                    case 2:
                        Console.WriteLine("가게 돈으로 여친에게 선물한다");
                        break;
                    default:
                        Console.WriteLine("일을 한다");
                        break;
                }
                Thread.Sleep(100);
            }
        }
        static void Main(string[] args) {
            Thread th = new Thread(ThreadProc);
            th.Start();
            for(int i = 0; i < 50; i++) {
                Console.WriteLine("주인이 지켜보고 있다");
                Thread.Sleep(100);
            }
            Console.WriteLine("알바를 해고했다.");
            isRun = false;
        }
    }
}
