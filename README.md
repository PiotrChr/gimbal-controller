# Gimbal Robot Controller (rg-controller)

## Overview

This repository hosts the firmware and documentation for a 2-axis gimbal controller designed for robotic applications. The gimbal controller is engineered to interface with NEMA 17 stepper motors, providing precise control over movement. It is an ideal solution for projects requiring stabilized motion or pointing capabilities. The controller integrates a range of features including LED indicators, an OLED display for status reporting, mode toggling for speed and precision, and programmable action buttons.

## Features

- **Microcontroller:** Powered by ESP32, offering robust performance and connectivity options.
- **Motion Control:** Supports 2-axis control compatible with robotic gimbals or pointers, utilizing NEMA 17 stepper motors for reliable operation.
- **User Interface:**
  - **LED Indicators:** Two LEDs to visually indicate the system's current mode (Idle or Active).
  - **OLED Display:** Provides real-time status updates and system information.
  - **Mode Toggle Button:** Allows switching between Precise and Fast movement modes.
  - **Action Buttons:** Two programmable buttons for custom operations.
- **Programming:**
  - Movement can be programmed using a language akin to GCODE, facilitating complex motion patterns and control strategies.
  - The language definition is available in the repository ([LANGDEF.md](./LANGDEF.md)) for detailed syntax and command information.
- **External Control Pad:** Code and documentation for an optional control pad are available, enhancing operational flexibility ([Gimbal Controller Pad](https://github.com/PiotrChr/gimbal-controller-pad)).

## Getting Started

To get started with the Gimbal Controller project, ensure you have an ESP32 microcontroller along with the required NEMA 17 stepper motors and peripheral components. Follow the steps below to setup your environment:

1. Clone this repository to your local machine.
2. Install the necessary development tools and libraries for the ESP32 platform.
3. Follow the wiring instructions provided in the documentation to connect the stepper motors, LED diodes, OLED display, and buttons to the ESP32.
4. Flash the firmware onto the ESP32 using the provided scripts.
5. For additional control capabilities, clone and setup the [Gimbal Controller Pad](https://github.com/PiotrChr/gimbal-controller-pad) repository.

## Usage

- **Mode Selection:** Use the toggle button on the controller to switch between Precise and Fast modes, catering to different operational requirements.
- **Programming Movements:** Refer to [LANGDEF.md](./LANGDEF.md) for instructions on programming movements using the custom GCODE-like language.
- **LED Indicators:** Monitor the LED indicators for the controller's state (Idle or Active).
- **OLED Display:** Keep an eye on the OLED display for real-time status and alerts.

## Contributing

Contributions to the rg-controller are welcome. Please refer to the CONTRIBUTING.md file for guidelines on how to contribute. Whether you're fixing a bug, adding a new feature, or improving the documentation, your help is appreciated.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements

- Special thanks to the ESP32 community for their comprehensive resources and support.
- Gratitude to contributors of the Gimbal Controller Pad project for extending the capabilities of this project.

