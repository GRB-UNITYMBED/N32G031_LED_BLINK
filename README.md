# N32G031_LED_BLINK — GPIO Hello World

![Blink](doc/images/blink.png)

An introductory project designed to teach basic GPIO (General Purpose Input/Output) control using the **N32G031** microcontroller. This "Hello World" of hardware serves as an excellent foundational learning tool for beginners and students to understand digital outputs, basic circuit wiring, and timing functions. This project is fully optimized for cross-platform workflows using UnityMbed.

---

## Wiring

| Component | Pin | N32G031 | Notes |
| :--- | :---: | :---: | :--- |
| **LED Cathode** | 🖤 Short Leg | **GND** | Connected via the negative rail (Black wire) |
| **LED Anode** | ❤️ Long Leg | **PA1** | Connected via a resistor (Red wire to control signal) |

---

## Behaviour & Execution

Once powered on and flashed with the code, the microcontroller will execute the following loop continuously:
1. Set PA1 to **HIGH** (LED turns ON).
2. Hold this state for **1 second** (1000 ms).
3. Set PA1 to **LOW** (LED turns OFF).
4. Hold this state for **1 second** (1000 ms), then restart the cycle.

---

## Hardware Setup & Troubleshooting

* **LED Polarity:** LEDs only allow current to flow in one direction. Ensure the longer leg (Anode) connects to the signal pin (PA1) and the shorter leg (Cathode) connects to Ground (GND).
* **Use a Resistor:** Always use a current-limiting resistor (e.g., 220Ω or 330Ω) in series with the LED. Connecting an LED directly to the signal pin without a resistor can draw excessive current and damage the LED or the microcontroller.

---

## Learning & AI Extension Ideas

* **Digital Outputs:** Understand the concepts of HIGH (ON) and LOW (OFF) states in digital electronics.
* **The Speed Challenge:** Encourage students to modify the delay times inside the code.
  * What happens if they change the delay to `100` milliseconds? Does it look like a strobe light?
  * What happens if the ON time is `100` but the OFF time is `2000`?
* **Heartbeat Effect:** Can they write a sequence of delays to make the LED blink like a human heartbeat (ba-bum... ba-bum...)?

---

## Build and Flash (Universal Cross-Platform)
1. **Open Project:** Open this project folder directly in the IDE.
2. **Build & Flash:** Simply click the **Build** and **Flash** buttons on the interface.

---
Part of the [UnityMbed](https://github.com/GRB-UNITYMBED) N32G031 example set.
