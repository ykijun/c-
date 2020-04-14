#include <iostream>
#include <string>
#include "Set.h"
using namespace std;

int main() {
  int intArray1[3] = { 1, 2, 3 };
  int intArray2[3] = { 2, 3, 4 };
  Set A(intArray1, 3);
  Set B(intArray2, 3);
  Set D(intArray1, 3);

  cout << "A = ";
  cout << A << endl;
  cout << "|A| = " << A.cardinality() << endl << endl;

  cout << "B = ";
  cout << B << endl;
  cout << "|B| = " << B.cardinality() << endl << endl;

  Set C = A + B;
  cout << "C = A + B (A union B)" << endl;
  cout << "C = ";
  cout << C << endl;
  cout << "|C| = " << C.cardinality() << endl << endl;

  Set E = A * B;
  cout << "E = A * B (A intersect B)" << endl;
  cout << "E = ";
  cout << E << endl;
  cout << "|E| = " << E.cardinality() << endl << endl;

  cout << "A = ";
  cout << A << endl;
  cout << "B = ";
  cout << B << endl;
  cout << "D = ";
  cout << D << endl;
  cout << "A == B? " << ((A==B)?"true":"false") << endl;
  cout << "A == D? " << ((A==D)?"true":"false") << endl;

  cout << endl;

  return 0;
}
