using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
namespace _43_NetworkStreamLoopServer {
    class Program {
        static void Main(string[] args) {
            Socket serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            const int PORT = 9000;
            IPEndPoint ipep = new IPEndPoint(IPAddress.Any, PORT);
            serverSocket.Bind(ipep);
            serverSocket.Listen(10);
            
            Console.WriteLine("클라이언트 접속 대기중...");
            Socket clientSocket = serverSocket.Accept();
            
            Console.WriteLine("클라이언트 접속 완료");
            NetworkStream ns = new NetworkStream(clientSocket);
            StreamReader sr = new StreamReader(ns);
            
            while(true) {
                string recvData = sr.ReadLine();
                Console.WriteLine("수신 : " + recvData);
            }
            clientSocket.Close();
            serverSocket.Close();
        }
    }
}
