int pinLED[] = {8, 9, 10, 11, 12};
bool LEDstate[] = {false, false, false, false, false};
bool initialSIDE = true;
int sensorVALUE;
int lastsensorVALUE = 1;
int pinBTN = 2;
int j;

void initialSTATE (){
  digitalWrite(pinLED[0], HIGH);
  LEDstate[0] = true;
  for (int i = 1; i < 5; i++){
    digitalWrite(pinLED[i], LOW);
    LEDstate[i] = false;
  }
  initialSIDE = true;
}

void setup()
{
  for(int i=0; i<5; i++){
    pinMode(pinLED[i], OUTPUT);
  }
  pinMode(pinBTN, INPUT);
  digitalWrite(pinLED[0], HIGH);
  Serial.begin(9600);
}

void loop()
{
  sensorVALUE = digitalRead(pinBTN);
  if(sensorVALUE == 0 && lastsensorVALUE == 1){
    initialSTATE();
    for(j=10; j>0; j--){
      if(initialSIDE == true){
        for(int i=0; i<4; i++){
          delay(1500/j^2);
          if (LEDstate[i] == true){
            digitalWrite(pinLED[i], LOW);
            LEDstate[i] = false;
            digitalWrite(pinLED[i+1], HIGH);
            LEDstate[i+1] = true;
          }
          initialSIDE = false;
        }
      }
      else{
       for(int i=4; i>0; i--){
         delay(1500/j^2); 
         if (LEDstate[i] == true){
            digitalWrite(pinLED[i], LOW);
            LEDstate[i] = false;
            digitalWrite(pinLED[i-1], HIGH);
            LEDstate[i-1] = true;
          }
          initialSIDE = true;
       }
     }
   }
 }
 lastsensorVALUE = sensorVALUE;
}