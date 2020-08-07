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
using System.Drawing.Drawing2D;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;

namespace teamproject {
    public partial class Form3 : Form {
        // Network 및 프로그램 관련
        Socket clientSocket;
        NetworkStream ns;
        StreamWriter sw;
        Thread tRecv;
        bool isRecv = true;

        // UI 출력을 위한 변수
        delegate void AddLogData(string data);
        AddLogData addLogData = null;
        int leftTabSize = 20;
        int pageIndex = 0;

        // User들의 정보
        SoundPlayer talkSound;
        List<Image> menteeImage;
        List<string> menteeName;
        Image mentorImage;
        int totalMentee = 0;
        string mentoName = "";
        string userName = "";
        string chatRoomName = "";

        public Form3(NetworkStream nl, Socket sl, string username) {
            InitializeComponent();
            this.Load += Form3_Load;
            this.Paint += Form3_Paint;
            this.FormClosed += Form3_FormClosed;
            // Login폼에서 생성한 Client 정보를 가져옴
            ns = nl;
            sw = new StreamWriter(ns);
            sw.AutoFlush = true;
            clientSocket = sl;
            this.userName = username;
        }
        private void Form3_FormClosed(object sender, FormClosedEventArgs e) {
            // Server와 연결을 끊음
            try {
                this.isRecv = false;
                if(this.clientSocket != null && this.clientSocket.Connected) {
                    string data = "request:Exit";
                    sw.WriteLine(data);
                    this.clientSocket.Close();
                    this.Close();
                }
            }
            catch(Exception ex) {
                Console.WriteLine("Exception : " + ex.Message);
            }
        }
        private void Form3_Load(object sender, EventArgs e) {
            this.addLogData = AddChatLogBox;
            this.Width = 965;
            this.Height = 865;
            this.isRecv = true;
	talkSound  = new SoundPlayer("../../Talk.wav");
            // Server와 통신하기 위한 스레드 생성
            this.tRecv = new Thread(new ThreadStart(ThreadRecv));
            this.tRecv.IsBackground = true;
            this.tRecv.Start();
        }

        private void Form3_Paint(object sender, PaintEventArgs e) {
            e.Graphics.DrawLine(new Pen(Brushes.YellowGreen, 10), leftTabSize + 30, 0, leftTabSize, ClientRectangle.Bottom);
        }

        // 채팅창에 내용을 입력
        void AddChatLogBox(string data) {
            if(chatLog.InvokeRequired) { // 스레드가 form 스레드에 접속할 때 충돌처리
                Invoke(addLogData, new object[] { data });
            }
            else {
                chatLog.Items.Add(data);
                chatLog.SelectedIndex = chatLog.Items.Count - 1;
            }
        }

