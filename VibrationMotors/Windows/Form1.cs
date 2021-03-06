// This application reads the Falcon 4 BMS shared memory and for a given set of parameters
// Sends a command through the Serial port to Arduino so that it can run 6 vibration motors.
// Currently implemented:
// - High AoA
// - Speed brake
// - Landing gear extension/retraction
// - Chaff, Flares, Missile, Bombs release
// - Gun Fire
// - Ejection
// - Damage
// - Runway run
//
// Motors :
// +---------------+
// | 1           2 |
// |               |
// |               |
// |               |
// |               |
// | 3           4 |
// +---------------+
// |               |
// | 5           6 |
// |               |
// +---------------+
//
// Giovanni Medici 2020
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

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Diagnostics;
using System.Management;
using System.Linq;
using System.Text;
//using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using Common.Math;
using Common.Strings;
using F4SharedMem;
using F4SharedMem.Headers;
using System.Reflection;
using VibrationMotors.Properties;



namespace VibrationMotors
{
    public partial class Form1 : Form
    {
        private Reader _sharedMemReader = new Reader();
        
        private FlightData _lastFlightData;

        private Timer _timer = new Timer();

        private Stopwatch _stopWatch = new Stopwatch();

        private double Udot { get; set; }  // Body frame acceleration along X axis (m/s2)
        private double Vdot { get; set; }  // Body frame acceleration along Y axis (m/s2)
        private double Wdot { get; set; }  // Body frame acceleration along Z axis (m/s2)

        private double Uold { get; set; }  // Previous timestep Body frame velocity along X axis (m/s)
        private double Vold { get; set; }  // Previous timestep Body frame velocity along Y axis (m/s)
        private double Wold { get; set; }  // Previous timestep Body frame velocity along Z axis (m/s)
        private double AoA { get; set; }   // Angle of attack (deg)
        private double Vinf { get; set; }  // Velocity vector (wind frame) (m/s)

        private long DeltaT { get; set; }  // Timestep (ms)
        private long OldT { get; set; }    // Old Elapsed time (ms)

        private long consT { get; set; }  // consolidation time (ms) for the bomb release
        private long consT1 { get; set; } // consolidation time (ms) for the chaff flare
        
        private long consT2 { get; set; } // consolidation time (ms) for the Ejection

        

        private int OrdenanceReleased { get; set; } // Number of ordernance released (int) ()

        private int ChaffFlareReleased { get; set; } // Number of chaff/flares released (int) ()


        // Motor Power Settings
        private double MotPow { get; set; }  // Motor Power (0-100)  (double) ()
        // Motors On (binary)
        private uint MotOn { get; set; }  // Motors On (1x6 booleans) (uint) ()

        private Boolean MotRun;

        private Boolean isEjected;  // Boolean to indicate whether the pilot is ejected

        private Boolean isCom = false; // Boolean to indicate whether an arduino Port is available
        private Boolean isShowedMsg = false; // Boolean to indicate whether the warning message was shown

        // Serial Part
        System.IO.Ports.SerialPort ArduinoPort;




        public Form1()
        {
            string comPort = Properties.Settings.Default.comport;

            InitializeComponent();

            //MessageBox.Show(Properties.Settings.Default.comport);
            ArduinoPort = new System.IO.Ports.SerialPort();
            ArduinoPort.BaudRate = 9600;
            // Detect Serial Device
            AutodetectArduinoDevice();
            

            if (comPort.Contains("COM"))
            {
                ArduinoPort.PortName = comPort;
                //ArduinoPort = new System.IO.Ports.SerialPort(comPort, 9600); 
                
            }
            else
            {
                MessageBox.Show("The user has not selected a valid COM port. Please select a COM port among the available ones.", "User did not selected a valid COM port", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                //ArduinoPort = new System.IO.Ports.SerialPort();
            }

            // Create Serial Port 
            

            
            
            
            _stopWatch.Start();
            Uold = 0;   // initialize old values of body axis frame velocities
            Vold = 0;
            Wold = 0;
            OldT = 0;   // initialize old time 
            MotRun = false; // initialize motor status
            isEjected = false; // initialize Pilot Ejection status
            
            

        }



        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            _timer.Tick += _timer_Tick;
            _timer.Interval = 20;
            _timer.Start();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }



        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            //closes the Serial port on exit
            if (ArduinoPort.IsOpen) ArduinoPort.Close();
        }


