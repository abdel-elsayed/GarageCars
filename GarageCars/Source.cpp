#include "garage.h"
#include "Garage_impl.cpp"
#include "stack.h"
#include "stack_impl.cpp"
#include "car.h"
#include <iomanip>

int main() {
	garage<Car> lot1;
	ifstream inData("garageLog.txt");
	char sym;
	string plateNumber;
	int countAdd = 1;
	int countDepart = 1;

	lot1.setConsoleColor(46);
	cout << "\n\n--------------------------------------------WELCOME TO MY GARAGE-----------------------------------------------------\n";
	cout <<     "                                           by Abdelrahman Elsayed                                                     ";
	lot1.setConsoleColor(7);
	cout << endl << endl;
	while (!inData.eof())
	{
		inData >> sym >> plateNumber;
		Car car(plateNumber);
		if (sym == 'A') 
		{				
			cout <<'|' << plateNumber << "| is being added to the garage " << endl << endl;
			if (lot1.addCar(car))
				{
				lot1.setConsoleColor(FOREGROUND_GREEN );
				cout << "  WELCOME " << endl;
				cout << "| ________ |       o" << " --------- " << "o" << endl;
				cout << "|  |    |  | <------:" << car << "" << ":  " << endl;
				cout << "|  |    |  |       o" << " --------- " << "o" << endl;
				cout << "|  |    |  |" << endl;
				cout << "|__|____|__|" << endl;
				lot1.setConsoleColor(7);
				lot1.display();
				}
			else
			{	
				lot1.setConsoleColor(100);
				cout << "\n~~~~~~~~~~~~~~~~The Garage is full!!~~~~~~~~~~~~~~" << endl;
				cout << "~~~~~~~~~~~~~~~~look somewhere else!~~~~~~~~~~~~~~" << endl;
				
				
				lot1.setConsoleColor(7);

			}
		}
		

		else if (sym == 'D')
		{
			lot1.setConsoleColor(12);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
		lot1.setConsoleColor(7);
			cout << "!!!!!!!!!!!!!   |"<< car.getPlateNumber() <<"|    IS REQUESTING TO LEAVE !!!!!!!!!!!!!"<<endl;
			
			
			
			if (lot1.departCar(car)) {
				
				lot1.setConsoleColor(7);
				cout << "\n--------The Garage AFTER removing the car-----" << endl;
				lot1.display();
				lot1.setConsoleColor(12);
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
				lot1.setConsoleColor(7);
			}
		}
		
		
		
		 
		cout << endl << endl;
		lot1.setConsoleColor(50);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
		lot1.setConsoleColor(7);
	}

	lot1.setConsoleColor(46);
	cout << "------------------------------------THE END-----------------------------------------------------" << endl;
	lot1.setConsoleColor(7);
	system("pause");
	return 0;
}