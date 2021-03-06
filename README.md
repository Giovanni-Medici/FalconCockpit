# READ ME

This repository contains a bunch of scripts in various scripting languages, that I've been developing during the years for my home cockpit.

## License
<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a>.
## Overview

Most of the projects are related to the development of an home cockpit for an F-16, the only exception is an arduino project I did for an autopilot of a CRJ-200.

### [Vibration Motors] (https://github.com/Giovanni-Medici/FalconCockpit)

This project relies on an Arduino Leonardo and Arduino Motor Shield and the great [lighting viper libs](https://github.com/lightningviper/lightningstools), to interface, through a C# windows application, Falcon 4 BMS, and a seat with 6 vibration motors. ]More info here] (giovannimedici.wordpress.com/2020/11/21/vibration-motors-seat/)

### [Standalone USB adapter for TM Cougar Throttle] (giovannimedici.wordpress.com/2020/08/28/standalone-usb-adapter-for-tm-cougar-throttle/)

In this project taking as reference [Uriba's post](https://pit.uriba.org/uriba/standalone-cougar-tqs-part-i/), I created a standalone adapter for the Thrustmaster Hotas Cougar Throttle, taking advantage of a Teensy 4.1. [More info here](giovannimedici.wordpress.com/2020/08/28/standalone-usb-adapter-for-tm-cougar-throttle/)

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
pip install foobar
```

## Usage

```python
import foobar

foobar.pluralize('word') # returns 'words'
foobar.pluralize('goose') # returns 'geese'
foobar.singularize('phenomena') # returns 'phenomenon'
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)