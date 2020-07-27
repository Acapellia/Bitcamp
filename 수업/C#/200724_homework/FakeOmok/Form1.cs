using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FakeOmok {
    public partial class Form1 : Form {
        class Point {
            public int x { get; set; }
            public int y { get; set; }
            public int color { get; set; }
            public Point(int _x, int _y, int c) {
                x = _x;
                y = _y;
                color = c;
            }
        }
        List<Point> stone = new List<Point>(1);
        bool[][] stoneExist = new bool[22][];
        int[][] stoneColor = new int[22][];
        const int margin = 40;
        int size;
        int color = -1; // false = black  true = white
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
                return;
            }
            stoneExist[tx][ty] = true;
            stoneColor[tx][ty] = color;
            stone.Add(new Point(tx, ty, color));
            if(check(tx, ty)) {
                return;
            }
            color = color*-1;
            Invalidate();
        }
        bool checkLR(int x, int y) {
            int cnt = 1;
            // 가로
            for(int i = x - 1; i >= 0; i--) {
                if(stoneColor[i][y] == color)
                    cnt++;
                else
                    break;
            }
            for(int i = x + 1; i <= 18; i++) {
                if(stoneColor[i][y] == color)
                    cnt++;
                else
                    break;
            }
            if(cnt == 5) {
                return true;
            }
            return false;
        }
        bool checkUD(int x, int y) {
            int cnt = 1;
            // 세로
            for(int i = y - 1; i >= 0; i--) {
                if(stoneColor[x][i] == color)
                    cnt++;
                else
                    break;
            }
            for(int i = y + 1; i <= 18; i++) {
                if(stoneColor[x][i] == color)
                    cnt++;
                else
                    break;
            }
            if(cnt == 5) {
                return true;
            }
            return false;
        }
        bool checkDiaL(int x, int y) {
            int cnt = 1;
            // 대각선\
            for(int i = 1; ; i++) {
                if((x - i) < 0 || (x - i) > 18 || (y - i) < 0 || (y - i) > 18)
                    break;
                if(stoneColor[x - i][y - i] == color)
                    cnt++;
                else
                    break;
            }
            for(int i = 1; ; i++) {
                if((x + i) < 0 || (x + i) > 18 || (y + i) < 0 || (y + i) > 18)
                    break;
                if(stoneColor[x + i][y + i] == color)
                    cnt++;
                else
                    break;
            }
            if(cnt == 5) {
                return true;
            }
            return false;
        }
        bool checkDiaR(int x, int y) {
            int cnt = 1;
            // 대각선/
            for(int i = 1; ; i++) {
                if((x + i) < 0 || (x + i) > 18 || (y - i) < 0 || (y - i) > 18)
                    break;
                if(stoneColor[x + i][y - i] == color)
                    cnt++;
                else
                    break;
            }
            for(int i = 1; ; i++) {
                if((x - i) < 0 || (x - i) > 18 || (y + i) < 0 || (y + i) > 18)
                    break;
                if(stoneColor[x - i][y + i] == color)
                    cnt++;
                else
                    break;
            }
            if(cnt == 5) {
                return true;
            }
            return false;
        }
        private bool check(int x, int y) {
            bool state = false;
            string colorText;
            if(checkLR(x, y)) { state = true; }
            if(checkUD(x, y)) { state = true; }
            if(checkDiaL(x, y)) { state = true; }
            if(checkDiaR(x, y)) { state = true; }
            if(state) {
                Invalidate();
                if(color == -1)
                    colorText = "검은 돌 ";
                else
                    colorText = "흰 돌 ";
                MessageBox.Show(colorText + "Win!!");
                initState();
                Invalidate();
                return true;
            }
            return false;
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
                if(stoneExist[x][y] == false)
                    continue;
                int color = stone[i].color;
                if(color == -1)
                    e.Graphics.FillEllipse(Brushes.Black, (x * size) + margin, (y * size) + margin, size, size);
                else if(color == 1){
                    e.Graphics.FillEllipse(Brushes.White, (x * size) + margin, (y * size) + margin, size, size);
                }
            }
            // state
            if(color == -1) {
                e.Graphics.FillEllipse(Brushes.Black, Width - margin - 20, 0, size, size);
            }
            else if(color == 1) {
                e.Graphics.FillEllipse(Brushes.White, Width - margin - 20, 0, size, size);
            }
        }
        private void initState() {
            Console.WriteLine("Start");
            for(int i = 0; i < 20; i++) {
                for(int j = 0; j < 20; j++) {
                    stoneExist[i][j] = false;
                    stoneColor[i][j] = 0;
                }
            }
            color = -1;
        }
        private void Form1_Load(object sender, EventArgs e) {
            this.Width = 860;
            this.Height = 880;
            size = (this.Height - 80) / 20;
            this.BackColor = Color.Orange;
            for(int i = 0; i < stoneExist.GetLength(0); i++) {
                stoneExist[i] = new bool[21];
                stoneColor[i] = new int[21];
            }
        }
    }
}
