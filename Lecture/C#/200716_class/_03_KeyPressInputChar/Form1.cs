using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _03_KeyPressInputChar
{
    public partial class Form1 : Form
    {
        string inputStr;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyPress += Form1_KeyPress;
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e) {
            this.inputStr += e.KeyChar;
            Invalidate();
            // 이곳에서 화면에 출력하면 다시 띄웠을때 지워진다...
            // 직접 Paint이벤트를 호출 -> Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Font f = new Font("맑은 고딕",20);
            g.DrawString(inputStr,f,Brushes.DarkBlue,10,10);
        }
    }
}
