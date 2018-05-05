#include <Arduino.h>

#define LED D4  // WEMOS D1 mini

void ICACHE_RAM_ATTR timerISR()
{
  digitalWrite(LED,!digitalRead(LED));
}

void setup()
{
  Serial.begin(115200);
  delay(3000); // wait for serial monitor/console
  Serial.println( "\n\nESP8266 sample - hardware timer1" );

  pinMode(LED,OUTPUT);

  timer1_attachInterrupt(timerISR);
  timer1_write(312500); // 80MHz / 256 (TIM_DIV256) / 312500 => 1s
  timer1_enable(TIM_DIV256, TIM_EDGE, TIM_LOOP);
}

void loop()
{
  yield();
}
