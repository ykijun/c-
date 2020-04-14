/*
 * PoliceCar.cpp
 *
 *  Created on: 2019. 11. 1.
 *      Author: kijun
 */

#include <iostream>
#include "PoliceCar.h"
#include "Car.h"
using namespace std;

PoliceCar::PoliceCar(int a, Color b, int c, bool d):Car(a,b,c),inAction(false){

}
PoliceCar::~PoliceCar(){
	cout << endl;
	cout << "Calling PoliceCar's destructor on the following police car:" <<endl;
	this->print();

}

bool PoliceCar::getInAction() const{
	return inAction;
}

void PoliceCar::setInAction(bool action){
	inAction = action;
}

////Print the information of the PoliceCar. Please refer to the sample I/O.
void PoliceCar::print() const{
	cout <<"Information of the police car:" <<endl;
	cout << "Engine: "<< this->getEngine() << '\t' << "Color: ";
	switch(this->getColor()){
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
	cout<< '\t' << "Current Mileage: " << this->getMileage() << endl;
	cout << "PoliceCar's state: ";
			if(this->getInAction())
		cout << "in action" << endl;
	else
		cout << "not in action" << endl;

}
