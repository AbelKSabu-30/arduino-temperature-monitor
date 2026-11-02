# Microcontroller-Based Temperature Monitoring and Alarm System

An Arduino Uno-based temperature monitoring system that uses a DHT11 sensor to measure temperature and humidity. When the measured temperature exceeds a predefined threshold, an LED and buzzer provide visual and audible alerts.

## Features

- Real-time temperature monitoring
- Humidity monitoring
- Configurable temperature threshold
- LED-based visual warning
- Buzzer-based audible warning
- Serial Monitor output

## Components Required

- Arduino Uno
- DHT11 temperature and humidity sensor
- LED
- Active buzzer
- 220 Ω resistor
- Breadboard
- Jumper wires
- USB cable or 5V USB power adapter

## Circuit Connections

| Component | Arduino Pin |
|---|---|
| DHT11 VCC (+) | 5V |
| DHT11 OUT | D2 |
| DHT11 GND (-) | GND |
| LED | D8 |
| Buzzer (+) | D9 |
| Buzzer (-) | GND |

The LED is connected through a 220 Ω resistor.

## Working Principle

1. The DHT11 sensor measures temperature and humidity.
2. The Arduino reads the sensor values.
3. The temperature is compared with a predefined threshold.
4. If the temperature exceeds the threshold, the LED turns ON and the buzzer sounds.
5. Otherwise, both remain OFF.

## Software Requirements

- Arduino IDE
- Adafruit DHT sensor library
- Adafruit Unified Sensor library

## Configuration

The default temperature threshold is 26°C.

It can be changed in the Arduino code:

`#define TEMP_THRESHOLD 26.0`

## Future Improvements

- LCD or OLED display integration
- Wireless temperature monitoring
- Data logging
- Improved temperature sensor accuracy

## Disclaimer

This is an educational prototype and is not intended to replace certified fire detection or industrial safety systems.
