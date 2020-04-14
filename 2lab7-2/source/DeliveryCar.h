/*
 * DeliveryCar.h
 *
 *  Created on: 2019. 11. 1.
 *      Author: kijun
 */

#ifndef DELIVERYCAR_H_
#define DELIVERYCAR_H_

#include "Vehicle.h"

class DeliveryCar : protected Vehicle
{
public:
	DeliveryCar(int nc, Color c, int m, int chargepermile);	//Constructor
	~DeliveryCar(); //Destructor


	void start();
	void brake(int distance);
	int getChargePerMile() const;
	void setChargePerMile(int charge);

	////Print the information of the PoliceCar. Please refer to the sample I/O.
	void print() const;

private:
	int chargePerMile;	//Data member indicating whether the police car is in action.
};



#endif /* SOURCE_DELIVERYCAR_H_ */
