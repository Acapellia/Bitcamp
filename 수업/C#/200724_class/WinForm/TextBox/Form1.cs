using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TextBox {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        private void btnInput_Click(object sender, EventArgs e) {
            string str = tbWord.Text;
            tbView.Text += str + Environment.NewLine;
            tbWord.Text = "";
        }

        private void btnClear_Click(object sender, EventArgs e) {
            tbWord.Text = "";
        }

        private void tbWord_KeyDown(object sender, KeyEventArgs e) {
            switch(e.KeyCode) {
                case Keys.Enter:
                    string str = tbWord.Text;
                    tbView.Text += str + Environment.NewLine; // '\r\n'
                    tbWord.Text = "";
                    break;

            }
        }
    }
}
