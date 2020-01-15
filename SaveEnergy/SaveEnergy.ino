int sensorVALUE;
int lastsensorVALUE = 1;
bool LEDstate = false;
unsigned long LEDtime;
int pinLED = 13;
int pinBTN = 6;
float timeinSECONDS;

void setup()
{
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(pinBTN, INPUT);
  digitalWrite(pinLED, LOW);
}

void loop()
{
  sensorVALUE = digitalRead(pinBTN);
  if(sensorVALUE == 0 && lastsensorVALUE == 1){
    digitalWrite(pinLED, HIGH);
    LEDstate = true;
    LEDtime = millis();
  }
  lastsensorVALUE = sensorVALUE;
  while(LEDstate == true){
    if(millis() - LEDtime < 20000){
      sensorVALUE = digitalRead(pinBTN);
      if(sensorVALUE == 0 && lastsensorVALUE == 1){
        digitalWrite(pinLED, LOW);
        LEDstate = false;
        timeinSECONDS = (millis()-LEDtime)/1000.000;
        Serial.print("The LED was on for ");
        Serial.print(timeinSECONDS);
        Serial.println(" seconds.");
      }
      lastsensorVALUE = sensorVALUE;
    }
    else{
      digitalWrite(pinLED, LOW);
      LEDstate = false;
      Serial.println("The LED was on for 20 seconds.");
    }
  }
}
