using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BounceCircle {
    public partial class Form1 : Form {
        Timer timer = new Timer();
        const int RAD = 50;
        const int MOVE_VAL = 5;
        int x = 0, y = 0;
        bool xDir = true, yDir = true;
        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            timer.Interval = 10;
            timer.Tick += Timer_Tick;
            this.Paint += Form1_Paint;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if(x <= ClientRectangle.Left || x + RAD >= ClientRectangle.Right) { xDir = !xDir; }
            if(y <= ClientRectangle.Top || y + RAD >= ClientRectangle.Bottom) { yDir = !yDir; }
            x = (xDir == true) ? (x - MOVE_VAL) : (x + MOVE_VAL);
            y = (yDir == true) ? (y - MOVE_VAL) : (y + MOVE_VAL);
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.Red, 1);
            g.FillEllipse(Brushes.Red, x, y, RAD, RAD);
        }
    }
}
