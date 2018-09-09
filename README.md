# binary_clock
Binary clock with RTC ds323 for arduino

## SETUP

First install the DS3231 library. If you use a different version than I have, then just replace the mn and hr functions with the equivalent library calls from the one you are using to get the current hour and minutes in decimal (DEC) format.

* Connect 10 led pins to Arduino digital 4-13. Pins 4 - 9 are minute pins, pins 10 - 13 are hour pins.
* Connect the power and ground on the RTC module.
* Connect SDA on the RTC to SDA on the Arduino (Uno A4)
* Connect SCL on the RTC to SCL on the Arduino (Uno A5)
* Set the time on the RTC module (currently not implemented)

After those steps, the leds should light up, representing in binary the current time in HHHH:MMMMM format.
For example, 11.22am is 0111:010110 (with 1 representing a lit led).
