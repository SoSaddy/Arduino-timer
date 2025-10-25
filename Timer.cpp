#include <Timer.h>

Timer::Timer(uint32_t cooldown, uint8_t mode) {

	this->_time = millis();
	this->_cooldown = cooldown;
	this->_mode = mode;
	this->_switched = false;

};

bool Timer::get() {

	bool state = (millis() - this->_time >= this->_cooldown);

	if (this->_mode == AS_TRIGGER) {

		if (state) {
			this->_time = millis();
		}
		return state;

	} else if (this->_mode == AS_SWITCH) {

		if (state) {
			this->_switched = !this->_switched;
			this->_time = millis();
		}
		return this->_switched;

	}

	return false;
	
};

bool Timer::get(uint32_t cooldown) {

	bool state = (millis() - this->_time >= cooldown);

	if (this->_mode == AS_TRIGGER) {

		if (state) {
			this->_time = millis();
		}
		return state;

	} else if (this->_mode == AS_SWITCH) {

		if (state) {
			this->_switched = !this->_switched;
			this->_time = millis();
		}
		return this->_switched;

	}

	return false;
	
};


void Timer::setCooldown(uint32_t cooldown) {
	this->_cooldown = cooldown;

};

void Timer::setMode(uint8_t mode) {
	this->_mode = mode;
};

void Timer::clear() {
	this->_time = millis();
};