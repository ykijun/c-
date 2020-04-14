/*
 * Set.h
 *
 *  Created on: 2019. 10. 4.
 *      Author: kijun
 */


#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

class Set
{
  public:
    // Default constructor: Construct an empty set
    Set();

    // Other constructor: Initialize the data members with the given parameters
    Set(const int elements[], int size);

    // Copy constructor: Perform deep copying
    // Hint: Make use of assignment operator function
    Set(const Set& s);

    // Destructor: De-allocate dynamic memory
    ~Set();

    // Return the cardinality of the set, i.e., the size
    int cardinality() const;

    // Return the element's index if it exists. Otherwise return -1
    int findElement(const int& element) const;

    // Return true if the element exists, otherwise return false
    bool isExist(const int& element) const;

    // Allocate a new array of size "size+1", copy all the existing elements over and
    // add the new element to the last position of the new array
    void addElement(const int& element);

    // Check if the element is in the set.
    // If it is in the set, allocate a new array and copy all the existing elements over except
    // the element to be deleted.
    // Return true if the element is found  	and deleted. Otherwise return false
    bool removeElement(const int& element);

    // Overload operator+ to support union operation of two set objects

    Set operator + (Set& S);

	// Overload operator* to support intersect operation of two set objects

    Set operator * (Set& S);

	// Overload assignment operator function
	// Note: Deep copying is required

    Set operator = (const Set& S);
	// Overload equality operator function

    bool operator == (Set& S);

    friend ostream& operator<< (ostream& os, const Set& a);

  private:
    int* elements;	// A pointer to an array of objects in type int storing all elements of the set
    int size;		// The number of the elements in the array, i.e. the size of the set
};

#endif