        void _timer_Tick(object sender, EventArgs e)
        {
            if ((ReadSharedMem() != null) && (isCom))
            {
                // Shared Memory active
                // Initialize each loop with 0 MotPow
                MotPow = 0;
                MotOn = 0b_0000_0000;
                textBoxEvent.Clear();
                //listBoxCOM.Enabled = false;
                if (!ArduinoPort.IsOpen) ArduinoPort.Open();
                BindSharedMemoryDataToFormElements();

                
            }
            else if (ReadSharedMem() == null)
            {
                // Shared Memory not active
                //textBox1.Text = "NULL";
                checkBox_SimActive.Checked = false;
                textBoxEvent.Text = "NULL";
                textBoxMotON.Text = "NULL";
                textBoxMotRPM.Text = "NULL";
                if (ArduinoPort.IsOpen) ArduinoPort.Close();
                if (_stopWatch.IsRunning)
                {
                    _stopWatch.Stop();
                }
                //listBoxCOM.Enabled = true;
                //this.Controls.Add(textBox1); // Investigate
                isShowedMsg = false;
            }
            else if ((ReadSharedMem() != null) && (!isCom))
            {
                if (!isShowedMsg)                              
                {                                           
                    isShowedMsg = true;
                    MessageBox.Show("Falcon 4 BMS shared memory is active, but the user has not selected a valid COM port. Please select a COM port among the available ones.", "User did not selected a valid COM port", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }                                           
            }
        }
        private FlightData ReadSharedMem()
        {
            return _lastFlightData = _sharedMemReader.GetCurrentData();
        }



        private void BindSharedMemoryDataToFormElements()
        // This void binds shared memory
        {
            this.SuspendLayout();
            //EnableChildControls(tabIVibe);
            BindIntelliVibeDataToFormElements();
            //this.Controls.Add(textBox1);
            //this.ResumeLayout();


        }

        private void EnableChildControls(Control control, bool enabled = true)
        {
            foreach (var thisControl in control.Controls)
            {
                (thisControl as Control).Enabled = enabled;
            }
        }

        private void BindIntelliVibeDataToFormElements()
        {

            if (!(_lastFlightData.IntellivibeData.IsEndFlight || _lastFlightData.IntellivibeData.IsPaused)) // do something only if in game (frozen is considered in game)
            {



                // Vinf
                double vinf = _lastFlightData.vt * 0.3048; // m/s

                checkBox_SimActive.Checked = true;

                if (!_stopWatch.IsRunning)
                {
                    _stopWatch.Start();
                }


                // Is firing Gun
                //textBox1.Text = _lastFlightData.IntellivibeData.IsFiringGun.ToString();

                Vinf = vinf;


                FireGun();
                ComputeUVW_dot();
                RunwayRun();
                //SpeedBrake();
                HighAlpha();
                Ejecting();
                ReleaseBombMissile();
                ReleaseChaffFlare();
                LandingGear();

                // AoA shall go with speed?
                // 

                textBoxMotON.Text = Convert.ToString(MotOn, 2).PadLeft(6, '0');
                textBoxMotRPM.Text = MotPow.FormatDecimal(decimalPlaces: 1);
                textBoxAx.Text = Udot.FormatDecimal(decimalPlaces: 4);
                textBoxAy.Text = Vdot.FormatDecimal(decimalPlaces: 4);
                textBoxAz.Text = Wdot.FormatDecimal(decimalPlaces: 4);

                textBoxDt.Text = DeltaT.ToString();
                textBoxT.Text  = _stopWatch.ElapsedMilliseconds.ToString();



                // Gets last damage (possibly to compare with previous?)
                //_lastFlightData.IntellivibeData.lastdamage.ToString();

                SendSerialData();




            }
            else
            {
                if (checkBox_SimActive.Checked == true)
                    {
                    stopMotors();
                }
                checkBox_SimActive.Checked = false;
                listBoxCOM.Enabled = true;

                if (isEjected== true ) 
                    {
                    isEjected = false;
                }
                
                

            }
        }

        private void ComputeUVW_dot()
        {

            long deltat = 0;
            // Reads xyzdot and computes uvw and uvwdot
            double udot = 0;
            double vdot = 0;
            double wdot = 0;
            double u = 0;
            double v = 0;
            double w = 0;

            // AoA AoS Gamma Val
            double aoa = _lastFlightData.alpha * Math.PI / 180;
            double aos = _lastFlightData.beta * Math.PI / 180;
            double gamma = _lastFlightData.gamma * Math.PI / 180;

            // xyz dot
            double xdot = _lastFlightData.xDot;
            double ydot = _lastFlightData.yDot;
            double zdot = _lastFlightData.zDot;

            double phi = _lastFlightData.roll * Math.PI / 180;
            double theta = _lastFlightData.pitch * Math.PI / 180;
            double psi = _lastFlightData.yaw * Math.PI / 180;



            deltat = _stopWatch.ElapsedMilliseconds-OldT;


            if (deltat<2)
            { 
                deltat = 2; // Prevents small delta ts
            }

            OldT = _stopWatch.ElapsedMilliseconds;
            // NED to Body velocity components.
            u = Math.Cos(psi) * Math.Cos(theta) * xdot + Math.Sin(psi) * Math.Cos(theta) * ydot - Math.Sin(theta) * zdot;

            v = (-Math.Sin(psi) * Math.Cos(phi) * +Math.Cos(psi) * Math.Sin(theta) * Math.Sin(phi)) * xdot + (Math.Cos(psi) * Math.Cos(phi) + Math.Sin(phi) * Math.Sin(psi) * Math.Sin(theta)) * ydot + Math.Cos(theta) * Math.Sin(phi) * zdot;

            w = (Math.Sin(psi) * Math.Sin(phi) + Math.Cos(psi) * Math.Cos(phi) * Math.Sin(theta)) * xdot + (Math.Sin(theta) * Math.Sin(psi) * Math.Cos(phi) - Math.Cos(psi) * Math.Sin(phi)) * ydot + Math.Cos(theta) * Math.Cos(phi) * zdot;

            

            // Wind to Body

            u = Vinf * Math.Cos(aoa) * Math.Cos(aos);
            v = Vinf * Math.Sin(aos);
            w = Vinf * Math.Sin(aoa) * Math.Cos(aos);

            udot = ( u - Uold ) / deltat;
            vdot = ( v - Vold ) / deltat;
            wdot = ( w - Wold ) / deltat;


            if (vdot > 0.005)
            {
                MotPow = Math.Max(MotPow, Linear(vdot, 0.005, 0.05, 0, 100));
                MotOn |= 0b_00101010;
                //textBoxEvent.Text = Convert.ToString(MotOn, 2);
                textBoxEvent.AppendText("v lat" + Environment.NewLine);
            }
            if (vdot < -0.005)
            {
                MotPow = Math.Max(MotPow, Linear(vdot, -0.05, -0.005, 100, 0));
                MotOn |= 0b_00010101;
                //textBoxEvent.Text = Convert.ToString(MotOn, 2);
                textBoxEvent.AppendText("v lat" + Environment.NewLine);
            }

            Uold = u;
            Vold = v;
            Wold = w;

            Udot = udot;
            Vdot = vdot;
            Wdot = wdot;

            AoA = aoa;

            DeltaT = deltat;
           


        }

        private void RunwayRun()
        {
            
            if (_lastFlightData.IntellivibeData.IsOnGround )
            {
                // Linear interp motor and keep max vib value
                MotPow = Math.Max( MotPow, Linear(Vinf, 30, 100, 0, 100) );
                MotOn |= 0b_00111100;
            }
        }

        private void FireGun()
        {
            if (_lastFlightData.IntellivibeData.IsFiringGun)
            {
                // Linear interp motor and keep max vib value
                MotPow = Math.Max(MotPow, 80 );
                MotOn |= 0b_00000011;
                //textBoxEvent.Text = Convert.ToString(MotOn, 2);
                textBoxEvent.AppendText("GUN" + Environment.NewLine);
            }
        }


        private void ReleaseBombMissile()
        {
            if ( ( _lastFlightData.IntellivibeData.BombDropped + _lastFlightData.IntellivibeData.AAMissileFired + _lastFlightData.IntellivibeData.AGMissileFired) > OrdenanceReleased )
            {
                consT = _stopWatch.ElapsedMilliseconds;  // Clears the consolidation Time watch
                OrdenanceReleased = (_lastFlightData.IntellivibeData.BombDropped + _lastFlightData.IntellivibeData.AAMissileFired + _lastFlightData.IntellivibeData.AGMissileFired);
                // Linear interp motor and keep max vib value
                MotPow = Math.Max(MotPow, 60);
                MotOn |= 0b_00000011;
                //textBoxEvent.Text = Convert.ToString(MotOn, 2);
                textBoxEvent.AppendText("BOMB MISSILE" + Environment.NewLine);
            }
            
            if ( (_stopWatch.ElapsedMilliseconds) - consT <100) // Maintain the effect of this instantaneous event in time
            {
                MotPow = Math.Max(MotPow, 60);
                MotOn |= 0b_00000011;
                //textBoxEvent.Text = Convert.ToString(MotOn, 2);
                textBoxEvent.AppendText("BOMB MISSILE" + Environment.NewLine);
            }
        }

        private void ReleaseChaffFlare()
        {
            if ((_lastFlightData.IntellivibeData.FlareDropped + _lastFlightData.IntellivibeData.ChaffDropped ) > ChaffFlareReleased)
            {
                consT1 = _stopWatch.ElapsedMilliseconds;  // Clears the consolidation Time watch
                ChaffFlareReleased = (_lastFlightData.IntellivibeData.FlareDropped + _lastFlightData.IntellivibeData.ChaffDropped);
                // Linear interp motor and keep max vib value
                MotPow = Math.Max(MotPow, 40);
                MotOn |= 0b_00000011;
                //textBoxEvent.Text = Convert.ToString(MotOn, 2);
                textBoxEvent.AppendText("CHAFF FLARE" + Environment.NewLine);
            }
            if ((_stopWatch.ElapsedMilliseconds) - consT1 < 75) // Maintain the effect of this instantaneous event in time
            {
                MotPow = Math.Max(MotPow, 40);
                MotOn |= 0b_00000011;
                //textBoxEvent.Text = Convert.ToString(MotOn, 2);
                textBoxEvent.AppendText("CHAFF FLARE" + Environment.NewLine);
            }
        }

        private void LandingGear()
        {
            if ((_lastFlightData.gearPos != 0) && (_lastFlightData.gearPos != 1) )
            {
                double vinf = Linear(Vinf, 30, 150, 0, 1);
                MotPow = Math.Max(MotPow, Linear(vinf, 0, 1, 30, 40));
                MotOn |= 0b_0011_1100;

                textBoxEvent.AppendText("LANDING GEAR" + Environment.NewLine);
            }
        }
        private void SpeedBrake()
        {
            if ( _lastFlightData.speedBrake > 0)
            {
                double vinf = Linear(Vinf, 30, 400, 0, 1);
                MotPow = Math.Max( MotPow, Linear(vinf* _lastFlightData.speedBrake , 0, 1, 25, 35) );
                MotOn |= 0b_0000_0011;

                textBoxEvent.AppendText("BRAKES" + Environment.NewLine);
            }
        }

        private void HighAlpha()
        {
            if (_lastFlightData.alpha > 12)
            {
                
                MotPow = Math.Max(MotPow, Linear(_lastFlightData.alpha , 12, 16, 0, 50));
                MotOn |= 0b_00111111;

                textBoxEvent.AppendText("AoA" + Environment.NewLine);
            }
        }



        private void Ejecting()
        {
            if ( (_lastFlightData.IntellivibeData.IsEjecting) && (isEjected == false) )
            {
                consT2 = _stopWatch.ElapsedMilliseconds;  // Clears the consolidation Time watch
                isEjected = true;
                
            }

            if ( ((_stopWatch.ElapsedMilliseconds) - consT2 < 4000) && (isEjected) ) // Maintain the effect of this instantaneous event in time
            {
                // Linear interp motor and as velocity decreases
                MotPow = Math.Max(MotPow, Linear((_stopWatch.ElapsedMilliseconds) - consT2, 2000, 4000, 100, 20));
                MotOn |= 0b_00111111;
                
                textBoxEvent.AppendText("EJECTING" + Environment.NewLine);
            }
        }


        private void stopMotors()
        {
            // This simple function sends the command to the motors to stop
            // and changes the flag of MotRun to false.

            ArduinoPort.Write("`"); // Zeroes the motors
            ArduinoPort.Write(Convert.ToString(0)); // Zeroes the speed 
            ArduinoPort.Write(Convert.ToString("\n")); // Terminates the Arduino command
            MotRun = false;
        }

        private void parseSerial(byte[] byteMot)
        {
            MotRun = true;
            //textBoxEvent.AppendText(Convert.ToString(Math.Round(MotPow * 2.55)) + Environment.NewLine);
            //ArduinoPort.Write("a" + textMot + Environment.NewLine);
            ArduinoPort.Write(byteMot, 0, 1);
            ArduinoPort.Write(Convert.ToString("\n")); // Terminates the Arduino command
        }

        private void SendSerialData()
        {
            byte[] byteMot = new byte[] { Convert.ToByte(Math.Round(MotPow * 2.55)) }; // Writes the byte

            switch (MotOn)
            {
                case 0b_0000000:
                    if (MotRun)
                    {
                        stopMotors();
                        return;
                    }
                    break;

                case 0b_0000001:

                    ArduinoPort.Write("a");
                    //textBoxEvent.AppendText(Convert.ToString(Math.Round(MotPow * 2.55)) + Environment.NewLine);
                    parseSerial(byteMot);
                    
                    break;

                case 0b_000010:
                    
                    ArduinoPort.Write("b");
                    parseSerial(byteMot);
                    break;

                case 0b_000100:
                    ArduinoPort.Write("c");
                    parseSerial(byteMot);
                    break;

                case 0b_001000:
                    ArduinoPort.Write("d");
                    parseSerial(byteMot);
                    break;

                case 0b_010000:
                    ArduinoPort.Write("c"); // Connected to the same Arduno Motor 
                    parseSerial(byteMot);
                    break;

                case 0b_100000:
                    ArduinoPort.Write("d"); // Connected on the same Arduino Motor controller (MotorX)
                    parseSerial(byteMot);
                    break;

                case 0b_000011:
                    ArduinoPort.Write("g");
                    parseSerial(byteMot);
                    break;

                case 0b_001100:
                    ArduinoPort.Write("h");
                    parseSerial(byteMot);
                    break;

                case 0b_110000:
                    ArduinoPort.Write("h"); // // Connected on the same Arduino Motor controller (MotorX)
                    parseSerial(byteMot);
                    break;

                case 0b_010101: 
                    ArduinoPort.Write("k");
                    parseSerial(byteMot);
                    break;

                case 0b_101010:
                    ArduinoPort.Write("i");
                    parseSerial(byteMot);
                    break;

                case 0b_001111:
                    ArduinoPort.Write("l");
                    parseSerial(byteMot);
                    break;

                case 0b_111100:
                    ArduinoPort.Write("m");
                    parseSerial(byteMot);
                    break;

                case 0b_111111:
                    ArduinoPort.Write("l");
                    parseSerial(byteMot);
                    break;
            }

            

            
            
        }



        static public double Linear(double x, double x0, double x1, double y0, double y1)
        {
            // Linear with clamped extrap
            if ((x1 - x0) == 0)
            {
                return (y0 + y1) / 2;
            }
            if (x <= x0)
            {
                return y0;
            }
            if (x >= x1)
            {
                return y1;
            }

            return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private string AutodetectArduinoPort()
        {
            Boolean isFound = false;
            string deviceString = "";
            ManagementScope connectionScope = new ManagementScope();
            SelectQuery serialQuery = new SelectQuery("SELECT * FROM Win32_SerialPort");
            ManagementObjectSearcher searcher = new ManagementObjectSearcher(connectionScope, serialQuery);

            
            
            
            try
            {
                foreach (ManagementObject item in searcher.Get())
                {
                    string desc = item["Description"].ToString();
                    string deviceId = item["DeviceID"].ToString();

                    if (desc.Contains("Arduino"))
                    {
                        isFound = true;
                        deviceString = deviceString + deviceId + Environment.NewLine;
                    }
                }
                if (isFound)
                {
                    return deviceString;
                }
            }
            catch (ManagementException e)
            {
                /* Do Nothing */
            }

            return null;
        }

        private string AutodetectArduinoDevice()
        {
            // Function which cycles on the available COM ports and populates the listBoxCOM
            Boolean isFound = false;
            string deviceString = "";
            ManagementScope connectionScope = new ManagementScope();
            SelectQuery serialQuery = new SelectQuery("SELECT * FROM Win32_SerialPort");
            ManagementObjectSearcher searcher = new ManagementObjectSearcher(connectionScope, serialQuery);

            


            try
            {
                foreach (ManagementObject item in searcher.Get())
                {
                    string desc = item["Description"].ToString();
                    string deviceId = item["DeviceID"].ToString();

                   
                    if (desc.Contains("Arduino"))
                    {
                        isFound = true;
                        listBoxCOM.Items.Add(deviceId + " " + desc); // deviceString = deviceString + deviceId + " " + desc + Environment.NewLine;
                    }
                    else
                    {
                        listBoxCOM.Items.Add(deviceId + " " + desc); //listBoxCOM.Items.Add(deviceId);
                    }
                    
                    if (deviceId.Equals(Properties.Settings.Default.comport))
                    {
                        
                        // In case the User Saved Preference matches with an item of the listobx, it is Selected
                        listBoxCOM.SelectedIndex = listBoxCOM.FindString(Properties.Settings.Default.comport);

                    }
                    

                }

                
                if (listBoxCOM.FindString(Properties.Settings.Default.comport)<0)
                {
                    MessageBox.Show("The saved port: " + Properties.Settings.Default.comport + "could not be found. Please revise the connection or the port selected.", "User selected COM port not found", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                if (isFound)
                {
                    //Eventually bold the line (to be implemented)
                }
            }
            catch (ManagementException e)
            {
                /* Do Nothing */
                

            }
            
            return null;
        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void listBoxCOM_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            // Get the currently selected item in the ListBox.
            string curItem = listBoxCOM.SelectedItem.ToString();
            int index = listBoxCOM.FindString(curItem);

            

            // Extract the COM PORT
            var output = curItem.Substring(0, curItem.IndexOf(" "));
            //MessageBox.Show(output);

            // Saves to the preferences
            Properties.Settings.Default.comport = output;
            Properties.Settings.Default.Save();
            isCom = true;
            
            // if ArduinoPort is open, it closes
            if (ArduinoPort.IsOpen) ArduinoPort.Close();
            
            ArduinoPort.PortName = output;

            
        }

        private void label10_Click(object sender, EventArgs e)
        {

        }
    }


    

}