# AsyncUDP_WT32_ETH01


[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_WT32_ETH01.svg?)](https://www.ardu-badge.com/AsyncUDP_WT32_ETH01)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncUDP_WT32_ETH01.svg)](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncUDP_WT32_ETH01.svg)](http://github.com/khoih-prog/AsyncUDP_WT32_ETH01/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents

* [Important Change from v2.1.0](#Important-Change-from-v210)
* [Why do we need this AsyncUDP_WT32_ETH01 library](#why-do-we-need-this-asyncudp_wt32_eth01-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Libraries' Patches](#libraries-patches)
  * [1. For fixing ESP32 compile error](#1-for-fixing-esp32-compile-error)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error) 
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
  * [ 6. **multiFileProject**](examples/multiFileProject) **New**
* [Example AsyncUdpNTPClient](#example-asyncudpntpclient)
  * [File AsyncUdpNTPClient.ino](#file-asyncudpntpclientino)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. AsyncUdpNTPClient on on ESP32_DEV with ETH_PHY_LAN8720](#1-asyncudpntpclient-on-esp32_dev-with-eth_phy_lan8720)
  * [2. AsyncUDPSendReceive on on ESP32_DEV with ETH_PHY_LAN8720](#2-asyncudpsendreceive-on-esp32_dev-with-eth_phy_lan8720)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)


---
---

### Important Change from v2.1.0

Please have a look at [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)


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


## Prerequisites

 1. [`Arduino IDE 1.8.16+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`ESP32 Core 2.0.3+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 
 3. [`WebServer_WT32_ETH01 library 1.5.0+`](https://github.com/khoih-prog/WebServer_WT32_ETH01). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_WT32_ETH01.svg?)](https://www.ardu-badge.com/WebServer_WT32_ETH01).
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
3. Install [**AsyncUDP_WT32_ETH01** library](https://registry.platformio.org/libraries/AsyncUDP_WT32_ETH01) by using [Library Manager](https://registry.platformio.org/libraries/AsyncUDP_WT32_ETH01/installation). Search for AsyncUDP_WT32_ETH01 in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---


### Libraries' Patches

#### 1. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.15/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)



---
---


### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can include this `.hpp` file

```
// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncUDP_WT32_ETH01.hpp"     //https://github.com/khoih-prog/AsyncUDP_WT32_ETH01
```

in many files. But be sure to use the following `.h` file **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "AsyncUDP_WT32_ETH01.h"       //https://github.com/khoih-prog/AsyncUDP_WT32_ETH01
```

Check the new [**multiFileProject** example](examples/multiFileProject) for a `HOWTO` demo.



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

// 0.ca.pool.ntp.org
IPAddress timeServerIP = IPAddress(208, 81, 1, 244);
// time.nist.gov
//IPAddress timeServerIP = IPAddress(132, 163, 96, 1);

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
 6. [**multiFileProject**](examples/multiFileProject) **New**
---

### Example [AsyncUdpNTPClient](examples/AsyncUdpNTPClient)

#### File [AsyncUdpNTPClient.ino](examples/AsyncUdpNTPClient/AsyncUdpNTPClient.ino)

https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/blob/38f14694c93ca0a393adfeffaee0027924a7e545/examples/AsyncUdpNTPClient/AsyncUdpNTPClient.ino#L11-L175

---

### Debug Terminal Output Samples

#### 1. AsyncUdpNTPClient on ESP32_DEV with ETH_PHY_LAN8720

This is terminal debug output when running [AsyncUdpNTPClient](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/tree/main/examples/AsyncUdpNTPClient) on  **WT32_ETH01 (ESP32 + LAN8720)**. It connects to NTP Server using AsyncUDP_WT32_ETH01 library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.

##### Connect to NTP server time.windows.com (IP=168.61.215.74)

```
Starting AsyncUdpNTPClient on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.0 for core v2.0.0+
AsyncUdp_WT32_ETH01 v2.1.0 for core v2.0.0+
ETH Started
ETH Connected
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.95
FULL_DUPLEX, 100Mbps
AsyncUdpNTPClient started @ IP address: 192.168.2.232
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.232:50549, Length: 48
Seconds since Jan 1 1900 = 3847193050
Epoch/Unix time = 1638204250
The UTC/GMT time is Mon 2021-11-29 16:44:10 GMT
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.232:50549, Length: 48
Seconds since Jan 1 1900 = 3847193110
Epoch/Unix time = 1638204310
The UTC/GMT time is Mon 2021-11-29 16:45:10 GMT
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.232:50549, Length: 48
Seconds since Jan 1 1900 = 3847193170
Epoch/Unix time = 1638204370
The UTC/GMT time is Mon 2021-11-29 16:46:10 GMT

```

##### Connect to NTP server time.nist.gov (IP=132.163.96.1)

```
Starting AsyncUdpNTPClient on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.0 for core v2.0.0+
AsyncUdp_WT32_ETH01 v2.1.0 for core v2.0.0+
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232
FULL_DUPLEX, 100Mbps
AsyncUdpNTPClient started @ IP address: 192.168.2.232
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 132.163.96.1:123, To: 192.168.2.232:50549, Length: 48
Seconds since Jan 1 1900 = 3847193590
Epoch/Unix time = 1638204790
The UTC/GMT time is Mon 2021-11-29 16:53:10 GMT
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 132.163.96.1:123:123, To: 192.168.2.232:50549, Length: 48
Seconds since Jan 1 1900 = 3847193650
Epoch/Unix time = 1638204850
The UTC/GMT time is Mon 2021-11-29 16:54:10 GMT
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 132.163.96.1:123:123, To: 192.168.2.232:50549, Length: 48
Seconds since Jan 1 1900 = 3847193710
Epoch/Unix time = 1638204910
The UTC/GMT time is Mon 2021-11-29 16:55:10 GMT

```

---

#### 2. AsyncUDPSendReceive on ESP32_DEV with ETH_PHY_LAN8720

This is terminal debug output when running [AsyncUDPSendReceive](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/tree/main/examples/AsyncUdpSendReceive) on **WT32_ETH01 (ESP32 + LAN8720)**. It connects to NTP Server `time.nist.gov` (IP=132.163.96.1) using AsyncUDP_WT32_ETH01 library, and requests NTP time every 60s. The packet is **received and processed asynchronously** to print current UTC/GMT time. The ACK packet is then sent.

```
Starting AsyncUDPSendReceive on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.0 for core v2.0.0+
AsyncUdp_WT32_ETH01 v2.1.0 for core v2.0.0+
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232
FULL_DUPLEX, 100Mbps
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


### Issues ###

Submit issues to: [AsyncUDP_WT32_ETH01 issues](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/issues)

---

## TO DO

 1. Fix bug. Add enhancement


## DONE

 1. Initial port to to WT32_ETH01 (ESP32 + LAN8720)
 2. Add more examples.
 3. Add debugging features.
 4. Auto detect ESP32 core to use for WT32_ETH01
 5. Fix bug in WT32_ETH01 examples to reduce connection time
 6. Fix `multiple-definitions` linker error.
 7. Add example [multiFileProject](examples/multiFileProject) to demo for multiple-file project
 
 
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

- The library is licensed under [GPLv3](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/blob/main/LICENSE)

---

## Copyright

Copyright 2018- Hristo Gochkov

Copyright 2021- Khoi Hoang


