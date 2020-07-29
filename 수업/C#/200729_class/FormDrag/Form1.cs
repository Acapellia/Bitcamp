using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FormDrag {
    public partial class Form1 : Form {
        Point mousePoint;
        public Form1() {
            InitializeComponent();
            this.MouseDown += Form1_MouseDown;
            this.MouseMove += Form1_MouseMove;
            this.MouseDoubleClick += Form1_MouseDoubleClick;
            this.MouseClick += Form1_MouseClick;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e) {
            if(e.Button== MouseButtons.Right) {
                DialogResult result = MessageBox.Show("Really?","종료하시겠습니까?", MessageBoxButtons.YesNo);
                if(result == DialogResult.Yes) { this.Close(); }
            }
        }

        private void Form1_MouseDoubleClick(object sender, MouseEventArgs e) {
            if(this.WindowState == FormWindowState.Maximized)
                this.WindowState = FormWindowState.Normal;
            else
                this.WindowState = FormWindowState.Maximized;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e) {
            if(e.Button == MouseButtons.Left) {
                int moveX = this.mousePoint.X - e.X;
                int moveY = this.mousePoint.Y - e.Y;
                this.Location = new Point(this.Left - moveX, this.Top - moveY);
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            this.mousePoint = new Point(e.X, e.Y);
        }
    }
}
