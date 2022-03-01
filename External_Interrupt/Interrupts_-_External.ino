//External Interrupt Programming (INT0/INT1)

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  SREG = 0x80;  // SREG = 1 <<I enable Interrupt bit
  EICRA = 0x04; //Any logical change on INT1 genarates an interrupt request.
  EIMSK = 0x02 ; //Enable INT1
  //PORT D pd2 - external Interrupt 0 input
  DDRD = 0xF0; //set last 4 nibble as input
  DDRB = 0xF0; //Port B's High nibble as output for inbuild led test
  PORTB = 0x0F; //enable pull up resistors.

}

void loop() {
  // put your main code here, to run repeatedly:

  while (1)
  {
    //External Interrupt Flag Register it will be 0x00 if interrupts enables

    Serial.print("EIFR value is: "); //Excute one program , if edge trigger in INT1 will execute ISR
    Serial.println(EIFR);
    Serial.println(INTF1);
    PORTB = 0 << PB5; //Off Inbuild LED 
    delay(1000);

  }
}
ISR (INT1_vect)
{
  PORTB = 1 << PB5; // When ISR enabled , Inbuild on .

  Serial.println("External Interrupt Executing / INT1");
  delay(10000);

}
