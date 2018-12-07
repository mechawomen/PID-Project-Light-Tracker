//PHOTORESISTORS
  const int ldrpin = A0;
 

//LED
  const int LED = 13;
  
//MOTOR
  const int ENA = 7;
  const int In1 = 8;
  const int In2 = 9;
  int SPEED = 100; // scale is 0 to 255
  
void setup() {
  Serial.begin(9600);  //Begin serial communcation
  //initialize LDRs and LED
  pinMode(ldrpin, INPUT);
  pinMode(LED,OUTPUT);

  //initialize MOTOR
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
    Serial.print("HELLO");
    Serial.print('\n');
    float ldrstat= analogRead(ldrpin);
    delay(10);
    Serial.print(ldrstat, DEC);
    Serial.print('\n');
    
    if (ldrstat > 2.3) {
      //move right
      digitalWrite(LED,HIGH);
    }

    else if (ldrstat > 2.7 || ldrstat < 5){
      //move to the left
      digitalWrite(LED,HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
    }

    else {
      digitalWrite(LED, LOW);
    }
    delay(500);
}

On Thu, Dec 6, 2018 at 2:02 PM Irene Duran <iduran@mail.csuchico.edu> wrote:

    //PHOTORESISTORS
      const int ldrpin = A0;
     

    //LED
      const int LED = 13;
      
    //MOTOR
      const int ENA = 7;
      const int In1 = 8;
      const int In2 = 9;
      int SPEED = 100; // scale is 0 to 255
      
    void setup() {
      Serial.begin(9600);  //Begin serial communcation
      //initialize LDRs and LED
      pinMode(ldrpin, INPUT);
      pinMode(LED,OUTPUT);

      //initialize MOTOR
      pinMode(In1, OUTPUT);
      pinMode(In2, OUTPUT);
      pinMode(ENA, OUTPUT);
    }

    void loop() {
     
        float ldrstat= analogRead(ldrpin);
        delay(10);
        Serial.print(ldrstat, DEC);
        if (ldrstat > 2.3) {
          //move right
          digitalWrite(LED,HIGH);
        }

        else if (ldrstat > 2.7 || ldrstat < 5){
          //move to the left
          digitalWrite(LED,HIGH);
          delay(200);
          digitalWrite(LED, LOW);
          delay(200);
        }

        else {
          digitalWrite(LED, LOW);
        }
        delay(500);
    }
