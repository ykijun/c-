/*
 * Vehicle.h
 *
 *  Created on: 2019. 11. 1.
 *      Author: kijun
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "Engine.h"

class Vehicle : private Engine
{
public:
	Vehicle(int nc, Color color, int mileage); // Constructor

	Color getColor() const;
	int getMileage() const;
	int getEngine() const;
	~Vehicle();

	void start();

	void brake(int distance);


	void print() const;

private:
	Color color;	// Color of the Vehicle
	int mileage;	// Total mileage

};



#endif /* SOURCE_VEHICLE_H_ */
