using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageChangewithClick {
    public partial class Form1 : Form {
        Image[] img = new Image[7];
        int cx, cy, rad;
        int idx = 0;
        public Form1() {
            InitializeComponent();
            this.Load += Form1_Load;
            this.MouseDown += Form1_MouseDown;
            this.Paint += Form1_Paint;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            e.Graphics.DrawImage(img[idx++], 0, 0,ClientRectangle.Right,ClientRectangle.Bottom);
            e.Graphics.DrawEllipse(new Pen(Brushes.Gold, 5), cx - rad, cy - rad, rad * 2, rad * 2);
            if(idx == 7)
                idx = 0;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            double difX, difY;
            difX = (double)(e.X - cx) * (double)(e.X - cx);
            difY = (double)(e.Y - cy) * (double)(e.Y - cy);
            if(difX + difY < rad * rad) { Invalidate(); }
            
        }

        private void Form1_Load(object sender, EventArgs e) {
            cx = 150;
            cy = 150;
            rad = 80;
            for(int i = 0; i < 7; i++) {
                string path = "../../../";
                path += (i + ".jpg");
                img[i] = Image.FromFile(path);
            }
        }
    }
}
