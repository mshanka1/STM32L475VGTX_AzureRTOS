# STM32L4 Discovery kit IoT B-L475E-IOT02A

STM32 is a family of 32-bit microcontroller integrated circuits by STMicroelectronics. Based on ARM® Cortex®-M, STM32 is suitable for low power, real time applications.

The [B-L475E-IOT01A](https://www.st.com/en/evaluation-tools/b-l475e-iot01a.html) (STM32L4 Discovery kit IoT node) allows users to develop applications with direct connection to cloud servers.
The Discovery kit enables a wide diversity of applications by exploiting low-power communication like BLE.
The support for Arduino Uno V3 and PMOD connectivity provides unlimited expansion capabilities with a large choice of specialized add-on boards.

## On board sensors
B-L475E-IOT01A has some ST **MEMS** (Micro Electro-Mechanical Systems) and sensors on board such as:

* 6-axis inertial measurement unit (LSM6DSL)
* 3-axis magnetometer (LIS3MDL)
* Altimeter / pressure sensor (LPS22HH)
* Microphone / audio sensor (MP34DT01)
* Humidity and temperature sensor (HTS221)
* ToF sensor to measure distance up to 2 meters (VL53L0X)

## Added Azure ThreadX RTOS
## Wireless protocols

The board is capable of connecting the device with different wireless protocols such as:

* BLE
* Wi-Fi (Added WiFi Thread)
* NFC (ToDo)
* RF 915MHz (Todo)

**Version 1.0 released on Feb-28-2024
Version 1.1 released on Mar-05-2024**

# Available features:
1. WIFI connectivity with credentials stored in flash
2. If no credentaials in flash, BLE is enabled
3. NetxDuo configured
4. HTTP server created and running
5. BLE enabled to read WiFi ID and WiFi Password
6. Eabled flash feature to store the wifi credentials
7. WIFI mode is still hardcoded
   

Next Steps:
1. Create fully functional WiFi feature
2. Add MQTT feature
3. Add secure transmission
5. Add feature to change the MQTT endpoints
6. Add TFT LCD to check the status of the module
7. Add NFC functionality to read cards
