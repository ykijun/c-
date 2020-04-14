/*
 * LinearProbing.h
 *
 *  Created on: 2019. 11. 22.
 *      Author: kijun
 */

#ifndef LINEARPROBING_H_
#define LINEARPROBING_H_
#include "Hashing.h"

class LinearProbing: public Hashing{
public:
	LinearProbing(int size);
	~LinearProbing();

	virtual void reset(int newSize);
	virtual void print();
	virtual bool insert(int newValue);

	virtual int getIndexByhashing(int keyValue);


protected:
	int *data;
	int occupiedSize;
};

#endif /* LINEARPROBING_H_ */
