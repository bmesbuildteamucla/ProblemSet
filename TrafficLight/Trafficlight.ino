int sensorVALUE;
int lastsensorVALUE = 1;
bool greenLIGHT = false;
int LEDred = 13;
int LEDyellow = 12;
int LEDgreen = 11;
int pinBTN = 3;

void setup()
{
  pinMode(pinBTN, INPUT);
  pinMode(LEDred, OUTPUT);
  pinMode(LEDyellow, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  digitalWrite (LEDred, HIGH);
}

void loop()
{
  sensorVALUE = digitalRead(pinBTN);
  if (sensorVALUE == 0 && lastsensorVALUE == 1){
    if (greenLIGHT == false){
      digitalWrite(LEDred, LOW);
      digitalWrite(LEDgreen, HIGH);
      greenLIGHT = true;
    }
    else{
      digitalWrite(LEDgreen, LOW);
      digitalWrite(LEDyellow, HIGH);
      delay(5000);
      digitalWrite(LEDyellow, LOW);
      digitalWrite(LEDred, HIGH);
      greenLIGHT = false;
    }
  }
  lastsensorVALUE = sensorVALUE;
}