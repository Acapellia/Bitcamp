using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _64_NetworkStreamMultiThreadClientForm {
    public partial class Form1 : Form {
        Socket clientSocket;
        IPEndPoint ipep;

        NetworkStream ns;
        StreamWriter sw;

        Thread tRecv;
        bool isRecv;

        delegate void AddMsgData(string data);
        AddMsgData addMsgData = null;

        public Form1() {
            InitializeComponent();
            this.Load += Form1_Load;
            this.FormClosed += Form1_FormClosed;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e) {

        }

        private void Form1_Load(object sender, EventArgs e) {
            addMsgData = AddLogListBox;
        }

        private void btnClear_Click(object sender, EventArgs e) {
            lbLog.Items.Clear();
        }

        private void btnDisConnect_Click(object sender, EventArgs e) {
            try {
                isRecv = false;
                if(clientSocket != null && clientSocket.Connected) {
                    clientSocket.Close();
                }
            }
            catch(Exception ex) {
                AddLogListBox("Exception " + ex.Message);
            }
            finally {
                btnConnect.Enabled = true;
                btnDisConnect.Enabled = false;
            }
        }

        private void btnConnect_Click(object sender, EventArgs e) {
            isRecv = true;
            clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            ipep = new IPEndPoint(IPAddress.Parse(tbIP.Text), Convert.ToInt32(tbPort.Text));
            AddLogListBox("서버 접속 요청중");
            clientSocket.Connect(ipep);
            AddLogListBox("서버 접속 완료");

            ns = new NetworkStream(clientSocket);
            sw = new StreamWriter(ns);

            tRecv = new Thread(new ThreadStart(threadRecv));
            tRecv.Start();

            btnConnect.Enabled = false;
            btnDisConnect.Enabled = true;
        }

        private void tbChat_KeyDown(object sender, KeyEventArgs e) {
            if(e.KeyCode == Keys.Enter) {
                string data = tbChat.Text;
                sw.WriteLine(data);
                sw.Flush();
                AddLogListBox("← to Client : " + data);
                tbChat.Clear();
            }
        }
        void AddLogListBox(string data) {
            if(lbLog.InvokeRequired) {
                Invoke(addMsgData, new object[] { data });
            }
            else {
                lbLog.Items.Add(data);
                
            }
        }
        
        void threadRecv() {
            StreamReader sr = new StreamReader(ns);
            while(isRecv) {
                try {
                    string data = sr.ReadLine();
                    AddLogListBox("→ from Server " + data);
                }
                catch(Exception ex) {
                    AddLogListBox("Exception " + ex.Message);
                    break;
                }
            }
        }
    }
}
