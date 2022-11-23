# AsyncUDP_WT32_ETH01 Library


[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_WT32_ETH01.svg?)](https://www.ardu-badge.com/AsyncUDP_WT32_ETH01)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncUDP_WT32_ETH01.svg)](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncUDP_WT32_ETH01.svg)](http://github.com/khoih-prog/AsyncUDP_WT32_ETH01/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>
<a href="https://profile-counter.glitch.me/khoih-prog/count.svg" title="Total khoih-prog Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog/count.svg" style="height: 30px;width: 200px;"></a>
<a href="https://profile-counter.glitch.me/khoih-prog-AsyncUDP_WT32_ETH01/count.svg" title="AsyncUDP_WT32_ETH01 Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog-AsyncUDP_WT32_ETH01/count.svg" style="height: 30px;width: 200px;"></a>


---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v2.1.0](#releases-v210)
  * [Releases v2.0.3](#releases-v203)
  * [Releases v2.0.2](#releases-v202)
  * [Releases v2.0.1](#releases-v201)
  * [Initial Releases v2.0.0](#initial-releases-v200)

---
---

## Changelog

#### Releases v2.1.0

1. Fix multiple-definitions linker error. Check [Multiple definitions #1](https://github.com/khoih-prog/AsyncUDP_WT32_ETH01/issues/1)
2. Add example [multiFileProject](examples/multiFileProject) to demo for multiple-file project to avoid `multiple-definitions` linker error

### Releases v2.0.3

##### Warning: Releases v2.0.3+ can be used and autodetect ESP32 core v2.0.0+ or v1.0.6- for WT32_ETH01

1. Auto detect ESP32 core to use for WT32_ETH01
2. Fix bug in WT32_ETH01 examples to reduce connection time
3. Remove library's redundant code


### Releases v2.0.2

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix

### Releases v2.0.1

1. Update to use WebServer_WT32_ETH01 v1.2.0

### Initial Releases v2.0.0

1. Initial coding to port [AsyncUDP](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP) to WT32_ETH01 (ESP32 + LAN8720)
2. Add more examples.
3. Add debugging features.
4. Bump up to v2.0.0 to sync with [AsyncUDP v2.0.0](https://github.com/espressif/arduino-esp32/tree/master/libraries/AsyncUDP).


