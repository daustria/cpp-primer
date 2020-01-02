#include "lightswitch.h"
#include "states.h"

LightSwitch::LightSwitch() { state = new OffState(); }

void LightSwitch::set_state(State *state) { this->state = state; } 

void LightSwitch::on() { state->on(this); }

void LightSwitch::off() { state->off(this); }
