using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClickPositionImage {
    class Point {
        public int x { get; set; }
        public int y { get; set; }
        public int sx { get; set; }
        public int sy { get; set; }
        public int ex { get; set; }
        public int ey { get; set; }
        public bool t { get; set; }
        public Point(int _x, int _y, int _ex, int _ey, bool _t) { 
            x = _x; y = _y; ex = _ex; ey = _ey; sx = 0; sy = 0; t = _t; 
        }
    }
    public partial class Form1 : Form {
        Image img1,img2 = null;
        int mx, my;
        bool type = false;
        List<Point> point;
        public Form1() {
            InitializeComponent();
            this.Width = 900;
            this.Height = 850;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            mx = e.X;
            my = e.Y;
            int ex, ey; 
            if(e.Button == MouseButtons.Left) {
                type = false;
                Console.WriteLine(mx + " " + img1.Width + " " + ClientRectangle.Right);
                ex = mx + img1.Width > ClientRectangle.Right ? (ClientRectangle.Right-mx)*100/33 : img1.Width;
                ey = my + img1.Height > ClientRectangle.Bottom ? (ClientRectangle.Bottom - my) * 100 / 33 : img1.Height;
                point.Add(new Point(mx, my, ex, ey, type));
            }
            else if(e.Button == MouseButtons.Right) {
                type = true;
                point.Add(new Point(mx, my, img2.Width, img2.Height, type));
            }
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.DoubleBuffered = true;
            BackColor = Color.Black;
            img1 = Image.FromFile("../../puppy.jpg");
            img2 = Image.FromFile("../../cat.jpg");
            point = new List<Point>(1);
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            for(int i = 0; i < point.Count; i++) {
                if(point[i].t == false) {
                    e.Graphics.DrawImage(img1, point[i].x, point[i].y);
                }
                else {
                    e.Graphics.DrawImage(img2, point[i].x, point[i].y);
                }
            }
        }
    }
}
