#include "Queue.h"
#include "Stack.h" // TODO: implement a stack using  an array in Stack.h and Stack.cpp (to be created by yourself)
#include <iostream>
using namespace std;

// checkBox: Determine whether the switch box is routable
bool checkBox(Stack pins)
{

    // TODO: Return true if it is routable, false otherwise
    // Use Stack to implement this part
	int a;
	   int n = 0;
	   int distance=0;
	   Stack temp;

	   while(!pins.empty())
	   {
	      temp.Push(pins.pop());
	      n++;
	   }

	   for(int i = 0; i<n; i++)
	   {
	      Stack temp2;
	      a = temp.pop();


	      for(int i=n-1; i>0; i--)
	      {
	         if(a==temp.top())
	         {

	            if((distance%2)==1)
	            {
	               return false;
	            } else {

	               temp.pop();
	            }
	         }
	         else {
	            temp2.Push(temp.pop());
	            distance++;
	         }
	      }
	      temp = temp2;
	      distance = 0;
	   }
	   return true;
}

int main()
{
    int n;
    Stack pins;

    cout << "** Assumption: The number of pins is even and it is greater than or equal to  2 **" << endl ;

    cout << "Type number of pins in switch box: " ;
    cin >> n ;

    cout << "Type numbers for pins 1 through " << n << ": " ;
    int k;
    for (int i=0;i<n;i++)
    {
        cin >> k;
        pins.Push(k);
    }

    bool result = checkBox(pins);
    if ( result ) {
        cout << "The switch box is routable" << endl ;
    } else {
        cout << "The switch box is NOT routable" << endl ;
    }

    return 0;
}
