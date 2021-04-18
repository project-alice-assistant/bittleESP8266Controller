# bittleESP8266Controller
Developping robotics for Alice to access through skills

## What's Bittle?

Bittle is a robot dog made by Petoi https://www.petoi.com/ that is open source.

## What's the purpose of this for Alice?

To create a protocol for Alice to use, that is hardware agnostic. The robot dog is only the start.

## Who made this

OpenCat.ino is created and maintenained by Petoi: https://github.com/PetoiCamp/OpenCat
We are adding new functions and changing stuff, but the creeator of its base is Petoi

## Licensing

Project Alice usually uses GPLv3 but to respect @PetoiCamp, this repository is MIT licensed

## How to

- Flash the instincts on your robot: https://github.com/PetoiCamp/OpenCat/tree/main/WriteInstinct . For now we haven't developped instincts, so use the originals!
- Flash OpenCat.ino to your robot
- Flash ESP8266WiFiController.ino to your ESP8266 controller
- The ESP8266 controller will create a Wifi Access Point for you to connect to. Connect to the AP and navigate to 192.168.4.1
- The page at 192.168.4.1 lets you configure your ESP8266 to connect to your home wifi.
- Unplug your EESP8266 and connect it to your Bittle
- Turn on your Bittle
- Check on your router to find out the IP adress of your ESP8266
- Navigate to your ESP8266 IP adress
- Enjoy the wireless controlling of your robot!

- In a distant future, download and install the Petoi Skill from Alice's skill store to control your robot