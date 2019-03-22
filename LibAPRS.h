// Copyright Mark Qvist / unsigned.io
// https://unsigned.io/microaprs
//
// Licensed under GPL-3.0. For full info,
// read the LICENSE file.
#include "Arduino.h"
#include <stdint.h>
#include <stdbool.h>

#include "FIFO.h"
#include "CRC-CCIT.h"
#include "HDLC.h"
#include "AFSK.h"
#include "AX25.h"

#define USE_COMPRESSION

void APRS_init(int reference, bool open_squelch);
void APRS_poll(void);

void APRS_setCallsign(char *call, int ssid);
void APRS_setDestination(char *call, int ssid);
void APRS_setMessageDestination(char *call, int ssid);
void APRS_setPath1(char *call, int ssid);
void APRS_setPath2(char *call, int ssid);

void APRS_setPreamble(unsigned long pre);
void APRS_setTail(unsigned long tail);
void APRS_useAlternateSymbolTable(bool use);
void APRS_setSymbol(char sym);

#ifdef USE_COMPRESSION
void APRS_setLat(float lat);
void APRS_setLon(float lon);
#else
void APRS_setLat(char *lat);
void APRS_setLon(char *lon);
#endif
void APRS_setPower(int s);
void APRS_setHeight(int s);
void APRS_setGain(int s);
void APRS_setDirectivity(int s);

void APRS_sendPkt(void *_buffer, size_t length);
void APRS_sendLoc(void *_buffer, size_t length);
void APRS_sendMsg(void *_buffer, size_t length);
void APRS_msgRetry();

void APRS_printSettings();

int freeMemory();
