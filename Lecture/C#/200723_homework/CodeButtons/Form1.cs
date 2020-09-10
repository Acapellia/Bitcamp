using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CodeButtons {
    public partial class Form1 : Form {
        Image BombImg = null;
        Image BackImg = null;
        const int FORM_WIDTH = 800;
        const int FORM_HEIGHT = 800;
        const int BUTTON_SIZE = 50;
        int rows, cols;
        int cnt = 0;
        bool isBoom = false;
        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Paint += Form1_Paint;
            //this.Load += Form1_Load;
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            e.Graphics.DrawImage(BackImg, 0, 0, 800, 800);
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.Width = FORM_WIDTH + 18;
            this.Height = FORM_HEIGHT + 38;
            this.rows = FORM_WIDTH / BUTTON_SIZE;
            this.cols = FORM_HEIGHT / BUTTON_SIZE;
            //Console.WriteLine($"({rows},{cols})");
            BombImg = Image.FromFile("../../bomb.png");
            BackImg = Image.FromFile("../../image0.jpg");
            MakeButtons();
        }

        private void MakeButtons() {
            Random random = new Random();
            for(int i = 0; i < this.rows; i++)  // 세로 행
            {
                for(int j = 0; j < this.cols; j++)  // 가로 열
                {
                    Button btn = new Button();
                    btn.Left = j * BUTTON_SIZE;
                    btn.Top = i * BUTTON_SIZE;
                    btn.Width = BUTTON_SIZE;
                    btn.Height = BUTTON_SIZE;
                    btn.Margin = new Padding(0);
                    btn.Text = cnt++.ToString();
                    btn.Font = new Font("맑은 고딕", 15, FontStyle.Bold);
                    btn.BackColor = Color.FromArgb(255, random.Next(256), random.Next(256), random.Next(256));
                    btn.Click += Btn_Click;
                    this.Controls.Add(btn);
                }
            }
        }
        // 버튼 클릭시 화면 이미지가 폭탄이미지로 변경
        // 1초후 버튼이 사라지게 하세요
        private void eraseBtn(object obtn) {
            Button btn = obtn as Button;
            Thread.Sleep(1000);
            btn.Visible = false;
            this.Refresh();
        }
        private void Btn_Click(object sender, EventArgs e) {
            Button btn = sender as Button; // idraw - Stop - btnErase - Rdraw
            if(btn != null) {
                btn.Image = BombImg;
                this.Refresh();
                Thread btnThread = new Thread(new ParameterizedThreadStart(eraseBtn));
                btnThread.Start(btn);
            }
        }
    }
}
