using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ClipboardMonitorEngine;

namespace ClipboardMonitor
{
    public partial class Form1 : Form
    {
        private ClipboardMonitorEngine.ClipboardMonitor cm;
        
        public Form1()
        {
            InitializeComponent();
            
        }

        

        private void button1_Click(object sender, EventArgs e)
        {

            cm = new ClipboardMonitorEngine.ClipboardMonitor();
            //cm.OnMonitorCreated += Cm_OnMonitorCreated;
            cm.Run();
        }
    }
}
