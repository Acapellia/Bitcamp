using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SQLApp
{
    public partial class Form1 : Form
    {
        SqlConnection conn = null;
        string dbConnInfo = @"Server=localhost;" + @"database=Test_DB;" + @"uid=Acapellia;" + @"pwd=Acapellia1234";
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
            this.FormClosed += Form1_FormClosed;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e) {
            btnDBDisconnect_Click(sender,e);
        }

        private void Form1_Load(object sender, EventArgs e) {
            btnEnable(true, false, false, false, false, false);
            tbDBInfo.Text = dbConnInfo;
        }
        void AddResultLogListBox(string result) {
            lbResultLog.Items.Add(result);
        }
        void btnEnable(bool conn, bool disconn,bool select = false, bool insert=false, bool update=false, bool delete=false) {
            btnDBConnect.Enabled = conn;
            btnDBDisconnect.Enabled = disconn;
            btnSelectSQL.Enabled = select;
            btnInsertSQL.Enabled = insert;
            btnUpdateSQL.Enabled = update;
            btnDeleteSQL.Enabled = delete;
        }

        
        private void btnDBConnect_Click(object sender, EventArgs e) {

            conn = new SqlConnection(tbDBInfo.Text);
            try {
                conn.Open();
                if(conn.State == ConnectionState.Open) {
                    AddResultLogListBox("SQL-Server 연결 성공");
                    btnEnable(false, true, true, true, true, true);
                }
                else {
                    conn = null;
                    AddResultLogListBox("상태 : "+conn.State.ToString());
                }
            }
            catch (Exception ex){
                conn = null;
                AddResultLogListBox(ex.Message);
            }
        }
        private void btnDBDisconnect_Click(object sender, EventArgs e) {
            if(conn != null && (conn.State == ConnectionState.Open || conn.State == ConnectionState.Connecting)) {
                conn.Close();
                conn = null;
                AddResultLogListBox("SQL-Sever 연결 해제");
                btnEnable(true, false);
            }
        }

        private void btnSelectSQL_Click(object sender, EventArgs e) {
            try {
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "Select * From dbo.Human";

                // select문은 실행 후 결과를 받아온다.
                SqlDataReader reader = cmd.ExecuteReader();

                // dbo.human 테이블의 컬럼을 얻어온다.
                string[] colNames = new string[reader.FieldCount];
                for(int i=0;i<reader.FieldCount;i++) {
                    colNames[i] = reader.GetName(i);
                    AddResultLogListBox("컬럼명_" + i + " : " + colNames[i]);
                }
                AddResultLogListBox("");
                // 행을 가져온다.
                while(reader.Read()) {
                    string[] data = new string[reader.FieldCount];
                    for(int i=0; i < reader.FieldCount; i++) {
                        data[i] = reader.GetValue(i).ToString();
                    }
                    for(int i = 0; i < reader.FieldCount; i++) {
                        AddResultLogListBox(string.Format($"{colNames[i]} : {data[i]}"));
                    }
                    AddResultLogListBox("");
                }
                reader.Close();
                cmd.Dispose();
            }
            catch(Exception ex) {
                AddResultLogListBox(ex.Message);
            }
        }

        private void btnInsertSQL_Click(object sender, EventArgs e) {
            using(SqlCommand cmd = new SqlCommand()) {
                cmd.Connection = conn;
                cmd.CommandText = @"Insert into dbo.Human values(@번호, @이름, @전화, @주소)";
                cmd.Parameters.AddWithValue(@"번호", "11");
                cmd.Parameters.AddWithValue(@"이름", "문채원");
                cmd.Parameters.AddWithValue(@"전화", "010-5387-1579");
                cmd.Parameters.AddWithValue(@"주소", "강원도 강릉");
                int nRun = cmd.ExecuteNonQuery();
                AddResultLogListBox(string.Format($"insert {nRun} 행이 변경되었다."));
            }
        }

        private void btnUpdateSQL_Click(object sender, EventArgs e) {
            try {
                using(SqlCommand cmd = new SqlCommand()) {
                    cmd.Connection = conn;
                    cmd.CommandText = @"UPDATE dbo.Human SET" + "\r\n" +
                                    @"name=@이름0" + "\r\n" +
                                    @"WHERE name=@이름1";
                    cmd.Parameters.AddWithValue("@이름0", "문근영");
                    cmd.Parameters.AddWithValue("@이름1", "문채원");
                    int nRun = cmd.ExecuteNonQuery();
                    AddResultLogListBox(String.Format("UPDATE {0} 행이 실행됨",
                                        nRun));
                }
            }
            catch(Exception ex) {
                AddResultLogListBox(ex.Message);
            }
        }
        private void btnDeleteSQL_Click(object sender, EventArgs e) {
            try {
                using(SqlCommand cmd = new SqlCommand()) {
                    cmd.Connection = conn;
                    cmd.CommandText = @"DELETE FROM dbo.Human" + "\r\n" +
                                    @"WHERE name=@이름";
                    cmd.Parameters.AddWithValue("@이름", "문근영");
                }
            }
            catch(Exception ex) {
                AddResultLogListBox(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e) {
            lbResultLog.Items.Clear();
        }
    }
}
