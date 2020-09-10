using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
namespace _44_NetworkStreamLoopClient {
    class Program {
        static void Main(string[] args) {
            const string IP = "127.0.0.1";
            const int PORT = 9000;
            Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPEndPoint ipep = new IPEndPoint(IPAddress.Parse(IP), PORT);
            clientSocket.Connect(ipep);
            NetworkStream ns = new NetworkStream(clientSocket);
            StreamWriter sw = new StreamWriter(ns);

            while(true) {
                Console.WriteLine("메시지를 입력하세요 : ");
                string data = Console.ReadLine();
                sw.WriteLine(data);
                sw.Flush();
                if(data == "bye")
                    break;
            }
            clientSocket.Close();
        }
    }
}
