using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TrafficLight {
    public partial class Form1 : Form {
        Random r = new Random();
        Timer timer = new Timer();
        int w, h, light;
        public Form1() {
            InitializeComponent();
            BackColor = Color.Black;
            this.Width = 150;
            this.Height = 460;
            w = this.Width - 35;
            h = (this.Height - 80) / 3;
            timer.Interval = 300;
            timer.Tick += Timer_Tick;
            this.Paint += Form1_Paint;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e) {
            light = r.Next(0, 3);
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Pen myPen = new Pen(Brushes.White);

            for(int i = 0; i < 3; i++) {
                if(i == light) {
                    if(i == 0)
                        e.Graphics.FillEllipse(Brushes.Red, new Rectangle(10, i * h + 10 + (i * 10), w, h));
                    if(i == 1)
                        e.Graphics.FillEllipse(Brushes.Yellow, new Rectangle(10, i * h + 10 + (i * 10), w, h));
                    if(i == 2)
                        e.Graphics.FillEllipse(Brushes.Green, new Rectangle(10, i * h + 10 + (i * 10), w, h));
                }
                else {
                    e.Graphics.DrawEllipse(myPen, new Rectangle(10, i * h + 10 + (i * 10), w, h));
                }
            }
        }
    }
}
