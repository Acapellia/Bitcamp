using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Omok {

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
        SoundPlayer putSound, endSound, existSound;
        Image[] image = new Image[9];
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
            int tx = (e.X - 20) / size;
            int ty = (e.Y - 20) / size;
            Console.WriteLine($"x : {tx} y: {ty}");
            if(stoneExist[tx][ty] == true) {
                existSound.Play();
                MessageBox.Show("이미 돌이 있습니다!!!");
                return;
            }
            stoneExist[tx][ty] = true;
            stoneColor[tx][ty] = color;
            stone.Add(new Point(tx, ty, color));
            if(check(tx, ty)) {
                color = color * -1;
                return;
            }
            putSound.Play();
            color = color * -1;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Pen penB = new Pen(Brushes.Black, 1);
            Pen penW = new Pen(Brushes.White, 2);
            // board
            for(int i = 0; i < 20; i++) {
                e.Graphics.DrawLine(penW, margin, i * size + margin, 800, i * size + margin);
                e.Graphics.DrawLine(penW, i * size + margin, margin, i * size + margin, 800);
                e.Graphics.DrawLine(penB, margin, i * size + margin, 800, i * size + margin);
                e.Graphics.DrawLine(penB, i * size + margin, margin, i * size + margin, 800);
            }

            // point
            int[] ploc = new int[] { 3, 10, 16 };
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    e.Graphics.FillEllipse(Brushes.Black, ploc[i] * size + margin - 5, ploc[j] * size + margin - 5, 10, 10);
                }
            }
            
            // stone
            for(int i = 0; i < stone.Count; i++) {
                int x = stone[i].x, y = stone[i].y;
                int color = stone[i].color;
                if(stoneExist[x][y] == false)
                    continue;
                if(color == -1) {
                    e.Graphics.FillEllipse(Brushes.Black, (x * size) + margin / 2, (y * size) + margin / 2, size, size);
                    e.Graphics.DrawEllipse(new Pen(Color.White,2), (x * size) + margin / 2, (y * size) + margin / 2, size, size);
                }
                else if(color == 1) {
                    e.Graphics.FillEllipse(Brushes.White, (x * size) + margin / 2, (y * size) + margin / 2, size, size);
                    e.Graphics.DrawEllipse(new Pen(Color.Black, 2), (x * size) + margin / 2, (y * size) + margin / 2, size, size);
                }
            }

            // state
            if(color == -1) {
                e.Graphics.FillEllipse(Brushes.Black, Width - margin - 20, 0, size, size);
                e.Graphics.DrawEllipse(new Pen(Color.White, 2), Width - margin - 20, 0, size, size);
            }
            else if(color == 1) {
                e.Graphics.FillEllipse(Brushes.White, Width - margin - 20, 0, size, size);
                e.Graphics.DrawEllipse(new Pen(Color.Black, 2), Width - margin - 20, 0, size, size);
            }
        }

        private void Form1_Load(object sender, EventArgs e) {
            // back image
            for(int i = 0; i < 9; i++) {
                string path = "../../natural";
                path += (i + ".jpg");
                Console.WriteLine(path);
                image[i] = Image.FromFile(path);
            }
            // back music
            putSound = new SoundPlayer();
            putSound.SoundLocation = "../../목탁.wav";
            endSound = new SoundPlayer();
            endSound.SoundLocation = "../../닭울음.wav";
            existSound = new SoundPlayer();
            existSound.SoundLocation = "../../윈도우_클릭.wav";

            // omok
            this.Width = 860;
            this.Height = 880;
            size = (this.Height - 80) / 20;
            this.BackColor = Color.Orange;
            for(int i = 0; i < stoneExist.GetLength(0); i++) {
                stoneExist[i] = new bool[22];
                stoneColor[i] = new int[22];
            }
        }

        bool checkLR(int x, int y) {
            int cnt = 1;
            // 가로
            for(int i = x - 1; i >= 0; i--) {
                if(stoneColor[i][y] == color)
                    cnt++;
                else break;
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
                endSound.Play();
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
        private void initState() {
            Random r = new Random();
            Console.WriteLine("Start");
            for(int i = 0; i < 20; i++) {
                for(int j = 0; j < 20; j++) {
                    stoneExist[i][j] = false;
                    stoneColor[i][j] = 0;
                }
            }
            //color = -1;
            this.BackgroundImage = image[r.Next(0, 9)];
        }
    }
}
