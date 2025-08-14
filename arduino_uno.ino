#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int ecgPin = A0;  
int x = 0;             
int lastY = 32;         

void setup() {
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println("ECG Waveform");
  display.display();

  delay(1000);
  display.clearDisplay();
}

void loop() {
  int ecgValue = analogRead(ecgPin);

  
  Serial.println(ecgValue);

 
  int y = map(ecgValue, 0, 1023, SCREEN_HEIGHT - 1, 0); 

  
  display.drawLine(x, lastY, x + 1, y, SSD1306_WHITE);
  display.display();

  lastY = y;
  x++;

  
  if (x >= SCREEN_WIDTH) {
    x = 0;
    lastY = 32;
    display.clearDisplay();
  }

  delay(5); 
}
