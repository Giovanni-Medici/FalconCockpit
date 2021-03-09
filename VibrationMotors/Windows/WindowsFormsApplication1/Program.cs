//
// Change Log:
// V0.9 2021 03 06 First issue
//
// © 2021. This work is licensed under a CC BY 4.0 license. 
// You are free to:
// Share — copy and redistribute the material in any medium or format.
// Under the following terms:
// Attribution — You must give appropriate credit, provide a link to the license, 
// and indicate if changes were made. You may do so in any reasonable manner, but 
// not in any way that suggests the licensor endorses you or your use.
// NonCommercial — You may not use the material for commercial purposes.
// NoDerivatives — If you remix, transform, or build upon the material, you may 
// not distribute the modified material.
// No additional restrictions — You may not apply legal terms or technological 
// measures that legally restrict others from doing anything the license permits.

#region Using statements
using System;
using System.Globalization;
using System.Threading;
using System.Windows.Forms;
using log4net;
using UnhandledExceptionEventArgs = System.UnhandledExceptionEventArgs;

#endregion

/*using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;*/


namespace VibrationMotors
{
    static class Program
    {
        #region Class variable declarations

        // private members
        private static Form mainForm;
        private static readonly ILog _log = LogManager.GetLogger(typeof(Program));

        #endregion

        #region Static methods

        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            LogException((Exception)e.ExceptionObject);
        }

        private static void UIThreadException(object sender, ThreadExceptionEventArgs t)
        {
            LogException(t.Exception);
        }

        private static void LogException(Exception e)
        {
            _log.Error(e.Message, e);
        }

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            //Application.EnableVisualStyles();
            //Application.SetCompatibleTextRenderingDefault(false);
            //Application.Run(new Form1());

            // Add the event handler for handling UI thread exceptions to the event.
            Application.ThreadException += UIThreadException;

        // Set the unhandled exception mode to force all Windows Forms errors to go through
        // our handler.
        Application.SetUnhandledExceptionMode(UnhandledExceptionMode.CatchException);

        // Add the event handler for handling non-UI thread exceptions to the event. 
        AppDomain.CurrentDomain.UnhandledException +=
                CurrentDomain_UnhandledException;

        Thread.CurrentThread.Name = "MainThread";


        mainForm = new Form1();

        Application.Run(mainForm);
        }

        #endregion
    }
}
