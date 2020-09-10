using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _11_MouseSelectEllipse {
    public partial class Form1 : Form {
        private int x = 50, y = 50;
        private const int DIAMETER = 200;
        private const int RAD = DIAMETER / 2;
        private bool isSelfLeft = false;
        bool isInEllipse(int centX, int centY, int mX, int mY) {
            if(Math.Sqrt((double)(mX-centX)*(mX-centX)+(double)(mY-centY)*(mY-centY))<RAD)
                return true;
            else {
                return false;
            }
        }
        public Form1() {
            InitializeComponent();
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
            this.MouseUp += Form1_MouseUp;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e) {
            if(e.Button == MouseButtons.Left) {
                isSelfLeft = false;
                Invalidate();
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            if(e.Button == MouseButtons.Left) {
                int centX = x + (DIAMETER / 2);
                int centY = y + (DIAMETER / 2);
                if(isInEllipse(centX,centY,e.X,e.Y) == true) {
                    Console.WriteLine("MouseDown");
                    isSelfLeft = true;
                    Invalidate();
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e) {
            BackColor = Color.Black;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Pen myPen;
            myPen = new Pen(Brushes.Gold, 10);
            g.DrawEllipse(myPen, x, y, DIAMETER, DIAMETER);
            if(this.isSelfLeft) {
                myPen = new Pen(Brushes.Ivory, 10);
                g.DrawRectangle(myPen, x, y, DIAMETER, DIAMETER);
            }
            
        }
    }
}
