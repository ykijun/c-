/*
 * Set.cpp
 *
 *  Created on: 2019. 10. 4.
 *      Author: kijun
 */
#include "Set.h"
#include <cmath>
#include <limits>
using namespace std;

// Default constructor: Construct an empty set
Set::Set() {
  elements = NULL;
  size = 0;
}

// Other constructor: Initialize the data members with the given parameters
Set::Set(const int elements[], int size)
{
  this->elements = new int[size];
  this->size = size;
  for(int i=0; i<size; i++)
    (this->elements)[i] = elements[i];
}

// Copy constructor: Perform deep copying
// Hint: Make use of assignment operator function
Set::Set(const Set& s)
{
  elements = NULL;
  size = 0;
  *this = s;
}

// Destructor: De-allocate dynamic memory
Set::~Set()
{
  if(elements != NULL) {
    delete [] elements;
    size = 0;
  }
}

// Return the cardinality of the set, i.e., the size
int Set::cardinality() const
{
  return size;
}

// Return the element's index if it exists. Otherwise return -1
int Set::findElement(const int& element) const
{
  int pos = -1;
  for(int i=0; i<size; i++) {
    if(elements[i] == element) {
      pos = i;
      break;
    }
  }
  return pos;
}

// Return true if the element exists, otherwise return false
bool Set::isExist(const int& element) const
{
  int pos = findElement(element);
  if(pos == -1)
    return false;
  else
    return true;
}

// Allocate a new array of size "size+1", copy all the existing elements over and
// add the new element to the last position of the new array
void Set::addElement(const int& element)
{
  int* newElements = new int[size+1];
  for(int i=0; i<size; i++)
    newElements[i] = elements[i];
  newElements[size] = element;
  delete [] elements;
  elements = newElements;
  size++;
}

// Check if the element is in the set.
// If it is in the set, allocate a new array and copy all the existing elements over except
// the element to be deleted.
// Return true if the element is found and deleted. Otherwise return false
bool Set::removeElement(const int& element)
{
  if(isExist(element)) {
    int pos = findElement(element);
    int* newElements = new int[size-1];
    int count = 0;
    for(int i=0; i<size; i++) {
      if(i != pos) {
        newElements[count] = elements[i];
        count++;
      }
    }
    delete [] elements;
    elements = newElements;
    size--;
    return true;
  }
  else
    return false;
}

// Overload operator+ to support union operation of two set objects

Set Set::operator + (Set& S2){
	Set S1;
	for (int i = 0; i < this->size; i++){
		if (S1.isExist(this->elements[i])){
			continue;
		}
		else{
			S1.addElement(this->elements[i]);
		}
	}

	for (int i = 0; i < S2.size; i++){
		if (S1.isExist(S2.elements[i])){
			continue;
		}
		else{
			S1.addElement(S2.elements[i]);
		}
	}

	return S1;
}

// Overload operator* to support intersect operation of two set objects

Set Set::operator * (Set& S2){
	Set S1;
	for (int i = 0; i < this->size; i++){
		if (S2.isExist(this->elements[i])){
			S1.addElement(this->elements[i]);
		}
		else continue;
	}
	return S1;

}

// Overload assignment operator function
// Note: Deep copying is required

Set Set::operator = (const Set& S2){
	Set S1;
	for (int i = 0; i < this->size; i++){
	S1.addElement(this->elements[i]);
	S1.size = this->cardinality();
	}
	return S1;
}
// Overload equality operator function

bool Set::operator == (Set& S2){

	if (this->size != S2.size){
		return false;
	}
	else {
		for (int i = 0; i < this->size; i++){
			if(!(this->isExist(S2.elements[i]))){
				return false;
			}
		}
	}
	return true;

}


// Overload operator<< to allow output of objects in Set type
ostream& operator<< (ostream& os, const Set& a){
	os << "{";
	for (int i = 0; i < a.size; i++){
		os << a.elements[i]<< "";
		if (i < a.size - 1){
			os << ", ";
		}
		else {
			os << "}";
		}
	}
	return os;
}
