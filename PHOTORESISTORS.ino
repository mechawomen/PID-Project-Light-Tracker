const int ldrpin = A0;
const int ldrpin1 = A1;
const int LED = 13;

//MOTOR
const int ENA = 6   ;
const int In1 = 8;
const int In2 = 9;
int SPEED = 150; // scale is 0 to 255
  
void setup() {
  //LDRS AND LED
  Serial.begin(9600);
   pinMode(ldrpin, INPUT);
   pinMode(ldrpin1, INPUT);
   pinMode(LED, OUTPUT);

   //MOTOR
   pinMode(In1, OUTPUT);
   pinMode(In2, OUTPUT);
   pinMode(ENA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("HELLO");
    Serial.print('\n');
    int stat= analogRead(ldrpin);
    delay(100);
    int stat1 = analogRead(ldrpin1);
    delay(100);

    analogWrite(ENA, 0);
    delay (250);
    
    float ldrstat = stat/100;
    float ldrstat1= stat1/100;
    Serial.print("ldrstat: ");
    Serial.print(ldrstat, DEC);
    Serial.print('\n');
    Serial.print("ldrstat1: ");
    Serial.print(ldrstat1, DEC);
    Serial.print('\n');

    //if not at max light subtract one and compare
    if (ldrstat1 < 9){
      ldrstat1 =  ldrstat1 - 2;
       if (ldrstat == ldrstat1) {
        analogWrite(ENA, 0);
        digitalWrite(In1, LOW);
        digitalWrite(In2, LOW); 
        digitalWrite(LED, HIGH);
      }
      else if (ldrstat > ldrstat1){
        //Move Right
        analogWrite(ENA, SPEED);
        digitalWrite(In1, HIGH);
        digitalWrite(In2, LOW);  
      }
      else if (ldrstat1 > ldrstat){
        //move left
        analogWrite(ENA, SPEED);
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH); 
      }
    }

    //
    else {
       if (ldrstat1 == ldrstat) {
        //dont move
        analogWrite(ENA, 0);
        digitalWrite(In1, LOW);
        digitalWrite(In2, LOW); 
        digitalWrite(LED, HIGH);
      }
      else if (ldrstat > ldrstat1){
        //Move Right
        analogWrite(ENA, SPEED);
        digitalWrite(In1, HIGH);
        digitalWrite(In2, LOW);  
      }
      else if (ldrstat1 > ldrstat){
        //move left
        analogWrite(ENA, SPEED);
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH); 
      }     
    }
}
