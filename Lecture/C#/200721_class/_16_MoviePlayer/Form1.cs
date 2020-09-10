using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _16_MoviePlayer
{
    public partial class Form1 : Form
    {
        Timer timer = new Timer();
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.Layout += Form1_Layout;
            timer.Interval = 2000;
            timer.Tick += Timer_Tick;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            this.axWindowsMediaPlayer1.URL = @"D:\Share\발표자료\김명년\2.jpg";
            this.timer.Stop();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.axWindowsMediaPlayer1.URL = @"D:\Share\발표자료\김명년\1.png";
            this.timer.Start();
            
        }

        private void Form1_Layout(object sender, LayoutEventArgs e)
        {
            this.axWindowsMediaPlayer1.Size =
                this.ClientSize;
        }
    }
}
