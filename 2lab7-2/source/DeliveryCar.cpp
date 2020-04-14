/*
 * DeliveryCar.cpp
 *
 *  Created on: 2019. 11. 1.
 *      Author: kijun
 */

#include <iostream>
#include "DeliveryCar.h"
#include "Vehicle.h"

using namespace std;

DeliveryCar::DeliveryCar(int a, Color b, int c, int cpm): Vehicle(a,b,c),chargePerMile(cpm){// Constructor

}

DeliveryCar::~DeliveryCar(){
	cout<<endl;
	cout<<"Calling Vehicle's destructor on the following delivery car: "<<endl;
	this->print();
}
void DeliveryCar::start(){
	Vehicle::start();
}
void DeliveryCar::brake(int dist){
	Vehicle::brake(dist);
}



int DeliveryCar::getChargePerMile() const{
	return this->chargePerMile;
}

void DeliveryCar::setChargePerMile(int charge){
	this->chargePerMile = charge;
}

////Print the information of the PoliceCar. Please refer to the sample I/O.
void DeliveryCar::print() const{
	cout << "Information of the delivery car:"<<endl;
	cout << "Engine: "<< this->getEngine()<< '\t' << "Color: ";
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
		cout<< '\t' << "Current Miles: " << this->getMileage()<< endl;
		cout<< "DeliveryCar's charges per mile: "<< this->getChargePerMile() <<endl;
		cout<< "DeliveryCar's calculated charges: " << this->getChargePerMile()*this->getMileage()<<endl;


}


