using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;    // MS-SQL 사용 네임스페이스

namespace _02_SQLProvider
{
    public partial class Form1 : Form
    {
        // 연결 객체 변수
        SqlConnection conn;

        // 테이블의 컬럼명을 작성하는 함수
        void MakeListViewColumn(string[] sArr)
        {
            foreach(string s in sArr)
            {
                ColumnHeader cHeader = new ColumnHeader();   // 헤더 생성
                cHeader.Text = s;     // 헤더에 들어갈 텍스트
                cHeader.Width = 150;   // 헤더의 크기
                listView1.Columns.Add(cHeader);  //  ListView에 헤더컬럼 추가
            }            
        }

        // 테이블 항목들을 ListView에 보여주는 함수
        void AddListView(string[] sArr)
        {
            listView1.Items.Add(new ListViewItem(sArr));
        }

        // 로그를 ListBox에 출력하는 함수
        void AddListBox(string str)
        {
            listBox1.Items.Add(str);
        }

        public Form1()
        {
            InitializeComponent();
            this.Load += new EventHandler(Form1_Load);
            this.FormClosed += new FormClosedEventHandler(Form1_FormClosed);
        }

        // 프로그램 종료시 처리하는 함수
        void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (conn != null)
            {
                conn.Close();
            }
        }

        // 프로그램 시작시 처리하는 함수
        void Form1_Load(object sender, EventArgs e)
        {
            tb_DB.Text = @"Server=localhost;database=Test_DB;uid=Acapellia;pwd=Acapellia1234;";
            tb_SQL.Text = @"SELECT * FROM dbo.Human";
        }

        // 데이터베이스 연결 버튼
        private void btn_DBConnect_Click(object sender, EventArgs e)
        {
            string conStr = tb_DB.Text;

            conn = new SqlConnection(conStr);
            try
            {
                conn.Open();
                AddListBox("연결 성공");
            }
            catch (Exception ex)
            {
                AddListBox(ex.Message);
            }
        }

        // 데이터베이스 연결 해제 버튼
        private void btn_DBDisconnect_Click(object sender, EventArgs e)
        {
            conn.Close();
            AddListBox("연결 해제");
        }

        // SQL문 실행 버튼
        private void btn_SQLRun_Click(object sender, EventArgs e)
        {
            // Trim : 양끝 공백없애기, ToUpper() : 대문자
            string strSql = tb_SQL.Text.Trim().ToUpper();
            string strSql_ori = tb_SQL.Text.Trim();

            try
            {
                SqlCommand cmd = new SqlCommand("", conn);
                cmd.CommandText = strSql_ori;

                /*SELECT : 검색 결과가 존재*/
                if (strSql.StartsWith("SELECT"))
                {
                    SqlDataReader read = cmd.ExecuteReader();

                    /*Name, Phone, Age*/
                    string[] str = new string[read.FieldCount];
                    for (int i = 0; i < read.FieldCount; i++)
                        str[i] = read.GetName(i);
                        
                    // ListView에 컬럼 헤더 생성
                    MakeListViewColumn(str);

                    /*테이블의 데이터 가져와서 ListView에 출력*/
                    while (read.Read())
                    {
                        string[] strValue = new string[read.FieldCount];
                        for (int i = 0; i < read.FieldCount; i++)
                        {
                            strValue[i] = read.GetValue(i).ToString();
                        }
                        AddListView(strValue);
                    }

                    read.Close();
                }                
                else/*INSERT, DELETE, UPDATE : 처리만 확인*/
                {
                    cmd.CommandText = strSql_ori;
                    cmd.ExecuteNonQuery();
                    AddListBox("명령 실행 마침");
                }
            }
            catch (Exception ex)
            {
                AddListBox(ex.Message);
            }                        
        }

        // 테이블정보(ListView)를 삭제 초기화 버튼
        private void btn_ResetListView_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear();
            listView1.Columns.Clear();            
        }

        // 로그정보(ListBox)를 삭제 초기화 버튼
        private void btn_ResetListBox_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }
    }
}
