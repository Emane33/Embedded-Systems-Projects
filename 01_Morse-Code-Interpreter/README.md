# Morse Code Interpreter

An embedded systems project that translates text input from the Serial Monitor into Morse code, signaled through an LED. This demonstrates core firmware principles like serial communication, timing, and non-blocking code structure.


## 🚀 Features

- **Serial Input Processing:** Accepts text input via the Arduino Serial Monitor.
- **Morse Code Translation:** Converts alphanumeric characters into their corresponding dots and dashes.
- **Non-blocking Implementation:** Efficiently reads serial data using `Serial.available()` without halting program execution.
- **Extensible Design:** The `playMorse()` function can be easily expanded to include numbers, punctuation, and prosigns.

## 🛠️ Hardware Requirements

| Component | Quantity | Notes |
| :--- | :--- | :--- |
| **Arduino Uno** (or compatible) | 1 | Any AVR-based Arduino will work. |
| **LED** (Optional) | 1 | The built-in LED on pin 13 is used by default. |
| **220Ω Resistor** (Optional) | 1 | Needed if using an external LED. |
| **Breadboard & Jumper Wires** (Optional) | - | For connecting an external LED. |

## 📦 Installation & Usage

### 1. Upload the Firmware
This project is configured for **PlatformIO**. Open it in VSCode with the PlatformIO extension installed and click **Upload**.

**Alternatively, for Arduino IDE:**
- Create a new sketch.
- Copy the contents of `src/main.cpp` into it.
- Ensure the sketch is named `01_Morse-Code-Interpreter.ino` (required by Arduino IDE).
- Select your board and port, then click **Upload**.

### 2. Connect the Hardware (Optional)
If using an external LED:
- Connect the anode (long leg) to **Digital Pin 13** via a 220Ω resistor.
- Connect the cathode (short leg) to **GND**.

### 3. Run the Program
1.  Open the **Serial Monitor** (Tools > Serial Monitor or `Ctrl+Shift+M`).
2.  Set the baud rate to **9600**.
3.  Set the line ending to **"Newline"**.
4.  Type a word (e.g., "SOS") and press **Enter** or click "Send".
5.  Observe the LED blink the message in Morse code.

## 📁 Project Structure

```
01_Morse-Code-Interpreter/
├── src/
│   └── main.cpp          # Main firmware source code
├── schematics/           # (Optional) for Fritzing diagrams or screenshots
├── README.md             # This file
└── platformio.ini        # PlatformIO configuration (if used)
```

## 🔧 Code Overview

The core logic is structured into three main functions:

1.  `morseDot()` / `morseDash()`: Handle the physical blinking of the LED for the fundamental Morse code units.
2.  `playMorse(char character)`: Contains a switch-case statement that maps a single character to its corresponding sequence of dots and dashes.
3.  `loop()`: Implements a non-blocking serial read routine. It appends incoming characters to a `String` variable and flags when a complete message (ending with a newline `\n`) is ready for processing.

## 🚧 Future Enhancements

- [ ] Add support for numbers (`0-9`) and punctuation (`.`, `,`, `?`).
- [ ] Add a buzzer for audible Morse code output.
- [ ] Implement a potentiometer to control the transmission speed (WPM).
- [ ] Create a lookup table for Morse codes to clean up the `playMorse()` function.

## 📜 License

This project is part of my Embedded Systems Portfolio and is licensed under the MIT License. See the main repository LICENSE file for details.
