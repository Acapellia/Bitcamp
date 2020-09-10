using System;

namespace _200715_preparation
{
    class Archeive
    {
        public static int num = 0;
        public delegate void SendProg(int nFile);
        public static void SendPacket(SendProg Prog)
        {

            Prog(num);
            num++;
            System.Threading.Thread.Sleep(500);

        }

    }
    class _11_Delegate
    {
        public static void Progress(int nFile)
        {
            Console.WriteLine($"{nFile + 1}번째 패킷을 전송중...");
        }
        public static void EndProgress(int nFile)
        {
            Console.WriteLine($"Now Sending {nFile + 1} Packet. Wait Please");
        }
        static void Main(string[] args)
        {
            for (int i = 0; i < 10; i++)
            {
                if (Archeive.num % 2 == 0)
                    Archeive.SendPacket(EndProgress);
                else
                    Archeive.SendPacket(Progress);
            }
            Console.WriteLine("모든 패킷을 전송했습니다.");
        }
    }
}
