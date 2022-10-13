# Remote Power Outage Detection & Alert System
This github repository and project outlines the usage of an Arduino Based ESP8266 WiFi and Bluetooth Module along with a WaveShare SIM7000E NB-Iot / Cat-M / EDGE / GPRS Module in creating an alert system for a remote site power outage.

---

## Versions
- [V0.1a](#v01a)
- [V0.2a](#v02a) - Current Version
---

## Background
During the summer in outback queensland, temperatures can exceed 50°C. ALong with the high temperatures weather can be rather sporadic, with suden flash flooding and lightning storms. This can cause havoc with the electricity network with unplanned outages. A lot of properties in outback queensland are far from any town and getting notified of a power outage is incredibly rare. In order to avoid rotten food in both fridges and freezers I wanted to create a device that could notify me of a power outage so that I could take appropriate action to save, or at least salvage, food and perishables at these remote locations.

## Initial Drawing of Idea
Simply put we needed a system that could detect the power outage which then alerted some form of microcontroller to then send an alert to myself to notify/warn of the power outage. In order to actually do this, in the case of a power outage, this system would need to be battery operated so that it could continue after power was removed from the site.

![Block Diagram of Project](Images/Block%20Diagram.png)

# V0.1a
This version used the below components to detect and alert of a power outage.

- [WaveShare SIM7000E][def]
    - *Only LTE Capable module available in australia at time of purchase*
- [ESP8266 WiFi Board - XC3082][def2]
    - *Small Footprint, Cheap cost and easy to access. Uses the arduino library and IDE for ease of programming and debugging*
- [XC4502][def4] paired with an [XC4512][def5], a cheap and small footprint LiPo charger and 5v boost module.
- 10k - 10k voltage divider with a 5v Wall Plug into the analog pin of the ESP8266
- Telstra Cat-M SIM Card

## What went well?
- Proof of concept for sending an SMS on an external trigger (analog pin falling below a certain threshold)
- Footprint of prototype, could all be contained within a small jiffy type container.

## ~~Bugs~~ "Features" and what had to be improved on:
- Source of heat in the winter - The XC4502 and the XC4512 cannot be used simutaneously. Loading the battery caused the charger module to think that the battery needed charging and therefore pumped in more voltage causing parts to overheat.
- The useage of the 10k - 10k voltage divider was to ensure that the voltage going into the analog pin didn't exceed the maximum voltage. However, connecting the external 5v and the 5v boost module's ground together caused some strange behavoiur on the analog to digital convertion in code.
- The price of maintaining a cellular capable SIM was extortionate when considering the usage of this device would probably be a couple times a month during summer or rather 4-6 months of the year.

# V0.2a
This version included a multitude of updates making the system more relieable and user friendly, including a WebUI for configuring and customizing the alerts to be sent. The detection system also had an overhaul and the charging functionality was completely removed.

The code was changed to incorporate the deep sleep functionality of the ESP Family.

One additional part was added in this version - [LiteOn 4N25 Optocoupler][def7]. This allowed the 5v Wall Adapter to be compeltely seperated and isolated from the ESP and Modem.

With testing complete a pcb prototype of this version was made - KiCAD Project Files can be found under this [folder][def8].

## What went well



## What needs improved on

Psuedo code or flow chart was as follows.
![Flow Chart of V0.2a](Images/V0.2a%20Flow%20Chart.jpg)

Parts used in this project & Why they were chosen:
- [WaveShare SIM7000E][def]
    - *Only LTE Capable module available in australia at time of purchase*
- [ESP8266 WiFi Board - XC3082][def2]
    - *Small Footprint, Cheap cost and easy to access. Uses the arduino library and IDE for ease of programming and debugging*
- [IP5306][def3] based mobile charge/boost module for LiPo Battery, found on ebay.
    - *Allows both boost and charge simutaneously. Other modules that were proposed were:*
        - [XC4502][def4] paired with an [XC4512][def5], however this combination did not allow both boosting the voltage to 5v and charging of a LiPo Battery
        - Removing the charge capability of the unit altogether. Using a voltage divider to check the voltage of the battery periodically and send an alert if battery needed changing/charging.
        - [DFR0446][def6] this was more than suitable and from a reputable source, however footprint was too large and not easily solder wires to.

[def]: https://www.waveshare.com/sim7000e-nb-iot-hat.htm
[def2]: https://www.jaycar.com.au/wifi-mini-esp8266-main-board/p/XC3802
[def3]: https://www.kynix.com/editor_u/pdf/20220117/IP5306.pdf
[def4]: https://www.jaycar.com.au/arduino-compatible-lithium-battery-usb-charger-module/p/XC4502
[def5]: https://www.jaycar.com.au/arduino-compatible-5v-dc-to-dc-converter-module/p/XC4512
[def6]: https://www.dfrobot.com/product-1613.html
[def7]: https://au.mouser.com/datasheet/2/239/775704_1-1175530.pdf
[def8]: https://github.com/Chuffs/RemotePowerMonitor/tree/main/v0.2a/v0.2a