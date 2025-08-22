
# Bare-Metal I2C Communication with DS3231 RTC

A deep dive into embedded systems communication, this project demonstrates how to read time and temperature data from a DS3231 Real-Time Clock (RTC) module using **raw I2C protocol** without relying on high-level libraries.

![IMG_4613](https://github.com/user-attachments/assets/acac887b-7597-4668-b460-e42696be05ee)

## 🧠 Concept

Instead of using the convenient `RTClib.h` library, this code implements the I2C communication protocol from the ground up. It directly reads the DS3231's internal registers by following the exact sequence specified in its datasheet, providing a fundamental understanding of how master-slave communication works on the I2C bus.

## ⚙️ How It Works

The project follows the standard I2C protocol for reading a device register:
1.  **Start Condition:** Initiate communication with the DS3231 (slave address `0x68`).
2.  **Register Pointer:** Send the address of the specific register to read (e.g., `0x00` for seconds).
3.  **Repeated Start:** Restart communication to switch from write mode to read mode.
4.  **Read Data:** Request and read the byte(s) of data from the specified register.
5.  **Stop Condition:** End the transmission.

The raw data from the RTC is in **Binary-Coded Decimal (BCD)** format. The code includes a function to convert these BCD values into human-readable decimal numbers.

## 📁 Project Structure

```
02_Bare-Metal-I2C/
├── src/
│   └── main.cpp              # Main firmware source code
├── README.md                 # This file
└── platformio.ini            # PlatformIO configuration
```

## 🔌 Wiring Diagram

| DS3231 Pin | Arduino Pin |
| :--------- | :---------- |
| VCC        | 5V          |
| GND        | GND         |
| SDA        | A4          |
| SCL        | A5          |

*Note: This is the standard I2C wiring for Arduino Uno. Power is provided by the Arduino's 5V pin.*

## 🚀 Usage

1.  Connect the DS3231 module to the Arduino as shown in the wiring diagram.
2.  Upload the code to your Arduino board.
3.  Open the Serial Monitor (baud rate 9600).
4.  Observe the output, which shows the raw byte values and their BCD-converted decimal equivalents for seconds, minutes, hours, and temperature.

## 🔬 Key Features Demonstrated

- **Low-Level I2C Communication:** Using `Wire.beginTransmission()`, `Wire.write()`, `Wire.endTransmission(false)`, and `Wire.requestFrom()`.
- **Register Map Navigation:** Reading specific internal registers of an IC based on its datasheet.
- **BCD to Decimal Conversion:** Converting Binary-Coded Decimal values to standard decimal numbers.
- **Datasheet Analysis:** Translating technical documentation into functional code.

## 📊 Sample Output

```
<img width="682" height="221" alt="image" src="https://github.com/user-attachments/assets/c97b3950-d009-40c1-a730-0ab5db5c9dfd" />

```

*The "Raw" value shows the byte's decimal value, while the converted value shows the actual time digit.*

## 🔧 Code Highlights

The core of the I2C read operation:

```cpp
// Read from a specific register
Wire.beginTransmission(DS3231_I2C_ADDRESS);
Wire.write(REGISTER_ADDRESS);
Wire.endTransmission(false);
Wire.requestFrom(DS3231_I2C_ADDRESS, bytesToRead);
byte data = Wire.read();
```

The BCD conversion algorithm:

```cpp
int decimal_value = (converter->high * 10) + converter->low;
```

## 📚 Resources

- [DS3231 Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/DS3231.pdf) - Official documentation for the RTC module
- [Arduino Wire Library Reference](https://www.arduino.cc/reference/en/language/functions/communication/wire/) - Official documentation for I2C communication

## 🎯 Skills Applied

- Embedded C/C++ Programming
- I2C Protocol Implementation
- Hardware Datasheet Analysis
- Binary Data Manipulation
- Serial Communication Debugging
