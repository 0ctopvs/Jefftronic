# My Hobby Code Projects

Greetings\! In this repository, I'm sharing some code projects I've created in my free time. My intention is that they might be useful for other enthusiasts and developers. Any feedback is welcome\!

## Repository Contents:

### 1. Custom IR Controller RM-SCEX1 for M5StickC PLUS2 / ESP32
<img src="https://github.com/0ctopvs/Jefftronic/blob/main/IR%20Controller%20RM-SCEX1%20-%20M5StickC%20PLUS2%20ESP3/image.png?raw=true" width="200">
This project consists of an infrared remote control designed primarily for the M5StickC PLUS2, although it can be adapted to other ESP32 boards that have a screen. The visual interface on the ESP32 screen allows you to explore the different functions of the control and execute the sending of the corresponding IR signal.

**Why this project?** The main motivation arose from the difficulty in finding and the high cost of the original RM-SCEX1 remote control for certain sound equipment, such as the CMT-EX1. This solution allows the use of LIRC codes available online to emulate its functions.

**Usage Instructions:**

* **Navigation:** The side buttons allow you to move through the options displayed on the screen.
* **Send Signal:** To send the IR signal of the selected option, simply press the center button.
* **Turn Off:** Press and hold the power button for 4 seconds. You will notice that the screen continues to navigate, but the device will turn off upon completion of the cycle.
* **Turn On:** To turn on the device, press and hold the power button for 3 seconds.
* **Hardware Requirements:** This project takes advantage of the infrared transmitter integrated into the M5StickC PLUS2, so you don't need to add any additional modules.

I hope you find it useful\!
