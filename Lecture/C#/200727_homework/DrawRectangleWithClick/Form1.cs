using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DrawRectangleWithClick {
    class Rect {
        public int x { get; set; }
        public int y { get; set; }
        public Color color { get; set; }
        public Rect(int _x, int _y, Color _c) {
            x = _x; y = _y; color = _c;
        }
    }
    public partial class Form1 : Form {
        List<Rect> rect = new List<Rect>(1);
        Random r = new Random();
        public Form1() {
            InitializeComponent();
            this.Paint += Form1_Paint;
            this.MouseDown += Form1_MouseDown;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            Color c = Color.FromArgb(r.Next(256), r.Next(256), r.Next(256), r.Next(256));
            rect.Add(new Rect(e.X, e.Y, c));
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            for(int i = 0; i < rect.Count; i++) {
                Brush brush = new SolidBrush(rect[i].color);
                e.Graphics.FillRectangle(brush, rect[i].x, rect[i].y, 20, 20);
            }
        }
    }
}
