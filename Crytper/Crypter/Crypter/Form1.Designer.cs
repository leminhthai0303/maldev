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
            this.txtServer = new System.Windows.Forms.TextBox();
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
            this.panel2.SuspendLayout();
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
            this.btnServer.Location = new System.Drawing.Point(401, 73);
            this.btnServer.Name = "btnServer";
            this.btnServer.Size = new System.Drawing.Size(145, 56);
            this.btnServer.TabIndex = 1;
            this.btnServer.Text = "Select";
            this.btnServer.UseVisualStyleBackColor = true;
            this.btnServer.Click += new System.EventHandler(this.btnServer_Click);
            // 
            // btnIcon
            // 
            this.btnIcon.AccessibleName = "";
            this.btnIcon.Location = new System.Drawing.Point(401, 154);
            this.btnIcon.Name = "btnIcon";
            this.btnIcon.Size = new System.Drawing.Size(145, 56);
            this.btnIcon.TabIndex = 1;
            this.btnIcon.Text = "Select";
            this.btnIcon.UseVisualStyleBackColor = true;
            this.btnIcon.Click += new System.EventHandler(this.btnIcon_Click);
            // 
            // txtServer
            // 
            this.txtServer.AccessibleName = "";
            this.txtServer.Location = new System.Drawing.Point(129, 73);
            this.txtServer.Multiline = true;
            this.txtServer.Name = "txtServer";
            this.txtServer.Size = new System.Drawing.Size(266, 56);
            this.txtServer.TabIndex = 2;
            this.txtServer.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtServer.TextChanged += new System.EventHandler(this.txtServer_TextChanged);
            // 
            // txtIcon
            // 
            this.txtIcon.AccessibleName = "";
            this.txtIcon.Location = new System.Drawing.Point(129, 154);
            this.txtIcon.Multiline = true;
            this.txtIcon.Name = "txtIcon";
            this.txtIcon.Size = new System.Drawing.Size(266, 56);
            this.txtIcon.TabIndex = 2;
            this.txtIcon.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // btnBuild
            // 
            this.btnBuild.AccessibleName = "";
            this.btnBuild.Location = new System.Drawing.Point(570, 157);
            this.btnBuild.Name = "btnBuild";
            this.btnBuild.Size = new System.Drawing.Size(148, 137);
            this.btnBuild.TabIndex = 1;
            this.btnBuild.Text = "Build";
            this.btnBuild.UseVisualStyleBackColor = true;
            this.btnBuild.Click += new System.EventHandler(this.btnBuild_Click);
            // 
            // labelServer
            // 
            this.labelServer.AutoSize = true;
            this.labelServer.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelServer.Location = new System.Drawing.Point(28, 86);
            this.labelServer.Name = "labelServer";
            this.labelServer.Size = new System.Drawing.Size(76, 25);
            this.labelServer.TabIndex = 3;
            this.labelServer.Text = "Server:";
            // 
            // labelIcon
            // 
            this.labelIcon.AutoSize = true;
            this.labelIcon.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelIcon.Location = new System.Drawing.Point(49, 167);
            this.labelIcon.Name = "labelIcon";
            this.labelIcon.Size = new System.Drawing.Size(55, 25);
            this.labelIcon.TabIndex = 3;
            this.labelIcon.Text = "Icon:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(12, 251);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(90, 25);
            this.label4.TabIndex = 6;
            this.label4.Text = "KeyGen:";
            // 
            // txtKeyGen
            // 
            this.txtKeyGen.AccessibleName = "";
            this.txtKeyGen.Location = new System.Drawing.Point(129, 238);
            this.txtKeyGen.Multiline = true;
            this.txtKeyGen.Name = "txtKeyGen";
            this.txtKeyGen.Size = new System.Drawing.Size(266, 56);
            this.txtKeyGen.TabIndex = 5;
            this.txtKeyGen.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // btnKeyGen
            // 
            this.btnKeyGen.AccessibleName = "";
            this.btnKeyGen.Location = new System.Drawing.Point(401, 238);
            this.btnKeyGen.Name = "btnKeyGen";
            this.btnKeyGen.Size = new System.Drawing.Size(145, 56);
            this.btnKeyGen.TabIndex = 4;
            this.btnKeyGen.Text = "Generate";
            this.btnKeyGen.UseVisualStyleBackColor = true;
            this.btnKeyGen.Click += new System.EventHandler(this.btnKeyGen_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(28, 338);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(74, 25);
            this.label5.TabIndex = 9;
            this.label5.Text = "IVGen:";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // txtIVGen
            // 
            this.txtIVGen.AccessibleName = "";
            this.txtIVGen.Location = new System.Drawing.Point(129, 325);
            this.txtIVGen.Multiline = true;
            this.txtIVGen.Name = "txtIVGen";
            this.txtIVGen.Size = new System.Drawing.Size(266, 56);
            this.txtIVGen.TabIndex = 8;
            this.txtIVGen.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtIVGen.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // btnIVGen
            // 
            this.btnIVGen.AccessibleName = "";
            this.btnIVGen.Location = new System.Drawing.Point(401, 325);
            this.btnIVGen.Name = "btnIVGen";
            this.btnIVGen.Size = new System.Drawing.Size(145, 56);
            this.btnIVGen.TabIndex = 7;
            this.btnIVGen.Text = "Generate";
            this.btnIVGen.UseVisualStyleBackColor = true;
            this.btnIVGen.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(740, 435);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtIVGen);
            this.Controls.Add(this.btnIVGen);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtKeyGen);
            this.Controls.Add(this.btnKeyGen);
            this.Controls.Add(this.labelIcon);
            this.Controls.Add(this.labelServer);
            this.Controls.Add(this.txtIcon);
            this.Controls.Add(this.txtServer);
            this.Controls.Add(this.btnIcon);
            this.Controls.Add(this.btnBuild);
            this.Controls.Add(this.btnServer);
            this.Controls.Add(this.panel2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
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
        private System.Windows.Forms.TextBox txtServer;
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
    }
}

