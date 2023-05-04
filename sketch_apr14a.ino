int led1 = 2;   
int led2 = 3;
int b1 = 4;     
int b2 = 5;    
int b3 = 6;     
int b4 = 7;     
int led_state = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
}

void loop() {  
  if (digitalRead(b1) == HIGH && led_state == 0){
    digitalWrite(led1, HIGH);   
    digitalWrite(led2, LOW);    
    led_state = 1; 
    delay(100);
  }
  
  if (digitalRead(b2) == HIGH && led_state == 0){
    digitalWrite(led1, LOW);    
    digitalWrite(led2, HIGH);  
    led_state = 2;  
    delay(100);
  }
  
  if (digitalRead(b3) == HIGH) { 
    digitalWrite(led1, LOW);    
    digitalWrite(led2, LOW);    
    led_state = 0;              
  }
  
  if (digitalRead(b4) == HIGH) {
    if (led_state == 1) {       
      digitalWrite(led1, LOW);  
      digitalWrite(led2, HIGH); 
      led_state = 2;            
      delay(600);
    }
    else if (led_state == 2) { 
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, LOW);  
      led_state = 1;            
      delay(1000);
    }
  }
}
