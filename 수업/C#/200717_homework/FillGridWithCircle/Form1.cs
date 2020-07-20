using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FillGridWithCircle {
    class Pair {
        public int x { get; set; }
        public int y { get; set; }
        public bool color { get; set; }
        public Pair(int x, int y, bool c) { this.x = x; this.y = y; this.color = c; }
    }
    public partial class Form1 : Form {
        int w, h, len = 50;
        int mx = -99, my = -99;
        int cnt = 0;
        bool color = false;
        //int[,] circleArr = new int[150, 2];
        List<Pair> circleList = new List<Pair>();
        public Form1() {
            InitializeComponent();
            BackColor = Color.Aqua;
            w = h = len;
            this.Paint += Form1_Paint;
            this.MouseClick += Form1_MouseClick;
            Invalidate();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e) {
            mx = e.X; my = e.Y;
            //circleArr[cnt, 0] = (mx / w) * w;
            //circleArr[cnt, 1] = (my / h) * h;
            circleList.Add(new Pair((mx / w) * w, (my / h) * h, color));     
            color = !color; cnt++;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.Black, 1);

            // w
            for(int i = 0; i < ClientRectangle.Bottom/h; i++) {
                g.DrawLine(myPen, 0, h*(i+1), ClientRectangle.Right, h*(i+1));
            }

            // h
            for(int i = 0; i < ClientRectangle.Right/w; i++) {
                g.DrawLine(myPen, w * (i+1), 0, w * (i+1), ClientRectangle.Bottom);
            }

            // ellipse
            for(int i = 0; i < cnt; i++) {
                //g.DrawEllipse(myPen, circleArr[i, 0], circleArr[i, 1], w, h);
                if(circleList[i].color == false) { g.FillEllipse(Brushes.Black, circleList[i].x, circleList[i].y, w, h);}
                else if(circleList[i].color == true) { g.FillEllipse(Brushes.White, circleList[i].x, circleList[i].y, w, h);}
            }
        }
    }
}
