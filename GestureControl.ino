#include <Servo.h>
Servo servox;
Servo servoy;
#define  servomaxx   180  
#define  servomaxy   180   
#define  servocenterx   90  
#define  servocentery   90 
#define  servopinx   6   
#define  servopiny   9 

      
int val1 = 0, val2 = 0;
int side = 0;
  
String inString = "";    

void setup() {

  Serial.begin(9600);        
  pinMode(servopinx, OUTPUT);  
  pinMode(servopiny, OUTPUT);   

  servoy.attach(servopiny);
  servox.attach(servopinx);
  servox.write(servocenterx);
  delay(500);
  servoy.write(servocentery);
  delay(500);

}
void loop () {
  
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar))
    {
      inString += (char)inChar;
    }

    if (inChar == ',')
    {
      val1 = inString.toInt();
      inString = "";
   
    }
    if (inChar == '#')
    {
      val2 = inString.toInt();
      inString = "";
    }
    if (inChar == '\n')
    {
      side = inString.toInt();
      
      inString = "";
    }
  }
   if (side == 1)
  {
    servox.write(val1);

  side=0;
  }
  if (side == 2)
  {   
    servoy.write(val1);
  side=0;   
  }
}
