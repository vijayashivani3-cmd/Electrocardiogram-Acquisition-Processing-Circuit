# Real-Time ECG Waveform Display on OLED

This project reads **ECG analog signal values** from a sensor, processes them via Arduino, and **plots a real-time ECG waveform** on an SSD1306 OLED display.  
It’s ideal for biomedical signal visualization, hardware testing, and embedded electronics learning.

---

## 🚀 Features
- Reads ECG voltage from an **analog input pin**.
- Maps signal amplitude to OLED pixel height.
- Displays **scrolling waveform** in real time.
- Outputs raw ECG values to Serial Monitor for debugging or logging.
- Compact design using SSD1306 (128x64) OLED.

---

## 📦 Hardware Required
- **Arduino** (Uno, Nano, Mega, etc.)
- **ECG Sensor Module** (e.g., AD8232, AD620-based front-end)
- **SSD1306 OLED Display** (I²C, 128×64 resolution)
- Jumper wires and breadboard

---

## 🛠 Wiring
| Component      | Arduino Pin | Notes |
|----------------|-------------|-------|
| OLED SDA       | A4          | I²C Data |
| OLED SCL       | A5          | I²C Clock |
| ECG Output     | A0          | Analog input from ECG circuit |
| VCC (OLED + ECG)| 5V/3.3V    | Match module specs |
| GND            | GND         | Common ground |
