#include <ezButton.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

ezButton button1(13);
ezButton button2(33);
ezButton button3(14);
ezButton button4(27);
ezButton button5(26);

bool goingUp = true;
int currentFloor = 1;
int buttonState = 0;

void setup()
{

  Serial.begin(9600);

  button1.setDebounceTime(25);
  button2.setDebounceTime(25);
  button3.setDebounceTime(25);
  button4.setDebounceTime(25);
  button5.setDebounceTime(25);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  };

  delay(2000);        
  oled.clearDisplay(); 
 
  displayMessage();
  delay(1000);

  oled.clearDisplay();
}

void loop(){

  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();

  if (button1.isPressed()){
    Serial.println("button 1 is pressed");
  } else if(button2.isPressed()){
    Serial.println("button 2 is pressed");
  } else if(button3.isPressed()){
    Serial.println("button 3 is pressed");
  } else if(button4.isPressed()){
    Serial.println("button 4 is pressed");
  } else if(button5.isPressed()){
    Serial.println("button 5 is pressed");
  }

  delay(10);
}

  

void displayMessage(){
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(2, 5);
  oled.println("Press");
  oled.display();
  oled.setCursor(2, 25);
  oled.println("floor");
  oled.display();
  oled.setCursor(2, 45);
  oled.println("number");
  oled.display();

  delay(2000);
  oled.clearDisplay();
}
