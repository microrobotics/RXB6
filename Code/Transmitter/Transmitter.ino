#include <VirtualWire.h>
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;


void setup() {
  Serial.begin(9600);       // Debugging only
  Serial.println("setup");  // Prints "Setup to the serial monitor"

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);



  vw_set_tx_pin(12);          // Sets pin D12 as the TX pin
  vw_set_ptt_inverted(true);  // Required for DR3100
  vw_setup(4000);             // Bits per sec
}

void loop() {
  int buttonState1 = 1;
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == LOW) {
    const char *msg = "A";                 // Message to be sent
    digitalWrite(13, true);                // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg));  //Sending the message
    vw_wait_tx();                          // Wait until the whole message is gone
    Serial.println(*msg);
    digitalWrite(13, false);  // Turn the LED off.
    delay(1000);              // A short gap.    }
  }
  {
    int buttonState2 = 1;
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 == LOW) {
      const char *msg = "B";                 // Message to be sent
      digitalWrite(13, true);                // Flash a light to show transmitting
      vw_send((uint8_t *)msg, strlen(msg));  //Sending the message
      vw_wait_tx();                          // Wait until the whole message is gone
      Serial.println(*msg);
      digitalWrite(13, false);  // Turn the LED off.
      delay(1000);              // A short gap.    }
    }
    {
      int buttonState3 = 1;
      buttonState3 = digitalRead(buttonPin3);
      if (buttonState3 == LOW) {
        const char *msg = "C";                 // Message to be sent
        digitalWrite(13, true);                // Flash a light to show transmitting
        vw_send((uint8_t *)msg, strlen(msg));  //Sending the message
        vw_wait_tx();                          // Wait until the whole message is gone
        Serial.println(*msg);
        digitalWrite(13, false);  // Turn the LED off.
        delay(1000);              // A short gap.    }
      }
      {
        int buttonState4 = 1;
        buttonState4 = digitalRead(buttonPin4);
        if (buttonState4 == LOW) {
          const char *msg = "D";                 // Message to be sent
          digitalWrite(13, true);                // Flash a light to show transmitting
          vw_send((uint8_t *)msg, strlen(msg));  //Sending the message
          vw_wait_tx();                          // Wait until the whole message is gone
          Serial.println(*msg);
          digitalWrite(13, false);  // Turn the LED off.
          delay(1000);              // A short gap.    }
        }
      }
    }
  }
  delay(100);
}

