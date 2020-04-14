/*
 * main.cpp
 *
 *  Created on: 2019. 10. 29.
 *      Author: kijun
 */


#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

void printSetUsingIterator(const set<string>& s) {
   // TODO: Print a set of string using iterator

	set<string>::iterator itr = s.begin();
	cout << "{";
	while(itr != s.end()){
		cout << *itr ;
		if (itr != prev(s.end(),1)){
			cout << ", ";
		}
		itr++;
	}
	cout << "}"<< endl;


}

void printListUsingIterator(const list<string>& s) {
   // TODO: Print a list of string using iterator

	list<string>::const_iterator itr = s.begin();
	cout << "{";
	while(itr != s.end()){
		cout << *itr ;
		if (itr != prev(s.end(),1)){
			cout << ", ";
		}
		itr++;
	}
	cout << "}"<< endl;
}

void printMapUsingIterator(const map<string,int>& s) {
   // TODO: Print a map using iterator

	map<string,int>::const_iterator itr = s.begin();

	while(itr != s.end()){
		cout << "key: " << itr->first <<'\t'<< "Value: "<< itr->second<< endl;
		itr++;
	}

}


//TODO: You may need to define a comparator function yourself here (for the sorting task)
bool comparator(const string a , const string b){
	return (a.size() < b.size());
}

int main() {

	cout << endl;
	cout << "************************** Part1: set **************************";
	cout << endl;

	set<string> Fictions, Movies;
	Fictions.insert("The Time Machine");
	Fictions.insert("Harry Potter");
	Fictions.insert("The Lord of the Rings");

	Movies.insert("The Shawshank Redemption");
	Movies.insert("City of God");
	Movies.insert("The Lord of the Rings");
	Movies.insert("Harry Potter");

	cout << "Set Fictions Content =" ;
	printSetUsingIterator(Fictions);
	cout << "Set Movies Content =" ;
	printSetUsingIterator(Movies);

    // Part 1 TODO: Complete the set operations: intersection
	set<string> interSet;

   // ADD YOUR CODE HERE
	for (set<string>::iterator itr = Fictions.begin(); itr != Fictions.end();itr++){
		for(set<string>::iterator itr2 = Movies.begin(); itr2 != Movies.end(); itr2++){
			if (*itr == *itr2)
				interSet.insert(*itr);
		}
	}

   cout << "Fictions intersect Movies Content = ";
   printSetUsingIterator(interSet);

   cout << endl;
	cout << "************************** Part2: list **************************";
   cout << endl;

	// Merge Fictions and Movies to listR
	list<string> listR ;


   // Part 2 TODO: Merge Fictions and Movies to listR
   // ADD YOUR CODE HERE

	for (set<string>::iterator itr = Fictions.begin(); itr != Fictions.end();itr++){
		listR.push_back(*itr);
	}

	for(set<string>::iterator itr2 = Movies.begin(); itr2 != Movies.end(); itr2++){
		listR.push_back(*itr2);
	}

	listR.sort();


	cout << "List R Content = ";
	printListUsingIterator(listR);

	// Part 2 TODO:
    //Add a new string "Saw" at the end of the list
    //Add a new string "Avenger" at the head of the list
    // ADD YOUR CODE HERE

	listR.push_back("Saw");
	listR.push_front("Avenger");


	cout << "New R Content = ";
	printListUsingIterator(listR);

	 // Sort listR by movie name length ascendingly
    // ADD YOUR CODE HERE

//	sort(listR.begin(), listR.end(), comparator);
	listR.sort(comparator);



	cout << "Sorted R Content = ";
	printListUsingIterator(listR);

   cout << endl;
	cout << "************************** Part3: map **************************";
   cout << endl;

    //map
	map<string,int> mapMovie;
	mapMovie.insert(make_pair("The Shawshank Redemption",1994));
	mapMovie.insert(make_pair("City of God",2002));
	mapMovie.insert(make_pair("The Lord of the Rings", 2002));
	mapMovie.insert(make_pair("Star Wars", 1977));
	mapMovie.insert(make_pair("Forest Gump", 1994));
	cout << "mapMovie Content: "<<endl;
	printMapUsingIterator(mapMovie);

   //Part3 TODO : Complete element search and deletion in mapMovie here
    // search "Star Wars" in map
    // ADD YOUR CODE HERE

	cout<< "Key found, the value is "<< mapMovie.find("Star Wars")->second <<endl;

    // delete "City of God" in map
    // ADD YOUR CODE HERE

	mapMovie.erase("City of God");



	cout << "mapMovie Content after deletion: "<<endl;
	printMapUsingIterator(mapMovie);



	return 0;
}
