namespace teamproject
{
    partial class Sign_In
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Sign_In));
            this.txtboxName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.Password = new System.Windows.Forms.Label();
            this.ID = new System.Windows.Forms.Label();
            this.txtboxPW = new System.Windows.Forms.TextBox();
            this.txtboxID = new System.Windows.Forms.TextBox();
            this.btnsignin = new System.Windows.Forms.Button();
            this.btnCancle = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // txtboxName
            // 
            this.txtboxName.Font = new System.Drawing.Font("굴림", 21.75F);
            this.txtboxName.Location = new System.Drawing.Point(47, 344);
            this.txtboxName.Name = "txtboxName";
            this.txtboxName.Size = new System.Drawing.Size(313, 41);
            this.txtboxName.TabIndex = 15;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("휴먼편지체", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(41, 296);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(87, 34);
            this.label1.TabIndex = 14;
            this.label1.Text = "Name";
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pictureBox1.BackgroundImage")));
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox1.Location = new System.Drawing.Point(96, 22);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(231, 149);
            this.pictureBox1.TabIndex = 13;
            this.pictureBox1.TabStop = false;
            // 
            // Password
            // 
            this.Password.AutoSize = true;
            this.Password.Font = new System.Drawing.Font("휴먼편지체", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Password.Location = new System.Drawing.Point(45, 414);
            this.Password.Name = "Password";
            this.Password.Size = new System.Drawing.Size(52, 34);
            this.Password.TabIndex = 11;
            this.Password.Text = "PW";
            // 
            // ID
            // 
            this.ID.AutoSize = true;
            this.ID.Font = new System.Drawing.Font("휴먼편지체", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.ID.Location = new System.Drawing.Point(45, 179);
            this.ID.Name = "ID";
            this.ID.Size = new System.Drawing.Size(42, 34);
            this.ID.TabIndex = 10;
            this.ID.Text = "ID";
            // 
            // txtboxPW
            // 
            this.txtboxPW.Font = new System.Drawing.Font("굴림", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.txtboxPW.Location = new System.Drawing.Point(47, 468);
            this.txtboxPW.Name = "txtboxPW";
            this.txtboxPW.Size = new System.Drawing.Size(315, 41);
            this.txtboxPW.TabIndex = 8;
            // 
            // txtboxID
            // 
            this.txtboxID.Font = new System.Drawing.Font("굴림", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.txtboxID.Location = new System.Drawing.Point(47, 229);
            this.txtboxID.Name = "txtboxID";
            this.txtboxID.Size = new System.Drawing.Size(315, 41);
            this.txtboxID.TabIndex = 9;
            // 
            // btnsignin
            // 
            this.btnsignin.BackColor = System.Drawing.Color.LightBlue;
            this.btnsignin.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnsignin.Font = new System.Drawing.Font("휴먼편지체", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnsignin.Location = new System.Drawing.Point(140, 525);
            this.btnsignin.Margin = new System.Windows.Forms.Padding(0);
            this.btnsignin.Name = "btnsignin";
            this.btnsignin.Size = new System.Drawing.Size(133, 76);
            this.btnsignin.TabIndex = 17;
            this.btnsignin.Text = "Sign up";
            this.btnsignin.UseVisualStyleBackColor = false;
            this.btnsignin.Click += new System.EventHandler(this.btnsignin_Click_1);
            // 
            // btnCancle
            // 
            this.btnCancle.BackColor = System.Drawing.Color.Tomato;
            this.btnCancle.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnCancle.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCancle.Location = new System.Drawing.Point(335, 541);
            this.btnCancle.Name = "btnCancle";
            this.btnCancle.Size = new System.Drawing.Size(75, 48);
            this.btnCancle.TabIndex = 18;
            this.btnCancle.Text = "Cancle";
            this.btnCancle.UseMnemonic = false;
            this.btnCancle.UseVisualStyleBackColor = false;
            this.btnCancle.Click += new System.EventHandler(this.btnCancle_Click);
            // 
            // Sign_In
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(433, 611);
            this.Controls.Add(this.btnCancle);
            this.Controls.Add(this.btnsignin);
            this.Controls.Add(this.txtboxName);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.Password);
            this.Controls.Add(this.ID);
            this.Controls.Add(this.txtboxPW);
            this.Controls.Add(this.txtboxID);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Sign_Up";
            this.Text = "Sign_Up";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtboxName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label Password;
        private System.Windows.Forms.Label ID;
        private System.Windows.Forms.TextBox txtboxPW;
        private System.Windows.Forms.TextBox txtboxID;
        private System.Windows.Forms.Button btnsignin;
        private System.Windows.Forms.Button btnCancle;
    }
}