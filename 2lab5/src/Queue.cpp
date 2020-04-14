#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
	n = 0;
}

int Queue::dequeue()
{
	if(n<=0)
	{
		cerr << "Queue is empty!" << endl;
		return -1;
	}

	int front = content[0];
	for(int i=0;i<n-1;i++)
		content[i] = content[i+1];
	n--;
	return front;
}

void Queue::enqueue(int element)
{
	if(n>=SIZE)
	{
		cerr << "Queue is full!" << endl;
		return;
	}

	content[n] = element;
	n++;
}
