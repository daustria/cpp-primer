#include "lightswitch.h"
#include "states.h"

void State::on(LightSwitch *ls)
{
	std::cout << "Light is already on." << std::endl;
}

void State::off(LightSwitch *ls)
{
	std::cout << "Light is already off." << std::endl;
}

void OnState::off(LightSwitch *ls)
{
	std::cout << "Switching light off..." << std::endl;
	ls->set_state(new OffState());
	delete this; //?
}

void OffState::on(LightSwitch *ls)
{
	std::cout << "Switching light on..." << std::endl;
	ls->set_state(new OnState());
	delete this; //?
}
