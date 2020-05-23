# Garage Lanes - Stack

Example use of stack in simulation of cars arrivals/departures in 2-lanes parking garage.

## Project Assignment

> The Parking Garage contains 2 lanes, each capable of holding up to 10 cars. There is only a single entrance/exit to the garage at one end of the lanes.

> ![alt tag](https://github.com/abdel-elsayed/GarageCars/blob/master/garage1.png)

> If a customer arrives to pick up a car which is not nearest the exit, all cars blocking the cars' path are moved into the other lane. If more cars still must be moved out of the way, they go into the street. When the customer's car is driven out, all cars in the street must be put back into the garage.

>Write a C++ program that reads input from a file (that you create). Each line in the file contains two fields separated by a blank: a code (A = an arriving car, or D = a car wishes to depart) and a license plate number (this could be a string). Cars are assumed to arrive and depart in the order specified by the input. The program should print a message whenever a car arrives or departs.

> When a car arrives, the message should specify whether or not there is room in the garage for the car. If there is no room, the car leaves without entering. When a car departs, the message should include the number of times the car had to be moved out of the way so that other cars could depart. Each move from one lane to the other counts as 1; each move to the street counts as 1; each move from the street to a lane counts as 1. Don't forget to check for conditions such as someone wanting a car that's not in the garage, trying to park a car but both lanes are full, trying to park a car when only one lane is full, etc.

> Your program should define an object from a 'garage' class to represent the 2 lanes and the street. The garage class will contain three stack objects one for each lane and the street. Use the dynamic array implementation of the stack. You'll need methods for manipulating the cars in the lanes, e.g. search for a car in a lane, move a car from a lane to somewhere, and perhaps higher-level methods like arrive and depart and methods to handle your output.


## Format

Console application
  
## Input file 

* Each line in the file contains status (letter 'A' - arrival, 'D' - departure) and plate number XXX-XXX.
* [Example](https://github.com/abdel-elsayed/GarageCars/blob/master/garageLog.txt)


## Screen shots

![alt tag](https://github.com/abdel-elsayed/GarageCars/blob/master/garage_entry_screenshot.PNG)

![alt_tag](https://github.com/abdel-elsayed/GarageCars/blob/master/garage_exit1_screenshot.PNG)

![alt tag](https://github.com/abdel-elsayed/GarageCars/blob/master/garage_exit2_screenshot.PNG)

![alt tag](https://github.com/abdel-elsayed/GarageCars/blob/master/garage_isFull_screenshot.PNG)

![alt tag](https://github.com/abdel-elsayed/GarageCars/blob/master/garage_notFound_screenshot.PNG)

## Author

* [Abdelrahman Elsayed](https://github.com/abdel-elsayed)

## Project repository link

https://github.com/abdel-elsayed/GarageCars
