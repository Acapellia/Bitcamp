using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CircleTime {
    public partial class Form1 : Form {
        int centX, centY;
        int timerX = 20;
        int timerY = 20;
        const int RADIUS = 200;
        DateTime dt = DateTime.Now;
        Timer timer = new Timer();

        public Form1() {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            timer.Interval = 1000;  //1초
            timer.Tick += Timer_Tick;
            DoubleBuffered = true;
        }

        private void Timer_Tick(object sender, EventArgs e) {
            dt = DateTime.Now;
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.BackColor = Color.Black;
            this.Width = 800;
            this.Height = 820;
            this.centX = this.Width / 2;
            this.centY = this.Height / 2;
            timer.Start();
        }

        void DrawWatchNum(Graphics g, int cnt) {
            g.FillEllipse(Brushes.White, new RectangleF((float)centX - 10, (float)centY - 10, 20, 20));
            Pen pen = new Pen(Brushes.Gold, 10);
            int degree = 360 / cnt;             // 몇도씩 움직일 것인지

            for(int i = 0; i < 360; i += degree) {
                double x = this.centX + (RADIUS * Math.Cos(i * Math.PI / 180));
                double y = this.centY + (RADIUS * Math.Sin(i * Math.PI / 180));
                g.DrawEllipse(pen, new RectangleF((float)x - 20, (float)y - 20, 40, 40));
                g.FillEllipse(Brushes.DarkBlue, new RectangleF((float)x - 20, (float)y - 20, 40, 40));
                int time = (i / 30 + 3);
                int gap;
                //time = time > 12 ? time - 12 : time;
                gap = time < 10 ? 10 : 0;
                g.DrawString(time.ToString(), new Font("맑은 고딕", 20), Brushes.White, (float)x - 20 + gap, (float)y - 20);
            }
        }

        void DrawWatchLine(Graphics g, int cnt) {
            int degree = 360 / cnt;             // 몇도씩 움직일 것인지
            for(int i = 0; i < 360; i += degree) {
                double x = this.centX + (RADIUS * Math.Cos(i * Math.PI / 180));
                double y = this.centY + (RADIUS * Math.Sin(i * Math.PI / 180));
                g.FillEllipse(Brushes.White, new RectangleF((float)x - 5, (float)y - 5, 10, 10));
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Font font = new Font("Arial", 32);
            DrawWatchLine(e.Graphics, 360);
            DrawWatchNum(e.Graphics, 12);
            e.Graphics.DrawString(dt.ToString("HH:mm:ss"), font, Brushes.White, timerX, timerY);
        }
    }
}
