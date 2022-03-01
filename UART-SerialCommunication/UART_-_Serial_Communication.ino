/* Following program for UART Serial communication in ATmega328p and PC"*/

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/(BAUD*16)-1

void setup() {
  // put your setup code here, to run once:
  // set baudrate in UBRR(Baud Rate register is 16 bit Register)
  UBRR0L = MYUBRR; //Buad rate registers lower byte
  UBRR0H = MYUBRR >> 8; ////Buad rate registers Higher byte

  Serial.begin(9600); //There is an issue with ubrr value, so initilizes Serial communication with Inbuild function.
  Serial.println(MYUBRR); //Checks Baud Rate value.
  // enable the receiver
  UCSR0B |= (1 << RXEN0) ; 
  DDRB = 0x20; //Set Data direction register for PORTB(Inbuilt LED) pin as output.
  PORTB = 0x00; //LED off
}

void loop() {
  // put your main code here, to run repeatedly:
  // wait for reciever buffer to be empty

  if (Serial.available() > 0) //Check the input data size is 0 or anything left
  {
    char data = Serial.read(); //Read PC data to Atmega328p
    Serial.println(data); //Prints data
    delay(100);

    while (!(UCSR0A & (1 >> UDRE0)))
    {//Check data buffer register value is ascii equavalent of 1 then Inbuild LED on, and if buffer value is acsii of 2 then Inbuild LED off.
      if (UDR0 == 49)
      {
        PORTB = 0x20;
        Serial.println("LED IS ON");
        delay(1000);
      }
      if (UDR0 == 50)
      {
        {
          PORTB = 0x00;
          Serial.println("LED IS OFF");
          delay(1000);
        }
      }

    }
  }
}
