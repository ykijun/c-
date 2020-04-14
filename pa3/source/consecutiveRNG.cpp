// SUBMIT THIS FILE
#include "consecutiveRNG.h"
using namespace std;


ConsecutiveRNG::ConsecutiveRNG(){ //remember to initialize the data member here, you can decide on the initial value of current
current = 0;
}

ConsecutiveRNG::~ConsecutiveRNG(){} //nothing needs to be done in this destructor

int ConsecutiveRNG::getRandomNumber(){ //return a fake "random" number, see webpage for description
	int prev = current;
	current++;
	if(current > 32767){
		current = current % 32768;
	}
	return prev;
    }
