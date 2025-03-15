#include <Timer.h>

//Timer timer(2000);
Timer timer;

bool state;

void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  if (timer.get()) state = !state;
  //if (timer.get(2000)) state = !state;
  
  digitalWrite(LED_BUILTIN, state);

}
