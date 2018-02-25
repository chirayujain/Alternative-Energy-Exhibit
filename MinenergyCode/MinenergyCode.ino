/*This is the game code for the MinEnergy Exhibit written by Chirayu Jain
 * It takes button inputs, turns on/off LEDs and updats the score and $ left.
 * This code was written using the Adafruit Neopixel library which can be found here:
 * https://github.com/adafruit/Adafruit_NeoPixel
 * 
 * This code is open source and free to use
 */


//Add all of the Libraries needed for the project
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>


//Define values for the Neopixels running next to the buttons
#define BUTTON_LEDS 50
#define BUTTON_DATA_PIN 6
Adafruit_NeoPixel Energy = Adafruit_NeoPixel(BUTTON_LEDS, BUTTON_DATA_PIN, NEO_GRB + NEO_KHZ800);


//Define values for Neopixels placed on the top of the display to indicate weather
#define WEATHER_LEDS 75
#define WEATHER_DATA_PIN 5
Adafruit_NeoPixel Weather = Adafruit_NeoPixel(WEATHER_LEDS, WEATHER_DATA_PIN, NEO_GRB + NEO_KHZ800);


//Define values for Neopixels place under the houses and the school buiilding
#define DISPLAY_LEDS 100
#define DISPLAY_DATA_PIN 4
Adafruit_NeoPixel Display = Adafruit_NeoPixel(DISPLAY_LEDS, DISPLAY_DATA_PIN, NEO_GRB + NEO_KHZ800);


//Define I2C address for the LCD and its pins to setup up the LCD as a standard LCD
#define I2C_ADDR    0x3F 
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


//initialize pin for start button and a variable to store it's state
const int startButton = 24;
int startReading;


//This variable controls whether the game code loop is running or the GAME OVER screen comes up
int ending = 0;


//initialize pin numbers for all of the buttons
const int solar1=44;
const int solar2=42;
const int solar3=45;
const int solar4=43;
const int solar5=40;

const int hydro1=38; 
const int hydro2=36; 
const int hydro3=37; 
const int hydro4=34;  
const int hydro5=35;

const int wind1=32; 
const int wind2=33; 
const int wind3=30; 
const int wind4=31; 
const int wind5=29; 


//create variables to store the button states for all the buttons
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



//setup all of the previous button states as HIGH so that we can use the buttons as switches
int solar1previous = HIGH;
int solar2previous = HIGH;
int solar3previous = HIGH;
int solar4previous = HIGH;
int solar5previous = HIGH;

int hydro1previous = HIGH;
int hydro2previous = HIGH;
int hydro3previous = HIGH;
int hydro4previous = HIGH;
int hydro5previous = HIGH;

int wind1previous = HIGH;
int wind2previous = HIGH;
int wind3previous = HIGH;
int wind4previous = HIGH;
int wind5previous = HIGH;


//create values for time and debounce that help the buttons only trigger the code once
long time = 0;     
long debounce = 200;



//create the rest of the game variables needed for the codeq
bool game = false;
int money = 180;
int score = 0;
int randNumber = 1;



void setup() {
  //initialize LCD as a 16 by 2 lcd and set the backlight to be on
  lcd.begin (16,2); 
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  

  //setup all of the button pins as input pullups, so that resistors are not necessary in the physical wiring
  pinMode(startButton, INPUT_PULLUP);
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


//turn on the Neopixel strips
Display.begin();
Display.show();

Weather.begin();
Weather.show();

Energy.begin();
Energy.show();
}




