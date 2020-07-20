using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MoveCircle {
    enum Dir { Left=1, Right=2 }
    public partial class Form1 : Form {
        Timer timer = new Timer();
        const int RAD = 80;
        const int MOVE_VAL = 10;
        int x = 10, y = 150;
        int dir = (int)Dir.Right;
        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            timer.Interval = 10;
            timer.Tick += Timer_Tick;
            this.Paint += Form1_Paint;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if(x <= ClientRectangle.Left)
                dir = (int)Dir.Right;
            if(x + RAD >= ClientRectangle.Right)
                dir = (int)Dir.Left;

            if(dir == (int)Dir.Left) {
                x -= MOVE_VAL;
            }
            else if(dir == (int)Dir.Right) {
                x += MOVE_VAL;
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.Red,1);
            g.FillEllipse(Brushes.Red, x, y, RAD, RAD);
        }
    }
}
