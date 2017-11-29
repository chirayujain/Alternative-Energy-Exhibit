
//include the library for the neopixels
#include <FastLED.h>

//define how many leds are in the strip and what data pin its on
#define BUTTON_LEDS 45
CRGB energy[BUTTON_LEDS];
#define BUTTON_DATA_PIN 6

//initialize all the buttons for the energy sources
const int solar1=22;
const int solar2=23;
const int solar3=24;
const int solar4=25;
const int solar5=26;

const int hydro1=27; 
const int hydro2=28; 
const int hydro3=29; 
const int hydro4=30;  
const int hydro5=31;

const int wind1=32; 
const int wind2=33; 
const int wind3=34; 
const int wind4=35; 
const int wind5=36; 

//initialize the state of each button
int solar1reading;     
int solar2reading;
int solar3reading;
int solar4reading;
int solar5reading;

int hydro1reading;  
int hydro2reading; 
int hydro3reading; 
int hydro4reading;     
int hydro5reading; 

int wind1reading;  
int wind2reading; 
int wind3reading; 
int wind4reading;    
int wind5reading;

//store the default previous state of each button to function as switches
int solar1previous = LOW;
int solar2previous = LOW;
int solar3previous = LOW;
int solar4previous = LOW;
int solar5previous = LOW;

int hydro1previous = LOW;
int hydro2previous = LOW;
int hydro3previous = LOW;
int hydro4previous = LOW;
int hydro5previous = LOW;

int wind1previous = LOW;
int wind2previous = LOW;
int wind3previous = LOW;
int wind4previous = LOW;
int wind5previous = LOW;


//set up timer and debounce constant for the buttons
long time = 0;         
long debounce = 200;


void setup()
{
  //add neopixels to a matrix using the library
  FastLED.addLeds<NEOPIXEL, BUTTON_DATA_PIN>(energy, BUTTON_LEDS);

  //set up all the button pins as inputs
  pinMode(solar1, INPUT_PULLUP);
  pinMode(solar2, INPUT_PULLUP);
  pinMode(solar3, INPUT_PULLUP);
  pinMode(solar4, INPUT_PULLUP);
  pinMode(solar5, INPUT_PULLUP);
  
  pinMode(hydro1, INPUT_PULLUP);
  pinMode(hydro2, INPUT_PULLUP);
  pinMode(hydro3, INPUT_PULLUP);
  pinMode(hydro4, INPUT_PULLUP);
  pinMode(hydro5, INPUT_PULLUP);
    
  pinMode(wind1, INPUT_PULLUP);
  pinMode(wind2, INPUT_PULLUP);
  pinMode(wind3, INPUT_PULLUP);
  pinMode(wind4, INPUT_PULLUP);
  pinMode(wind5, INPUT_PULLUP);
}

