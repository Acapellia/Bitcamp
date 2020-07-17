using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _10_MoveEllipseTimer {
    public partial class Form1 : Form {
        Timer timer = new Timer();
        bool isStart = false;
        const int MOVE_VAL = 20;
        const int RAD = 100;
        int x=0, y = 0;
        int cnt = 0;
        public Form1() {
            InitializeComponent();
            timer.Interval = 100;
            timer.Tick += Timer_Tick;
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            switch(e.KeyCode) {
                case Keys.Enter:
                    if(!isStart)
                        timer.Start();
                    else
                        timer.Stop();
                    isStart = !isStart;
                    break;
            }
        }

        private void Timer_Tick(object sender, EventArgs e) {
            x += MOVE_VAL;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.DarkCyan, 5);
            g.DrawEllipse(myPen, x, y, RAD, RAD);
        }
    }
}
