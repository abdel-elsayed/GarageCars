#ifndef _GARAGE_
#define  _GARAGE_
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "car.h"
#include "stack.h"



using namespace std;
template <class T> 
class garage {
private:
	stack<T> Lane1;
	stack<T> Lane2;
	stack<T> street;
public:
	bool addCar(const T & in);
	bool departCar(const T & out);
	void display();
	void retrieveCar(stack<T>& dest, stack<T>& source,int current, const Car &car);
	void moveBackCars(stack<T>& dest, stack<T>& source, int count);

	void setConsoleColor(WORD c)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

};
#endif // !_GARAGE_
