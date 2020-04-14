//
//  buddy.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "buddy.h"

Buddy::Buddy(string name, int fat, int muscle, int energy, int money){

	this->name = name;
	this->fat = fat;
	this->muscle = muscle;
	this->energy = energy;
	this->money = money;

}

string Buddy::get_name() const{
	return this->name;
}

int Buddy::get_fat()const{
	return this->fat;
}

int Buddy::get_muscle()const{
	return this->muscle;
}

int Buddy::get_energy()const{
	return this->energy;
}

int Buddy::get_money()const{
	return this->money;
}
void Buddy::set_fat(int fat){
	this->fat = fat;
}
void Buddy::set_muscle(int muscle){
	this->muscle = muscle;
}
void Buddy::set_energy(int energy){
	this->energy = energy;
}
void Buddy::set_money(int money){
	if (money < 0){
		this->money = 0;
	}
	else
	this->money = money;
}
void Buddy::earn_money(int money, int times){
	this->money += money * times;
}
void Buddy::gain_energy(RelaxPlan plan){
	Relaxation* head_ = plan.get_head();
	while(head_){
		this->energy += head_->get_energy_gain();
		head_=head_->get_next();
	}
}

