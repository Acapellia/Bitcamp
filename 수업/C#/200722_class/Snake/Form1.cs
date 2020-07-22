using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Snake {
    enum Dir { Left=0, Right, Up, Down }
    public partial class Form1 : Form {
        class Food {
            public int x { get; set; }
            public int y { get; set; }
            public bool s { get; set; }
            public Food(int _x,int _y,bool _s) { x = _x; y = _y;s = _s; }
        }
        class Snake {
            public int dir { get; set; }
            public int[][] point = new int[100][];
        }
        List<Food> food = new List<Food>();
        Snake snake = new Snake();
        Timer timer = new Timer();
        int wallW, wallH;
        int foodSize = 15, snakeSize = 20;
        int foodCnt = 0, snakeCnt=0, snakeDir=(int)Dir.Right;
        int head, tail;
        public Form1() {
            InitializeComponent();
            timer.Interval = 100;
            BackColor = Color.Black;
            this.Width = 860;
            this.Height = 840;
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            if(e.KeyCode == Keys.Left && snake.point[0][0]>=wallW+snakeSize) { 
                snakeDir = (int)Dir.Left; 
            }
            else if(e.KeyCode == Keys.Right && snake.point[0][0]+snakeSize<ClientRectangle.Right-wallW-snakeSize) {
                snakeDir = (int)Dir.Right; 
            }
            else if(e.KeyCode == Keys.Up) { snakeDir = (int)Dir.Up; }
            else if(e.KeyCode == Keys.Down) { snakeDir = (int)Dir.Down; }
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if(foodCnt == 0) {
                makeFood(); 
            }
            if(snakeDir==(int)Dir.Left && snake.point[0][0] >= wallW + snakeSize) {
                snake.point[0][0] -= snakeSize;
            }
            else if(snakeDir == (int)Dir.Right && snake.point[0][0] + snakeSize < ClientRectangle.Right - wallW - snakeSize) {
                snake.point[0][0] += snakeSize;
            }
            Invalidate();
        }

        public void makeFood() {
            Random r = new Random();
            for(int i = 0; i < 10; i++) {
                int tx = r.Next(wallW, ClientRectangle.Right - wallW - foodSize);
                int ty = r.Next(wallH, ClientRectangle.Bottom - wallH - foodSize);
                food.Add(new Food(tx, ty, true));
            }
            foodCnt = 10;
        }
        private void Form1_Paint(object sender, PaintEventArgs e) {
            Pen pen = new Pen(Brushes.White, 2);
            // wall
            for(int i = 0; i < 40; i++) {
                e.Graphics.DrawRectangle(pen, i * wallW, 0, wallW, wallH);
                e.Graphics.DrawRectangle(pen, i * wallW, ClientRectangle.Bottom - wallH, wallW, wallH);
                e.Graphics.DrawRectangle(pen, 1, i * wallH, wallW, wallH);
                e.Graphics.DrawRectangle(pen, ClientRectangle.Right - wallW, i * wallH, wallW, wallH);
            }
            // food
            for(int i = 0; i < foodCnt; i++) {
                e.Graphics.FillRectangle(Brushes.Red, food[i].x, food[i].y,foodSize,foodSize);
            }
            // snake
            Console.WriteLine(snakeCnt);
            for(int i = head; i >=tail; i--) {
                e.Graphics.FillRectangle(Brushes.Blue, snake.point[i][0], snake.point[i][1], snakeSize, snakeSize);
                e.Graphics.DrawRectangle(new Pen(Brushes.Yellow, 1), snake.point[i][0], snake.point[i][1], snakeSize, snakeSize);
            }
        }

        private void Form1_Load(object sender, EventArgs e) {
            wallW = ClientRectangle.Right / 40;
            wallH = ClientRectangle.Bottom / 40;
            for(int i = 1; i <= 4; i++) {
                snake.point[4 - i] = new int[2];
                snake.point[4 - i][0] = 50 + snakeSize*i;
                snake.point[4 - i][1] = 50 ;
                snakeCnt++;
            }
            head = 3; tail = 0;
        }
    }
}
