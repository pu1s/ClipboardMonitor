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
            
        }

        public pu1ssoft.ClipboardViewer cv;
        //public pu1soft.ClipboardViewer cv1;
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //btn1.Content = cv.ToString() + cv.Handle.ToString() + cv.NextClipboardViewerHandle.ToString() + cv.LastError.ToString();

            cv = new ClipboardViewer();

        }

        private void Window_Activated(object sender, EventArgs e)
        {
           
        }

        private void Window_KeyUp(object sender, KeyEventArgs e)
        {
            
        }
    }
}
