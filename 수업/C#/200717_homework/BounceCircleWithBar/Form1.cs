using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BounceCircleWithBar {
    public partial class Form1 : Form {
        Timer timer = new Timer();
        const int MOVE_VAL = 5;
        const int MOVE_BAR = 30;
        int x = 1, y = 1;
        const int RAD = 50;
        bool xDir = true, yDir = true;
        int barX, barY;
        int barW=100, barH=20;
        int score = 0, loss = 0;
        public Form1() {
            InitializeComponent();
            barX = (ClientRectangle.Left + ClientRectangle.Right) / 2;
            barY = ClientRectangle.Bottom - barH;

            timer.Interval = 15;
            timer.Tick += Timer_Tick;
            this.DoubleBuffered = true;
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;

            timer.Start();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            if(e.KeyCode == Keys.Left && barX>ClientRectangle.Left)
                barX -= MOVE_BAR;
            else if(e.KeyCode == Keys.Right && barX+barW<ClientRectangle.Right)
                barX += MOVE_BAR;
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if((x <= ClientRectangle.Left || x + RAD >= ClientRectangle.Right) && (y <= ClientRectangle.Top || y + RAD >= ClientRectangle.Bottom)) {
                xDir = !xDir; yDir = !yDir;
            }
            else if(x <= ClientRectangle.Left || x + RAD >= ClientRectangle.Right) {
                xDir = !xDir;
            }
            else if(yDir == true && (barX <= ((x + x + RAD) / 2) && ((x + x + RAD) / 2) <= barX + barW) && (y + RAD >= barY)) {
                yDir = !yDir; score++;
                ScoreLabel.Text = "Score : " + score;
            }
            else if(y <= ClientRectangle.Top || y + RAD >= ClientRectangle.Bottom) {
                yDir = !yDir;
                if(y + RAD >= ClientRectangle.Bottom) {
                    score--; loss = 1;
                }
                ScoreLabel.Text = "Score : " + score;
            }
            x = (xDir == true) ? (x + MOVE_VAL) : (x - MOVE_VAL);
            y = (yDir == true) ? (y + MOVE_VAL) : (y - MOVE_VAL);
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen = new Pen(Brushes.Green, 30);
            g.FillEllipse(Brushes.Red, x, y, RAD, RAD);
            g.FillRectangle(Brushes.DarkBlue, barX, barY, barW, barH);
            if(loss == 1) {
                g.DrawLine(myPen, 0, ClientRectangle.Bottom, ClientRectangle.Right, ClientRectangle.Bottom);
                loss = 0;
            }
        }
    }
}
