# Backstory
We had a few days of wet and heavy snow and that caused power to flicker on and off for various lenghts of time.
Power did not go out for long (from few seconds to few hours), but it did go out fairly often.
Every morning when I would wake up I would have to go reset the WiFiRouter to get network connectivity back (after previous nights power outage).

# Problem
What was happening was that the cable modem and the WiFi router get power at the same time and the router asks for an IP before the modem is fully ready, so it receives a temporary one.
The problem is that the temporary IP is never renewed, so the WiFi router is left without internet conectivity.
Or at least this is my theory, I don't really know why this would happen... But I thought I can solve it anyway, good reason to build something :-)

# Solution
I realized that if I can delay the cable modem from powering on utill the WiFi router is fully started, that would avoid the two devices getting in the bad state.
So my plan was to have a a device that simply waits a specified amount of time before giving power to the cable modem.

# BOM (2019)
* Controllable Power Relay - Adafruit has one for [24$](https://www.adafruit.com/product/2935)
* ATTiny85 - Ebay has them for about [9$/5 pcs](https://www.ebay.com/itm/5-PCS-ATTINY85-20PU-ATTINY85-MCU-8BIT-8KB-MICROCONTROLLER-SHIPPED-FROM-USA/282315166074?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649)
* Socket - Ebay has them for about [3$/20 pcs](https://www.ebay.com/itm/20Pcs-8Pin-Dip-20-Ic-Socket-Double-In-Line-Integrated-Circuit-Solder-Type/163040422083?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649)
* Power Source - I simply broke down a power adapter with 5V output, and built a 3D printed case for it.
  Another great idea from a friend would be to use something like [IRM-05-5](https://www.mouser.com/productdetail/mean-well/irm-05-5?qs=WkdRfq4wf1OdYoHS8Am9VA%3D%3D). Which is smaller and simple to use (it just has 4 pins AC IN and 5V DC out).
* Some Wires - I had some in my parts drawer, so I don't know where to buy this. In general I tend to keep all kinds of wires and cables that I come across so I very rarely have to buy wire.

# Electrical circuit
![Electrical Diagram](https://raw.githubusercontent.com/RazMake/PowerDelayDevice/master/Circuit.png "Power Delay Electrical Diagram")

# Code
The code is trivial. Full code [here](https://github.com/RazMake/PowerDelayDevice/blob/master/PowerDelay.ino?raw=true).
The ideea is to use the PB4 pin (pin 3) on the ATTiny to trigger the relay, but delay a specific amount of miliseconds before doing that.

# Case
In order to protect agains accientaly touching the high voltage contacts, I have also created and 3D printed a case.

# Endresult
![Device](https://raw.githubusercontent.com/RazMake/PowerDelayDevice/master/Photos/image007.jpg =500x400)


## _Disclaimer_
_I'm not claiming this is the best implementation for what I was trying to obtain, I am not even claiming that the solution itself is the best given the problem.  
This is something that worked for me, it was easy enough and quick enough to solve my problem._