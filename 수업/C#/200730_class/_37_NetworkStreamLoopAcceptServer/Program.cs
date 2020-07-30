﻿using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
namespace _47_NetworkStreamLoopAcceptServer {
    class Program {
        static void Main(string[] args) {
            Socket serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            const int PORT = 9000;
            IPEndPoint ipep = new IPEndPoint(IPAddress.Any, PORT);
            serverSocket.Bind(ipep);
            serverSocket.Listen(10);

            for(int i=0;i<3;i++) {
                Console.WriteLine("클라이언트 접속 대기중...");
                Socket clientSocket = serverSocket.Accept();

                Console.WriteLine("클라이언트 접속 완료");
                NetworkStream ns = new NetworkStream(clientSocket);
                StreamReader sr = new StreamReader(ns);
                StreamWriter sw = new StreamWriter(ns);

                while(true) {
                    string recvData = sr.ReadLine();
                    Console.WriteLine("← Client : " + recvData);
                    Console.WriteLine("→ Server : " + recvData);
                    sw.WriteLine(recvData);
                    sw.Flush();
                    if(recvData == "bye")
                        break;
                }
                clientSocket.Close();
            }
            serverSocket.Close();
        }
    }
}
