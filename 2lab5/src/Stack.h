/*
 * Stack.h
 *
 *  Created on: 2019. 10. 22.
 *      Author: kijun
 */

#ifndef STACK_H_
#define STACK_H_

const int SIZE2 = 1024;

class Stack
{
private:
	int element[SIZE2]; //stores the data
	int m; //number of elements


public:
	Stack();
	void Push(int element);
	int pop();
	int top();
	bool empty();

};





#endif /* STACK_H_ */
