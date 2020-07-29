using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace FileStream {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        private void btnSaveFile_Click(object sender, EventArgs e) {
            SaveFileDialog sfd = new SaveFileDialog();
            if(sfd.ShowDialog() == DialogResult.OK) {
                string path = sfd.FileName;
                byte[] data = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74 };
                System.IO.FileStream fs = new System.IO.FileStream(path, FileMode.Create, FileAccess.Write);
            }
        }

        private void btnOpenFile_Click(object sender, EventArgs e) {
            OpenFileDialog ofd = new OpenFileDialog();
            if(ofd.ShowDialog() == DialogResult.OK) {
                string path = ofd.FileName;
                byte[] data = new byte[10];
                System.IO.FileStream fs = new System.IO.FileStream(path, FileMode.Open, FileAccess.Read);
                fs.Read(data, 0, data.Length);
                fs.Close();
                string result = "";
                foreach(byte b in data) {
                    result += b.ToString();
                }
                MessageBox.Show(result);
            }
        }
    }
}
