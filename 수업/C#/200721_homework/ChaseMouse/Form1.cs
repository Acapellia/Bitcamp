using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ChaseMouse {
    public partial class Form1 : Form {
        Timer timer = new Timer();
        Image catImage, MouseImage;
        int catX, catY, mx, my;
        bool mouseClicked = false;

        public Form1() {
            catX = 30; catY = 50;
            BackColor = Color.White;
            InitializeComponent();
            timer.Interval = 50;
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
            this.MouseUp += Form1_MouseUp;
            this.MouseMove += Form1_MouseMove;
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Form1_Load(object sender, EventArgs e) {
            catImage = Image.FromFile("../../cat.png");
            MouseImage = Image.FromFile("../../mouse.png");
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if(mouseClicked == true) {
                int difX = mx - catX, difY = my - catY;
                catX += difX / 10; catY += difY / 10;
                Invalidate();
            }
        }
        private void Form1_Paint(object sender, PaintEventArgs e) {
            e.Graphics.DrawImage(catImage, catX, catY,60, 60);
            //e.Graphics.DrawString("고양이", new Font("맑은 고딕", 15), Brushes.MediumVioletRed, catX, catY);
            if(mouseClicked == true) {
                e.Graphics.DrawImage(MouseImage, mx - 15, my - 15, 35, 35);
                //e.Graphics.DrawString("쥐", new Font("맑은 고딕", 15), Brushes.YellowGreen, mx - 15, my - 15);
            }
        }
        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            mouseClicked = true;
            mx = e.X; my = e.Y;
            Invalidate();
        }
        private void Form1_MouseUp(object sender, MouseEventArgs e) {
            mouseClicked = false;
            Invalidate();
        }
        private void Form1_MouseMove(object sender, MouseEventArgs e) {
            mx = e.X; my = e.Y;  
        }
    }
}
