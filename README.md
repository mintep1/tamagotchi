# Arduino Tamagotchi
Tamagotchi for a basic LED arduino project

# Components
* 1x 1kΩ resistor
* 3x 10kΩ resistor
* 3x 220 Ω resistor
* 3x LEDs
* 3x Push Button
* 1x 2x16 LCD Screen
* Arduino Uno R3 SMD
* 2x Breadboard
* 23x Wires

# CAD & Hookup
| Wire Colour | Pinned To |
|---|---|
| Red | Power
| Black | Ground
| Orange | RS and Enable LCD pins
| Green | D4-D7 LCD pins
| Yellow | Button right terminal
| Blue | LED anodes |

| Resistance (Ω) | Connection |
|---|---|
| 220 | LED Anode → Digital Pin wire
| 1k | VO LCD pin → GND
| 10k | Left terminal of each button → GND 

![tamagotchi-cad](https://github.com/mintep1/tamagotchi/assets/121994642/68609acd-5d6e-48a4-97df-254f401c4ad2)
