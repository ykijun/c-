/*
 * QuadraticProbing.cpp
 *
 *  Created on: 2019. 11. 22.
 *      Author: kijun
 */

#include <iostream>
#include "QuadraticProbing.h"
using namespace std;


QuadraticProbing::QuadraticProbing(int newSize):Hashing(newSize), data(NULL), occupiedSize(0){
	reset(newSize);
}


QuadraticProbing::~QuadraticProbing(){
	if(data != NULL){
		delete []data;
		data = NULL;
	}
}

void QuadraticProbing::reset(int newSize){
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

void QuadraticProbing::print()  {
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

bool QuadraticProbing::insert(int value) {
	if ( occupiedSize < bucketSize ) {
		int itemIndex = getIndexByhashing(value);
		if(itemIndex != -1){ //NOTE: -1 means that there are no empty entries in hash table or some other errors exist
			data[itemIndex] = value;
			occupiedSize++;
			return true;
		}
	}

	cout<<"the hash table is full!!!"<<endl;
	return false;
}
int QuadraticProbing::getIndexByhashing(int keyValue){
	int index = keyValue % bucketSize;
	int inc= 0;
	while(data[index] != EMPTY){
		index = (keyValue % bucketSize+(inc*inc))%bucketSize;
		inc++;
	}
	return index;
}


