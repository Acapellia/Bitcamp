using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace homework03_FillRectWithKey {
    public partial class Form1 : Form {
        int W = 50, H = 100;
        enum dir { UP=0,DOWN,LEFT,RIGHT,MIDDLE}
        bool[] fill = { false, false, false, false,false };
        public Form1() {
            InitializeComponent();
            this.KeyDown += Form1_KeyDown;
            this.KeyUp += Form1_KeyUp;
            this.Paint += Form1_Paint;
        }
      
        private void Form1_KeyUp(object sender, KeyEventArgs e) {
            switch(e.KeyCode) {
                case Keys.Left:
                    fill[(int)dir.LEFT] = false; break;
                case Keys.Right:
                    fill[(int)dir.RIGHT] = false; break;
                case Keys.Up:
                    fill[(int)dir.UP] = false; break;
                case Keys.Down:
                    fill[(int)dir.DOWN] = false; break;
                case Keys.Space:
                    fill[(int)dir.MIDDLE] = false; break;
            }
            Invalidate();
        }


        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.DarkBlue, 1);

            if(fill[(int)dir.UP]) g.FillRectangle(Brushes.Red, W, 0, W, H);
            if(fill[(int)dir.DOWN]) g.FillRectangle(Brushes.Red, W, H * 2, W, H);
            if(fill[(int)dir.LEFT]) g.FillRectangle(Brushes.Red, 0, H, W, H);
            if(fill[(int)dir.RIGHT]) g.FillRectangle(Brushes.Red, W * 2, H, W, H);
            if(fill[(int)dir.MIDDLE]) g.FillRectangle(Brushes.Red, W, H, W, H);

            g.DrawRectangle(myPen, W, 0, W, H); // up
            g.DrawRectangle(myPen, W, H * 2, W, H); // down
            g.DrawRectangle(myPen, 0, H, W, H); // left
            g.DrawRectangle(myPen, W * 2, H, W, H); // right
            g.DrawRectangle(myPen, W, H, W, H); // middle
            
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            int state = 0;
            switch(e.KeyCode) {
                case Keys.Left:
                    if(fill[(int)dir.LEFT] == false) { fill[(int)dir.LEFT] = true; state = 1; } break;
                case Keys.Right:
                    if(fill[(int)dir.RIGHT] == false){ fill[(int)dir.RIGHT] = true; state = 1; } break;
                case Keys.Up:
                    if(fill[(int)dir.UP] == false){ fill[(int)dir.UP] = true; state = 1; } break;
                case Keys.Down:
                    if(fill[(int)dir.DOWN] == false){ fill[(int)dir.DOWN] = true; state = 1; } break;
                case Keys.Space:
                    if(fill[(int)dir.MIDDLE] == false){ fill[(int)dir.MIDDLE] = true; state = 1; } break;
            }
            if(state == 1) Invalidate();
        }
    }
}
