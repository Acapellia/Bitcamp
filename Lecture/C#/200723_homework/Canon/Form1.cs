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

namespace Canon {
    public partial class Form1 : Form {
        int ballLeft, ballTop;
        const int BALL_SIZE = 50;
        double speed = 100;             // 초속
        double degree = 45;             // 각도
        const double G = 9.80665D;      // 중력가속도
        Brush ballBrush = Brushes.DarkRed;

        public Form1() {
            InitializeComponent();
            this.Load += Form1_Load;
            this.KeyDown += Form1_KeyDown;
            this.Paint += Form1_Paint;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            e.Graphics.FillEllipse(ballBrush, ballLeft, this.ballTop, BALL_SIZE, BALL_SIZE);
            e.Graphics.DrawString("Degree : (Left, Right)  /  Speed : (Up, Down)", new Font("맑은 고딕", 30), Brushes.White, 50, 50);
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            switch(e.KeyCode) {
                case Keys.Enter: {
                        Graphics g = CreateGraphics();
                        double x, y;
                        for(int t = 0; ; t++) {
                            g.Clear(Color.Black);
                            double radian = degree * Math.PI / 180;
                            x = this.speed * Math.Cos(radian) * t;
                            y = (this.speed * Math.Sin(radian) * t) - (G * t * t * 0.5);
                            y = -y; //y축이 Catersian좌표에 반대라서
                            g.FillEllipse(Brushes.Gold, (float)(x + ballLeft), (float)(y + ballTop), BALL_SIZE, BALL_SIZE);

                            if(y > this.ClientRectangle.Bottom) {
                                this.ballLeft = this.Width / 10;
                                this.ballTop = this.Height / 10 * 7;
                                Invalidate();
                                break;
                            }
                            Thread.Sleep(100);
                        }
                        g.Dispose();
                    }
                    break;
                case Keys.Left:
                    degree -= 5; break;
                case Keys.Right:
                    degree += 5; break;
                case Keys.Up:
                    speed += 10; break;
                case Keys.Down:
                    speed -= 10; break;
            }
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.Width = 1024;
            this.Height = 768;
            this.BackColor = Color.Black;
            this.ballLeft = this.Width / 10;
            this.ballTop = this.Height / 10 * 7;
        }
    }
}