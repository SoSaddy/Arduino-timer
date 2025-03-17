#include <Timer.h>

Timer::Timer(uint32_t cooldown) {

	_time = millis();
	_cooldown = cooldown;

};

bool Timer::get() {

	bool state = (millis() - _time >= _cooldown);
	if (state) _time = millis();
	return state;
	
};

bool Timer::get(uint32_t cooldown) {

	bool state = (millis() - _time >= cooldown);
	if (state) _time = millis();
	return state;
	
};