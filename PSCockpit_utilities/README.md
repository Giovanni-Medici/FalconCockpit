# READ ME

This folder contains a few gerber files for utility PCB that can be very handy for your home cockpit. You can read a lot more details in my [blog](https://giovannimedici.wordpress.com).

## License
<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a>.
## Overview

There are currently several PCB available:


### [Interrupt PCB](https://giovannimedici.wordpress.com/2021/11/04/mainboard-wiring-update/)

This PCB provides a convenient scheme to merge your interrupts signals for the psCockpit MainBoard PCB. There are 8 daisy chain channels in the mainboard, each has the option to carry an Interrupt signal. But on the mainboard there are actually only 4 connections available ( I understand that it will sort of handle only four master channels). This board lets you merge channel 0 to 1, 2 to 3, 4 to 5, and finally 6 to 7. [More info here](https://giovannimedici.wordpress.com/2021/11/04/mainboard-wiring-update/)

### [Connection multiplier PCB](https://giovannimedici.wordpress.com/2022/04/03/rewiring-the-power-supply/)

This PCB simply shortcuts 9 signals (it comes in two pairs). It can be used to multiply either 5V common GND. The PCB has the standard 2.54 mm (0.1 in) pitch. [More info here](https://giovannimedici.wordpress.com/2022/04/03/rewiring-the-power-supply/)

### [Two inputs 555 Timer delay](https://giovannimedici.wordpress.com/2021/10/02/miscellaneous-panel-update/)

This small PCB contains a 555 timer delay circuit so as to make the digital signal to the solenoids last longer. The board takes advantage of two 555 IC, and a couple of NPN transitors (to invert the digital signal coming from the psfalcon software, which is normally low, while the 555 trigger expect a normally high signal). Once it receives a signal it holds it longer (the timespan depends on the RC setup you will chose). The PCB is basically an hardware "HOLD" signal. It is useful when you need a bit more of consolidation time for your circuits.  [More info here](https://giovannimedici.wordpress.com/2021/10/02/miscellaneous-panel-update/)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

