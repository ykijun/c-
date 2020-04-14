/*
 * QuadraticProbing.h
 *
 *  Created on: 2019. 11. 22.
 *      Author: kijun
 */

#ifndef QUADRATICPROBING_H_
#define QUADRATICPROBING_H_
#include "Hashing.h"

class QuadraticProbing: public Hashing{
public:
	QuadraticProbing(int size);
	~QuadraticProbing();

	virtual void reset(int newSize);
	virtual void print();
	virtual bool insert(int newValue);

	virtual int getIndexByhashing(int keyValue);


protected:
	int *data;
	int occupiedSize;
};

#endif /* QUADRATICPROBING_H_ */
