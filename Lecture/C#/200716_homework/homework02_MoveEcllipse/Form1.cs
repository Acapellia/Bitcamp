using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace homework02_MoveEcllipse {
    public partial class Form1 : Form {
        const int RAD = 100;
        const int MOVE_VAL = 10;
        int x = 10, y = 10;

        public Form1() {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            switch(e.KeyCode) {
                case Keys.Left:
                    if(this.ClientRectangle.Left<this.x)
                        this.x -= MOVE_VAL;
                    break;
                case Keys.Right:
                    if(this.ClientRectangle.Right > this.x+RAD)
                        this.x += MOVE_VAL;
                    break;
                case Keys.Up:
                    if(this.ClientRectangle.Top < this.y)
                        this.y -= MOVE_VAL;
                    break;
                case Keys.Down:
                    if(this.ClientRectangle.Bottom > this.y+RAD)
                        this.y += MOVE_VAL;
                    break;
            }
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.DarkBlue, 5);
            g.DrawEllipse(myPen, x, y, RAD, RAD);
        }
    }
}
