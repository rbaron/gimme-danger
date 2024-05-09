![logo](./media/logo.jpg)

An open source [USB Power Delivery](https://en.wikipedia.org/wiki/USB_hardware#USB_Power_Delivery) trigger board and 5-channel PWM controller that runs [ESPHome](https://esphome.io).

_GIMME DANGER!!_ negotiates up to 21 V and 3 A[^1] from a USB Power Delivery (USB-PD) capable source -- such as wall adapters and power banks -- and provides control for its 5 PWM channels. Each channel can be used to interface with LEDs, fans, motors and more. See below for some demos.

# Hardware
![PCB front](./media/gimme-danger-front.jpg)
* [ESP32-S3](https://www.espressif.com/en/products/socs/esp32-s3) module, mounted on the [back of the PCB](./media/gimme-danger-back.jpg)
* [FUSB302B](https://www.onsemi.com/products/interfaces/usb-type-c/fusb302b) USB-PD controller
* [INA219](https://www.ti.com/product/INA219) current sensor
* 5 output PWM channels
* 2x5.5mm barrel jack for raw VBUS output
* Optional OLED display

The [`kicad/`](./kicad/) directory contains design files and fabrication files for [JLCPCB](https://jlcpcb.com) manufacturing and assembly. The big through-hole components (headers, power terminals) and the ESP32-S3 module are not included in the assembly, and expected to be soldered by hand.

# Software
A custom `fusb302` component was implemented in ESPHome to support this project. It currently lives in its own fork on [github.com/rbaron/tree/fusb302](https://github.com/rbaron/esphome/tree/fusb302).

Configs for the demos below and more are available in the [`code/`](./code) directory.

# Some use cases & demos
## 12V LED strip
Here we can see _GIMME DANGER!!_ connected to [Home Assistant](https://www.home-assistant.io) and controlling a 12V LED strip.
[![12V LED Strip](https://img.youtube.com/vi/a7QtX55lgi8/maxres1.jpg)](https://youtu.be/a7QtX55lgi8)

## 12V RGBW LED strip
[![RGBW LED Strip](https://img.youtube.com/vi/ThnvIa4zbsM/maxres1.jpg)](https://youtu.be/ThnvIa4zbsM)

## A simple programmable power supply
We can also negotiate voltages on the fly from USB-PD 3.0 sources that offer . Here we have a potentiometer that sets the target voltage, and a button that triggers the USB-PD negotiation for that voltage.

[![Power Supply](https://img.youtube.com/vi/3Acu_VfSuck/maxres1.jpg)](https://youtu.be/3Acu_VfSuck)

# A Home Assistant controlled power supply
As a display of the flexibility of ESPHome and Home Assistant, we can use _GIMME DANGER!!_ to make a WiFi-controlled power supply. This is probably a terrible idea,  but kind of neat.
[![Home Assistant Power Supply](https://img.youtube.com/vi/tXYciUaycYI/maxres1.jpg)](https://youtu.be/tXYciUaycYI)

# Optional OLED display
There are female pin headers on the board to connect an 0.91" OLED display like [this one from Aliexpress](https://aliexpress.com/item/1005004816561244.html). It's used to display the current voltage and current. There's also a cute animation when negotiation is succesfull -- you can see it in the demos above.

# 3D printed case
The [`case/`](./case) directory contains a very simply 3D printable case for _GIMME DANGER!!_. It's designed to be printed in two parts and assembled with 3 M2 screws and threaded inserts.

# License
The hardware and associated design files are released under the [Creative Commons CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/) license. The code is released under the [MIT license](https://opensource.org/licenses/MIT).


[^1]: FUSB302B's typical max bus voltage is 21 V, with 28 V abosolute maximum. Each PWM channel is rated for 3 A. In theory the board supports up to 5 A, but has only been tested for 3 A in total so far.