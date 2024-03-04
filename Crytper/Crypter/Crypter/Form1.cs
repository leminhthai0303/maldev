using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Crypter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void txtServer_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnServer_Click(object sender, EventArgs e)
        {
            using(OpenFileDialog ofd = new OpenFileDialog())
            {
                ofd.Filter = "Excutable (*.exe)|*.exe";
                ofd.Title = "Select .NET File to Crypter....";

                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    txtServer.Text = ofd.FileName;
                }
            }
        }

        private void btnIcon_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                ofd.Filter = "Excutable (*.ico)|*.ico";
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
    }
}
