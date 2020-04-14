/*
 * DeliveryCar.cpp
 *
 *  Created on: 2019. 11. 1.
 *      Author: kijun
 */

#include <iostream>
#include "Vehicle.h"
#include "Engine.h"

using namespace std;

Vehicle::Vehicle(int nc, Color color, int mileage):Engine(nc),color(color), mileage(mileage){

}

Color Vehicle::getColor() const{
	return this->color;
}
int Vehicle::getMileage() const{
	return this->mileage;

}
int Vehicle::getEngine() const{
	return Engine::getNumCylinder();
}

Vehicle::~Vehicle(){
	cout<<endl;
	cout << "Calling Vehicle's destructor on the following vehicle:"<<endl;
	this->print();
}

void Vehicle::start(){
	cout << "Vehicle with ";
	Engine::Start();
}

void Vehicle::brake(int distance){
	mileage +=distance;
	//this->mileage = this->getMileage() + distance;
	cout << "Vehicle with ";
	Engine::Stop();
	cout << "Driving distance: " << distance << endl;
}


void Vehicle::print() const{
	cout << "Engine: "<< Engine::getNumCylinder() << '\t' << "Color: ";
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
		cout<< '\t' << "Current Miles: " << mileage << endl;
}

