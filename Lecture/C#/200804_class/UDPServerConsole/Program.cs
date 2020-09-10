using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;                                   // 네트워크 관련 클래스 사용
using System.Net.Sockets;                           // Socket 클래스

namespace UDPServerConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            Socket server = null;                   // 서버로 사용할 소켓
            byte[] data = new byte[1024];           // 데이터를 수신할 byte 배열

            IPEndPoint serverIpep = new IPEndPoint(IPAddress.Any, 3317);
            server = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

            IPEndPoint clientIpep = new IPEndPoint(IPAddress.Any, 0);
            EndPoint client = (EndPoint) (clientIpep);

            server.Bind(serverIpep);                      

            Console.WriteLine("서버를 시작합니다.\n");

            while (true)
            {
                int len = server.ReceiveFrom(data, ref client);   // 클라이언트로부터 데이터 수신
                string str = Encoding.Default.GetString(data, 0, len);
                //Console.WriteLine("클라이언트로부터 데이터를 수신하였습니다\n메시지: " + str);
                Console.WriteLine("메시지 :" + str);
                if (str == "bye")
                    break;
            }

            server.Close();                         // 서버 소켓 닫기
        }
    }
}
