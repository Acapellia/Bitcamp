using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FillGridNoOver {
    public partial class Form1 : Form {
        class Point {
            public int x { get; set; }
            public int y { get; set; }
            public bool color { get; set; }
            public Point(int _x, int _y, bool c) {
                x = _x;
                y = _y;
                color = c;
            }
        }
        List<Point> stone = new List<Point>(1);
        bool[][] stoneExist = new bool[22][];
        const int margin = 40;
        int size;
        bool color = false; // false = black  true = white
        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            int tx = (e.X - margin) / size;
            int ty = (e.Y - margin) / size;
            Console.WriteLine($"x : {tx} y: {ty}");
            if(stoneExist[tx][ty] == true) {
                MessageBox.Show("이미 돌이 있습니다!!!");
                return;
            }
            stone.Add(new Point(tx, ty, color));
            color = !color;
            stoneExist[tx][ty] = true;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Pen pen = new Pen(Brushes.Black);
            // board
            for(int i = 0; i < 20; i++) {
                e.Graphics.DrawLine(pen, margin, i * size + margin, 800, i * size + margin);
                e.Graphics.DrawLine(pen, i * size + margin, margin, i * size + margin, 800);
            }
            // stone
            for(int i = 0; i < stone.Count; i++) {
                int x = stone[i].x, y = stone[i].y;
                bool color = stone[i].color;
                if(color == false)
                    e.Graphics.FillEllipse(Brushes.Black, (x * size) + margin, (y * size) + margin, size, size);
                else {
                    e.Graphics.FillEllipse(Brushes.White, (x * size) + margin, (y * size) + margin, size, size);
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.Width = 860;
            this.Height = 880;
            size = (this.Height - 80) / 20;
            this.BackColor = Color.Orange;
            for(int i = 0; i < stoneExist.GetLength(0); i++) {
                stoneExist[i] = new bool[22];
            }
        }
    }
}
