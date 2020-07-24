using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CanonGame {
    
    public partial class Form1 : Form {
        Stopwatch sw = new Stopwatch();
        System.Windows.Forms.Timer timer = new System.Windows.Forms.Timer();
        List<Point> target = new List<Point>();
        int ballLeft, ballTop, firedX, firedY;
        double mX, mY;
        const int BALL_SIZE = 30, TargetSize = 50, ShooterSize = 100, move = 10;
        double speed = 70;             // 초속
        double degree = 45;             // 각도
        const double G = 9.80665D;      // 중력가속도
        bool isFired = false;
        Brush ballBrush = Brushes.DarkRed;

        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;
            this.Paint += Form1_Paint;
            timer.Interval = 50;
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e) {
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            sw.Start();
            this.Width = 1500;
            this.Height = 900;
            this.BackColor = Color.Black;
            this.ballLeft = this.Width / 10;
            this.ballTop = this.Height / 10 * 7;
            makeFood();
        }
        
        
        private void Form1_Paint(object sender, PaintEventArgs e) {
            if(isFired == false)
                e.Graphics.FillEllipse(ballBrush, ballLeft, ballTop, BALL_SIZE, BALL_SIZE);
            else { e.Graphics.FillEllipse(Brushes.Gold, (float)(mX + (float)firedX), (float)(mY + (float)firedY), BALL_SIZE, BALL_SIZE); }
            e.Graphics.FillRectangle(Brushes.White, ballLeft - ShooterSize, ballTop, ShooterSize, BALL_SIZE);
            e.Graphics.DrawString("Degree : (W, S)  /  Speed : (A, D)", new Font("맑은 고딕", 30), Brushes.White, 10, 10);
            TimeLabel.Text = sw.Elapsed.ToString("hh\\:mm\\:ss\\.ffffff");
            for(int i = 0; i < target.Count; i++) {
                e.Graphics.FillRectangle(Brushes.Aquamarine, target[i].x, target[i].y, TargetSize, TargetSize);
            }
        }
        private void fire() {
            //Graphics g = CreateGraphics();
            double x, y;
            for(float t = 0; ; t+=0.2f) {
                //g.Clear(Color.Black);
                double radian = degree * Math.PI / 180;
                x = this.speed * Math.Cos(radian) * t;
                y = (this.speed * Math.Sin(radian) * t) - (G * t * t * 0.5);
                y = -y;
                mX = x;
                mY = y;
                if(y > this.ClientRectangle.Bottom) {
                    Invalidate();
                    break;
                }
                collision();
                Invalidate();
                Thread.Sleep(1);
            }
            isFired = false;
            //g.Dispose();
        }
        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            switch(e.KeyCode) {
                case Keys.Space: {
                        if(isFired == true)
                            break;
                        firedX = ballLeft; firedY = ballTop;
                        Thread shoot = new Thread(fire);
                        shoot.Start();
                        isFired = true;
                    }
                    break;
                case Keys.W:
                    degree += 5;
                    break;
                case Keys.S:
                    degree = degree > 0 ? degree - 5 : 0;
                    break;
                case Keys.A:
                    speed = speed > 0 ? speed - 10 : 0;
                    break;
                case Keys.D:
                    speed += 10;
                    break;
                case Keys.Left:
                    ballLeft -= move;
                    break;
                case Keys.Right:
                    ballLeft += move;
                    break;
                case Keys.Up:
                    ballTop -= move;
                    break;
                case Keys.Down:
                    ballTop += move;
                    break;
            }
            this.Text = "Degeree : " + degree + " / Speed : " + speed;
            Invalidate();
        }
        
        private void makeFood() {
            Random r = new Random();
            for(int i = 0; i < 10; i++) {
                int x = r.Next(50, ClientRectangle.Right - 100);
                int y = r.Next(50, ClientRectangle.Bottom - 100);
                target.Add(new Point(x, y));
            }
        }

        private void collision() {
            float cx = (float)firedX + (float)mX + BALL_SIZE/2;
            float cy = (float)firedY + (float)mY + BALL_SIZE/2;
            
            for(int i=0; i < target.Count; i++) {
                if(((float)target[i].x <= cx && cx <= (float)target[i].x + (float)TargetSize) && 
                    ((float)target[i].y <= cy && cy <= (float)target[i].y + (float)TargetSize)) {
                    target.RemoveAt(i);
                    Invalidate(); break;
                }
            }
            if(target.Count <= 0) { timer.Stop(); }
        }
    }
    class Point {
        public int x { get; set; }
        public int y { get; set; }
        public Point(int _x, int _y) { x = _x; y = _y; }
    }
}