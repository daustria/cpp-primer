#ifndef LIGHT_SWITCH_H
#define LIGHT_SWITCH_H
#include "states.h"
class LightSwitch
{
	public:
		LightSwitch();
		void set_state(State *state);
		void on();
		void off();
	private:
		State *state;
};
#endif //LIGHT_SWITCH_H
