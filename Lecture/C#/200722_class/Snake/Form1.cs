using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Snake
{
    enum Dir { Left = 0, Right, Up, Down }
    public partial class Form1 : Form
    {
        class Food
        {
            public int x { get; set; }
            public int y { get; set; }
            public bool s { get; set; }
            public Food(int _x, int _y, bool _s) { x = _x; y = _y; s = _s; }
        }
        class Snake
        {
            public int dir { get; set; }
            public int[][] point = new int[100][];
        }
        List<Food> food = new List<Food>();
        Snake snake = new Snake();
        Timer timer = new Timer();
        int wallW, wallH;
        int size = 20;
        int foodCnt = 0, snakeCnt = 0, snakeDir = (int)Dir.Right;
        int head, tail, body, score = 0;
        bool state = false;
        public Form1()
        {
            InitializeComponent();
            timer.Interval = 200;
            BackColor = Color.Black;
            this.Width = 860;
            this.Height = 840;
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.Paint += Form1_Paint;
            this.KeyDown += Form1_KeyDown;
            timer.Tick += Timer_Tick;
            //timer.Start();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter) { state = !state; }
            if (state == false) { timer.Stop(); }
            else { timer.Start(); }

            if (e.KeyCode == Keys.Left){ snakeDir = (int)Dir.Left; }
            else if (e.KeyCode == Keys.Right){ snakeDir = (int)Dir.Right; }
            else if (e.KeyCode == Keys.Up) { snakeDir = (int)Dir.Up; }
            else if (e.KeyCode == Keys.Down) { snakeDir = (int)Dir.Down; }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (snakeCnt == 0) { timer.Stop(); }
            if (++head == 100) { head = 0; body = 98; }
            if (++tail == 100) { tail = 0; }
            if (++body == 100) { body = 0; }

            if (foodCnt == 0)
            {
                makeFood();
            }

            addBody(head,body);
            if(snake.point[head][0]<=0 || snake.point[head][0]+size>=ClientRectangle.Right ||
               snake.point[head][1] <= 0 || snake.point[head][1] + size >= ClientRectangle.Bottom)
            {
                snakeCnt = 0;  timer.Stop();
            }
            eatFood();

            Invalidate();
        }
        public void addBody(int h, int b)
        {
            if (snakeDir == (int)Dir.Left && snake.point[0][0] >= wallW + size)
            {
                snake.point[h][0] = snake.point[b][0] - size;
                snake.point[h][1] = snake.point[b][1];
            }
            else if (snakeDir == (int)Dir.Right && snake.point[0][0] + size < ClientRectangle.Right - wallW - size)
            {
                snake.point[h][0] = snake.point[b][0] + size;
                snake.point[h][1] = snake.point[b][1];
            }
            else if (snakeDir == (int)Dir.Up)
            {
                snake.point[h][0] = snake.point[b][0];
                snake.point[h][1] = snake.point[b][1] - size;
            }
            else if (snakeDir == (int)Dir.Down)
            {
                snake.point[h][0] = snake.point[b][0];
                snake.point[h][1] = snake.point[b][1] + size;
            }
        }
        public void makeFood()
        {
            Random r = new Random();
            for (int i = 0; i < 10; i++)
            {
                int tx = r.Next(wallW, ClientRectangle.Right - wallW - size);
                int ty = r.Next(wallH, ClientRectangle.Bottom - wallH - size);
                food.Add(new Food(tx, ty, true));
            }
            foodCnt = 10;
        }
        public void eatFood()
        {
            int hx = snake.point[head][0];
            int hy = snake.point[head][1];
            for (int i = 0; i < foodCnt; i++)
            {
                Console.WriteLine("(" + hx + " " + hy + ") " + "(" + food[i].x + " " + food[i].y + ") ");
                if(((snake.point[head][0]<=food[i].x && food[i].x <= snake.point[head][0]+ size) 
                || (snake.point[head][0] <= food[i].x+ size && food[i].x + size <= snake.point[head][0] + size))
                && ((snake.point[head][1] <= food[i].y && food[i].y <= snake.point[head][01] + size) 
                || (snake.point[head][1] <= food[i].y + size && food[i].y + size <= snake.point[head][1] + size)))
                {
                    if (++head == 100) { head = 0; body = 98; }
                    if (++body == 100) { body = 0; }
                    addBody(head, body);
                    food.RemoveAt(i);
                    snakeCnt++; foodCnt--; score++;
                    break;
                }
            }
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen pen = new Pen(Brushes.White, 2);
            // wall
            for (int i = 0; i < 40; i++)
            {
                e.Graphics.DrawRectangle(pen, i * wallW, 0, wallW, wallH);
                e.Graphics.DrawRectangle(pen, i * wallW, ClientRectangle.Bottom - wallH, wallW, wallH);
                e.Graphics.DrawRectangle(pen, 1, i * wallH, wallW, wallH);
                e.Graphics.DrawRectangle(pen, ClientRectangle.Right - wallW, i * wallH, wallW, wallH);
            }
            // food
            for (int i = 0; i < foodCnt; i++)
            {
                e.Graphics.FillRectangle(Brushes.Red, food[i].x, food[i].y, size, size);
            }
            // snake
            int idx = head;
            for (int i = 0; i < snakeCnt; i++)
            {
                if(idx==-1) { idx = 99; }
                //Console.Write(idx + " ");
                e.Graphics.FillRectangle(Brushes.Blue, snake.point[idx][0], snake.point[idx][1], size, size);
                e.Graphics.DrawRectangle(new Pen(Brushes.Yellow, 1), snake.point[idx][0], snake.point[idx][1], size, size);
                idx--;
            }Console.WriteLine();
            if(snakeCnt>0) e.Graphics.DrawString("Score : " + score, new Font("맑은 고딕", 50), Brushes.White, 250, 350);
            else { e.Graphics.DrawString("GameOver", new Font("맑은 고딕", 50), Brushes.White, 250, 350); }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            wallW = ClientRectangle.Right / 40;
            wallH = ClientRectangle.Bottom / 40;
            for(int i= 0; i < snake.point.Length; i++)
            {
                snake.point[i] = new int[2];
            }
            for (int i = 1; i <= 4; i++)
            {
                snake.point[4 - i][0] = size + size * i;
                snake.point[4 - i][1] = size*3;
                snakeCnt++;
            }
            head = 3; body = 2; tail = 0;
        }
    }
}