#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {

	public:
		Timer(uint32_t cooldown = 1000);
		bool get();
		bool get(uint32_t cooldown);

	private:
		uint32_t _time;
		uint32_t _cooldown;

};

#endif