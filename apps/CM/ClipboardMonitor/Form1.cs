using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using pulsoft;

namespace ClipboardMonitor
{
    public partial class Form1 : Form
    {

        pulsoft.ClipboardMonitor cmw;
        public Form1()
        {
            InitializeComponent();
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            cmw = new pulsoft.ClipboardMonitor();
            button1.Text = cmw.MonitorHandle.ToString();
            //cmw.Show();
        }
    }
}
