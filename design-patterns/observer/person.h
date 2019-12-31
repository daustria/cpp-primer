#ifndef PERSON_H
#define PERSON_H
#include "observable.h"
class Person : public Observable<Person>
{
	public:
		Person(const int yrs): age(yrs) {}
		virtual ~Person() {}
		int getAge() { return age; }
		void setAge(const int yrs) 
		{ 
			if (age == yrs)
				return;
			age = yrs; 
			notify(*this, "age");
		}	
	private:
		int age;
};
#endif //PERSON_H
