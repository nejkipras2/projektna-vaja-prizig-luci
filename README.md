# projektna-vaja-prizig-zarnic


Prižig žarnic: S tipkalom b1 naj se trajno prižge LED 1, s tipkalom b2 pa LED 2. S skupnim tipkalom b3 naj se LED ugasneta. S tipko b4 pa se stanji LED zamenjata. Hkrati sme goreti le ena LED! Prehod od gorenja ene LED na drugo naj bo možen, če prejšnjo LED ugasnemo s tipko b3. Ukaz za ugasnitev ima prednost pred ukazom za vklop.

Komponente in materiali:

arduino uno,

protoboard,

LED,

4 stikala,

žice,

upori.


VHODI:

![pnadss](https://user-images.githubusercontent.com/129928759/232752544-ef5f590e-5342-4994-810e-a456bdd1c2a3.png)

IZHODI:

![pnaasdf](https://user-images.githubusercontent.com/129928759/232752575-48fbd7e1-90d0-4377-ab16-740938f09526.png)

načrtna shema:

![image](https://user-images.githubusercontent.com/129928759/232747875-e3980bc9-d345-4056-9bcb-bc1c2b72015f.png)

slika arduino vezja:

![image](https://user-images.githubusercontent.com/129928759/236142873-8487819c-2060-437d-bd35-488ab5588651.png)

koda za arduino:

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
