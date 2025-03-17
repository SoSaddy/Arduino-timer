#include <Timer.h>    // https://github.com/SoSaddy/Arduino-timer.git

//Timer timer(2000);  // Экземпляр с установкой задержки предварительно
Timer timer;          // Экземпляр без предварительной установки задержки (по умолчанию 1000мс)

bool state;           // Статус светодиода

void setup() {
  
  // Назначение встроенного светодиода на плате
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  // Проверка таймера с внутренней задержкой
  if (timer.get()) state = !state;
  
  // Проверка таймера с установленной задержкой
  //if (timer.get(2000)) state = !state;
  
  // Мигание светодиодом
  digitalWrite(LED_BUILTIN, state);

}