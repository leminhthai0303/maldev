using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Crypter.Tools
{
    internal class Encryption
    {
        public static byte[] AesEncryption(byte[] shellcode, byte[] key, byte[] iv)
        {
            using (var aes = Aes.Create())
            {
                aes.KeySize = 128;
                aes.BlockSize = 128;
                aes.Padding = PaddingMode.PKCS7;
                aes.Mode = CipherMode.CBC;

                aes.Key = key;
                aes.IV = iv;

                using (var encryptor = aes.CreateEncryptor())
                {
                    using (var msEncShellcode = new MemoryStream())
                    {   
                        using (var cryptorStream = new CryptoStream(msEncShellcode, encryptor, CryptoStreamMode.Write))
                        {
                            cryptorStream.Write(shellcode, 0, shellcode.Length);
                            cryptorStream.FlushFinalBlock();

                            return msEncShellcode.ToArray();
                        }
                    }
                }
            }
        }
        public static byte[] AesDecryption(byte[] shellcode, byte[] key, byte[] iv)
        {
            using (var aes = Aes.Create())
            {
                aes.KeySize = 128;
                aes.BlockSize = 128;
                aes.Padding = PaddingMode.PKCS7;
                aes.Mode = CipherMode.CBC;

                aes.Key = key;
                aes.IV = iv;

                using (var Decryptor = aes.CreateDecryptor())
                {
                    using (var msEncShellcode = new MemoryStream())
                    {
                        using (var cryptorStream = new CryptoStream(msEncShellcode, Decryptor, CryptoStreamMode.Write))
                        {
                            cryptorStream.Write(shellcode, 0, shellcode.Length);
                            cryptorStream.FlushFinalBlock();

                            return msEncShellcode.ToArray();
                        }
                    }
                }
            }
        }
    }
}
