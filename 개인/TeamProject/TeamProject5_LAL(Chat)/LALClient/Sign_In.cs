using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace teamproject
{
    public partial class Sign_In : Form
    {
        Socket clientSocket;

        NetworkStream ns;
        StreamWriter sw;
        string signin = "request:Register,";
        public Sign_In(NetworkStream nl, Socket sl)
        {
            InitializeComponent();
            ns = nl;
            sw = new StreamWriter(ns);
            clientSocket = sl;
        }
        private void btnCancle_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void btnsignin_Click_1(object sender, EventArgs e)
        {
            signin += "ID:" + txtboxID.Text + ",";
            signin += "NAME:" + txtboxName.Text + ",";
            signin += "PW:" + txtboxPW.Text;
            sw.WriteLine(signin);
            sw.Flush();
            this.Hide();
        }
    }
}
