using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
namespace _200715_preparation
{
    class _25_MultiThread
    {
        static void ThreadProc()
        {
            for(int i = 0; i < 10; i++)
            {
                Console.WriteLine(i);
                Thread.Sleep(500);
            }
            Console.WriteLine("작업 스레드 종료");
        }
        static void Main()
        {
            Thread T = new Thread(new ThreadStart(ThreadProc));
            T.Start();
            for(; ; )
            {
                ConsoleKeyInfo cki;
                cki = Console.ReadKey();
                if (cki.Key == ConsoleKey.A) Console.Beep();
                if (cki.Key == ConsoleKey.B) break;
            }
            Console.WriteLine("주 스레드 종료");
        }
    }
}
