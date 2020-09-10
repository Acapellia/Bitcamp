namespace RadioCheckBox {
    partial class Form1 {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing) {
            if(disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent() {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.chkMoney = new System.Windows.Forms.CheckBox();
            this.chkHohor = new System.Windows.Forms.CheckBox();
            this.chkForce = new System.Windows.Forms.CheckBox();
            this.chkPower = new System.Windows.Forms.CheckBox();
            this.radioDestroyer = new System.Windows.Forms.RadioButton();
            this.radioCommon = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnSelect = new System.Windows.Forms.Button();
            this.chkJustice = new System.Windows.Forms.CheckBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.chkJustice);
            this.groupBox1.Controls.Add(this.chkPower);
            this.groupBox1.Controls.Add(this.chkForce);
            this.groupBox1.Controls.Add(this.chkHohor);
            this.groupBox1.Controls.Add(this.chkMoney);
            this.groupBox1.Font = new System.Drawing.Font("굴림", 15F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))));
            this.groupBox1.Location = new System.Drawing.Point(31, 24);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(738, 175);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "능갖고 싶은 것(2개만 가능)";
            // 
            // chkMoney
            // 
            this.chkMoney.AutoSize = true;
            this.chkMoney.Location = new System.Drawing.Point(24, 96);
            this.chkMoney.Name = "chkMoney";
            this.chkMoney.Size = new System.Drawing.Size(49, 24);
            this.chkMoney.TabIndex = 0;
            this.chkMoney.Text = "돈";
            this.chkMoney.UseVisualStyleBackColor = true;
            // 
            // chkHohor
            // 
            this.chkHohor.AutoSize = true;
            this.chkHohor.Location = new System.Drawing.Point(150, 96);
            this.chkHohor.Name = "chkHohor";
            this.chkHohor.Size = new System.Drawing.Size(70, 24);
            this.chkHohor.TabIndex = 1;
            this.chkHohor.Text = "명예";
            this.chkHohor.UseVisualStyleBackColor = true;
            // 
            // chkForce
            // 
            this.chkForce.AutoSize = true;
            this.chkForce.Location = new System.Drawing.Point(296, 96);
            this.chkForce.Name = "chkForce";
            this.chkForce.Size = new System.Drawing.Size(49, 24);
            this.chkForce.TabIndex = 2;
            this.chkForce.Text = "힘";
            this.chkForce.UseVisualStyleBackColor = true;
            // 
            // chkPower
            // 
            this.chkPower.AutoSize = true;
            this.chkPower.Location = new System.Drawing.Point(419, 96);
            this.chkPower.Name = "chkPower";
            this.chkPower.Size = new System.Drawing.Size(70, 24);
            this.chkPower.TabIndex = 3;
            this.chkPower.Text = "권력";
            this.chkPower.UseVisualStyleBackColor = true;
            // 
            // radioDestroyer
            // 
            this.radioDestroyer.AutoSize = true;
            this.radioDestroyer.Location = new System.Drawing.Point(119, 95);
            this.radioDestroyer.Name = "radioDestroyer";
            this.radioDestroyer.Size = new System.Drawing.Size(182, 24);
            this.radioDestroyer.TabIndex = 0;
            this.radioDestroyer.TabStop = true;
            this.radioDestroyer.Text = "카리스마 파괴자";
            this.radioDestroyer.UseVisualStyleBackColor = true;
            // 
            // radioCommon
            // 
            this.radioCommon.AutoSize = true;
            this.radioCommon.Location = new System.Drawing.Point(424, 95);
            this.radioCommon.Name = "radioCommon";
            this.radioCommon.Size = new System.Drawing.Size(253, 24);
            this.radioCommon.TabIndex = 1;
            this.radioCommon.TabStop = true;
            this.radioCommon.Text = "평범하고 가정적인 사람";
            this.radioCommon.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radioCommon);
            this.groupBox2.Controls.Add(this.radioDestroyer);
            this.groupBox2.Font = new System.Drawing.Font("굴림", 15F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))));
            this.groupBox2.Location = new System.Drawing.Point(31, 216);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(738, 176);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "되고 싶은 사람";
            // 
            // btnSelect
            // 
            this.btnSelect.Font = new System.Drawing.Font("굴림", 12F);
            this.btnSelect.Location = new System.Drawing.Point(593, 406);
            this.btnSelect.Name = "btnSelect";
            this.btnSelect.Size = new System.Drawing.Size(176, 32);
            this.btnSelect.TabIndex = 2;
            this.btnSelect.Text = "당신의 선택은?";
            this.btnSelect.UseVisualStyleBackColor = true;
            this.btnSelect.Click += new System.EventHandler(this.btnSelect_Click);
            // 
            // chkJustice
            // 
            this.chkJustice.AutoSize = true;
            this.chkJustice.Location = new System.Drawing.Point(568, 96);
            this.chkJustice.Name = "chkJustice";
            this.chkJustice.Size = new System.Drawing.Size(70, 24);
            this.chkJustice.TabIndex = 3;
            this.chkJustice.Text = "정의";
            this.chkJustice.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnSelect);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox chkPower;
        private System.Windows.Forms.CheckBox chkForce;
        private System.Windows.Forms.CheckBox chkHohor;
        private System.Windows.Forms.CheckBox chkMoney;
        private System.Windows.Forms.RadioButton radioDestroyer;
        private System.Windows.Forms.RadioButton radioCommon;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnSelect;
        private System.Windows.Forms.CheckBox chkJustice;
    }
}

