/****************************************************************************************************************************
  multiFileProject.ino
  AsyncUDP_WT32_ETH01 is a Async UDP library for the WT32_ETH01 (ESP32 + LAN8720)

  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_WT32_ETH01
  Licensed under MIT license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#include "multiFileProject.h"

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncUDP_WT32_ETH01.h"

void setup() 
{
  Serial.begin(115200);
  while (!Serial);

  delay(500);
  
  Serial.println("\nStart multiFileProject");
  Serial.println(WEBSERVER_WT32_ETH01_VERSION);
  Serial.println(ASYNC_UDP_WT32_ETH01_VERSION);


  Serial.print("You're OK now");
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
