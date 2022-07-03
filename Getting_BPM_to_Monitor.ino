


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

LiquidCrystal_I2C lcd(0x27,20,4);
//  Variables
const int PulseWire = 0;      
//const int LED13 = 13;       
int Threshold = 525;           
                               
                               
                               
PulseSensorPlayground pulseSensor;  


void setup() {   

  Serial.begin(9600);          
  lcd.begin();                     
  lcd.begin();
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.setThreshold(Threshold);   

   if (pulseSensor.begin()) {
    lcd.setCursor(2,0);
    lcd.print("Sensor Denyut");
    lcd.setCursor(6,1);
    lcd.print("Nadi");

  }
}



void loop() {
//  lcd.display();
//  delay(500);
//  lcd.noDisplay();
//  delay(200);
 

 int myBPM = pulseSensor.getBeatsPerMinute();  
                                               

if (pulseSensor.sawStartOfBeat()) {            
                       
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("BPM");
  
  lcd.setCursor(6,1);
  lcd.print(myBPM);
  delay(15000);
  Serial.println(myBPM);     
  
}
                    

}

  
