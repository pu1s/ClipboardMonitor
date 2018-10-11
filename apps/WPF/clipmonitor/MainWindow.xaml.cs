using System;
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

using pu1ssoft;


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
            cv = new ClipboardViewer();
        }

       

        public pu1ssoft.ClipboardViewer cv;
        //public pu1soft.ClipboardViewer cv1;
        private void Button_Click(object sender, RoutedEventArgs e)
        {

            //cv.Create();
            //cv.Show();
            //cv1.Show();
            cv.Init();
            btn1.Content = cv.ToString() + cv.Handle.ToString() + cv.NextClipboardViewerHandle.ToString() + cv.LastError.ToString();
           
        }   
    }
}