void loop() {

//store the start button state to determine if game should start or not
startReading = digitalRead(startButton);


  //if the start button is pressed it starts the game
  if(startReading == LOW){

// turns the leds next to the buttons all off and it 
 for (int i=0;i<=50;i++){
  Energy.setPixelColor(i, 0x000000);
  
}
   
//prepares the LCD for the new text it will have
  lcd.clear();
  lcd.setCursor(0,0); 


//resets all variables to the game
  score = 0;
  ending = 0;
  money = 180;
  
  //tells the code to run the game loop instead of the main void loop
  game = true;


  //cycles through the different weather patterns
  if(randNumber == 1){
    randNumber++;
    }
  else if(randNumber == 2){
    randNumber++;
    }
    else{
      randNumber = 1;
    }


}
//this delay is very important because it prevents the software interrupts from breaking the game code and the lcd screen
delay(1000);





/*The next section of code is heavily repeated and there for I will only comment one of the blocks
 * The while loop is copy and pasted 2 times for the other types of weather. The loops were then modified to
 * fit the values and score for the adjusted energy efficiencies for that day.
 * The code within the while loops are also copy and pasted 14 times because the code for all of the buttons is similiar.
 * The LED indexes are changed, the color references are changed and the score values and money values are adjusted for each 
 * block of if and else statement.
 */






 // game loop for rainy weather:
while(game == true && randNumber == 1 && ending ==0){

  //print the top line of the LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rainy   $ Left:"); 

// set the leds on the top of the display to show the color for the weather
 for(int l=0;l<=75;l++){
    Weather.setPixelColor(l, 0x00FFFF);
  }
  Weather.show();

// call the displayleds function to update the brightness of the leds based on the money left
  displayleds(money);
   
  // read values for the buttons and store them so the code knows what to do ahead of time
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


//this if statement is important because it wont let the game end if the user is in negative money values
  if(money>=0){

    //this code ends the game and goes to the GAME OVER screen
  startReading = digitalRead(startButton);
  
  if(startReading == LOW){
    ending = 1;
    game = false;
    delay(500);
    break;
  }
  
  }



 /*This is where the copy and paste begins heavily
  * The next if and else statement are copy and pasted 14 times for each button
  * the variable names are changed to work for the other buttons
  */

  //first if statement makes sure that the button is in a valid state to be pressed and is not in a debouncing state
  if (solar1reading == HIGH && solar1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(0) == 0x000000){//if the led next to the button was off, turn it on
      Energy.setPixelColor(0,0x320000);
       
      delay(100);
      // store the prvious reading value as the current one which will allow the button to be used as a switch
      solar1previous = solar1reading;

      //update score and money values. These values are changed for each type of button
      score = score + 30;
      money = money - 31;
  }
    else{// if the button is not off, turn it off
      Energy.setPixelColor(0,0x000000);
       
      delay(100);

      //update score and money values. These values are changed for each type of button
      score = score - 30;
      money = money + 31;
    }
    time = millis();  //update time variable to keep proper debounce
  }
  // store the prvious reading value as the current one which will allow the button to be used as a switch
  solar1previous = solar1reading;




   if (solar2reading == HIGH && solar2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(3) == 0x000000){
      Energy.setPixelColor(3,0x320000);
       
      delay(100);
      solar2previous = solar2reading;
      score = score + 30;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(3,0x000000);
       
      delay(100);
      score = score - 30;
      money = money + 31;
    }
    time = millis();  
  }
  solar2previous = solar2reading;

  
    if (solar3reading == HIGH && solar3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(6) == 0x000000){
      Energy.setPixelColor(6,0x320000);
       
      delay(100);
      solar3previous = solar3reading;
      score = score + 30;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(6,0x000000);
       
      delay(100);
      score = score - 30;
      money = money + 31;
    }
    time = millis();  
  }
  solar3previous = solar3reading;

  
    if (solar4reading == HIGH && solar4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(9) == 0x000000){
      Energy.setPixelColor(9,0x320000);
       
      delay(100);
      solar4previous = solar4reading;
      score = score + 30;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(9,0x000000);
       
      delay(100);
      score = score - 30;
      money = money + 31;
    }
    time = millis();  
  }
  solar4previous = solar4reading;


    if (solar5reading == HIGH && solar5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(12) == 0x000000){
      Energy.setPixelColor(12,0x320000);
       
      delay(100);
      solar5previous = solar5reading;
      score = score + 30;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(12,0x000000);
       
      delay(100);
      score = score - 30;
      money = money + 31;
    }
    time = millis();  
  }
  solar5previous = solar5reading;









