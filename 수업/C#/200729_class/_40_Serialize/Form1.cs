using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _40_Serialize {
    public partial class Form1 : Form {
        Human human = new Human();
        public Form1() {
            InitializeComponent();
            this.Load += Form1_Load;
        }

        private void Form1_Load(object sender, EventArgs e) {
            human.Name = "홍길동";
            human.Age = 24;
            human.Height = 158;
            human.Weight = 48;
        }

        private void btnReadSerialize_Click(object sender, EventArgs e) {
            DeserialzeXML();
        }

        private void btnWriteSerialize_Click(object sender, EventArgs e) {
            SerialzeXML();
        }

        void SerializeBinary() {
            FileStream fs = new FileStream("Human.bin", FileMode.Create, FileAccess.Write);
            BinaryFormatter bf = new BinaryFormatter();
            bf.Serialize(fs, human);
            fs.Close();
        }
        void SerialzeXML() {
            FileStream fs = new FileStream("Human.xml", FileMode.Create, FileAccess.Write);
            SoapFormatter bf = new SoapFormatter();
            bf.Serialize(fs, human);
            fs.Close();
        }
        void DeserializeBinary() {
            FileStream fs = new FileStream("Human.bin", FileMode.Open, FileAccess.Read);
            BinaryFormatter bf = new BinaryFormatter();
            Human hong = bf.Deserialize(fs) as Human;
            MessageBox.Show(hong.ToString(), "Human Information");
            fs.Close();
        }
        void DeserialzeXML() {
            FileStream fs = new FileStream("Human.xml", FileMode.Open, FileAccess.Read);
            SoapFormatter bf = new SoapFormatter();
            Human hong = bf.Deserialize(fs) as Human;
            MessageBox.Show(hong.ToString(), "Human Information");
            fs.Close();
        }
    }
}
