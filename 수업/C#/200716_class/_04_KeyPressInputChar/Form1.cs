using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _04_KeyPressInputChar {
    public partial class Form1 : Form {
        StringBuilder inputStr = new StringBuilder(100);
        public Form1() {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.KeyPress += Form1_KeyPress;
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e) {
            if(e.KeyChar == '\b' && inputStr.Length>0) inputStr.Remove(inputStr.Length-1,1);
            else if(e.KeyChar != '\b') inputStr.Append(e.KeyChar);
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            TextFormatFlags flags = TextFormatFlags.WordBreak;
            string str = inputStr.ToString();
            Graphics g = e.Graphics;
            Font f = new Font("궁서체", 20);
            TextRenderer.DrawText(e.Graphics,str,f,this.ClientRectangle,Color.DarkCyan,flags);
        }
    }
}
