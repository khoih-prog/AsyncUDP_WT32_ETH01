/****************************************************************************************************************************
  AsyncUdp_WT32_ETH01.h
  
  AsyncUDP_WT32_ETH01 is a Async UDP library for the WT32_ETH01 (ESP32 + LAN8720)
  
  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_WT32_ETH01
  Licensed under MIT license
  
  Version: 2.1.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  2.0.0   K Hoang      10/07/2021 Initial coding for WT32_ETH01. Bump up version to v2.0.0 to sync with AsyncUDP v2.0.0
  2.0.1   K Hoang      12/07/2021 Update to use WebServer_WT32_ETH01 v1.2.0
  2.0.2   K Hoang      09/10/2021 Update `platform.ini` and `library.json`
  2.0.3   K Hoang      29/11/2021 Auto detect ESP32 core version. Optimize library code. Fix bug in examples
  2.1.0   K Hoang      21/06/2022 Fix multiple-definitions linker error
 *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_UDP_WT32_ETH01_H
#define ASYNC_UDP_WT32_ETH01_H

////////////////////////////////////////////////

#if ( ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) ) && ( ARDUINO_ESP32_GIT_VER != 0x46d5afb1 ) )
 
  #if (_ASYNC_UDP_WT32_ETH01_LOGLEVEL_ > 2)
    #warning Using code for ESP32 core v2.0.0+ in AsyncUdp_WT32_ETH01.h
  #endif
    
  #define ASYNC_UDP_WT32_ETH01_VERSION      "AsyncUdp_WT32_ETH01 v2.1.0 for core v2.0.0+"
  
  extern "C" 
{
  #include "lwip/ip_addr.h"
  #include "freertos/queue.h"
  #include "freertos/semphr.h"
}
  
#else

  #if (_ASYNC_UDP_WT32_ETH01_LOGLEVEL_ > 2)
    #warning Using code for ESP32 core v1.0.6- in AsyncUdp_WT32_ETH01.h
  #endif
  
  #define ASYNC_UDP_WT32_ETH01_VERSION      "AsyncUdp_WT32_ETH01 v2.1.0 for core v1.0.6-"
  
  extern "C" 
{
  #include "lwip/ip_addr.h"
  #include <tcpip_adapter.h>
  #include "freertos/queue.h"
  #include "freertos/semphr.h"
}
#endif

#include "IPAddress.h"
#include "IPv6Address.h"
#include "Print.h"
#include <functional>

////////////////////////////////////////////////

#include <WebServer_WT32_ETH01.h>     // https://github.com/khoih-prog/WebServer_WT32_ETH01

#include "AsyncUDP_WT32_ETH01_Debug.h"

#include "AsyncUDP_WT32_ETH01.hpp"
#include "AsyncUDP_WT32_ETH01_Impl.h"

////////////////////////////////////////////////

#endif    //ASYNC_UDP_WT32_ETH01_H
