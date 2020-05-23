#include "stack.h"
#include <iostream>
using namespace std;


template<class T>
bool stack<T>::push(T item) {

	if (!isFull())
	{
		arr[++top] = item;
		return true;
	}
	return false;
}

template <class T>
void stack<T>::displayAll()
{
	if (!isEmpty()) {
		for (int i = 0; i <= top; i++)
		{
			cout << i << ") " << arr[i] << "|" << endl;
		}
		cout << "____________________________" << endl;
	}
	else {
		cout << "This lane is currently empty " << endl;
		cout << "____________________________" << endl;
	}
}


template <class T>
void stack<T>::deleteCar()
{
	arr[top].setPlateNumber(0);

}


template<class T>
T stack<T>::getCarAtIndex(int index )
{
	return arr[index];

}

template<class T> 
bool stack<T>::pop() {

	if (!isEmpty())
	{
		top--;

		return true;
	}
	return false;
}

template <class T>
bool stack<T>::isEmpty() {

	if (top == -1)
	{
		return true;
		cout << "the garage is empty!";

	}
	return false;
}

template <class T>
bool stack<T>::isFull() {


	if (top == (capacity-1))
	return true;

	return false;

}

template <class T>
stack<T>::stack(int size ) 
{
	capacity = size - 1;
	arr = new T[size];
	top = -1;
}

template <class T>
stack<T>::stack()
{
	capacity = 10;
	top = -1;
	arr = new T[capacity];
}

template <class T>
T stack<T>::peek() const
{
	return arr[top];
}

template <class T>
int stack <T>::search(const T& x)
{
	for (int i = 0; i <= top; i++)
	{
		if (x == arr[i])
			return i;
	}
	return -1;
}