if (hydro1reading == HIGH && hydro1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(25) == 0x000000){
      Energy.setPixelColor(25,0x000032);
       
      delay(100);
      hydro1previous = hydro1reading;
      score = score + 23;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(25,0x000000);
       
      delay(100);
      score = score - 23;
      money = money + 21;
    }
    time = millis();  
  }
  hydro1previous = hydro1reading;


  
if (hydro2reading == HIGH && hydro2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(22) == 0x000000){
      Energy.setPixelColor(22,0x000032);
       
      delay(100);
      hydro2previous = hydro2reading;
      score = score + 23;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(22,0x000000);
       
      delay(100);
      score = score - 23;
      money = money + 21;
    }
    time = millis();  
  }
  hydro2previous = hydro2reading;


  
if (hydro3reading == HIGH && hydro3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(19) == 0x000000){
      Energy.setPixelColor(19,0x000032);
       
      delay(100);
      hydro3previous = hydro3reading;
      score = score + 23;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(19,0x000000);
       
      delay(100);
      score = score - 23;
      money = money + 21;
    }
    time = millis();  
  }
  hydro3previous = hydro3reading;


  
if (hydro4reading == HIGH && hydro4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(16) == 0x000000){
      Energy.setPixelColor(16,0x000032);
       
      delay(100);
      hydro4previous = hydro4reading;
      score = score + 23;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(16,0x000000);
       
      delay(100);
      score = score - 23;
      money = money + 21;
    }
    time = millis();  
  }
  hydro4previous = hydro4reading;



if (hydro5reading == HIGH && hydro5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(13) == 0x000000){
      Energy.setPixelColor(13,0x000032);
       
      delay(100);
      hydro5previous = hydro5reading;
      score = score + 23;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(13,0x000000);
       
      delay(100);
      score = score - 23;
      money = money + 21;
    }
    time = millis();  
  }
  hydro5previous = hydro5reading;




if (wind1reading == HIGH && wind1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(34) == 0x000000){
      Energy.setPixelColor(34,0x003200);
       
      delay(100);
      wind1previous = wind1reading;
      score = score + 14;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(34,0x000000);
       
      delay(100);
      score = score - 14;
      money = money + 19;
    }
    time = millis();  
  }
  wind1previous = wind1reading;


if (wind2reading == HIGH && wind2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(37) == 0x000000){
      Energy.setPixelColor(37,0x003200);
       
      delay(100);
      wind2previous = wind2reading;
      score = score + 14;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(37,0x000000);
       
      delay(100);
      score = score - 14;
      money = money + 19;
    }
    time = millis();  
  }
  wind2previous = wind2reading;


if (wind3reading == HIGH && wind3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(40) == 0x000000){
      Energy.setPixelColor(40,0x003200);
       
      delay(100);
      wind3previous = wind3reading;
      score = score + 14;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(40,0x000000);
       
      delay(100);
      score = score - 14;
      money = money + 19;
    }
    time = millis();  
  }
  wind3previous = wind3reading;


if (wind4reading == HIGH && wind4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(43) == 0x000000){
      Energy.setPixelColor(43,0x003200);
       
      delay(100);
      wind4previous = wind4reading;
      score = score + 14;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(43, 0x000000);
       
      delay(100);
      score = score - 14;
      money = money + 19;
    }
    time = millis();  
  }
  wind4previous = wind4reading;


if (wind5reading == HIGH && wind5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(46) == 0x000000){
      Energy.setPixelColor(46,0x003200);
       
      delay(100);
      wind5previous = wind5reading;
      score = score + 14;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(46,0x000000);
      delay(100);
      score = score - 14;
      money = money + 19;
    }
    time = millis();  
  }
  wind5previous = wind5reading;

  
// end of the game loop turns on all the led that was turned on for the button that cycle
  Energy.show();


  //uncomment the next two lines for debugging purposes
  //lcd.setCursor(0,1);
  //lcd.print(score);

  //update the money left in the game
  lcd.setCursor(10,1);
  lcd.print(money);

  //again another crucial delay that prevents the interrupts from breaking the LCD and the game code
  delay(101);
}











