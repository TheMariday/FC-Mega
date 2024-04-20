#include <OctoWS2811.h>

const int channelCount = 24;
const int channelSize = 400;
const int pins[] = {23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 41, 40, 39, 38, 37, 36, 35, 34, 33, 28, 29, 30, 31, 32};

DMAMEM int displayMemory[channelSize * channelCount * 3 / 4];
int drawingMemory[channelSize * channelCount * 3 / 4];

char channelToPin[] = {23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 41, 40, 39, 38, 37, 36, 35, 34, 33, 28, 29, 30, 31, 32};

OctoWS2811 leds(channelSize, displayMemory, drawingMemory, WS2811_GRB | WS2811_800kHz, channelCount, channelToPin);

char r,g,b;
char controlByte;

short GetShort()
{
  if (Serial.available()) {
    byte low = Serial.read();
    byte high = Serial.read();

    short combined = high;
    combined = combined<<8;
    combined |= low;
    return combined;
  }
  return 0;
}

void setup() {
    Serial.begin(0);
    leds.begin();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    controlByte = Serial.read();
    if (controlByte == 1) {
        digitalWrite(LED_BUILTIN, HIGH);
        short offset = GetShort();
        short bufferLen = GetShort();

        for(int ledIndex = offset; ledIndex < offset+bufferLen; ledIndex++)
        {
          r = Serial.read();
          g = Serial.read();
          b = Serial.read();

          if(ledIndex < channelSize * channelCount)
          {
            leds.setPixel(ledIndex, r, g, b);
          }
        }
        if(offset == 0 && bufferLen == 400*24)
        {
          Serial.write(1);
          Serial.send_now();
        }
        else
        {
          Serial.write(0);
          Serial.send_now();
        }
        digitalWrite(LED_BUILTIN, LOW);
    }
    else if (controlByte == 2) {
        leds.show();
        Serial.write(1);
        Serial.send_now();
    }
    else {
      Serial.write(0);
      Serial.send_now();
    }
  }
}