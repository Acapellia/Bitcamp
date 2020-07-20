using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _13_TextureBrush {
    public partial class Form1 : Form {
        Image img = null;
        Image img2 = null;
        TextureBrush tBrush = null;
        int imgNum=0;
        public Form1() {
            InitializeComponent();
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.MouseClick += Form1_MouseClick;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e) {
            if(imgNum == 0)
                imgNum = 1;
            else
                imgNum = 0;
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.DoubleBuffered = true;
            img = Image.FromFile("../../HeartTree.jpg");
            img2 = Image.FromFile("../../BrokenHeart.jpg");
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            if(imgNum == 0)
                tBrush = new TextureBrush(img);
            else
                tBrush = new TextureBrush(img2);
            e.Graphics.FillRectangle(tBrush, this.ClientRectangle);
        }
    }
}
