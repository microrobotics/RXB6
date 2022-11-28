#include <VirtualWire.h>
int count;
void setup() {
  Serial.begin(9600);         // Debugging only
  Serial.println("setup");    //Prints "Setup" to the serial monitor
  vw_set_rx_pin(12);           //Sets pin D12 as the RX Pin
  vw_set_ptt_inverted(true);  // Required for DR3100
  vw_setup(4000);             // Bits per sec
  vw_rx_start();              // Start the receiver PLL running

  pinMode(2, OUTPUT);  //Relay one
  pinMode(3, OUTPUT);  //Relay two
  pinMode(4, OUTPUT);  //Relay three
  pinMode(5, OUTPUT);  //Relay four

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen))  // Non-blocking
  {
    int i;
    digitalWrite(13, true);  // Flash a light to show received good message
    // Message with a good checksum received, dump it.
    Serial.print("Got: ");

    for (i = 0; i < buflen; i++) {
      int c = (buf[i]);
      Serial.print(c);
      Serial.print(" ");
      if (c == 65) {
        digitalWrite(2, !digitalRead(2));
      }
      if (c == 66) {
        digitalWrite(3, !digitalRead(3));
      }

      if (c == 67) {
        digitalWrite(4, !digitalRead(4));
      }

      if (c == 68) {
        digitalWrite(5, !digitalRead(5));
      }
    }
    count++;
    // Serial.print(count);
    Serial.println("");
    digitalWrite(13, false);
  }
}
