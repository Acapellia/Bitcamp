using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    delegate void Notice();
    class Message
    {
        public void SendComplete() { Console.WriteLine("모두 전송했습니다."); }
    }
    class Sender
    {
        public event Notice OnComplete;
        public void Send()
        {
            for(int i = 0; i < 100; i += 10)
            {
                Console.WriteLine(i + "% 전송중");
                System.Threading.Thread.Sleep(200);
            }
            if (OnComplete != null) OnComplete();
        }
    }
    class _14_Event
    {
        static void Main()
        {
            Message M = new Message();
            Sender S = new Sender();
            S.OnComplete += M.SendComplete;
            S.Send();
        }
    }
}
