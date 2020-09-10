using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BandLine {
    public partial class Form1 : Form {
        class Line {
            public int sx { get; set; }
            public int sy { get; set; }
            public int ex { get; set; }
            public int ey { get; set; }
            public Line(int _sx,int _sy, int _ex, int _ey) {
                sx = _sx; sy = _sy; ex = _ex; ey = _ey;
            }
        }
        List<Line> line = new List<Line>(1);
        int sx, sy, ex, ey;
        bool state = false;
        public Form1() {
            InitializeComponent();
            BackColor = Color.DarkBlue;
            this.DoubleBuffered = true;
            this.MouseDown += Form1_MouseDown;
            this.MouseMove += Form1_MouseMove;
            this.MouseUp += Form1_MouseUp;
            this.Paint += Form1_Paint;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            if(state==true)
                e.Graphics.DrawLine(new Pen(Brushes.White, 10), sx, sy, ex, ey);
            for(int i=0;i<line.Count;i++)
                e.Graphics.DrawLine(new Pen(Brushes.White,10), line[i].sx, line[i].sy, line[i].ex, line[i].ey);
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e) {
            ex = e.X; ey = e.Y;
            line.Add(new Line(sx, sy, ex, ey));
            state = false;
            Invalidate();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e) {
            ex = e.X; ey = e.Y;
            Invalidate();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            sx = e.X; sy = e.Y;
            state = true;
        }
    }
}
