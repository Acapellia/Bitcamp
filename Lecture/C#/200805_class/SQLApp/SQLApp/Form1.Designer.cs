namespace SQLApp
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
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnDBConnect = new System.Windows.Forms.Button();
            this.lbResultLog = new System.Windows.Forms.ListBox();
            this.btnDBDisconnect = new System.Windows.Forms.Button();
            this.btnSelectSQL = new System.Windows.Forms.Button();
            this.btnInsertSQL = new System.Windows.Forms.Button();
            this.btnUpdateSQL = new System.Windows.Forms.Button();
            this.btnDeleteSQL = new System.Windows.Forms.Button();
            this.tbDBInfo = new System.Windows.Forms.TextBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnDBConnect
            // 
            this.btnDBConnect.Font = new System.Drawing.Font("굴림", 25F);
            this.btnDBConnect.Location = new System.Drawing.Point(774, 12);
            this.btnDBConnect.Name = "btnDBConnect";
            this.btnDBConnect.Size = new System.Drawing.Size(254, 51);
            this.btnDBConnect.TabIndex = 1;
            this.btnDBConnect.Text = "Connect";
            this.btnDBConnect.UseVisualStyleBackColor = true;
            this.btnDBConnect.Click += new System.EventHandler(this.btnDBConnect_Click);
            // 
            // lbResultLog
            // 
            this.lbResultLog.FormattingEnabled = true;
            this.lbResultLog.ItemHeight = 12;
            this.lbResultLog.Location = new System.Drawing.Point(12, 78);
            this.lbResultLog.Name = "lbResultLog";
            this.lbResultLog.Size = new System.Drawing.Size(731, 508);
            this.lbResultLog.TabIndex = 2;
            // 
            // btnDBDisconnect
            // 
            this.btnDBDisconnect.Font = new System.Drawing.Font("굴림", 25F);
            this.btnDBDisconnect.Location = new System.Drawing.Point(774, 78);
            this.btnDBDisconnect.Name = "btnDBDisconnect";
            this.btnDBDisconnect.Size = new System.Drawing.Size(254, 50);
            this.btnDBDisconnect.TabIndex = 3;
            this.btnDBDisconnect.Text = "Disconnect";
            this.btnDBDisconnect.UseVisualStyleBackColor = true;
            this.btnDBDisconnect.Click += new System.EventHandler(this.btnDBDisconnect_Click);
            // 
            // btnSelectSQL
            // 
            this.btnSelectSQL.Font = new System.Drawing.Font("굴림", 25F);
            this.btnSelectSQL.Location = new System.Drawing.Point(774, 146);
            this.btnSelectSQL.Name = "btnSelectSQL";
            this.btnSelectSQL.Size = new System.Drawing.Size(254, 50);
            this.btnSelectSQL.TabIndex = 4;
            this.btnSelectSQL.Text = "Select SQL";
            this.btnSelectSQL.UseVisualStyleBackColor = true;
            this.btnSelectSQL.Click += new System.EventHandler(this.btnSelectSQL_Click);
            // 
            // btnInsertSQL
            // 
            this.btnInsertSQL.Font = new System.Drawing.Font("굴림", 25F);
            this.btnInsertSQL.Location = new System.Drawing.Point(774, 215);
            this.btnInsertSQL.Name = "btnInsertSQL";
            this.btnInsertSQL.Size = new System.Drawing.Size(254, 50);
            this.btnInsertSQL.TabIndex = 5;
            this.btnInsertSQL.Text = "Insert SQL";
            this.btnInsertSQL.UseVisualStyleBackColor = true;
            this.btnInsertSQL.Click += new System.EventHandler(this.btnInsertSQL_Click);
            // 
            // btnUpdateSQL
            // 
            this.btnUpdateSQL.Font = new System.Drawing.Font("굴림", 25F);
            this.btnUpdateSQL.Location = new System.Drawing.Point(774, 285);
            this.btnUpdateSQL.Name = "btnUpdateSQL";
            this.btnUpdateSQL.Size = new System.Drawing.Size(254, 50);
            this.btnUpdateSQL.TabIndex = 6;
            this.btnUpdateSQL.Text = "Update SQL";
            this.btnUpdateSQL.UseVisualStyleBackColor = true;
            this.btnUpdateSQL.Click += new System.EventHandler(this.btnUpdateSQL_Click);
            // 
            // btnDeleteSQL
            // 
            this.btnDeleteSQL.Font = new System.Drawing.Font("굴림", 25F);
            this.btnDeleteSQL.Location = new System.Drawing.Point(774, 355);
            this.btnDeleteSQL.Name = "btnDeleteSQL";
            this.btnDeleteSQL.Size = new System.Drawing.Size(254, 50);
            this.btnDeleteSQL.TabIndex = 7;
            this.btnDeleteSQL.Text = "Delete SQL";
            this.btnDeleteSQL.UseVisualStyleBackColor = true;
            this.btnDeleteSQL.Click += new System.EventHandler(this.btnDeleteSQL_Click);
            // 
            // tbDBInfo
            // 
            this.tbDBInfo.Font = new System.Drawing.Font("굴림", 20F);
            this.tbDBInfo.Location = new System.Drawing.Point(12, 12);
            this.tbDBInfo.Name = "tbDBInfo";
            this.tbDBInfo.Size = new System.Drawing.Size(731, 38);
            this.tbDBInfo.TabIndex = 8;
            // 
            // btnClear
            // 
            this.btnClear.Font = new System.Drawing.Font("굴림", 25F);
            this.btnClear.Location = new System.Drawing.Point(774, 536);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(254, 50);
            this.btnClear.TabIndex = 9;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1040, 617);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.tbDBInfo);
            this.Controls.Add(this.btnDeleteSQL);
            this.Controls.Add(this.btnUpdateSQL);
            this.Controls.Add(this.btnInsertSQL);
            this.Controls.Add(this.btnSelectSQL);
            this.Controls.Add(this.btnDBDisconnect);
            this.Controls.Add(this.lbResultLog);
            this.Controls.Add(this.btnDBConnect);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnDBConnect;
        private System.Windows.Forms.ListBox lbResultLog;
        private System.Windows.Forms.Button btnDBDisconnect;
        private System.Windows.Forms.Button btnSelectSQL;
        private System.Windows.Forms.Button btnInsertSQL;
        private System.Windows.Forms.Button btnUpdateSQL;
        private System.Windows.Forms.Button btnDeleteSQL;
        private System.Windows.Forms.TextBox tbDBInfo;
        private System.Windows.Forms.Button btnClear;
    }
}

