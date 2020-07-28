using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clock {
    public partial class Form1 : Form {
        SoundPlayer clockSound;
        Random r = new Random();
        Image[] img = new Image[13];
        int centX, centY;
        int timerX = 20;
        int timerY = 20;
        const int RADIUS = 230;
        const int SEC_RADIUS = 200;
        const int MIN_RADIUS = 150;
        const int HOUR_RADIUS = 100;
        DateTime dt = DateTime.Now;
        Timer timer = new Timer();

        double secX, secY;
        double minX, minY;
        double hourX, hourY;
        int hour, min, sec;

        public Form1() {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            timer.Interval = 1000;  //1초
            timer.Tick += Timer_Tick;
            DoubleBuffered = true;
        }
        private void calcTimeHand() {
            dt = DateTime.Now;
            sec = dt.Second;
            min = dt.Minute;
            hour = dt.Hour;
            secX = this.centX + (SEC_RADIUS * Math.Cos(6 * (sec - 15) * Math.PI / 180));
            secY = this.centY + (SEC_RADIUS * Math.Sin(6 * (sec - 15) * Math.PI / 180));
            minX = this.centX + (MIN_RADIUS * Math.Cos((double)(6 * (min - 15) + 0.1 * (double)sec) * Math.PI / 180));
            minY = this.centY + (MIN_RADIUS * Math.Sin((double)(6 * (min - 15) + 0.1 * (double)sec) * Math.PI / 180));
            hourX = this.centX + (HOUR_RADIUS * Math.Cos((double)(30 * (hour - 15) + 0.5 * (double)min + 0.1 * (double)sec) * Math.PI / 180));
            hourY = this.centY + (HOUR_RADIUS * Math.Sin((double)(30 * (hour - 15) + 0.5 * (double)min + 0.1 * (double)sec) * Math.PI / 180));
        }
        private void Timer_Tick(object sender, EventArgs e) {
            calcTimeHand();
            clockSound.Play();
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.BackColor = Color.Black;
            this.Width = 800;
            this.Height = 820;
            this.centX = this.Width / 2;
            this.centY = this.Height / 2;
            calcTimeHand();
            clockSound = new SoundPlayer();
            clockSound.SoundLocation = "../../clock.wav";
            for(int i = 0; i < 12; i++) {
                string path = "../../" + i + ".jpg";
                img[i] = Image.FromFile(path);
            }
            
            timer.Start();
        }

        void DrawWatchNum(Graphics g, int cnt) {
            g.FillEllipse(Brushes.White, new RectangleF((float)centX - 10, (float)centY - 10, 20, 20));
            Pen pen = new Pen(Brushes.Gold, 10);
            int degree = 360 / cnt;             // 몇도씩 움직일 것인지

            for(int i = 0; i < 360; i += degree) {
                double x = this.centX + (SEC_RADIUS * Math.Cos(i * Math.PI / 180));
                double y = this.centY + (SEC_RADIUS * Math.Sin(i * Math.PI / 180));
                int time = (i / 30 + 3);
                int gap;
                time = time > 12 ? time - 12 : time;
                gap = time < 10 ? 10 : 0;
                g.DrawString(time.ToString(), new Font("맑은 고딕", 20), Brushes.Black, (float)x - 18 + gap, (float)y - 18);
                g.DrawString(time.ToString(), new Font("맑은 고딕", 20), Brushes.White, (float)x - 20 + gap, (float)y - 20);

            }
            g.DrawLine(new Pen(Brushes.CornflowerBlue, 3), (float)centX, (float)centY, (float)secX, (float)secY);
            g.DrawLine(new Pen(Brushes.DeepSkyBlue, 5), (float)centX, (float)centY, (float)minX, (float)minY);
            g.DrawLine(new Pen(Brushes.Aqua, 7), (float)centX, (float)centY, (float)hourX, (float)hourY);
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Font font = new Font("Arial", 32);

            //e.Graphics.DrawImage(image, ix, iy, new Rectangle(imageSize * (idx), 50, imageSize, image.Height), GraphicsUnit.Pixel);
            

            e.Graphics.DrawEllipse(new Pen(Brushes.White,5), this.centX - RADIUS, this.centY - RADIUS, RADIUS * 2, RADIUS * 2);
            e.Graphics.DrawEllipse(new Pen(Brushes.Red, 2), this.centX - RADIUS+2, this.centY - RADIUS+2, RADIUS * 2-4, RADIUS * 2-4);
            DrawWatchNum(e.Graphics, 12);
            e.Graphics.DrawString(dt.ToString("HH:mm:ss"), font, Brushes.White, timerX, timerY);
        }
    }
}
