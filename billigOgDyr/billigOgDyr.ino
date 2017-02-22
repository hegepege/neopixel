#include <Adafruit_NeoPixel.h>
#define PIN_A 6
#define PIN_B 5

#define NUM_LEDS 24
#define BRIGHTNESS 100

Adafruit_NeoPixel af = Adafruit_NeoPixel(NUM_LEDS, PIN_A, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel cheap = Adafruit_NeoPixel(NUM_LEDS, PIN_B, NEO_GRB + NEO_KHZ800);

uint32_t orange = cheap.Color(255, 100, 0);
uint32_t l_y = cheap.Color(255, 255, 153);
uint32_t yellow = cheap.Color(255, 255, 51);
uint32_t black = cheap.Color(0, 0, 0);
uint32_t tungsten = cheap.Color(255, 214, 170);
uint32_t sky = cheap.Color(64, 156, 255);



               int wait = 50;

void setup() {
  Serial.begin(115200);
  af.setBrightness(BRIGHTNESS);
  cheap.setBrightness(BRIGHTNESS);
  af.begin();
  cheap.begin();
  af.show();
  cheap.show();
  delay(500);
}

void loop() {
  //colorWipe(af.Color(255, 0, 0), 50); // Red
  pulseWhite(5);
}


void pulseWhite(int wait) {
  for (int j = 0; j < 256 ; j++) {
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      af.setPixelColor(i, af.Color(0, 0, 0, 255) );
    }
    delay(wait);
    af.show();
  }
  // setCheapColor(orange, 5000);
  //setCheapColor(black, 1000);
  // setCheapColor(l_y, 5000);
  // setCheapColor(black, 1000);
  // setCheapColor(yellow, 5000);
  // setCheapColor(black, 1000);
  setCheapColor(tungsten, 5000);

  setCheapColor(black, 1000);
  setCheapColor(sky, 5000);

  delay(wait);
  af.show();
}


void setCheapColor(uint32_t c, int wait) {
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    cheap.setPixelColor(i, c);
  }
  cheap.show();
  delay(wait);

}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (int i = 0; i < NUM_LEDS; i++) {
    af.setPixelColor(i, c);
    cheap.setPixelColor(i, c);
    af.show();
    cheap.show();
    delay(wait);
  }
}

