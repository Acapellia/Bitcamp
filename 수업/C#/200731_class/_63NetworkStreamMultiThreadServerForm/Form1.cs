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

namespace NetworkStreamMultiThreadServerForm {
    public partial class Form1 : Form {
        Socket acceptSocket;
        IPEndPoint ipep;

        Thread tAccept;
        bool isAccept = true;
        //Thread tRecv;
        bool isRecv = true;

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
            addMsgData = AddLogListbox;
        }

        private void btnStart_Click(object sender, EventArgs e) {
            this.isAccept = true;
            this.isRecv = true;
            this.acceptSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            this.ipep = new IPEndPoint(IPAddress.Any, Convert.ToInt32(tbPort.Text));
            this.acceptSocket.Bind(ipep);
            this.acceptSocket.Listen(1000);
            AddLogListbox("서버 대기중.....");
            this.tAccept = new Thread(new ThreadStart(ThreadAccept));
            this.tAccept.Start();

            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }

        private void btnStop_Click(object sender, EventArgs e) {
            try {
                this.isAccept = false;
                this.isRecv = false;
                this.acceptSocket.Close();
            }catch(Exception ex) {
                AddLogListbox("Exception " + ex.Message);
            }
            finally {
                btnStart.Enabled = true;
                btnStop.Enabled = false;
            }
        }

        private void btnClear_Click(object sender, EventArgs e) {
            lbLog.Items.Clear();
        }
        void ThreadAccept() {
            while(this.isAccept) {
                try {
                    Socket partnerSocket = this.acceptSocket.Accept();
                    AddLogListbox("클라이언트 접속");
                    NetworkStream ns = new NetworkStream(partnerSocket);
                    //StreamWriter sw = new StreamWriter(ns);
                    Thread tRecv = new Thread(new ParameterizedThreadStart(ThreadRecv));
                    tRecv.Start(ns);
                }
                catch(Exception ex) {
                    AddLogListbox("Exception " + ex.Message);
                }
            }
        }
        void ThreadRecv(object obj) {
            NetworkStream ns = obj as NetworkStream;
            StreamReader sr = new StreamReader(ns);
            StreamWriter sw = new StreamWriter(ns);
            while(this.isRecv) {
                try {
                    string data = sr.ReadLine();
                    AddLogListbox("← Client 수신 " + data);
                    sw.WriteLine(data);
                    AddLogListbox("→ echo : " + data);
                    sw.Flush();
                }
                catch(Exception ex) {
                    AddLogListbox("Exception " + ex.Message);
                    break;
                }
            }
        }
        void AddLogListbox(string data) {
            if(lbLog.InvokeRequired) {
                Invoke(addMsgData, new object[] { data });
            }
            else {
                lbLog.Items.Add(data);
                lbLog.SelectedIndex = lbLog.Items.Count - 1;
            }
        }
    }
}
