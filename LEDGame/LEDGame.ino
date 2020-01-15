int pinLED[] = {6, 5, 4, 3, 2};
int pinBTN[] = {13, 12, 11, 10, 9};
int sensorVal[] = {0, 0, 0, 0, 0};
int lastsensorVal[] = {0, 0, 0, 0, 0};
bool lightLED[] = {false, false, false, false, false};
const int numberLED = 5;

void switchLED(int pinNUMBER){
  if(lightLED[pinNUMBER] == false){
    digitalWrite(pinLED[pinNUMBER], HIGH);
    lightLED[pinNUMBER] = true;
  }
  else{
    digitalWrite(pinLED[pinNUMBER], LOW);
    lightLED[pinNUMBER] = false;
  }  
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for (int i=0; i < numberLED; i++){
  pinMode(pinBTN[i], INPUT);
  pinMode(pinLED[i], OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i < numberLED; i++){
    sensorVal[i] = digitalRead(pinBTN[i]);
  }
  for (int i=0; i < numberLED; i++){
    if (sensorVal[i] == 0 && lastsensorVal[i] == 1){
      switchLED(i);
      
      if (i == 0)
        switchLED(numberLED - 1);
      else
        switchLED(i-1);
      
      if (i == numberLED -1)
        switchLED(0);
      else
        switchLED(i+1);
      
      break;
    }
  }
  for (int i = 0; i < numberLED; i++)
    lastsensorVal[i] = sensorVal[i];
}