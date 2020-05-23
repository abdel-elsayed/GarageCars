#pragma once
#include "stack.h"
#include "garage.h"
using namespace std;

class Car
{
public:
	Car()							// default constructor
	{
		plateNumber = "";
		moveCount = 0;
	}

	Car(const string& plateNum)		// parameterized constructor
	{
		plateNumber = plateNum;
		moveCount = 0;
	}
	 
	friend ostream& operator<<(ostream& os, const Car& car)
	{
		os << " |" <<car.plateNumber << "|" << " MC-" << car.moveCount;
		return os;
	}

	void addMove() {moveCount++; }

	int getMoveCount() const { return moveCount; }

	string getPlateNumber() const { return plateNumber; }

	bool operator==(const Car& car) const { return(plateNumber == car.getPlateNumber()); }

	void setPlateNumber(int x)
	{
		plateNumber = x;
	}

private:
	string plateNumber;
	int moveCount;
};