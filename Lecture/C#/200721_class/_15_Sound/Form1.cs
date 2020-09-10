using MediaPlayer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlTypes;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _15_Sound
{
    public partial class Form1 : Form
    {
        MediaPlayerClass mp3Player = new MediaPlayerClass();
        Timer timer = new Timer();
        double addOpa = -0.01;

        public Form1()
        {
            InitializeComponent();
            this.btnMusic.MouseHover += BtnMusic_MouseHover;
            this.btnMusic.MouseLeave += BtnMusic_MouseLeave;
            this.btnSound.MouseHover += BtnSound_MouseHover;
            this.btnSound.MouseLeave += BtnSound_MouseLeave;
            this.MouseDoubleClick += Form1_MouseDoubleClick;
            this.MouseClick += Form1_MouseClick;
            timer.Interval = 100;
            timer.Tick += Timer_Tick;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Right)
            {
                this.Opacity = 1.0;
                timer.Stop();
                mp3Player.Stop();

                OpenFileDialog ofd = new OpenFileDialog();
                ofd.ShowDialog();
                string filename = ofd.FileName;

                mp3Player.FileName = filename;
                mp3Player.Play();
                timer.Start();
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            this.Opacity += this.addOpa;
            if (this.Opacity <= 0.0 || this.Opacity >= 1.0)
                this.addOpa *= -1;
        }

        private void Form1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            Image image = Image.FromFile("../../수지.jpg");
            this.BackgroundImage = image;
            this.FormBorderStyle = 
                System.Windows.Forms.FormBorderStyle.None;
            this.WindowState = FormWindowState.Maximized;

            this.timer.Start();
        }

        private void BtnSound_MouseLeave(object sender, EventArgs e)
        {
            Image image = Properties.Resources.강아지;
            this.btnSound.BackgroundImage = image;
        }

        private void BtnSound_MouseHover(object sender, EventArgs e)
        {
            Image image = Properties.Resources.pet;
            this.btnSound.BackgroundImage = image;
        }

        private void BtnMusic_MouseLeave(object sender, EventArgs e)
        {
            Image image = Properties.Resources.music;
            this.btnMusic.BackgroundImage = image;
        }

        private void BtnMusic_MouseHover(object sender, EventArgs e)
        {
            Image image = Properties.Resources.음악;
            this.btnMusic.BackgroundImage = image;
        }

        private void btnSound_Click(object sender, EventArgs e)
        {
            SoundPlayer sp = new SoundPlayer();
            //sp.Stream = Properties.Resources.강아지1;
            sp.SoundLocation = "../../강아지1.wav";
            sp.Play();            
        }

        private void btnMusic_Click(object sender, EventArgs e)
        {
            //mp3Player.EnableContextMenu = true;
            string path = System.IO.Directory.GetCurrentDirectory();
            path += "\\지난날.mp3";
            mp3Player.FileName = path;
            mp3Player.Play();
        }
    }
}
