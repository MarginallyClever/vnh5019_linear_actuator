// Arduino linear actuator demo
// dan@marginallyclever.com 2015-07-28
// http://www.github.com/MarginallyClever/vnh5019_linear_actuator

void setup() {
  Serial.begin(57600);

  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  
  Serial.println("** Ready **");
}

void loop() {
  Serial.println("Slide Forward");
  setDir(1);
  slide(5);

  Serial.println("Slide Backward");
  setDir(2);
  slide(5);
}

void setDir(int d) {
  switch(d) {
    case 0: // off?
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    break;
    case 1: // forward
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    break;
    case 2:  // backward
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    break;
    case 3:  // locked?
    digitalWrite(2,HIGH);
    digitalWrite(4,HIGH);
    break;
  }
}


// gradually speed up, then gradually slow down.
void slide(int d) {
  for(int v=0;v<256;++v) {
    analogWrite(3,v);
    delay(d);
  }
  for(int v=255;v>=0;--v) {
    analogWrite(3,v);
    delay(d);
  }
}
