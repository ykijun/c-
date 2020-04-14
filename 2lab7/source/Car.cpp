/*
 * Car.cpp
 *
 *  Created on: 2019. 11. 1.
 *      Author: kijun
 */

#include <iostream>
#include "Car.h"
#include "Engine.h"
using namespace std;

Car::Car(int nc, Color color, int mileage): engine(nc){ // Constructor
	this->color = color;
	this->mileage = mileage;
}
Color Car::getColor() const{
	return this->color;
}
int Car::getMileage() const{
	return this->mileage;
}
int Car::getEngine() const{
	return this->engine.getNumCylinder();
}

Car::~Car(){
	cout<< endl;
	cout << "Calling Car's destructor on the following car:" << endl;
	this->print();
}

// Start the engine and print the information.
// Please refer to the sample I/O.
void Car::start(){
	cout<<"Car with ";
	engine.Start();
}

// Stop the engine and update the data member "mileage" by adding the traveled distance to it.
// Print the information.
// Please refer to the sample I/O.
void Car::brake(int distance){
	mileage +=distance;
	cout << "Car with ";
	engine.Stop();
	cout << "Driving distance: " << distance << endl;
}

// Print the information of the car. (Please refer to the I/O sample)
void Car::print() const{
	cout << "Engine: "<< engine.getNumCylinder() << '\t' << "Color: ";
	switch(color){
			case 0:
				cout<< "Black";
				break;
			case 1:
				cout<< "White";
				break;
			case 2:
				cout<< "Silver";
				break;
			case 3:
				cout<< "Grey";
				break;
			case 4:
				cout<< "Red";
				break;
			case 5:
				cout<< "Blue";
				break;
				cout<< " ";
			}
	cout<< '\t' << "Current Mileage: " << mileage << endl;
}


