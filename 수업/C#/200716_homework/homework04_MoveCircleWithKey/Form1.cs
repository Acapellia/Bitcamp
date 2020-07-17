using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace homework04_MoveCircleWithKey {
    public partial class Form1 : Form {
        Timer timer = new Timer();
        bool isStart = false;
        enum dir { UP = 0, DOWN, LEFT, RIGHT }
        int moveDir = 3;
        const int MOVE_VAL = 20;
        const int RAD = 50;
        int x = 0, y = 0;
        //int cnt = 0;
        public Form1() {
            InitializeComponent();
            timer.Interval = 20;
            timer.Tick += Timer_Tick;
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.DarkCyan, 5);
            g.DrawEllipse(myPen, x, y, RAD, RAD);
        }

        private void Timer_Tick(object sender, EventArgs e) {
            switch(moveDir) {
                case (int)dir.LEFT:
                    if(this.ClientRectangle.Left < this.x) x -= 10;
                    break;
                case (int)dir.RIGHT:
                    if(this.ClientRectangle.Right > this.x + RAD) x += 10;
                    break;
                case (int)dir.UP:
                    if(this.ClientRectangle.Top < this.y) y -= 10;
                    break;
                case (int)dir.DOWN:
                    if(this.ClientRectangle.Bottom > this.y + RAD) y += 10;
                    break;
            }
            Invalidate();
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
                case Keys.Left:
                    moveDir = (int)dir.LEFT;
                    break;
                case Keys.Right:
                    moveDir = (int)dir.RIGHT;
                    break;
                case Keys.Up:
                    moveDir = (int)dir.UP;
                    break;
                case Keys.Down:
                    moveDir = (int)dir.DOWN;
                    break;
            }
        }
    }
}

