using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClickCircle {
    public partial class Form1 : Form {
        int cx, cy, rad;
        bool state = false;
        public Form1() {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.Load += Form1_Load;
            this.MouseDown += Form1_MouseDown;
            this.MouseUp += Form1_MouseUp;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e) {
            state = false;
            Invalidate();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            double difX, difY;
            difX = (double)(e.X - cx) * (double)(e.X - cx);
            difY = (double)(e.Y - cy) * (double)(e.Y - cy);
            if(difX + difY < rad * rad) { state = true; }
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            cx = 150;
            cy = 150;
            rad = 80;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            e.Graphics.DrawEllipse(new Pen(Brushes.DarkBlue, 5), cx - rad, cy - rad, rad * 2, rad * 2);
            if(state == true) {
                e.Graphics.DrawRectangle(new Pen(Brushes.Gold, 5), cx - rad, cy - rad, rad * 2, rad * 2);
                e.Graphics.DrawString("Click", new Font("맑은 고딕", 30), Brushes.Gold, cx-rad/2-10, cy-rad/2+10);
            }
        }
    }
}