//game loop for Windy weather
while(game == true && randNumber == 2 && ending ==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Windy    $ Left:"); 
  
 for(int l=0;l<=75;l++){
    Weather.setPixelColor(l, 0x00FF00);
  }
  Weather.show();

  displayleds(money);
  

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


  if(money>=0){
  startReading = digitalRead(startButton);
  if(startReading == LOW){
    ending = 1;
    game = false;
    delay(500);
    break;
  }

  }
 
  if (solar1reading == HIGH && solar1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(0) == 0x000000){
      Energy.setPixelColor(0,0x320000);
       
      delay(100);
      solar1previous = solar1reading;
      score = score + 32;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(0,0x000000);
       
      delay(100);
      score = score - 32;
      money = money + 31;
    }
    time = millis();  
  }
  solar1previous = solar1reading;


   if (solar2reading == HIGH && solar2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(3) == 0x000000){
      Energy.setPixelColor(3,0x320000);
       
      delay(100);
      solar2previous = solar2reading;
      score = score + 32;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(3,0x000000);
       
      delay(100);
      score = score - 32;
      money = money + 31;
    }
    time = millis();  
  }
  solar2previous = solar2reading;

  
    if (solar3reading == HIGH && solar3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(6) == 0x000000){
      Energy.setPixelColor(6,0x320000);
       
      delay(100);
      solar3previous = solar3reading;
      score = score + 32;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(6,0x000000);
       
      delay(100);
      score = score - 32;
      money = money + 31;
    }
    time = millis();  
  }
  solar3previous = solar3reading;

  
    if (solar4reading == HIGH && solar4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(9) == 0x000000){
      Energy.setPixelColor(9,0x320000);
       
      delay(100);
      solar4previous = solar4reading;
      score = score + 32;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(9,0x000000);
       
      delay(100);
      score = score - 32;
      money = money + 31;
    }
    time = millis();  
  }
  solar4previous = solar4reading;


    if (solar5reading == HIGH && solar5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(12) == 0x000000){
      Energy.setPixelColor(12,0x320000);
       
      delay(100);
      solar5previous = solar5reading;
      score = score + 32;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(12,0x000000);
       
      delay(100);
      score = score - 32;
      money = money + 31;
    }
    time = millis();  
  }
  solar5previous = solar5reading;





