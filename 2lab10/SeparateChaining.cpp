
#include <iostream>
#include "SeparateChaining.h"
using namespace std;

SeparateChaining::SeparateChaining(int size): Hashing(size),data(NULL){
	reset(size);
}

SeparateChaining::~SeparateChaining(){
	clearData();
}


void SeparateChaining::reset(int newSize){
	if(data != NULL)
		clearData();

	//create the hash table
	data = new ChainingElem[newSize];
	for(int i = 0; i < newSize; i++){
		data[i].value = EMPTY;			//NOTE: please do not store any other data here
		data[i].next = NULL;	 		//the pointer pointing to the linked list
	}
	bucketSize=newSize;
}

void SeparateChaining::print(){
	cout<<"[";
	for(int i = 0; i < bucketSize; i++){
		if(data[i].next == NULL){
			cout<<"_";
			if(i != bucketSize -1){
				cout<<",";
			}
		}
		else{
			ChainingElem *tmp = data[i].next;
			while(tmp != NULL){
				if(tmp != data[i].next){ //the value is not the first element of the linked list
					cout<<"->";
				}
				cout<<tmp->value;
				tmp = tmp->next;
			}
			cout<<",";
		}
	}
	cout<<"]"<<endl;
}


//TODO: Implement the hash function and return the location in which new value will be inserted
int SeparateChaining::getIndexByhashing(int keyValue){
	int i = 0;
	for (ChainingElem *p = this->data; p != NULL; p = p->next){
		i++;
	}
	if (i == bucketSize){
		return -1;
	}
	else return (keyValue % bucketSize) ;
}



//TODO: Implement the function that will insert the new value into the hash table
bool SeparateChaining::insert(int newValue){
	int index = getIndexByhashing(newValue);
	if (index == -1)
		{return false;}
	else{
		ChainingElem *p = &data[index];
		while (p->next != NULL){
			p = p->next;
		}
		p->next = new ChainingElem;
		p->next->value = newValue;
		p->next->next = NULL;
		return true;
	}
}



//TODO: Implement the function that clear the hash table
//just return true after deletion; you may return false if the data is already deleted when this function is called
bool SeparateChaining::clearData(){
	for(int i = 0; i < bucketSize; i++){
			if(data[i].next != NULL){
				ChainingElem *p = &data[i];
				ChainingElem *pn = p->next;
				while (p == NULL){
					delete p;
					p = pn;
					pn = pn->next;
				}
				p = pn = NULL;
			}
			else continue;
	}
	return true;
}

