# Пример работы таймера

Суть таймера заключатеся в том, чтобы не прерывать поток, как это делает delay().

```c++
#include <Timer.h>

Timer timer;          // без аргумента по умолчанию 1000мс
//Timer timer(2000);  // аргумент установки в мс

bool state;

void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  if (timer.get()) state = !state;        // проверка по установленной внутри задержке
  //if (timer.get(2000)) state = !state;  // проверка по внешней заданной задержке
  
  digitalWrite(LED_BUILTIN, state);

}
```
