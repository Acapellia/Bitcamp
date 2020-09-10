using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Animation {
    public partial class Form1 : Form {
        Timer timer = new Timer();
        Image image = null;
        int imageSize,idx=0;
        int ix=0, iy=0, gap=100;
        public Form1() {
            InitializeComponent();
            BackColor = Color.Black;
            this.Width = 1200;
            this.Height = 700;
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            this.MouseDown += Form1_MouseDown;
            timer.Interval = gap;
            timer.Start();
            timer.Tick += Timer_Tick;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            ix = e.X; iy = e.Y;
            Invalidate();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            if(e.KeyCode == Keys.Left && ix>0) { ix-=10; }
            if(e.KeyCode == Keys.Right && ix + imageSize < ClientRectangle.Right) { ix+=10; }
            if(e.KeyCode == Keys.Up && gap > 0) { gap -= 1; }
            if(e.KeyCode == Keys.Down) { gap += 1; }
            timer.Interval = gap;
            this.Text = "speed : " + gap.ToString();
            Invalidate();
        }

        private void Timer_Tick(object sender, EventArgs e) {
            idx = idx > 5 ? 0 : idx+1;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
             e.Graphics.DrawImage(image, ix, iy,new Rectangle(imageSize * (idx), 50, imageSize, image.Height), GraphicsUnit.Pixel);
        }

        private void Form1_Load(object sender, EventArgs e) {
            image = Image.FromFile("../../ani.png");
            imageSize = image.Width / 5;
        }
    }
}
