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
            
            //cv1 = new ClipboardViewer();
            
        }

       

        public pu1soft.ClipboardViewer cv;
        //public pu1soft.ClipboardViewer cv1;
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            cv = new ClipboardViewer();
            cv.Create();
            //cv.Show();
            //cv1.Show();
            btn1.Content = cv.ToString()
                + " / "
                + cv.Handle.ToString()
                + " / "
                + cv.ClipboardViewerHandle
                + " / "
                + cv.NextClipboardViewerHandle
                + " / "
                + cv.LastError.ToString();
                //+ " / "
                //+ cv1.Handle.ToString()
                //+ " / "
                //+ cv1.ClipboardViewerHandle
                //+ " / "
                //+ cv1.NextClipboardViewerHandle
                //+ " / "
                //+ cv1.LastError.ToString();
            cv.Destroy();
        }   
    }
}
