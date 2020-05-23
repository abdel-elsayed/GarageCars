#ifndef _STACK
#define _STACK

//#include "garage.h"
#include <iostream>

using namespace std;

template <class T>
class stack {
private:
	int capacity;
	int top= -1;
	T *arr;
		
public:
	bool isEmpty();
	bool isFull();
	T peek() const;
	bool push(T);
	bool pop();
	stack();
	stack(int size ); // put it in the constructor
	~stack() { delete[] arr; }
	void displayAll();
	T getCarAtIndex(int);
	int search(const T&);	
	int getTopIndex() { return top; }
	int getCapacity() { return capacity-1; }
	void deleteCar();
};
#endif // !_STACK
