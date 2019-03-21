
#define OPEN_SQUELCH false
#define ADC_REFERENCE REF_3V3

#include "LibAPRS.h"
#include "KISS.h"

extern Afsk modem;
extern AX25Ctx AX25;

char incomingByte;

void aprs_msg_callback(struct AX25Ctx *ctx) {
  kiss_messageCallback(ctx);
}

void setup() {
  Serial.begin(9600);
    
  APRS_init(ADC_REFERENCE, OPEN_SQUELCH);
  kiss_init(&AX25, &modem, &Serial);
}

void loop() {
  APRS_poll();
    while (Serial.available() > 0) {
    incomingByte = Serial.read();
    kiss_serialCallback(incomingByte);
  }
}
