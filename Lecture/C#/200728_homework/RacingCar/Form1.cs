using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RacingCar {
    class Obstacle {
        public int x { get; set; }
        public int y { get; set; }
        public int type { get; set; }
        public Obstacle(int x, int y, int t) {
            this.x = x;
            this.y = y;
            this.type = t;
        }
    }
    public partial class Form1 : Form {
        Image backgroundImage;
        Image carImage;
        Image[] obstacle = new Image[9];
        Timer timer = new Timer();
        Timer obTimer = new Timer();
        List<Obstacle> obList = new List<Obstacle>(1);
        int backLoc, scrollSize;
        int carX, carY;
        //bool obState = false;
        bool carMove = false;
        bool gameStart = true;
        int gameTime = 0;
        Random r = new Random();
        public Form1() {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Load += Form1_Load;
            this.SizeChanged += Form1_SizeChanged;
            this.Paint += Form1_Paint;
            this.MouseMove += Form1_MouseMove;
            this.MouseUp += Form1_MouseUp;
            this.MouseDown += Form1_MouseDown;
            timer.Interval = 10;
            timer.Tick += Timer_Tick;
            timer.Start();
            obTimer.Interval = 3000;
            obTimer.Tick += ObTimer_Tick;
            obTimer.Start();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            carMove = true;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e) {
            carMove = false;
        }
        private void Form1_MouseMove(object sender, MouseEventArgs e) {
            if(carMove == true) {
                carX = e.X - 40;
                carY = e.Y - 90;
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e) {
            if(backgroundImage == null)
                return;
            backgroundImage = backgroundImage.GetThumbnailImage(ClientRectangle.Right, ClientRectangle.Bottom * 2, null, new IntPtr());
            Invalidate();
        }

        private void ObTimer_Tick(object sender, EventArgs e) {
            if(gameTime / 100 < 5)
                return;
            int tx = r.Next(0, ClientRectangle.Right - 100);
            obList.Add(new Obstacle(tx, 10, r.Next(0, 9)));
            //obState = true;
            Invalidate();
        }

        

        private void Timer_Tick(object sender, EventArgs e) {
            backLoc--;
            if(backLoc * scrollSize < 0) {
                backLoc = (ClientRectangle.Bottom * 2 - ClientRectangle.Bottom) / scrollSize;
            }
            for(int i = 0; i < obList.Count; i++) {
                obList[i].y += 3;
            }
            if(gameTime/100<6) gameTime++;
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {

            //e.Graphics.DrawImage(backgroundImage,0,0);
            if(gameTime / 100 >= 5) {
                e.Graphics.DrawImage(backgroundImage, 0, 0, new Rectangle(0, backLoc * scrollSize, ClientRectangle.Right, ClientRectangle.Bottom), GraphicsUnit.Pixel);
                e.Graphics.DrawImage(carImage, carX, carY, 80, 180);
                Console.WriteLine(obList.Count);
                for(int i = 0; i < obList.Count; i++) {
                    e.Graphics.DrawImage(obstacle[obList[i].type], obList[i].x, obList[i].y);
                }
            }
            if(gameStart == true && (gameTime/100<5)) {
                if(gameTime / 1000 == 5) {
                    gameStart = false;
                }
                else {
                    //Console.WriteLine("back");
                    e.Graphics.DrawImage(backgroundImage, 0, 0, new Rectangle(0, 0, ClientRectangle.Right, ClientRectangle.Bottom), GraphicsUnit.Pixel);
                    e.Graphics.DrawString((gameTime / 100 + 1).ToString(), new Font("맑은 고딕", 300), Brushes.Yellow, 200, 100);
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e) {
            this.Width = 800;
            this.Height = 839;
            //this.backLoc = (1000 - 800)/10;
            this.backLoc = (ClientRectangle.Bottom * 2 - ClientRectangle.Bottom) / 10 - 80;
            this.scrollSize = ClientRectangle.Bottom/80;

            // background
            backgroundImage = Image.FromFile("../../Images/backRoad.jpg");
            //backgroundImage = backgroundImage.GetThumbnailImage(ClientRectangle.Right, 1000, null, new IntPtr());
            backgroundImage = backgroundImage.GetThumbnailImage(ClientRectangle.Right, ClientRectangle.Bottom * 2, null, new IntPtr());

            // car
            carImage = Image.FromFile("../../Images/redCar.jpg");
            carImage = carImage.GetThumbnailImage(carImage.Width, carImage.Height, null, new IntPtr());
            this.carX = ClientRectangle.Right / 2 - (carImage.Width / 2);
            this.carY = ClientRectangle.Bottom - carImage.Height;

            // obstacle
            for(int i = 0; i < obstacle.Length; i++) {
                string path = "../../Images/obstacle";
                path += (i + ".jpg");
                obstacle[i] = Image.FromFile(path);
                obstacle[i] = obstacle[i].GetThumbnailImage(80, 80, null, new IntPtr());
            }
        }
    }
}
