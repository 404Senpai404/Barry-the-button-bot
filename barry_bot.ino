#include <Keyboard.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int button = 8;
int buttonState = LOW;

void setup(){
    Serial.begin(9600);
    
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    
    pinMode(button, INPUT);    //Setting up button  
    oledTextSetup();
    face1();
}

void loop(){
  buttonPressV2(); 
  face2();
  buttonPressV2(); 
  delay(200);
  face1();
  buttonPressV2();   
  delay(100);
   
}

void buttonPress(){
    if(digitalRead(button) != LOW){
        Serial.println("GGEZ WIN LOSERS LOLOLOLOL");
        niceMessage();
        msg("get good ");
        delay(2000);
    }
    else{
    }
}

void buttonPressV2(){
    if(digitalRead(button) != LOW){
        Serial.println("GGEZ WIN LOSERS LOLOLOLOL");
        openChat();
        niceMessage();
        Keyboard.press(KEY_RETURN);
        delay(200);
        Keyboard.release(KEY_RETURN);
        msg("get good ");
        delay(200);
    }
    else{

    }
}

void oledTextSetup(){
    //sets up the display for us on normal config that we would be using

    display.clearDisplay();

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE); //font
    display.setCursor(10, 0); // places cursor on xy graph on oled
    display.display();      // Show initial text
    delay(100);
}


void hello(){
    //Test
    //types hello in chat
    Keyboard.begin();
    Keyboard.print("Hello ");
    Keyboard.end();
}

void pressEnter(){
    Keyboard.begin();
    Keyboard.press(47);
    delay(100);
    Keyboard.release(47);
    delay(100);
}

void Press(char x){
    //takes the character that is put into the perameters
    // and uses that as a key press
    Keyboard.begin();
    Keyboard.press(x);
    delay(100);
    Keyboard.release(x);
    delay(100);
}

void niceMessage(){
    //types the message into the chat when you win
    //might want to add smth to it that makes the chat pop-up
    //For example in R6 use 'T' to pull up chat

    Keyboard.begin();
    Keyboard.print("GGEZ WIN ");
    Keyboard.print("UR DOG WATER ");
    delay(100);
    Keyboard.end();
}

void face1() {
  //sets up the display for us on normal config that we would be using

  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE); //font
  display.setCursor(50, 16); // places cursor on xy graph on oled
  display.println("OwO");
  display.display();
  delay(100);
}


void face2() {
  //sets up the display for us on normal config that we would be using

  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE); //font
  display.setCursor(50, 16); // places cursor on xy graph on oled
  display.println("uwu");
  display.display();
  delay(100);
}


void msg(String w){
  
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE); //font
  display.setCursor(0, 16); // places cursor on xy graph on oled
  display.println(w);
  display.display();//F in front may make it scroll; remove it later.
  //remove the thingy above before uploading ^^^^^
  //or at least commit it      // Show initial text
  delay(100);
}



void openChat(){
    //for R6
    Keyboard.begin();
    Keyboard.press('t');
    delay(100);
    Keyboard.release('t');
    Keyboard.end();
}
