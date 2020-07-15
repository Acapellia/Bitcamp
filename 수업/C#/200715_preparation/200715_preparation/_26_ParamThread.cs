using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace _200715_preparation
{
    // 매개변수가 있는 스레드 예제
    // Thread.Abort() - 스레드 강제 종료
    // Thread.Join() - 스레드가 종료될 때까지 대기
    // Thread.isBackground - 주 스레드 종료시 같이 종료(true) 따로 동작(false)
    // Thread.isAlive - 스레드가 살아있는지 확인
    // Thread.Priorit - 스레드 우선순위
    // Thread에 함수가 아닌 exe파일을 주면 프로세스를 생성 가능
    class _26_ParamThread
    {
        static void ThreadProc(object count)
        {
            for (int i = 0; i < (int)count; i++)
            {
                Console.WriteLine(i);
                Thread.Sleep(500);
            }
            Console.WriteLine("작업 스레드 종료");
        }
        static void Main()
        {
            Thread T = new Thread(new ParameterizedThreadStart(ThreadProc)); // param이 있는 스레드 시작
            T.Start(5); // start 할때 매개변수 넣어줌
            for(; ; )
            {
                ConsoleKeyInfo cki = Console.ReadKey();
                if (cki.Key == ConsoleKey.A) Console.Beep();
                if (cki.Key == ConsoleKey.B) break;
            }
            Console.WriteLine("주 스레드 종료");
        }
    }
}
