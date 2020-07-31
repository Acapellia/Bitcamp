using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RunGameWithThread {
    public partial class Form1 : Form {
        System.Windows.Forms.Timer timer = new System.Windows.Forms.Timer();
        Image[] img = new Image[3];
        Thread[] thread = new Thread[3];
        int sizeX, sizeY;
        int[] moveX = new int[3];
        int gameState = 0 , winner = -1;
        Random r = new Random();
        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.MouseDoubleClick += Form1_MouseDoubleClick;
            timer.Interval = 1;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if(gameState == 0) {
                for(int i = 0; i < 3; i++) {
                    if(thread[i].IsAlive == false) {
                        gameState = 1; winner = i; break;
                    }
                }
            }
            if(winner != -1) {
                timer.Stop();
            }
            Invalidate();
        }

        private void runStart(object i) {
            int idx = (int)i;
            int dir = 1;
            Console.WriteLine(idx);
            while(winner==-1) {
                if(dir == 1) {
                    moveX[idx] += r.Next(10, 50);
                    if(moveX[idx]+sizeX > ClientRectangle.Right)
                        dir=0;
                }
                else if(dir == 0) {
                    moveX[idx] -= r.Next(10, 50);
                    if(moveX[idx] < 0) // goal
                        break;
                }
                Thread.Sleep(r.Next(10,100));
                Invalidate();
            }
        }

        private void Form1_MouseDoubleClick(object sender, MouseEventArgs e) {
            for(int i = 0; i < 3; i++) {
                thread[i] = new Thread(new ParameterizedThreadStart(runStart));
                thread[i].Start(i);
            }
            timer.Start();
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.BackColor = Color.Black;
            sizeX = ClientRectangle.Right / 8;
            sizeY = ClientRectangle.Bottom / 3;
            img[0] = Image.FromFile("../../../박보영.jpg");
            img[1] = Image.FromFile("../../../아이유.jpg");
            img[2] = Image.FromFile("../../../장나라.jpg");
        }
        private void Form1_Paint(object sender, PaintEventArgs e) {
            if(gameState == 1) {
                string strWinner = "";
                if(winner == 0)  strWinner = "박보영";
                if(winner == 1) strWinner = "아이유";
                if(winner == 2) strWinner = "장나라";
                e.Graphics.DrawString(strWinner, new Font("맑은 고딕", 200), Brushes.White, ClientRectangle.Right / 2-450, ClientRectangle.Bottom / 2 - 200);
            }
            else {
                e.Graphics.DrawImage(img[0], moveX[0], 0, sizeX, sizeY);
                e.Graphics.DrawImage(img[1], moveX[1], sizeY, sizeX, sizeY);
                e.Graphics.DrawImage(img[2], moveX[2], sizeY * 2, sizeX, sizeY);
                for(int i = 0; i < 4; i++) {
                    e.Graphics.DrawLine(new Pen(Brushes.Yellow, 5), 0, i * sizeY, ClientRectangle.Right, i * sizeY);
                }
                e.Graphics.DrawLine(new Pen(Brushes.Aqua, 10), 0, 0, 0, ClientRectangle.Bottom);
                e.Graphics.DrawLine(new Pen(Brushes.Red, 10), ClientRectangle.Right, 0, ClientRectangle.Right, ClientRectangle.Bottom);
            }
        }
    }
}
