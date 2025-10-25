# Назначение библиотеки
Таймер не прерывает поток, как это делает delay().

# Свойства.
Подключение библиотеки
```c++
#include <Timer.h>
```

Обявление класса
```c++
Timer timer;                  // по умолчанию: задержка 1000мс, режим AS_TRIGGER
// или
Timer timer(2000, AS_SWITCH); // аргументы [задержка, режим]
```

Методы
```c++
bool get();                   // -> возвращает состояние
bool get(uint32_t);           // -> возвращает состояние [по указанной в аргументе задержке]
void setCooldown(uint32_t);   // -> установка задержки
void setMode(const uint8_t);  // -> установка режима [AS_SWITCH, AS_TRIGGER]
void clear();                 // -> синхронизирует задержку (сброс)
```

# Примеры работы таймера

Пример 1. Мигание светодиода.
<br>
Таймер по срабатыванию переключает состояние переменной state, которая затем используется для передачи логического уровня на пин со светодиодом.
```c++
#include <Timer.h>

Timer timer;  // по умолчанию: задержка 1000мс, режим AS_TRIGGER
bool state = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (timer.get()) state = !state;
  digitalWrite(LED_BUILTIN, state);
}
```

Пример 2. Мигание светодиода - альтернативный.
<br>
Таймер по срабатыванию переключает внутреннее состояние каждые 2000мс
```c++
#include <Timer.h>

Timer timer(2000, AS_SWITCH);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, timer.get());
}
```

Пример 3. Гибкая настройка.
```c++
#include <Timer.h>

Timer timer;

void setup() {
  timer.setCooldown(5000);
  timer.setMode(AS_SWITCH);
}

void loop() {
  if (timer.get()) {
    timer.setCooldown(3000);
    // ...
  } else {
    // ...
  }
}
```
