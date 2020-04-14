/*
 * LinearProbing.cpp
 *
 *  Created on: 2019. 11. 22.
 *      Author: kijun
 */

#include <iostream>
#include "LinearProbing.h"
using namespace std;


LinearProbing::LinearProbing(int newSize):Hashing(newSize), data(NULL), occupiedSize(0){
	reset(newSize);
}

LinearProbing::~LinearProbing(){
	if(data != NULL){
		delete []data;
		data = NULL;
	}
}


void LinearProbing::reset(int newSize){
	if ( data != NULL ) {
		delete [] data ;
		data = NULL;
	}
	occupiedSize = 0;
	bucketSize = newSize;
	data = new int[bucketSize];
	for (int i=0; i<bucketSize; i++)
		data[i] = EMPTY;
}

int LinearProbing::getIndexByhashing(int keyValue){
	int index = keyValue % bucketSize;
	while(data[index] != EMPTY){
		index = ((index+1) % bucketSize);
	}
	return index;
}

bool LinearProbing::insert(int newValue){
	if ( occupiedSize < bucketSize ) {
		int itemIndex = getIndexByhashing(newValue);
		if(itemIndex != -1){ //NOTE: -1 means that there are no empty entries in hash table or some other errors exist
			data[itemIndex] = newValue;
			occupiedSize++;
			return true;
		}
	}

	cout<<"the hash table is full!!!"<<endl;
	return false;
}

void LinearProbing::print(){
	cout << "[" ;
	for (int i=0; i<bucketSize; i++) {
		if ( data[i] == EMPTY ) {
			cout << "_" ;
		}
		else {
			cout << data[i] ;
		}
		if ( i<bucketSize-1)
			cout << ", " ;
	}
	cout << "]" << endl ;
}

