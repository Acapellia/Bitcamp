using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RadioCheckBox {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e) {

        }

        private void btnSelect_Click(object sender, EventArgs e) {
            int selectCnt = 0;
            string selectStr = "";
            if(chkMoney.Checked ) {
                selectStr += "돈\r\n"; 
                selectCnt++;
            }
            if(chkHohor.Checked) {
                selectStr += "명예\r\n"; 
                selectCnt++;
            }
            if(chkForce.Checked) {
                selectStr += "힘\r\n";
                selectCnt++;
            }
            if(chkPower.Checked) {
                selectStr += "권력\r\n";
                selectCnt++;
            }
            if(chkJustice.Checked) {
                selectStr += "정의\r\n";
                selectCnt++;
            }
            if(radioDestroyer.Checked) {
                selectStr += "카리스마 파괴자\r\n";
            }
            if(radioCommon.Checked) {
                selectStr += "평범하고 가정적인 사람\r\n";
            }
            MessageBox.Show(selectStr);
        }
    }
}
