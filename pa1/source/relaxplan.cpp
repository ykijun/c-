//
//  relaxplan.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 3/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxplan.h"

// Example solution for copy constructor, you don't have to implement it
RelaxPlan::RelaxPlan(RelaxPlan const & rp): name(rp.name) {
    // empty list
    if (!rp.head) {
        head = NULL;
        return;
    }
    // copy first node, prepare to copy second
    head = new Relaxation(*rp.head);
    Relaxation* curr_copied = head;
    Relaxation* next_to_copy = rp.head->get_next();
    // while next exists, continue copy
    while (next_to_copy) {
        Relaxation* copied = new Relaxation(*next_to_copy);
        curr_copied->set_next(copied);
        // next_to_copy is always a node in rp
        // curr_copied is always a node in self
        next_to_copy = next_to_copy->get_next();
        curr_copied = copied;
    }
}

RelaxPlan::RelaxPlan(string name){
	this->name = name;
	this->head = NULL;
}

Relaxation* RelaxPlan::get_head()const{
	return this->head;
}

void RelaxPlan::addToStart(Relaxation r){
	string name_ = r.get_name();
	int energy_ = r.get_energy_gain();
	Relaxation* head_ = this->head;

	if (!this->head){
		this->head = new Relaxation(name_, energy_);
	}
	else if(this->head){
		this->head = new Relaxation(name_, energy_);
		this->head->set_next(head_);
	}


}

void RelaxPlan::addToEnd(Relaxation r){
	string name_ = r.get_name();
	int energy_ = r.get_energy_gain();
	Relaxation* head_ = this->head;

	if (!this->head)
		this->head = new Relaxation(name_,energy_);
	else if(this->head){
		while(head_->get_next()){
			head_ = head_->get_next();
		}
		head_->set_next(new Relaxation(name_, energy_));
	}
}

bool RelaxPlan::remove(int remove_index){
	Relaxation* curr_ = this->head;
	Relaxation* rese_ ;
	if(remove_index < 0)
		return false;
	if(remove_index == 0 && this->head == NULL)
		return false;
	if(remove_index == 0){
		this->head = curr_->get_next();
	}
	else{
		while(remove_index){
			rese_ = curr_;
			curr_ = curr_->get_next();
			remove_index--;
			if(!curr_)
				return false;
		}

		rese_->set_next(curr_->get_next());
	}
	delete curr_;
	return true;
}

RelaxPlan::~RelaxPlan(){

		Relaxation* p = this->head;
		Relaxation* next;
		while (p){
			next=p->get_next();
			delete p;
			p=next;
		}
}
