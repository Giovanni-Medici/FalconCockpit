# READ ME

This repository contains a bunch of scripts in various scripting languages, that I've been developing during the years for my home cockpit. You can read a lot more details in my [blog](https://giovannimedici.wordpress.com).

## License
<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a>.
## Overview

Most of the projects are related to the development of an home cockpit for an F-16, the only exception is an arduino project I did for an autopilot of a CRJ-200.


### [Speedbrake indicator](https://giovannimedici.wordpress.com/2022/04/03/speed-brake-indicator/)

In this project I designed a custom PCB and 3D case to simulate a speedbrake indicator. I relied on a great idea of [Diabolo](http://www.viperpits.org/smf/index.php?topic=10716.msg185798#msg185798), and modified it to be more efficient in terms of pin input needed. The design relies on a PIC12F683 Microchip, to command a stepper driver, which finally moves the stepper X27.168. I used the library originally developed for Arduino as baseline to code the stepper movements. [More info here](giovannimedici.wordpress.com/2022/04/03/speed-brake-indicator/)

### [Vibration Motors](https://github.com/Giovanni-Medici/FalconCockpit/tree/master/VibrationMotors_EjectionSeatHandle)

This project relies on an Arduino Leonardo and Arduino Motor Shield and the great [lighting viper libs](https://github.com/lightningviper/lightningstools), to interface, through a C# windows application, Falcon 4 BMS, and a seat with 6 vibration motors. [More info here](giovannimedici.wordpress.com/2020/11/21/vibration-motors-seat/)

### [Ejection Seat Handle and mechanism](https://github.com/Giovanni-Medici/FalconCockpit/tree/master/VibrationMotors_EjectionSeatHandle)

I added to the Arduino Leonardo, a 3d printed ejection seat handle and its springback mechanism, as the code is pretty straight forward, I simply merged it into the one of the vibration motors. [More info here](giovannimedici.wordpress.com/2021/03/25/ejection-seat-handle-and-mechanism/)

### [Standalone USB adapter for TM Cougar Throttle](https://github.com/Giovanni-Medici/FalconCockpit/tree/master/USBstandaloneCougar)

In this project taking as reference [Uriba's post](https://pit.uriba.org/uriba/standalone-cougar-tqs-part-i/), I created a standalone adapter for the Thrustmaster Hotas Cougar Throttle, taking advantage of a Teensy 4.1. [More info here](giovannimedici.wordpress.com/2020/08/28/standalone-usb-adapter-for-tm-cougar-throttle/)

### [Ch Pro Pedals Gameport to USB adapter](https://github.com/Giovanni-Medici/FalconCockpit/tree/master/CHProPedalsGameport2USB)

In this project I created an arduino interface and board to convert to USB Gameport CH Pro Pedals. [More info here](giovannimedici.wordpress.com/2020/10/11/ch-pro-pedals-gameport-to-usb-adapter/)

### [CRJ-200 Panel](https://github.com/Giovanni-Medici/FalconCockpit/tree/master/CRJ200autopilot)

This arduino project controls a Teensy 2.1++ Board which is interfaced with the buttons, Leds and encoders of the autopilot panel of a CRJ-200 (for x-plane flight simulator). [More info here](giovannimedici.wordpress.com/2013/01/07/crj-200-panel/)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

