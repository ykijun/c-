/*
 * DoubleHashing.h
 *
 *  Created on: 2019. 11. 22.
 *      Author: kijun
 */

#ifndef DOUBLEHASHING_H_
#define DOUBLEHASHING_H_
#include "Hashing.h"

class DoubleHashing: public Hashing{
public:
	DoubleHashing(int size);
	~DoubleHashing();

	virtual void reset(int newSize);
	virtual void print();
	virtual bool insert(int newValue);

	virtual int getIndexByhashing(int keyValue);


protected:
	int *data;
	int occupiedSize;
};

#endif /* DOUBLEHASHING_H_ */
