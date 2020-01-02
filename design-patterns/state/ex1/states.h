#ifndef STATES_H
#define STATES_H
#include <iostream>
class LightSwitch;

class State
{
	public:
		virtual ~State() = default;
		virtual void on (LightSwitch *ls);
		virtual void off (LightSwitch *ls);
};

class OnState : public State
{
	public:
		OnState() { std::cout << "Light turned on." << std::endl; }
		virtual ~OnState() = default;
		void off(LightSwitch *ls) override;
};

class OffState : public State
{
	public:
		OffState() { std::cout << "Light turned off." << std::endl; }
		virtual ~OffState() = default;
		void on(LightSwitch *ls) override;
};
#endif //STATES_H
