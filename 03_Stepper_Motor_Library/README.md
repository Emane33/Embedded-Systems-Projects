# Custom Stepper Motor Library

This project encapsulates the development of a from-scratch, professional-grade Arduino/PlatformIO library for controlling 28BYJ-48 stepper motors with ULN2003 driver boards. The library has been published to the PlatformIO registry for public use.

## 🚀 Project Overview

The goal was to move beyond writing simple sketches and create a reusable, well-documented software component that demonstrates industry-standard practices in embedded software development.

## 📁 Project Structure

```
03_Stepper_Motor_Library/
├── lib/
│   └── CustomStepper/          # The source code of the library
│       ├── src/
│       │   ├── CustomStepper.cpp
│       │   └── CustomStepper.h
│       ├── examples/
│       │   └── BasicUsage/
│       │       └── src/
│       │           └── main.cpp
│       ├── library.json        # PlatformIO package metadata
│       ├── LICENSE             # MIT License
│       └── README.md           # Library documentation
└── README.md                   # This file
```

## 🛠️ Skills Demonstrated

- **Object-Oriented Programming (OOP):** Designed a clean C++ class interface for the motor.
- **Library Architecture:** Structured the code into header (.h) and implementation (.cpp) files.
- **PlatformIO Packaging:** Created a `library.json` manifest file for dependency management.
- **Version Control:** Used semantic versioning (1.0.0, 1.0.1) for library updates.
- **Publication Process:** Published the library to the PlatformIO registry using the `pio pkg publish` command.
- **Documentation:** Wrote comprehensive READMEs and examples for end-users.

## ✨ Library Features

- **Absolute Positioning:** Move to a specific step count or angle.
- **Speed Control:** Set the motor's speed in Revolutions Per Minute (RPM).
- **Power Management:** `enable()`/`disable()` functions to reduce power consumption and heat.
- **Sweep Function:** Automatically move the motor back and forth between two angles.

## 📦 Installation & Usage

The library is available on the PlatformIO registry. To use it in a project, run:

```bash
pio pkg install --library "emane33/CustomStepper"
```

See the [library's own README][(./lib/CustomStepper/README.md)]for detailed usage instructions and examples.

## 🔗 Links

- [PlatformIO Registry Listing](https://registry.platformio.org/libraries/emane33/CustomStepper)
- [GitHub Repository][(https://github.com/Emane33/CustomStepper)]
