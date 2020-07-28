using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ChangeImageWithTime {
    public partial class Form1 : Form {
        Image[] img = new Image[7];
        Timer timer = new Timer();
        int idx = 0;
        public Form1() {
            InitializeComponent();
            timer.Interval = 1000;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e) {
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            e.Graphics.DrawImage(img[idx++], 0, 0, ClientRectangle.Right, ClientRectangle.Bottom);
            if(idx == 7)
                idx = 0;
            
        }

        private void Form1_Load(object sender, EventArgs e) {
            for(int i = 0; i < 7; i++) {
                string path = "../../../";
                path += (i + ".jpg");
                img[i] = Image.FromFile(path);
            }
        }
    }
}
