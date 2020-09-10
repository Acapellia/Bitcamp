using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _14_DrawImage {
    public partial class Form1 : Form {
        Image image = null;
        
        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.Layout += Form1_Layout;
        }

        private void Form1_Load(object sender, EventArgs e) {
            image = Image.FromFile("../../Image0.jpg");
        }

        private void Form1_Layout(object sender, LayoutEventArgs e) {
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            //e.Graphics.DrawImage(image, 0, 0); // 원본 크기
            //e.Graphics.DrawImage(image, 0, 0, ClientRectangle.Right, ClientRectangle.Bottom); // 화면 크기
            //e.Graphics.DrawImage(image, ClientRectangle.Right/4, ClientRectangle.Bottom/4, 
            //    ClientRectangle.Right/2, ClientRectangle.Bottom/2);
            e.Graphics.DrawImage(image, 100,100, new Rectangle(480,120,210,250),GraphicsUnit.Pixel); // pixel
        }

    }
}
