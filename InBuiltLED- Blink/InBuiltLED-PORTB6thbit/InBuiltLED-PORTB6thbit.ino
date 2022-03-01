//Program which sets PORTB's 6th pin (In build LED of Aurdiuno uno Rev board).
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Set Baud Rate
  DDRB = DDRB|0X20; //Set Port B'S Data direction register's 6th bit as out put.
  Serial.print("Initial set up Done");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = 0x20; //Blink led for 10000 milliseconds and then off Inbuild Led.
  Serial.println(PORTB);
  delay(10000);
  while(1){
    PORTB= 0x00;
    Serial.println(PORTB);
  }
}
