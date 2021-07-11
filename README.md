# AsyncUDP_WT32_ETH01


[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_WT32_ETH01.svg?)](https://www.ardu-badge.com/AsyncUDP_WT32_ETH01)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncUDP_WT32_ETH01.svg)](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncUDP_WT32_ETH01.svg)](http://github.com/khoih-prog/AsyncUDP_WT32_ETH01/issues)

---
---

## Table of Contents


* [Why do we need this AsyncUDP_WT32_ETH01 library](#why-do-we-need-this-asyncudp_wt32_eth01-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](#changelog)
  * [Initial Releases v2.0.0](#initial-releases-v200)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Libraries' Patches](#libraries-patches)
  * [1. For fixing ESP32 compile error](#1-for-fixing-esp32-compile-error)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [HOWTO Setting up the Async UDP Client](#howto-setting-up-the-async-udp-client)
* [Examples](#examples)
  * [ 1. AsyncUDPClient](examples/AsyncUDPClient)
  * [ 2. AsyncUdpNTPClient](examples/AsyncUdpNTPClient)
  * [ 3. AsyncUdpSendReceive](examples/AsyncUdpSendReceive)
  * [ 4. AsyncUDPServer](examples/AsyncUDPServer)
  * [ 5. AsyncUDPMulticastServer](examples/AsyncUDPMulticastServer)
* [Example AsyncUdpNTPClient](#example-asyncudpntpclient)
  * [File AsyncUdpNTPClient.ino](#file-asyncudpntpclientino)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. AsyncUdpNTPClient on on ESP32_DEV with ETH_PHY_LAN8720](#1-asyncudpntpclient-on-esp32_dev-with-eth_phy_lan8720)
  * [2. AsyncUDPSendReceive on on ESP32_DEV with ETH_PHY_LAN8720](#2-asyncudpsendreceive-on-esp32_dev-with-eth_phy_lan8720)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [AsyncUDP_WT32_ETH01 library](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01)

#### Features

This [AsyncUDP_WT32_ETH01 library](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01) is a fully asynchronous UDP library, designed for a trouble-free, multi-connection network environment, for WT32_ETH01 (ESP32 + LAN8720 Ethernet). The library is easy to use and includes support for Unicast, Broadcast and Multicast environments.

This library is based on, modified from:

1. [Hristo Gochkov's AsyncUDP](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP)

to apply the better and faster **asynchronous** feature of the **powerful** [AsyncUDP](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP) into WT32_ETH01.


#### Why Async is better

- Using asynchronous network means that you can handle **more than one connection at the same time**
- You are called once the request is ready and parsed
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- After connecting to a UDP server as an Async Client, you are **immediately ready** to handle other connections while the Client is taking care of receiving the UDP responding packets in the background.
- You are not required to check in a tight loop() the arrival of the UDP responding packets to process them.


#### Currently supported Boards

1. **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet

---
---

## Changelog


### Initial Releases v2.0.0

1. Initial coding to port [AsyncUDP](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP) to WT32_ETH01 (ESP32 + LAN8720)
2. Add more examples.
3. Add debugging features.
4. Bump up to v2.0.0 to sync with [AsyncUDP v2.0.0](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP).


---
---

## Prerequisites

 1. [`Arduino IDE 1.8.15+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`ESP32 Core 1.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `AsyncUDP_WT32_ETH01`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_WT32_ETH01.svg?)](https://www.ardu-badge.com/AsyncUDP_WT32_ETH01) for more detailed instructions.

### Manual Install

1. Navigate to [AsyncUDP_WT32_ETH01](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01) page.
2. Download the latest release `AsyncUDP_WT32_ETH01-master.zip`.
3. Extract the zip file to `AsyncUDP_WT32_ETH01-master` directory 
4. Copy the whole `AsyncUDP_WT32_ETH01-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AsyncUDP_WT32_ETH01** library](https://platformio.org/lib/show/12542/AsyncUDP_WT32_ETH01) by using [Library Manager](https://platformio.org/lib/show/12542/AsyncUDP_WT32_ETH01/installation). Search for AsyncUDP_WT32_ETH01 in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---


### Libraries' Patches

#### 1. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.15/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)


---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).


---
---

## HOWTO Setting up the Async UDP Client

```cpp
#define ASYNC_UDP_WT32_ETH01_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_WT32_ETH01_LOGLEVEL_      1

#include <AsyncUDP_WT32_ETH01.h>

/////////////////////////////////////////////

// Select the IP address according to your local network
IPAddress myIP(192, 168, 2, 232);
IPAddress myGW(192, 168, 2, 1);
IPAddress mySN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

/////////////////////////////////////////////

#include <time.h>

//IPAddress timeServerIP = IPAddress(168,  61, 215, 74);   // time.windows.com
IPAddress timeServerIP = IPAddress(132, 163,  96,  1);   // time.nist.gov

#define NTP_REQUEST_PORT      123

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
AsyncUDP Udp;

// send an NTP request to the time server at the given address
void createNTPpacket(void)
{
  ...
}

void sendNTPPacket(void)
{
  createNTPpacket();
  //Send unicast
  Udp.write(packetBuffer, sizeof(packetBuffer));
}

void parsePacket(AsyncUDPPacket packet)
{
  ...
}

void setup()
{
  ...
  
  //NTP requests are to port NTP_REQUEST_PORT = 123
  if (Udp.connect(timeServerIP, NTP_REQUEST_PORT))
  {
    // Setting up Async packet Handler
    Udp.onPacket([](AsyncUDPPacket packet)
    {
      parsePacket(packet);
    });
  }
}

void loop()
{
  sendNTPPacket();

  // wait 60 seconds before asking for the time again
  delay(60000);
}
```

---
---

### Examples

 1. [AsyncUDPClient](examples/AsyncUDPClient)
 2. [AsyncUdpNTPClient](examples/AsyncUdpNTPClient)
 3. [AsyncUdpSendReceive](examples/AsyncUdpSendReceive) 
 4. [AsyncUDPServer](examples/AsyncUDPServer)
 5. [AsyncUDPMulticastServer](examples/AsyncUDPMulticastServer)

---

### Example [AsyncUdpNTPClient](examples/AsyncUdpNTPClient)

#### File [AsyncUdpNTPClient.ino](examples/AsyncUdpNTPClient/AsyncUdpNTPClient.ino)


```cpp
#define ASYNC_UDP_WT32_ETH01_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_WT32_ETH01_LOGLEVEL_      1

#include <AsyncUDP_WT32_ETH01.h>

/////////////////////////////////////////////

// Select the IP address according to your local network
IPAddress myIP(192, 168, 2, 232);
IPAddress myGW(192, 168, 2, 1);
IPAddress mySN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

/////////////////////////////////////////////

#include <time.h>

//IPAddress timeServerIP = IPAddress(168,  61, 215, 74);   // time.windows.com
IPAddress timeServerIP = IPAddress(132, 163,  96,  1);   // time.nist.gov

#define NTP_REQUEST_PORT      123

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
AsyncUDP Udp;

// send an NTP request to the time server at the given address
void createNTPpacket(void)
{
  Serial.println("============= createNTPpacket =============");

  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0]   = 0b11100011;   // LI, Version, Mode
  packetBuffer[1]   = 0;     // Stratum, or type of clock
  packetBuffer[2]   = 6;     // Polling Interval
  packetBuffer[3]   = 0xEC;  // Peer Clock Precision
  
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
}

void parsePacket(AsyncUDPPacket packet)
{
  struct tm  ts;
  char       buf[80];
  
  memcpy(packetBuffer, packet.data(), sizeof(packetBuffer));

  Serial.print("Received UDP Packet Type: ");
  Serial.println(packet.isBroadcast() ? "Broadcast" : packet.isMulticast() ? "Multicast" : "Unicast");
  Serial.print("From: ");
  Serial.print(packet.remoteIP());
  Serial.print(":");
  Serial.print(packet.remotePort());
  Serial.print(", To: ");
  Serial.print(packet.localIP());
  Serial.print(":");
  Serial.print(packet.localPort());
  Serial.print(", Length: ");
  Serial.print(packet.length());
  Serial.println();

  unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
  unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);

  // combine the four bytes (two words) into a long integer
  // this is NTP time (seconds since Jan 1 1900):
  unsigned long secsSince1900 = highWord << 16 | lowWord;
  
  Serial.print(F("Seconds since Jan 1 1900 = "));
  Serial.println(secsSince1900);

  // now convert NTP time into )everyday time:
  Serial.print(F("Epoch/Unix time = "));
  
  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  const unsigned long seventyYears = 2208988800UL;
  
  // subtract seventy years:
  unsigned long epoch = secsSince1900 - seventyYears;
  time_t epoch_t = epoch;   //secsSince1900 - seventyYears;
 
  // print Unix time:
  Serial.println(epoch);

  // print the hour, minute and second:
  Serial.print(F("The UTC/GMT time is "));       // UTC is the time at Greenwich Meridian (GMT)

  ts = *localtime(&epoch_t);
  strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
  Serial.println(buf);
}

void sendNTPPacket(void)
{
  createNTPpacket();
  //Send unicast
  Udp.write(packetBuffer, sizeof(packetBuffer));
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStarting AsyncUdpNTPClient on " + String(ARDUINO_BOARD));
  Serial.println(" with " + String(SHIELD_TYPE));
  Serial.println(WEBSERVER_WT32_ETH01_VERSION);
  Serial.println(ASYNC_UDP_WT32_ETH01_VERSION);

  Serial.setDebugOutput(true);

  //bool begin(uint8_t phy_addr=ETH_PHY_ADDR, int power=ETH_PHY_POWER, int mdc=ETH_PHY_MDC, int mdio=ETH_PHY_MDIO,
  //           eth_phy_type_t type=ETH_PHY_TYPE, eth_clock_mode_t clk_mode=ETH_CLK_MODE);
  //ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER, ETH_PHY_MDC, ETH_PHY_MDIO, ETH_PHY_TYPE, ETH_CLK_MODE);
  ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);

  // Static IP, leave without this line to get IP via DHCP
  //bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = 0, IPAddress dns2 = 0);
  ETH.config(myIP, myGW, mySN, myDNS);

  WiFi.onEvent(WT32_ETH01_Event);

  while (!eth_connected)
    delay(100);

  // Client address
  Serial.print("AsyncUdpNTPClient started @ IP address: ");
  Serial.println(ETH.localIP());

  //NTP requests are to port NTP_REQUEST_PORT = 123
  if (Udp.connect(timeServerIP, NTP_REQUEST_PORT))
  {
    Serial.println("UDP connected");

    Udp.onPacket([](AsyncUDPPacket packet)
    {
      parsePacket(packet);
    });
  }
}

void loop()
{
  sendNTPPacket();

  // wait 60 seconds before asking for the time again
  delay(60000);
}
```

---

### Debug Terminal Output Samples

#### 1. AsyncUdpNTPClient on ESP32_DEV with ETH_PHY_LAN8720

This is terminal debug output when running [AsyncUdpNTPClient](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/tree/main/examples/AsyncUdpNTPClient) on  **WT32_ETH01 (ESP32 + LAN8720)**. It connects to NTP Server using AsyncUDP_WT32_ETH01 library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.

##### Connect to NTP server time.windows.com (IP=168.61.215.74)

```
Starting AsyncUdpNTPClient on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.1.0
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232, FULL_DUPLEX, 100Mbps
AsyncUdpNTPClient started @ IP address: 192.168.2.232
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 168.61.215.74:123, To: 192.168.2.232:58455, Length: 48
Seconds since Jan 1 1900 = 3834962406
Epoch/Unix time = 1625973606
The UTC/GMT time is Sun 2021-07-11 03:20:06 GMT
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 168.61.215.74:123, To: 192.168.2.232:58455, Length: 48
Seconds since Jan 1 1900 = 3834962466
Epoch/Unix time = 1625973666
The UTC/GMT time is Sun 2021-07-11 03:21:06 GMT
```

##### Connect to NTP server time.nist.gov (IP=132.163.96.1)

```
Starting AsyncUdpNTPClient on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.1.0
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232, FULL_DUPLEX, 100Mbps
AsyncUdpNTPClient started @ IP address: 192.168.2.232
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 132.163.96.1:123, To: 192.168.2.232:49209, Length: 48
Seconds since Jan 1 1900 = 3834962553
Epoch/Unix time = 1625973753
The UTC/GMT time is Sun 2021-07-11 03:22:33 GMT
```

---

#### 2. AsyncUDPSendReceive on ESP32_DEV with ETH_PHY_LAN8720

This is terminal debug output when running [AsyncUDPSendReceive](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/tree/main/examples/AsyncUdpSendReceive) on **WT32_ETH01 (ESP32 + LAN8720)**. It connects to NTP Server `time.nist.gov` (IP=132.163.96.1) using AsyncUDP_WT32_ETH01 library, and requests NTP time every 60s. The packet is **received and processed asynchronously** to print current UTC/GMT time. The ACK packet is then sent.

```
Starting AsyncUDPSendReceive on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.1.0
AsyncUdp_WT32_ETH01 v2.0.0
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232, FULL_DUPLEX, 100Mbps
AsyncUDPSendReceive started @ IP address: 192.168.2.232

Starting connection to server...
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 132.163.96.1:123, To: 192.168.2.232:62775, Length: 48
Seconds since Jan 1 1900 = 3834968497
Epoch/Unix time = 1625979697
The UTC/GMT time is Sun 2021-07-11 05:01:37 GMT
============= sendACKPacket =============
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 132.163.96.1:123, To: 192.168.2.232:62775, Length: 48
Seconds since Jan 1 1900 = 3834968557
Epoch/Unix time = 1625979757
The UTC/GMT time is Sun 2021-07-11 05:02:37 GMT
============= sendACKPacket =============
```

---
---

### Debug

Debug is enabled by default on Serial. To disable, use level 0

```cpp
#define ASYNC_UDP_WT32_ETH01_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_WT32_ETH01_LOGLEVEL_      1
```

You can also change the debugging level from 0 to 4

```cpp
#define ASYNC_UDP_WT32_ETH01_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_WT32_ETH01_LOGLEVEL_      4
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of Arduino IDE, the Arduino `STM32` core or depending libraries.

Sometimes, the library will only work if you update the `STM32` core to the latest version because I am always using the latest cores /libraries.

---
---

## Releases


### Initial Releases v2.0.0

1. Initial coding to port [AsyncUDP](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP) to WT32_ETH01 (ESP32 + LAN8720)
2. Add more examples.
3. Add debugging features.
4. Bump up to v2.0.0 to sync with [AsyncUDP v2.0.0](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP).

---

#### Supported Boards

 1. **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet


---
---

### Issues ###

Submit issues to: [AsyncUDP_WT32_ETH01 issues](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/issues)

---

## TO DO

 1. Fix bug. Add enhancement


## DONE

 1. Initial port to to WT32_ETH01 (ESP32 + LAN8720)
 2. Add more examples.
 3. Add debugging features.

---
---

### Contributions and Thanks

1. Based on and modified from [Hristo Gochkov's AsyncUDP](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP). Many thanks to [Hristo Gochkov](https://github.com/me-no-dev) for great [AsyncUDP Library]((https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP))


<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br /><sub><b>⭐️⭐️ Hristo Gochkov</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)

---

## Copyright

Copyright 2018- Hristo Gochkov

Copyright 2021- Khoi Hoang


