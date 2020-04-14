/*
 * Stack.cpp
 *
 *  Created on: 2019. 10. 22.
 *      Author: kijun
 */

#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
	m = 0;
}

void Stack::Push(int number){
	if (m >= SIZE2){
		return;
	}
	else if (m == 0) {
		element[0] = number;

	}
	else {
		element[m] = number;

	}
	m++;


}

int Stack::pop(){
	   if(m<=0)
	   {
	      return -1;
	   }

	   int top = element[m-1];
	   element[m-1] = -1;
	   m--;
	   return top;
}

int Stack::top(){
	if (m<=0)
		return -1;
	return this->element[m-1];
}

bool Stack::empty(){
	if (m)
		return false;
	return true;
}