if (hydro1reading == HIGH && hydro1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(25) == 0x000000){
      Energy.setPixelColor(25,0x000032);
       
      delay(100);
      hydro1previous = hydro1reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(25,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro1previous = hydro1reading;


  
if (hydro2reading == HIGH && hydro2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(22) == 0x000000){
      Energy.setPixelColor(22,0x000032);
       
      delay(100);
      hydro2previous = hydro2reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(22,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro2previous = hydro2reading;


  
if (hydro3reading == HIGH && hydro3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(19) == 0x000000){
      Energy.setPixelColor(19,0x000032);
       
      delay(100);
      hydro3previous = hydro3reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(19,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro3previous = hydro3reading;


  
if (hydro4reading == HIGH && hydro4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(16) == 0x000000){
      Energy.setPixelColor(16,0x000032);
       
      delay(100);
      hydro4previous = hydro4reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(16,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro4previous = hydro4reading;



if (hydro5reading == HIGH && hydro5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(13) == 0x000000){
      Energy.setPixelColor(13,0x000032);
       
      delay(100);
      hydro5previous = hydro5reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(13,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro5previous = hydro5reading;




if (wind1reading == HIGH && wind1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(34) == 0x000000){
      Energy.setPixelColor(34,0x003200);
       
      delay(100);
      wind1previous = wind1reading;
      score = score + 24;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(34,0x000000);
       
      delay(100);
      score = score - 24;
      money = money + 19;
    }
    time = millis();  
  }
  wind1previous = wind1reading;


if (wind2reading == HIGH && wind2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(37) == 0x000000){
      Energy.setPixelColor(37,0x003200);
       
      delay(100);
      wind2previous = wind2reading;
      score = score + 24;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(37,0x000000);
       
      delay(100);
      score = score - 24;
      money = money + 19;
    }
    time = millis();  
  }
  wind2previous = wind2reading;


if (wind3reading == HIGH && wind3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(40) == 0x000000){
      Energy.setPixelColor(40,0x003200);
       
      delay(100);
      wind3previous = wind3reading;
      score = score + 24;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(40,0x000000);
       
      delay(100);
      score = score - 24;
      money = money + 19;
    }
    time = millis();  
  }
  wind3previous = wind3reading;


if (wind4reading == HIGH && wind4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(43) == 0x000000){
      Energy.setPixelColor(43,0x003200);
       
      delay(100);
      wind4previous = wind4reading;
      score = score + 24;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(43, 0x000000);
       
      delay(100);
      score = score - 24;
      money = money + 19;
    }
    time = millis();  
  }
  wind4previous = wind4reading;


if (wind5reading == HIGH && wind5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(46) == 0x000000){
      Energy.setPixelColor(46,0x003200);
       
      delay(100);
      wind5previous = wind5reading;
      score = score + 24;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(46,0x000000);
      delay(100);
      score = score - 24;
      money = money + 19;
    }
    time = millis();  
  }
  wind5previous = wind5reading;



  Energy.show();
 // lcd.setCursor(0,1);
 // lcd.print(score);
  lcd.setCursor(10,1);
  lcd.print(money);
   delay(101);
}







//Game loop for Sunny weather
while(game == true && randNumber == 3 && ending ==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sunny    $ Left:"); 


 for(int l=0;l<=75;l++){
    Weather.setPixelColor(l, 0xFF8000);
  }
  Weather.show();

  displayleds(money);
  
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


  if(money>=0){
  startReading = digitalRead(startButton);
  if(startReading == LOW){
    ending = 1;
    game = false;
    delay(500);
    break;
  }

  }

 
  if (solar1reading == HIGH && solar1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(0) == 0x000000){
      Energy.setPixelColor(0,0x320000);
       
      delay(100);
      solar1previous = solar1reading;
      score = score + 33;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(0,0x000000);
       
      delay(100);
      score = score - 33;
      money = money + 31;
    }
    time = millis();  
  }
  solar1previous = solar1reading;


   if (solar2reading == HIGH && solar2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(3) == 0x000000){
      Energy.setPixelColor(3,0x320000);
       
      delay(100);
      solar2previous = solar2reading;
      score = score + 33;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(3,0x000000);
       
      delay(100);
      score = score - 33;
      money = money + 31;
    }
    time = millis();  
  }
  solar2previous = solar2reading;

  
    if (solar3reading == HIGH && solar3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(6) == 0x000000){
      Energy.setPixelColor(6,0x320000);
       
      delay(100);
      solar3previous = solar3reading;
      score = score + 33;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(6,0x000000);
       
      delay(100);
      score = score - 33;
      money = money + 31;
    }
    time = millis();  
  }
  solar3previous = solar3reading;

  
    if (solar4reading == HIGH && solar4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(9) == 0x000000){
      Energy.setPixelColor(9,0x320000);
       
      delay(100);
      solar4previous = solar4reading;
      score = score + 33;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(9,0x000000);
       
      delay(100);
      score = score - 33;
      money = money + 31;
    }
    time = millis();  
  }
  solar4previous = solar4reading;


    if (solar5reading == HIGH && solar5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(12) == 0x000000){
      Energy.setPixelColor(12,0x320000);
       
      delay(100);
      solar5previous = solar5reading;
      score = score + 33;
      money = money - 31;
  }
    else{
      Energy.setPixelColor(12,0x000000);
       
      delay(100);
      score = score - 33;
      money = money + 31;
    }
    time = millis();  
  }
  solar5previous = solar5reading;









