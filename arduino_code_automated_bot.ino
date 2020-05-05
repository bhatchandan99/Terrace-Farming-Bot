 const byte analogPin1 = 0;   // Connect AN output of LSA1 to analog pin 0
 const byte junctionPulse1 = 28; // Connect JPULSE of LSA1 to pin 28
 const byte analogPin2 = 1;   // Connect AN output of LSA2 to analog pin 1
 const byte junctionPulse2 = 29; // Connect JPULSE of LSA2 to pin 29
 const byte analogPin3 = 2;   // Connect AN output of LSA3 to analog pin 2
 const byte junctionPulse3 = 30; // Connect JPULSE of LSA3 to pin 30
  int MRdir =  36;      //middle right 
  int MLdir = 4;        // middle left
  int MRpwm = 13;
  int MLpwm = 5;
  int Fdir =  30;       // front
  int Rdir = 6;         // rear
  int Fpwm = 11;
  int Rpwm = 3;

  int readValue1,readValue2,readValue3,positionValue1,positionValue2,positionValue3;    // Variables to store analog and line position value
  unsigned int junctionCount = 0;   // Variable to store junction count value

void setup() {
  pinMode(junctionPulse1,INPUT);
  pinMode(junctionPulse2,INPUT);
  pinMode(junctionPulse3,INPUT);
  
    pinMode(36 , OUTPUT);
    pinMode(13 , OUTPUT);
    pinMode(4 , OUTPUT);
    pinMode(5 , OUTPUT);
    pinMode(30 , OUTPUT);
    pinMode(6 , OUTPUT);
    pinMode(11 , OUTPUT);
    pinMode(3 , OUTPUT);
    
    digitalWrite(Fdir , LOW);
    digitalWrite(Rdir , HIGH);
    digitalWrite(MRdir , LOW);
    digitalWrite(MLdir , HIGH);
    
    Serial.begin(9600);
}
void loop() {
  readValue1 = analogRead(analogPin1);    // Read value from analog pin A0 (of LSA1)
  readValue2 = analogRead(analogPin2);    // Read value from analog pin A1 (of LSA1)
  readValue3 = analogRead(analogPin3);    // Read value from analog pin A2 (of LSA1)

  positionValue1 = ((float)readValue1/921)*70;
  positionValue2 = ((float)readValue2/921)*70;
  positionValue3 = ((float)readValue3/921)*70;

  
    Serial.println("F");
    Forward();
    delay(5000);
    Serial.println("B");
    Backward();
    delay(5000);
    Serial.println("R");
    Right();
    delay(5000);
    Serial.println("L");
    Left();
    delay(5000);

  
  if((positionValue1 >=0 && positionValue1 <= 70) && (positionValue2 >= 0 && positionValue2 <= 70) && (positionValue3 >= 0 && positionValue3 <= 70)) {
    Forward();
    Serial.println(positionValue1);     
    Serial.println(positionValue2);
    Serial.println(positionValue3);
    delay(500);
  }
  if((positionValue1 >=0 && positionValue1 <= 70) && (positionValue2 < 0 || positionValue2 >70) && (positionValue3 < 0 || positionValue3 > 70)) {
    Forward();
        delay(500);

  }
  if((positionValue1 >= 0 && positionValue1 <=70) && (positionValue2 >= 0 && positionValue2 <=70) && (positionValue3 < 0 || positionValue3 >70) ){
    Right();
        delay(500);

  }
  if( (positionValue1 >= 0 && positionValue1 <=70) && (positionValue2 < 0 || positionValue2 > 70) && (positionValue3 >= 0 && positionValue3 <=70)){
    Left();
        delay(500);

  }
  if( (positionValue1 < 0 || positionValue1 > 70) && (positionValue2 >= 0 && positionValue2 <=70) && (positionValue3 < 0 || positionValue3 > 70)){
    Right();
        delay(500);

  }
  if( (positionValue1 < 0 || positionValue1 > 70) && (positionValue2 < 0 || positionValue2 > 70) && (positionValue3 >= 0 && positionValue3 <= 70)){
    Left();
        delay(500);

  }
  if((positionValue1 < 0 || positionValue1 > 70) && (positionValue2 >= 0 && positionValue2 <= 70) && (positionValue3 >= 0 && positionValue3 <= 70)) {
    Left();
        delay(500);

  }
  else{
    wait();
        delay(500);

  }
  */
  
}
void Forward(){
  digitalWrite(MRdir , LOW);
  digitalWrite(MLdir , LOW);
  analogWrite(Fpwm , 0);
  analogWrite(Rpwm , 0);
  analogWrite(MRpwm , 150);
  analogWrite(MLpwm , 150);
    
}
void Backward(){
  digitalWrite(MRdir , HIGH);
  digitalWrite(MLdir , HIGH);
  analogWrite(Fpwm , 0);
  analogWrite(Rpwm , 0);
  analogWrite(MRpwm , 150);
  analogWrite(MLpwm , 150);
  
}
void Right(){
  digitalWrite(Fdir , LOW); 
  digitalWrite(Rdir , HIGH);
  analogWrite(MRpwm , 0);
  analogWrite(MLpwm , 0);
  analogWrite(Fpwm , 150);
  analogWrite(Rpwm , 150);
}
void Left(){
  digitalWrite(Fdir , HIGH); 
  digitalWrite(Rdir , LOW); 
  analogWrite(MRpwm , 0);
  analogWrite(MLpwm , 0);
  analogWrite(Fpwm , 150);
  analogWrite(Rpwm , 150);
}
void wait(){
  analogWrite(MRpwm , 0);
  analogWrite(MLpwm , 0);
  analogWrite(Fpwm , 0);
  analogWrite(Rpwm , 0);
}

