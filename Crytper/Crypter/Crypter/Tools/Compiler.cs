using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Crypter.Tools
{
    internal class Compiler
    {
        private byte[] Key;
        private byte[] IV;
        public Compiler(String key, string iv) {
            this.Key = Convert.FromBase64String(key);
            this.IV = Convert.FromBase64String(iv);
        }
        public void SetSetting()
        {

        }
        public void Compile()
        {

        }
    }
}
