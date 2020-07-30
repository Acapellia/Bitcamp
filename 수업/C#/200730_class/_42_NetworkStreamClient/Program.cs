using System;
using System.IO;
using System.Net;
using System.Net.Sockets;

namespace _42_NetworkStreamClient {
    class Program {
        static void Main(string[] args) {
            const string IP = "127.0.0.1";
            const int PORT = 9000;
            Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPEndPoint ipep = new IPEndPoint(IPAddress.Parse(IP), PORT);
            clientSocket.Connect(ipep);
            NetworkStream ns = new NetworkStream(clientSocket);
            StreamWriter sw = new StreamWriter(ns);

            string data = "어디서 왔는지 모르는 메시지";
            sw.WriteLine(data);
            sw.Flush();
            clientSocket.Close();
        }
    }
}
