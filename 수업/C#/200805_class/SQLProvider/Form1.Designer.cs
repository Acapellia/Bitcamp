namespace _02_SQLProvider
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.tb_DB = new System.Windows.Forms.TextBox();
            this.btn_DBConnect = new System.Windows.Forms.Button();
            this.btn_DBDisconnect = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tb_SQL = new System.Windows.Forms.TextBox();
            this.btn_SQLRun = new System.Windows.Forms.Button();
            this.humanDataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.listView1 = new System.Windows.Forms.ListView();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.btn_ResetListView = new System.Windows.Forms.Button();
            this.btn_ResetListBox = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.humanDataSetBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // tb_DB
            // 
            this.tb_DB.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tb_DB.Location = new System.Drawing.Point(66, 549);
            this.tb_DB.Name = "tb_DB";
            this.tb_DB.Size = new System.Drawing.Size(747, 21);
            this.tb_DB.TabIndex = 1;
            // 
            // btn_DBConnect
            // 
            this.btn_DBConnect.Location = new System.Drawing.Point(819, 534);
            this.btn_DBConnect.Name = "btn_DBConnect";
            this.btn_DBConnect.Size = new System.Drawing.Size(105, 27);
            this.btn_DBConnect.TabIndex = 2;
            this.btn_DBConnect.Text = "연결";
            this.btn_DBConnect.UseVisualStyleBackColor = true;
            this.btn_DBConnect.Click += new System.EventHandler(this.btn_DBConnect_Click);
            // 
            // btn_DBDisconnect
            // 
            this.btn_DBDisconnect.Location = new System.Drawing.Point(819, 567);
            this.btn_DBDisconnect.Name = "btn_DBDisconnect";
            this.btn_DBDisconnect.Size = new System.Drawing.Size(105, 28);
            this.btn_DBDisconnect.TabIndex = 2;
            this.btn_DBDisconnect.Text = "연결 끊기";
            this.btn_DBDisconnect.UseVisualStyleBackColor = true;
            this.btn_DBDisconnect.Click += new System.EventHandler(this.btn_DBDisconnect_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 552);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(21, 12);
            this.label1.TabIndex = 3;
            this.label1.Text = "DB";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 623);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "SQL";
            // 
            // tb_SQL
            // 
            this.tb_SQL.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tb_SQL.Location = new System.Drawing.Point(66, 611);
            this.tb_SQL.Name = "tb_SQL";
            this.tb_SQL.Size = new System.Drawing.Size(747, 21);
            this.tb_SQL.TabIndex = 1;
            // 
            // btn_SQLRun
            // 
            this.btn_SQLRun.Location = new System.Drawing.Point(819, 608);
            this.btn_SQLRun.Name = "btn_SQLRun";
            this.btn_SQLRun.Size = new System.Drawing.Size(105, 28);
            this.btn_SQLRun.TabIndex = 2;
            this.btn_SQLRun.Text = "SQL 실행";
            this.btn_SQLRun.UseVisualStyleBackColor = true;
            this.btn_SQLRun.Click += new System.EventHandler(this.btn_SQLRun_Click);
            // 
            // humanDataSet
            // 

            // 
            // humanDataSetBindingSource
            // 

            // 
            // listView1
            // 
            this.listView1.FullRowSelect = true;
            this.listView1.GridLines = true;
            this.listView1.Location = new System.Drawing.Point(21, 18);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(567, 459);
            this.listView1.TabIndex = 4;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.HorizontalExtent = 2000;
            this.listBox1.HorizontalScrollbar = true;
            this.listBox1.ItemHeight = 12;
            this.listBox1.Location = new System.Drawing.Point(598, 20);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(325, 448);
            this.listBox1.TabIndex = 5;
            // 
            // btn_ResetListView
            // 
            this.btn_ResetListView.Location = new System.Drawing.Point(23, 487);
            this.btn_ResetListView.Name = "btn_ResetListView";
            this.btn_ResetListView.Size = new System.Drawing.Size(128, 34);
            this.btn_ResetListView.TabIndex = 6;
            this.btn_ResetListView.Text = "모두 삭제";
            this.btn_ResetListView.UseVisualStyleBackColor = true;
            this.btn_ResetListView.Click += new System.EventHandler(this.btn_ResetListView_Click);
            // 
            // btn_ResetListBox
            // 
            this.btn_ResetListBox.Location = new System.Drawing.Point(598, 487);
            this.btn_ResetListBox.Name = "btn_ResetListBox";
            this.btn_ResetListBox.Size = new System.Drawing.Size(128, 34);
            this.btn_ResetListBox.TabIndex = 6;
            this.btn_ResetListBox.Text = "모두 삭제";
            this.btn_ResetListBox.UseVisualStyleBackColor = true;
            this.btn_ResetListBox.Click += new System.EventHandler(this.btn_ResetListBox_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(936, 646);
            this.Controls.Add(this.btn_ResetListBox);
            this.Controls.Add(this.btn_ResetListView);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btn_SQLRun);
            this.Controls.Add(this.btn_DBDisconnect);
            this.Controls.Add(this.btn_DBConnect);
            this.Controls.Add(this.tb_SQL);
            this.Controls.Add(this.tb_DB);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tb_DB;
        private System.Windows.Forms.Button btn_DBConnect;
        private System.Windows.Forms.Button btn_DBDisconnect;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tb_SQL;
        private System.Windows.Forms.Button btn_SQLRun;
        private System.Windows.Forms.BindingSource humanDataSetBindingSource;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button btn_ResetListView;
        private System.Windows.Forms.Button btn_ResetListBox;
    }
}

