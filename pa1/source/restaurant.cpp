//
//  restaurant.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "restaurant.h"

Restaurant::Restaurant(string name){
	this->name = name;
	this->list_start_index = 0;
	this->list_end_index = 4;
	this->curr_num_of_meals = 0;
}

string Restaurant::get_name()const{
	return this->name;
}

bool Restaurant::add_meal(Food food){
	string name_ = food.get_name();
	int fat_ = food.get_fat_gain();
	int prot_ = food.get_protein_gain();
	int price_ = food.get_price();

	if (this->curr_num_of_meals == 5){
		return false;
	}
	else{
		this->list_end_index = (this->list_end_index+1)%5;
		this->meals_list[list_end_index]= Food(name_,fat_,prot_,price_);
		curr_num_of_meals++;

	}
	return true;
}

bool Restaurant::remove_first_meal(){
	if(!curr_num_of_meals){
		return false;
	}
	else {
		this->list_start_index = (this->list_start_index + 1)%5;
		curr_num_of_meals--;
	}
	return true;
}

bool Restaurant::remove_last_meal(){
	if (!curr_num_of_meals){
		return false;
	}
	else{
		this->list_end_index = (this->list_end_index+4)%5;
		curr_num_of_meals--;
	}
	return true;
}

bool Restaurant::serve_meal(Buddy* buddy, int meal_index)const{
	buddy->set_fat(buddy->get_fat()+this->meals_list[meal_index].get_fat_gain());
	buddy->set_muscle(buddy->get_muscle()+this->meals_list[meal_index].get_protein_gain());
	buddy->set_money(buddy->get_money()-this->meals_list[meal_index].get_price());
	return true;
}
