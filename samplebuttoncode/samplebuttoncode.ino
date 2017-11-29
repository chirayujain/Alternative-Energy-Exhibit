#include <FastLED.h>


#define BUTTON_LEDS 45
CRGB energy[BUTTON_LEDS];
#define BUTTON_DATA_PIN 6

const int button = 22;
int buttonreading;
int buttonprevious = LOW;


long time = 0;         
long debounce = 200;

int counter =0;




void setup() {
FastLED.addLeds<NEOPIXEL, BUTTON_DATA_PIN>(energy, BUTTON_LEDS);

  Serial.begin(9600);
  
  pinMode(button, INPUT_PULLUP);

}




void loop() {

  buttonreading = digitalRead(button);
  if (buttonreading == HIGH && buttonprevious == LOW && millis() - time > debounce) {
    if (energy[0].r == 0){
      energy[0].r = 50;
      FastLED.show();
      delay(100);
      buttonprevious = buttonreading;
  }
    else{
      energy[0].r = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  buttonprevious = buttonreading;
}



