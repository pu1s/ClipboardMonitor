﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using pu1soft;


namespace clipmonitor
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            pu1soft.ClipboardViewer clipboardMonitor = new ClipboardViewer();
            btn1.Content = clipboardMonitor.ToString() 
                + " / " 
                + clipboardMonitor.Handle.ToString()
                + " / "
                + clipboardMonitor.ClipboardViewerHandle
                + " / "
                + clipboardMonitor.NextClipboardViewerHandle
                + " / "
                + clipboardMonitor.LastError.ToString();
            //clipboardMonitor.Start();
        }

        
    }
}