        // 서버와 통신하기 위한 스레드
        void ThreadRecv() {
            StreamReader sr = new StreamReader(this.ns);
            bool enterRoom = true;
            Console.WriteLine(isRecv.ToString());
            while(this.isRecv) {
                try {
                    // 서버가 전송한 답변에 대한 처리
                    string data = sr.ReadLine();
                    // Server의 Answer에서 key와 value를 분리
                    string[] parse = data.Split(new char[2] { ',', ':' });
                    string answer = parse[1];
                    Console.WriteLine(data);
                    Console.WriteLine(answer);
                    switch(answer) {
                        /*case "Login":
                            for(int i = 0; i < parse.Length; i += 2) {
                                if(parse[i] == "Data")
                                    MessageBox.Show(parse[i + 1]);
                                else if(parse[i] == "UserName")
                                    userName = parse[i + 1];
                            }
                            break;*/
                        case "Tab2":
                            menteeName = new List<string>();
                            menteeImage = new List<Image>();
                            int lines = 0;
                            Console.WriteLine("Parse : " + parse.Length);
                            // Answer의 Key에 따른 value를 처리
                            for(int i = 0; i < parse.Length; i += 2) {
                                Console.WriteLine("Parse : " + parse[i] + " " + parse[i + 1]);
                                if(parse[i] == "Lines")
                                    lines = Convert.ToInt32(parse[i + 1]);
                                else if(parse[i] == "ChatLog" && enterRoom == true) {
                                    int idx = 0;
                                    string chatName;
                                    // Log가 [Username] Chat Content 형식으로 와서 username을 parsing
                                    // 해당 채팅이 누가 보낸 채팅인지에 따라 --> <-- 
                                    for(int j = 0; j < parse[i + 1].Length; j++) {
                                        if((parse[i + 1][j] == '>') || (parse[i + 1][j] == ']'))
                                            idx = j;
                                    }
                                    chatName = parse[i + 1].Substring(1, (idx - 1));
                                    //Console.WriteLine(chatName);
                                    if(chatName == userName) {
                                        AddChatLogBox($"--> {parse[i + 1]}");
                                    }
                                    else
                                        AddChatLogBox($"<-- {parse[i + 1]}");
                                }
                                else if(parse[i] == "ChatRoom" && enterRoom == true) {
                                    chatRoomName = parse[i + 1];
                                }
                                else if(parse[i] == "MentoName")
                                    mentoName = parse[i + 1];
                                else if(parse[i] == "TotalMentee") {
                                    totalMentee = Convert.ToInt32(parse[i + 1]);
                                }
                                else if(parse[i] == "MenteeName") {
                                    menteeName.Add(parse[i + 1]);
                                }
                                else if(parse[i] == "MentorImgPath") {
                                    mentorImage = Image.FromFile(parse[i + 1]);
                                }
                                else if(parse[i] == "MenteeImgPath") {
                                    menteeImage.Add(Image.FromFile(parse[i + 1]));
                                }
                                else if (parse[i] == "ExitChat")
                                {
                                    AddChatLogBox($"<-- {parse[i + 1]}");
                                }
                                else if (parse[i] == "EnterChat")
                                {
			talkSound.Play();
                                    AddChatLogBox($"<-- {parse[i + 1]}");
                                }
                            }
                            enterRoom = false;
                            //Console.WriteLine("totalMentee : " + totalMentee);
                            Invalidate();
                            tabPage2.Invalidate();
                            break;
                        case "Chat":
                            if(parse[3] == userName) {
                                AddChatLogBox($"--> [{userName}] {parse[5]}");
                            }
                            else {
                                AddChatLogBox($"<-- [{parse[3]}] {parse[5]}");
                            }
                            break;
                    }
                }
                catch(Exception ex) {
                    Console.WriteLine("Exception : " + ex.Message);
                    break;
                }
            }
        }

        // 탭을 변경했을때
        private void tabUI_SelectedIndexChanged(object sender, EventArgs e) {
            TabControl tab = sender as TabControl;
            //pageIndex = tab.TabPages.IndexOf(tab.SelectedTab) + 1;
            pageIndex = 2;
            string data = "request:Tab" + pageIndex.ToString();
            sw.WriteLine(data);
            Console.WriteLine("Page : " + pageIndex.ToString());
        }

        // 2번탭 그리기
        private void tabPage2_Paint(object sender, PaintEventArgs e) {
            if(pageIndex == 2) {
                Font font = new Font(" IBM Plex Mono ", 30);
                e.Graphics.DrawString(chatRoomName, font, Brushes.Blue, leftTabSize + 10, 0);
                e.Graphics.DrawString("참여자 " + (totalMentee + 1).ToString() + "명", new Font("맑은 고딕", 10), Brushes.Black, leftTabSize + 80, 50);
                e.Graphics.DrawString(" Mentor", new Font(" IBM Plex Mono ", 15), Brushes.DarkBlue, leftTabSize + 5, 70);
                if(mentorImage != null)
                    e.Graphics.DrawImage(mentorImage, leftTabSize + 15, 110, 180, 180);
                e.Graphics.DrawString(mentoName, new Font("Pyunji R", 15), Brushes.Black, leftTabSize + 15, 300);
                int menteePro = 350;
                e.Graphics.DrawString(" Mentee ", new Font(" IBM Plex Mono ", 15), Brushes.DarkBlue, leftTabSize + 5, menteePro - 7);
                for(int i = 0; i < totalMentee; i++) {
                    if(menteeImage.Count > i) {
                        e.Graphics.DrawImage(menteeImage[i], leftTabSize + 15, menteePro + 30, 100, 100);
                        e.Graphics.DrawString(menteeName[i], new Font("Pyunji R", 15), Brushes.Black, leftTabSize + 15, menteePro + 140);
                        menteePro += 140;
                    }
                }
            }
        }
        
        // 채팅을 입력하고 Enter쳤을 때
        private void chatText_KeyDown(object sender, KeyEventArgs e) {
            switch(e.KeyCode) {
                case Keys.Enter:
                    //SoundPlayer wp = new SoundPlayer("../../개.wav");
                    //wp.PlaySync();
                    string data = "request:Chat,Data:" + chatText.Text;
                    this.sw.WriteLine(data);
                    this.sw.Flush();
                    chatText.Clear();
                    break;
            }
        }
    }
}

