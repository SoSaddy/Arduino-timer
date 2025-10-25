#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

const uint8_t AS_SWITCH = 0;
const uint8_t AS_TRIGGER = 1;

class Timer {

	public:
		Timer(uint32_t cooldown = 1000, uint8_t mode = AS_TRIGGER);
		bool get();
		bool get(uint32_t cooldown);
		void setCooldown(uint32_t cooldown);
		void setMode(uint8_t mode);
		void clear();

	private:
		uint32_t _time;
		uint32_t _cooldown;
		uint8_t _mode;
		bool _switched;
};

#endif