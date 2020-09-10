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
    enum Dir { Left = 0, Right, Up, Down }
    public partial class Form1 : Form {
        class Food {
            public int x { get; set; }
            public int y { get; set; }
            public bool s { get; set; }
            public Food(int _x, int _y, bool _s) { x = _x; y = _y; s = _s; }
        }
        class Snake {
            public int dir { get; set; }
            public int[][] point = new int[100][];
        }
        List<Food> food = new List<Food>();
        Snake snake = new Snake();
        Timer timer = new Timer();
        int size = 20, timeGap = 150;
        int foodCnt = 0, snakeCnt = 0, snakeDir = (int)Dir.Right;
        int head, tail, body, score = 0;
        bool state = false;
        public Form1() {
            InitializeComponent();
            timer.Interval = timeGap;
            BackColor = Color.Black;
            this.Width = 840;
            this.Height = 840;
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            timer.Tick += Timer_Tick;
            //timer.Start();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e) {
            if(e.KeyCode == Keys.Enter) { state = !state; }
            if(state == false) { timer.Stop(); }
            else { timer.Start(); }

            if(e.KeyCode == Keys.Left) { snakeDir = (int)Dir.Left; }
            else if(e.KeyCode == Keys.Right) { snakeDir = (int)Dir.Right; }
            else if(e.KeyCode == Keys.Up) { snakeDir = (int)Dir.Up; }
            else if(e.KeyCode == Keys.Down) { snakeDir = (int)Dir.Down; }
        }

        private void Timer_Tick(object sender, EventArgs e) {
            if(snakeCnt == 0) { timer.Stop(); }
            if(++head == 100) { head = 0; body = 98; }
            if(++tail == 100) { tail = 0; }
            if(++body == 100) { body = 0; }

            if(foodCnt == 0) {
                makeFood();
            }

            addBody(head, body);

            eatFood();
            if(snake.point[head][0] <= 0 || snake.point[head][0] >= (ClientRectangle.Right / size - 1) ||
               snake.point[head][1] <= 0 || snake.point[head][1] >= (ClientRectangle.Bottom / size - 1)) {
                snakeCnt = 0;
                timer.Stop();
            }
            Invalidate();
        }
        public void delBody() {
            tail = tail < 99 ? tail++ : 0;
            snakeCnt--;
        }
        public void addBody(int h, int b) {
            if(snakeDir == (int)Dir.Left && snake.point[b][0] > 0) {
                snake.point[h][0] = snake.point[b][0] - 1;
                snake.point[h][1] = snake.point[b][1];
            }
            else if(snakeDir == (int)Dir.Right && snake.point[b][0] < (ClientRectangle.Right / size - 1)) {
                snake.point[h][0] = snake.point[b][0] + 1;
                snake.point[h][1] = snake.point[b][1];
            }
            else if(snakeDir == (int)Dir.Up && snake.point[b][1] > 0) {
                snake.point[h][0] = snake.point[b][0];
                snake.point[h][1] = snake.point[b][1] - 1;
            }
            else if(snakeDir == (int)Dir.Down && snake.point[b][1] < (ClientRectangle.Bottom / size - 1)) {
                snake.point[h][0] = snake.point[b][0];
                snake.point[h][1] = snake.point[b][1] + 1;
            }
        }
        public void makeFood() {
            Random r = new Random();
            for(int i = 0; i < 10; i++) {
                int tx = r.Next(1, (ClientRectangle.Right - size * 2) / size - 1);
                int ty = r.Next(1, (ClientRectangle.Bottom - size * 2) / size - 1);
                food.Add(new Food(tx, ty, true));
            }
            foodCnt = 10;
            timeGap -= 20;
            timer.Interval = timeGap;
        }
        public void eatFood() {
            int hx = snake.point[head][0];
            int hy = snake.point[head][1];
            for(int i = 0; i < foodCnt; i++) {
                //Console.WriteLine("(" + hx + " " + hy + ") " + "(" + food[i].x + " " + food[i].y + ") ");
                if(hx == food[i].x && hy == food[i].y) {
                    if(++head == 100) { head = 0; body = 98; }
                    if(++body == 100) { body = 0; }
                    addBody(head, body);
                    food.RemoveAt(i);
                    snakeCnt++;
                    foodCnt--;
                    score++;
                    break;
                }
            }
        }
        private void Form1_Paint(object sender, PaintEventArgs e) {
            Pen pen = new Pen(Brushes.White, 2);
            // wall
            for(int i = 0; i < ClientRectangle.Right / size; i++) {
                e.Graphics.DrawRectangle(pen, i * size, 0, size, size);
                e.Graphics.DrawRectangle(pen, i * size, ClientRectangle.Bottom - size, size, size);
                e.Graphics.DrawRectangle(pen, 0, i * size, size, size);
                e.Graphics.DrawRectangle(pen, 0 + size * (ClientRectangle.Right / size - 1), i * size, size, size);
            }
            // food
            for(int i = 0; i < foodCnt; i++) {
                e.Graphics.FillRectangle(Brushes.Red, food[i].x * size, food[i].y * size, size, size);
            }
            // snake
            int idx = head;
            for(int i = 0; i < snakeCnt; i++) {
                if(idx == -1) { idx = 99; }
                e.Graphics.FillRectangle(Brushes.Blue, snake.point[idx][0] * size, snake.point[idx][1] * size, size, size);
                e.Graphics.DrawRectangle(new Pen(Brushes.Yellow, 1), snake.point[idx][0] * size, snake.point[idx][1] * size, size, size);
                idx--;
            }
            Console.WriteLine();
            if(snakeCnt > 0)
                e.Graphics.DrawString("Score : " + score, new Font("맑은 고딕", 50), Brushes.White, 250, 350);
            else { e.Graphics.DrawString("GameOver", new Font("맑은 고딕", 50), Brushes.White, 250, 350); }
        }

        private void Form1_Load(object sender, EventArgs e) {
            for(int i = 0; i < snake.point.Length; i++) {
                snake.point[i] = new int[2];
            }
            for(int i = 0; i < 4; i++) {
                snake.point[3 - i][0] = 3+ (4 - i);
                snake.point[3 - i][1] = 3;
                snakeCnt++;
            }
            head = 3;
            body = 2;
            tail = 0;
        }
    }
}