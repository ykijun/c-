/*
 * DoubleHashing.cpp
 *
 *  Created on: 2019. 11. 22.
 *      Author: kijun
 */

#include <iostream>
#include "DoubleHashing.h"
using namespace std;


DoubleHashing::DoubleHashing(int newSize):Hashing(newSize), data(NULL), occupiedSize(0){
	reset(newSize);
}

DoubleHashing::~DoubleHashing(){
	if(data != NULL){
		delete []data;
		data = NULL;
	}
}


void DoubleHashing::reset(int newSize){
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
int DoubleHashing::getIndexByhashing(int keyValue){ // hi(K) = ( hash(K)+ i*hash2(K) ) mod m & hash2(K) = 5 - (K mod 5)
	int index = keyValue % bucketSize;
	int index2 = 5 - (keyValue % 5);
	int inc = 0;
	while(data[index] != EMPTY){
		index = (keyValue % bucketSize + inc*index2) % bucketSize;
		inc++;
	}
	return index;

}
bool DoubleHashing::insert(int newValue){
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

void DoubleHashing::print(){
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