if (hydro1reading == HIGH && hydro1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(25) == 0x000000){
      Energy.setPixelColor(25,0x000032);
       
      delay(100);
      hydro1previous = hydro1reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(25,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro1previous = hydro1reading;


  
if (hydro2reading == HIGH && hydro2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(22) == 0x000000){
      Energy.setPixelColor(22,0x000032);
       
      delay(100);
      hydro2previous = hydro2reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(22,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro2previous = hydro2reading;


  
if (hydro3reading == HIGH && hydro3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(19) == 0x000000){
      Energy.setPixelColor(19,0x000032);
       
      delay(100);
      hydro3previous = hydro3reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(19,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro3previous = hydro3reading;


  
if (hydro4reading == HIGH && hydro4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(16) == 0x000000){
      Energy.setPixelColor(16,0x000032);
       
      delay(100);
      hydro4previous = hydro4reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(16,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro4previous = hydro4reading;



if (hydro5reading == HIGH && hydro5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(13) == 0x000000){
      Energy.setPixelColor(13,0x000032);
       
      delay(100);
      hydro5previous = hydro5reading;
      score = score + 21;
      money = money - 21;
  }
    else{
      Energy.setPixelColor(13,0x000000);
       
      delay(100);
      score = score - 21;
      money = money + 21;
    }
    time = millis();  
  }
  hydro5previous = hydro5reading;




if (wind1reading == HIGH && wind1previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(34) == 0x000000){
      Energy.setPixelColor(34,0x003200);
       
      delay(100);
      wind1previous = wind1reading;
      score = score + 19;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(34,0x000000);
       
      delay(100);
      score = score - 19;
      money = money + 19;
    }
    time = millis();  
  }
  wind1previous = wind1reading;


if (wind2reading == HIGH && wind2previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(37) == 0x000000){
      Energy.setPixelColor(37,0x003200);
       
      delay(100);
      wind2previous = wind2reading;
      score = score + 19;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(37,0x000000);
       
      delay(100);
      score = score - 19;
      money = money + 19;
    }
    time = millis();  
  }
  wind2previous = wind2reading;


if (wind3reading == HIGH && wind3previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(40) == 0x000000){
      Energy.setPixelColor(40,0x003200);
       
      delay(100);
      wind3previous = wind3reading;
      score = score + 19;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(40,0x000000);
       
      delay(100);
      score = score - 19;
      money = money + 19;
    }
    time = millis();  
  }
  wind3previous = wind3reading;


if (wind4reading == HIGH && wind4previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(43) == 0x000000){
      Energy.setPixelColor(43,0x003200);
       
      delay(100);
      wind4previous = wind4reading;
      score = score + 19;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(43, 0x000000);
       
      delay(100);
      score = score - 19;
      money = money + 19;
    }
    time = millis();  
  }
  wind4previous = wind4reading;


if (wind5reading == HIGH && wind5previous == LOW && millis() - time > debounce) {
    if (Energy.getPixelColor(46) == 0x000000){
      Energy.setPixelColor(46,0x003200);
       
      delay(100);
      wind5previous = wind5reading;
      score = score + 19;
      money = money - 19;
  }
    else{
      Energy.setPixelColor(46,0x000000);
      delay(100);
      score = score - 19;
      money = money + 19;
    }
    time = millis();  
  }
  wind5previous = wind5reading;

 

  Energy.show();
 // lcd.setCursor(0,1);
  //lcd.print(score);
  lcd.setCursor(10,1);
  lcd.print(money);
   delay(101);
}




 if(ending !=0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GAME OVER");
  lcd.setCursor(0,1);
  lcd.print(score);
delay(1000);




 
}


}


/*This is the function to update the brightness of the leds in the town
 * Since the Adafruit library doesnt have a funtion to update brightness, it has to be done mannually
 */
 
void displayleds(int x){

  //if the money is at max (no buttons have been pressed) then turn all the leds off
if(x==180){
  for(int l=0;l<=100;l++){
    Display.setPixelColor(l, 0, 0,0);
  }
  Display.show();
}
//if the mony is at or above 160 turn them a little brighter than before
else if(x>160){
  Display.setPixelColor(2, 0, 30, 0);
  Display.setPixelColor(5, 0, 30, 0);
  Display.setPixelColor(8, 0, 30, 0);
  Display.setPixelColor(11, 0, 30, 0);
  Display.setPixelColor(14, 0, 30, 0);
  Display.setPixelColor(18, 0, 30, 0);  
  Display.setPixelColor(26, 0, 30, 0);  
  Display.setPixelColor(31, 0, 30, 0); 
  Display.setPixelColor(40, 0, 30, 0);
  Display.setPixelColor(47, 0, 30, 0); 
  Display.setPixelColor(65, 0, 30, 0); 
  Display.setPixelColor(70, 0, 30, 0); 
  Display.setPixelColor(82, 0, 30, 0);    
  Display.setPixelColor(88, 0, 30, 0);
  Display.setPixelColor(99, 0, 30, 0);
  Display.show();
}
//if the mony is at or above 140 turn them a little brighter than before
else if(x>140){
Display.setPixelColor(2, 0, 60, 0);
Display.setPixelColor(5, 0, 60, 0);
Display.setPixelColor(8, 0, 60, 0);
Display.setPixelColor(11, 0, 60, 0);
Display.setPixelColor(14, 0, 60, 0);
Display.setPixelColor(18, 0, 60, 0);  
Display.setPixelColor(26, 0, 60, 0);  
Display.setPixelColor(31, 0, 60, 0); 
Display.setPixelColor(40, 0, 60, 0);
Display.setPixelColor(47, 0, 60, 0); 
Display.setPixelColor(65, 0, 60, 0); 
Display.setPixelColor(70, 0, 60, 0); 
Display.setPixelColor(82, 0, 60, 0);    
Display.setPixelColor(88, 0, 60, 0);
Display.setPixelColor(99, 0, 60, 0);
Display.show();
}
//if the mony is at or above 120 turn them a little brighter than before
else if(x>120){
  Display.setPixelColor(2, 0, 90, 0);
Display.setPixelColor(5, 0, 90, 0);
Display.setPixelColor(8, 0, 90, 0);
Display.setPixelColor(11, 0, 90, 0);
Display.setPixelColor(14, 0, 90, 0);
Display.setPixelColor(18, 0, 90, 0);  
Display.setPixelColor(26, 0, 90, 0);  
Display.setPixelColor(31, 0, 90, 0); 
Display.setPixelColor(40, 0, 90, 0);
Display.setPixelColor(47, 0, 90, 0); 
Display.setPixelColor(65, 0, 90, 0); 
Display.setPixelColor(70, 0, 90, 0); 
Display.setPixelColor(82, 0, 90, 0);    
Display.setPixelColor(88, 0, 90, 0);
Display.setPixelColor(99, 0, 90, 0);
Display.show();
}
//if the mony is at or above 100 turn them a little brighter than before
else if(x>100){
  Display.setPixelColor(2, 0, 120, 0);
Display.setPixelColor(5, 0, 120, 0);
Display.setPixelColor(8, 0, 120, 0);
Display.setPixelColor(11, 0, 120, 0);
Display.setPixelColor(14, 0, 120, 0);
Display.setPixelColor(18, 0, 120, 0);  
Display.setPixelColor(26, 0, 120, 0);  
Display.setPixelColor(31, 0, 120, 0); 
Display.setPixelColor(40, 0, 120, 0);
Display.setPixelColor(47, 0, 120, 0); 
Display.setPixelColor(65, 0, 120, 0); 
Display.setPixelColor(70, 0, 120, 0); 
Display.setPixelColor(82, 0, 120, 0);    
Display.setPixelColor(88, 0, 120, 0);
Display.setPixelColor(99, 0, 120, 0);
Display.show();
}
//if the mony is at or above 80 turn them a little brighter than before
else if(x>80){
Display.setPixelColor(2, 0, 150, 0);
Display.setPixelColor(5, 0, 150, 0);
Display.setPixelColor(8, 0, 150, 0);
Display.setPixelColor(11, 0, 150, 0);
Display.setPixelColor(14, 0, 150, 0);
Display.setPixelColor(18, 0, 150, 0);  
Display.setPixelColor(26, 0, 150, 0);  
Display.setPixelColor(31, 0, 150, 0); 
Display.setPixelColor(40, 0, 150, 0);
Display.setPixelColor(47, 0, 150, 0); 
Display.setPixelColor(65, 0, 150, 0); 
Display.setPixelColor(70, 0, 150, 0); 
Display.setPixelColor(82, 0, 150, 0);    
Display.setPixelColor(88, 0, 150, 0);
Display.setPixelColor(99, 0, 150, 0);
Display.show();
}
//if the mony is at or above 60 turn them a little brighter than before
else if(x>60){
  Display.setPixelColor(2, 0, 180, 0);
Display.setPixelColor(5, 0, 180, 0);
Display.setPixelColor(8, 0, 180, 0);
Display.setPixelColor(11, 0, 180, 0);
Display.setPixelColor(14, 0, 180, 0);
Display.setPixelColor(18, 0, 180, 0);  
Display.setPixelColor(26, 0, 180, 0);  
Display.setPixelColor(31, 0, 180, 0); 
Display.setPixelColor(40, 0, 180, 0);
Display.setPixelColor(47, 0, 180, 0); 
Display.setPixelColor(65, 0, 180, 0); 
Display.setPixelColor(70, 0, 180, 0); 
Display.setPixelColor(82, 0, 180, 0);    
Display.setPixelColor(88, 0, 180, 0);
Display.setPixelColor(99, 0, 180, 0);
Display.show();
}
//if the mony is at or above 40 turn them a little brighter than before
else if(x>40){
  Display.setPixelColor(2, 0, 210, 0);
Display.setPixelColor(5, 0, 210, 0);
Display.setPixelColor(8, 0, 210, 0);
Display.setPixelColor(11, 0, 210, 0);
Display.setPixelColor(14, 0, 210, 0);
Display.setPixelColor(18, 0, 210, 0);  
Display.setPixelColor(26, 0, 210, 0);  
Display.setPixelColor(31, 0, 210, 0); 
Display.setPixelColor(40, 0, 210, 0);
Display.setPixelColor(47, 0, 210, 0); 
Display.setPixelColor(65, 0, 210, 0); 
Display.setPixelColor(70, 0, 210, 0); 
Display.setPixelColor(82, 0, 210, 0);    
Display.setPixelColor(88, 0, 210, 0);
Display.setPixelColor(99, 0, 210, 0);
Display.show();
}
//if the mony is at or above 20 turn them a little brighter than before
else if(x>20){
  Display.setPixelColor(2, 0, 240, 0);
Display.setPixelColor(5, 0, 240, 0);
Display.setPixelColor(8, 0, 240, 0);
Display.setPixelColor(11, 0, 240, 0);
Display.setPixelColor(14, 0, 240, 0);
Display.setPixelColor(18, 0, 240, 0);  
Display.setPixelColor(26, 0, 240, 0);  
Display.setPixelColor(31, 0, 240, 0); 
Display.setPixelColor(40, 0, 240, 0);
Display.setPixelColor(47, 0, 240, 0); 
Display.setPixelColor(65, 0, 240, 0); 
Display.setPixelColor(70, 0, 240, 0); 
Display.setPixelColor(82, 0, 240, 0);    
Display.setPixelColor(88, 0, 240, 0);
Display.setPixelColor(99, 0, 240, 0);
Display.show();
}
//if the mony is below 20 turn them to max brightness
else{
 Display.setPixelColor(2, 0, 255, 0);
Display.setPixelColor(5, 0, 255, 0);
Display.setPixelColor(8, 0, 255, 0);
Display.setPixelColor(11, 0, 255, 0);
Display.setPixelColor(14, 0, 255, 0);
Display.setPixelColor(18, 0, 255, 0);  
Display.setPixelColor(26, 0, 255, 0);  
Display.setPixelColor(31, 0, 255, 0); 
Display.setPixelColor(40, 0, 255, 0);
Display.setPixelColor(47, 0, 255, 0); 
Display.setPixelColor(65, 0, 255, 0); 
Display.setPixelColor(70, 0, 255, 0); 
Display.setPixelColor(82, 0, 255, 0);    
Display.setPixelColor(88, 0, 255, 0);
Display.setPixelColor(99, 0, 255, 0);
Display.show();
}
}

