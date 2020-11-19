#include "garage.h"
#include "car.h


template <class T>
bool garage<T>::addCar(const T  &in)
{
	if (!Lane1.isFull())
	{
		Lane1.push(in);
		return 1;
	}
	else if (!Lane2.isFull())
	{
		Lane2.push(in);
		return 1;
	}
	else
	return false;
}

template <class T>
void garage<T>::display()
{
	cout << "---/LANE1/" << endl;
	Lane1.displayAll();
	cout << "---/LANE2/" << endl;
	Lane2.displayAll();
	cout << "---/STREET/" << endl;
	street.displayAll();
}


template <class T>
bool garage<T>::departCar(const T  &out)
{
	if (Lane1.search(out) != -1)
	{	
		
		retrieveCar(Lane2, Lane1, 1, out);
		return true;
	}
	else if (Lane2.search(out) != -1)
	{
		retrieveCar(street, Lane2,2, out);
		return true;
	}
	else {
		setConsoleColor(FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		cout << "\nTHE CAR IS NOT FOUND IN THE GARAGE!!!!\n" << endl;
		setConsoleColor(12);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
		setConsoleColor(7);
		return false;
	}
}


template <class T>
void garage<T>::moveBackCars(stack<T> &dest, stack<T> &source, int count)
{

	Car car1;

	if (count <= -1)
	{
		return;
	}
	for (int i =0;i<count ; i++)
	{
		car1 = source.peek();
		car1.addMove();
		dest.push(car1);
		source.pop();
	}
}


template <class T>
void garage<T>::retrieveCar(stack<T>& dest, stack<T>& source, int current ,const Car& car)
{ // this function moves all the cars infront of the targeted car to the other lanes and then pops the target
	
	Car car1;
	int countLane2 = 0, countStreet = 0; // explain 
	int Lane2_empty_Spaces = (Lane2.getCapacity() - Lane2.getTopIndex());
	int No_of_moving_cars = source.getTopIndex() - source.search(car);

	if (current == 1)// if the car exists in lane 1
	{
		if (Lane2_empty_Spaces >= No_of_moving_cars) 
		{	// if lane 2 has enough empty spaces more than the number of cars moving from lane 1
			cout << "\nIn order to get the car: " << Lane2_empty_Spaces << " cars were moved to the 2nd lane " << endl;
			cout << "from index " <<  source.search(car) +1 << " to " << source.getTopIndex()<< endl;
			while (source.getTopIndex() > source.search(car))
			{
				car1 = source.peek();
				car1.addMove();
				Lane2.push(car1);
				source.pop();
			}
			cout << "\nCar is found at index " << source.getTopIndex() << " in the 1st lane of the garage\n\n";
			cout << "\n--------Garage before removing the car-----" << endl;
			cout << "Lane-1" << endl;
			cout << "-------" << endl;
			Lane1.displayAll();
			cout << "Lane-2" << endl;
			cout << "-------" << endl;
			Lane2.displayAll();
			cout << "street" << endl;
			cout << "-------" << endl;
			street.displayAll();

			
			setConsoleColor(FOREGROUND_RED);
			cout << "     BYE   " << endl;
			cout << "| ________ |       o" << " --------- " << "o" << endl;
			cout << "|  |   |   |       :" << car << "" << ":----->  " << endl;
			cout << "|  |   |   |       o" << " --------- " << "o" << endl;
			cout << "|  |   |   |" << endl;
			cout << "|__|___|___|" << endl << endl;
			source.pop();
			moveBackCars(Lane1, Lane2, Lane2_empty_Spaces);
		}

		else { // if lane 2 doesnt have enough spaces to move the cars
			int sourceTopIndex= source.getTopIndex();
			//cout << "\nCar is found at index " << source.search(car) << " in the 1st lane of the garage\n\n";
			while (!Lane2.isFull())
			{
				car1 = source.peek();
				car1.addMove();
				dest.push(car1);
				source.pop();
				countLane2++;
			}

			while (source.getTopIndex() > source.search(car))
			{
				car1 = source.peek();
				car1.addMove();
				street.push(car1);
				source.pop();
				countStreet++;
			}

			cout << "\nIn order to get the desired car: " << countLane2 << " cars were moved to the 2nd lane ";
			cout << ",and " << countStreet << " cars were moved to the street " << endl;
			cout << "From index " << source.search(car) + 1<< " to " << sourceTopIndex  << endl << endl;
			cout << "\nCar is found at index " << source.search(car) << " in the 1st lane of the garage\n\n";
			
			cout << "\n--------Garage before removing the car-----" << endl;
			cout << "Lane-1" << endl;
			Lane1.displayAll();
			cout << "Lane-2" << endl;
			Lane2.displayAll();
			cout << "street" << endl;
			street.displayAll();

			
			setConsoleColor(FOREGROUND_RED);
			cout << "     BYE   " << endl;
			cout << "| ________ |       o" << " --------- " << "o" << endl;
			cout << "|  |   |   |       :" << car << "" << ":----->  " << endl;
			cout << "|  |   |   |       o" << " --------- " << "o" << endl;
			cout << "|  |   |   |" << endl;
			cout << "|__|___|___|" << endl << endl;

			source.pop();
			moveBackCars(Lane1, street, countStreet); // to move back the cars from the street to their original places
			moveBackCars(Lane1, Lane2, countLane2);// to move back the cars from lane 2 to their original places
		}
	}
	if (current == 2) // if the car is in lane 2
	{
		int sourceTopIndex = source.getTopIndex();
		while (source.getTopIndex() > source.search(car))
		{
			car1 = source.peek();
			car1.addMove();
			street.push(car1);
			source.pop();
			countStreet++;
		}
		cout << "\nIn order to get the car: " << countStreet << " cars were moved to the street " << endl;
		cout << "from index " <<  source.search(car) + 1<< " to " << sourceTopIndex << endl;

		cout << "\nCar is found at index " << source.search(car) << " in the 2nd lane of the garage\n\n";


		cout << "Lane-1" << endl;
		Lane1.displayAll();
		cout << "Lane-2" << endl;
		Lane2.displayAll();
		cout << "street" << endl;
		street.displayAll();

		
		setConsoleColor(FOREGROUND_RED);
		cout << "     BYE   " << endl;
		cout << "| ________ |       o" << " --------- " << "o" << endl;
		cout << "|  |   |   |       :" << car << "" << ":----->  " << endl;
		cout << "|  |   |   |       o" << " --------- " << "o" << endl;
		cout << "|  |   |   |" << endl;
		cout << "|__|___|___|" << endl << endl;

		source.pop();
		moveBackCars(Lane2, street, countStreet);
	}
}
