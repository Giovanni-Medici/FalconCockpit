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

namespace VibrationMotors
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.checkBox_SimActive = new System.Windows.Forms.CheckBox();
            this.textBoxEvent = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxMotON = new System.Windows.Forms.TextBox();
            this.textBoxMotRPM = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.textBoxAx = new System.Windows.Forms.TextBox();
            this.textBoxAy = new System.Windows.Forms.TextBox();
            this.textBoxAz = new System.Windows.Forms.TextBox();
            this.textBoxDt = new System.Windows.Forms.TextBox();
            this.textBoxT = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.listBoxCOM = new System.Windows.Forms.ListBox();
            this.label10 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 122);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Simulation Active";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // checkBox_SimActive
            // 
            this.checkBox_SimActive.AutoSize = true;
            this.checkBox_SimActive.Location = new System.Drawing.Point(103, 121);
            this.checkBox_SimActive.Name = "checkBox_SimActive";
            this.checkBox_SimActive.Size = new System.Drawing.Size(15, 14);
            this.checkBox_SimActive.TabIndex = 2;
            this.checkBox_SimActive.UseVisualStyleBackColor = true;
            // 
            // textBoxEvent
            // 
            this.textBoxEvent.Location = new System.Drawing.Point(13, 184);
            this.textBoxEvent.Multiline = true;
            this.textBoxEvent.Name = "textBoxEvent";
            this.textBoxEvent.ReadOnly = true;
            this.textBoxEvent.Size = new System.Drawing.Size(233, 67);
            this.textBoxEvent.TabIndex = 3;
            this.textBoxEvent.BackColor = System.Drawing.SystemColors.Window;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 167);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(57, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Event List:";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 144);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Motors Status:";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // textBoxMotON
            // 
            this.textBoxMotON.Location = new System.Drawing.Point(94, 141);
            this.textBoxMotON.Name = "textBoxMotON";
            this.textBoxMotON.ReadOnly = true;
            this.textBoxMotON.Size = new System.Drawing.Size(85, 20);
            this.textBoxMotON.TabIndex = 6;
            this.textBoxMotON.Text = "0";
            this.textBoxMotON.BackColor = System.Drawing.SystemColors.Window;

            // 
            // textBoxMotRPM
            // 
            this.textBoxMotRPM.Location = new System.Drawing.Point(185, 141);
            this.textBoxMotRPM.Name = "textBoxMotRPM";
            this.textBoxMotRPM.ReadOnly = true;
            this.textBoxMotRPM.Size = new System.Drawing.Size(64, 20);
            this.textBoxMotRPM.TabIndex = 7;
            this.textBoxMotRPM.Text = "0";
            this.textBoxMotRPM.BackColor = System.Drawing.SystemColors.Window;

            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(276, 147);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(21, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "ax:";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(276, 168);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(21, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "ay:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(276, 189);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(21, 13);
            this.label6.TabIndex = 10;
            this.label6.Text = "az:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(278, 210);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(19, 13);
            this.label7.TabIndex = 11;
            this.label7.Text = "dt:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(284, 231);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(13, 13);
            this.label8.TabIndex = 12;
            this.label8.Text = "t:";
            // 
            // textBoxAx
            // 
            this.textBoxAx.Location = new System.Drawing.Point(303, 144);
            this.textBoxAx.Name = "textBoxAx";
            this.textBoxAx.ReadOnly = true;
            this.textBoxAx.Size = new System.Drawing.Size(53, 20);
            this.textBoxAx.TabIndex = 13;
            this.textBoxAx.Text = "0";
            this.textBoxAx.BackColor = System.Drawing.SystemColors.Window;
            // 
            // textBoxAy
            // 
            this.textBoxAy.Location = new System.Drawing.Point(303, 165);
            this.textBoxAy.Name = "textBoxAy";
            this.textBoxAy.ReadOnly = true;
            this.textBoxAy.Size = new System.Drawing.Size(53, 20);
            this.textBoxAy.TabIndex = 14;
            this.textBoxAy.Text = "0";
            this.textBoxAy.BackColor = System.Drawing.SystemColors.Window;

            // 
            // textBoxAz
            // 
            this.textBoxAz.Location = new System.Drawing.Point(303, 186);
            this.textBoxAz.Name = "textBoxAz";
            this.textBoxAz.ReadOnly = true;
            this.textBoxAz.Size = new System.Drawing.Size(53, 20);
            this.textBoxAz.TabIndex = 15;
            this.textBoxAz.Text = "0";
            this.textBoxAz.BackColor = System.Drawing.SystemColors.Window;

            // 
            // textBoxDt
            // 
            this.textBoxDt.Location = new System.Drawing.Point(303, 207);
            this.textBoxDt.Name = "textBoxDt";
            this.textBoxDt.ReadOnly = true;
            this.textBoxDt.Size = new System.Drawing.Size(53, 20);
            this.textBoxDt.TabIndex = 16;
            this.textBoxDt.Text = "0";
            this.textBoxDt.BackColor = System.Drawing.SystemColors.Window;

            // 
            // textBoxT
            // 
            this.textBoxT.Location = new System.Drawing.Point(303, 228);
            this.textBoxT.Name = "textBoxT";
            this.textBoxT.ReadOnly = true;
            this.textBoxT.Size = new System.Drawing.Size(53, 20);
            this.textBoxT.TabIndex = 17;
            this.textBoxT.Text = "0";
            this.textBoxT.BackColor = System.Drawing.SystemColors.Window;

            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(12, 9);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(83, 13);
            this.label9.TabIndex = 19;
            this.label9.Text = "Select Com Port";
            this.label9.Click += new System.EventHandler(this.label9_Click);
            // 
            // listBoxCOM
            // 
            this.listBoxCOM.FormattingEnabled = true;
            this.listBoxCOM.Location = new System.Drawing.Point(97, 9);
            this.listBoxCOM.Name = "listBoxCOM";
            this.listBoxCOM.Size = new System.Drawing.Size(259, 69);
            this.listBoxCOM.TabIndex = 20;
            this.listBoxCOM.SelectedIndexChanged += new System.EventHandler(this.listBoxCOM_SelectedIndexChanged);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(262, 256);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(110, 13);
            this.label10.TabIndex = 21;
            this.label10.Text = "Giovanni Medici 2020";
            this.label10.Click += new System.EventHandler(this.label10_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(377, 270);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.listBoxCOM);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.textBoxT);
            this.Controls.Add(this.textBoxDt);
            this.Controls.Add(this.textBoxAz);
            this.Controls.Add(this.textBoxAy);
            this.Controls.Add(this.textBoxAx);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBoxMotRPM);
            this.Controls.Add(this.textBoxMotON);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxEvent);
            this.Controls.Add(this.checkBox_SimActive);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "Vibration Motors";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox checkBox_SimActive;
        private System.Windows.Forms.TextBox textBoxEvent;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxMotON;
        private System.Windows.Forms.TextBox textBoxMotRPM;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox textBoxAx;
        private System.Windows.Forms.TextBox textBoxAy;
        private System.Windows.Forms.TextBox textBoxAz;
        private System.Windows.Forms.TextBox textBoxDt;
        private System.Windows.Forms.TextBox textBoxT;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ListBox listBoxCOM;
        private System.Windows.Forms.Label label10;
    }
}

