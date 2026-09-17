# Ultrasonic Parking Sensor

A reverse-parking style distance sensor built with an Arduino-compatible board, an HC-SR04 ultrasonic sensor, and a three-color LED display — written in modern, object-free procedural C++ using the PlatformIO toolchain.

As an object gets closer to the sensor, the system switches between three status LEDs (green → yellow → red) to give an immediate, at-a-glance distance warning, the same way a car's reverse parking sensors work.

## Features

- Real-time distance measurement via ultrasonic echo timing
- Three-zone visual alert system (safe / caution / danger)
- Graceful handling of out-of-range / no-echo readings (treated as "clear," not garbage data)
- Live distance readout over Serial for debugging and monitoring
- Built and managed with PlatformIO — reproducible builds, dependency management, and clean project structure instead of the classic Arduino IDE sketch workflow

## Hardware Used

| Component | Purpose |
|---|---|
| Arduino Uno (or ATmega328P-compatible clone) | Microcontroller |
| HC-SR04 ultrasonic sensor | Distance measurement |
| 3x LED (green, yellow, red) | Visual distance-zone indicator |
| 3x current-limiting resistor | Protects LEDs from excess current |
| Breadboard + jumper wires | Circuit assembly |

## Wiring

| Component | Arduino Pin |
|---|---|
| HC-SR04 — VCC | 5V |
| HC-SR04 — GND | GND |
| HC-SR04 — Trig | D9 |
| HC-SR04 — Echo | D10 |
| Green LED (+ resistor) | D5 |
| Yellow LED (+ resistor) | D6 |
| Red LED (+ resistor) | D7 |

All LED cathodes share a single common ground connection back to the Arduino, rather than requiring a dedicated GND pin per component.

## Distance Zones

| Zone | Distance | LED |
|---|---|---|
| Safe | > 50 cm | 🟢 Green |
| Caution | 20–50 cm | 🟡 Yellow |
| Danger | < 20 cm | 🔴 Red |
| No object detected | out of sensor range | 🟢 Green (treated as clear) |

## Getting Started

### Prerequisites

- [VS Code](https://code.visualstudio.com/)
- [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode)

### Build & Upload

```bash
git clone https://github.com/xXxAlock2024xXx/parking-sensor.git
cd parking-sensor
```

1. Open the folder in VS Code
2. Wait for PlatformIO to finish loading the project
3. Connect the Arduino via USB
4. Click **Build** (✓) then **Upload** (→) in the PlatformIO toolbar
5. Open the **Serial Monitor** to view live distance readings (9600 baud)

## How It Works

The HC-SR04 measures distance by timing a sound pulse:

1. A 10-microsecond HIGH pulse on the `Trig` pin fires an ultrasonic "chirp"
2. The sensor holds its `Echo` pin HIGH for exactly as long as the sound took to bounce back
3. `distance = (echo duration) × speed of sound ÷ 2` (divided by 2 since the sound travels to the object and back)

A timeout is applied to `pulseIn()` so that when no object is in range (and no echo returns), the system doesn't hang or report noisy, unreliable readings — it explicitly falls back to a "clear" state instead.

The resulting distance is then compared against two thresholds to decide which single LED should be lit, functioning as a simple three-state alert system.

## Possible Improvements

- Add a buzzer (driven through a transistor) for an audible alert that beeps faster as distance decreases, matching real parking sensor behavior
- Replace blocking `delay()` calls with a `millis()`-based timer for non-blocking timing
- Refactor into small C++ classes (`UltrasonicSensor`, `AlertSystem`) for cleaner separation of concerns
- Add a rolling average / median filter across multiple readings to further smooth out sensor noise

## License
MIT