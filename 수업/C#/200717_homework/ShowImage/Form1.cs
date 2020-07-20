using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ShowImage {
    public partial class Form1 : Form {
        Image[] img = new Image[10];
        TextureBrush tBrush = null;
        int imgNum = 5;
        public Form1() {
            InitializeComponent();
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.MouseClick += Form1_MouseClick;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e) {
            if(e.Button == MouseButtons.Left) {
                if(imgNum < 9) imgNum++;
                else if(imgNum == 9) imgNum = 0;
            }
            else if(e.Button == MouseButtons.Right) {
                if(imgNum > 0) imgNum--;
                else if(imgNum == 0) imgNum = 9;
            }
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.DoubleBuffered = true;
            for(int i = 0; i < 10; i++) {
                string path = "../../Image" + i + ".jpg";
                img[i] = Image.FromFile(path);
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            tBrush = new TextureBrush(img[imgNum]);
            e.Graphics.FillRectangle(tBrush, this.ClientRectangle);
        }
    }
}