void loop()
{
  // store all of the button readings at the start of the loop
  solar1reading = digitalRead(solar1);
  solar2reading = digitalRead(solar2);
  solar3reading = digitalRead(solar3);
  solar4reading = digitalRead(solar4);
  solar5reading = digitalRead(solar5);

  hydro1reading = digitalRead(hydro1);
  hydro2reading = digitalRead(hydro2);
  hydro3reading = digitalRead(hydro3);
  hydro4reading = digitalRead(hydro4);
  hydro5reading = digitalRead(hydro5);
  
  wind1reading = digitalRead(wind1);
  wind2reading = digitalRead(wind2);
  wind3reading = digitalRead(wind3);
  wind4reading = digitalRead(wind4);
  wind5reading = digitalRead(wind5);

 /*
  * The next section of code is copy and pasted and then adjusted for each button
  * It ensures that the push buttons act as switches instead of regular buttons by storing
  * the previous state of each button, allowing us to write a conditional to only turn on 
  * or off leds when it makes sense to do so.
  */

 
  if (solar1reading == HIGH && solar1previous == LOW && millis() - time > debounce) {
    if (energy[0].r == 0){
      energy[0].r = 50;
      FastLED.show();
      delay(100);
      solar1previous = solar1reading;
  }
    else{
      energy[0].r = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  solar1previous = solar1reading;


   if (solar2reading == HIGH && solar2previous == LOW && millis() - time > debounce) {
    if (energy[3].r == 0){
      energy[3].r = 50;
      FastLED.show();
      delay(100);
      solar2previous = solar2reading;
  }
    else{
      energy[3].r = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  solar2previous = solar2reading;
  
    if (solar3reading == HIGH && solar3previous == LOW && millis() - time > debounce) {
    if (energy[6].r == 0){
      energy[6].r = 50;
      FastLED.show();
      delay(100);
      solar3previous = solar3reading;
  }
    else{
      energy[6].r = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  solar3previous = solar3reading;
  
    if (solar4reading == HIGH && solar4previous == LOW && millis() - time > debounce) {
    if (energy[9].r == 0){
      energy[9].r = 50;
      FastLED.show();
      delay(100);
      solar4previous = solar4reading;
  }
    else{
      energy[9].r = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  solar4previous = solar4reading;

    if (solar5reading == HIGH && solar5previous == LOW && millis() - time > debounce) {
    if (energy[12].r == 0){
      energy[12].r = 50;
      FastLED.show();
      delay(100);
      solar5previous = solar5reading;
  }
    else{
      energy[12].r = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  solar5previous = solar5reading;









if (hydro1reading == HIGH && hydro1previous == LOW && millis() - time > debounce) {
    if (energy[25].b == 0){
      energy[25].b = 50;
      FastLED.show();
      delay(100);
      hydro1previous = hydro1reading;
  }
    else{
      energy[25].b = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  hydro1previous = hydro1reading;


  
if (hydro2reading == HIGH && hydro2previous == LOW && millis() - time > debounce) {
    if (energy[22].b == 0){
      energy[22].b = 50;
      FastLED.show();
      delay(100);
      hydro2previous = hydro2reading;
  }
    else{
      energy[22].b = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  hydro2previous = hydro2reading;


  
if (hydro3reading == HIGH && hydro3previous == LOW && millis() - time > debounce) {
    if (energy[19].b == 0){
      energy[19].b = 50;
      FastLED.show();
      delay(100);
      hydro3previous = hydro3reading;
  }
    else{
      energy[19].b = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  hydro3previous = hydro3reading;


  
if (hydro4reading == HIGH && hydro4previous == LOW && millis() - time > debounce) {
    if (energy[16].b == 0){
      energy[16].b = 50;
      FastLED.show();
      delay(100);
      hydro4previous = hydro4reading;
  }
    else{
      energy[16].b = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  hydro4previous = hydro4reading;



if (hydro5reading == HIGH && hydro5previous == LOW && millis() - time > debounce) {
    if (energy[13].b == 0){
      energy[13].b = 50;
      FastLED.show();
      delay(100);
      hydro5previous = hydro5reading;
  }
    else{
      energy[13].b = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  hydro5previous = hydro5reading;



if (wind1reading == HIGH && wind1previous == LOW && millis() - time > debounce) {
    if (energy[34].g == 0){
      energy[34].g = 50;
      FastLED.show();
      delay(100);
      wind1previous = wind1reading;
  }
    else{
      energy[34].g = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  wind1previous = wind1reading;


if (wind2reading == HIGH && wind2previous == LOW && millis() - time > debounce) {
    if (energy[37].g == 0){
      energy[37].g = 50;
      FastLED.show();
      delay(100);
      wind2previous = wind2reading;
  }
    else{
      energy[37].g = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  wind2previous = wind2reading;


if (wind3reading == HIGH && wind3previous == LOW && millis() - time > debounce) {
    if (energy[40].g == 0){
      energy[40].g = 50;
      FastLED.show();
      delay(100);
      wind3previous = wind3reading;
  }
    else{
      energy[40].g = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  wind3previous = wind3reading;


if (wind4reading == HIGH && wind4previous == LOW && millis() - time > debounce) {
    if (energy[43].g == 0){
      energy[43].g = 50;
      FastLED.show();
      delay(100);
      wind4previous = wind4reading;
  }
    else{
      energy[43].g = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  wind4previous = wind4reading;


if (wind5reading == HIGH && wind5previous == LOW && millis() - time > debounce) {
    if (energy[46].g == 0){
      energy[46].g = 50;
      FastLED.show();
      delay(100);
      wind5previous = wind5reading;
  }
    else{
      energy[46].g = 0;
      FastLED.show();
      delay(100);
    }
    time = millis();  
  }
  wind5previous = wind5reading;
  
}
