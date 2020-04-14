//
//  food.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "food.h"

	Food::Food(string name, int fat_gain, int protein_gain, int price){
		this->name = name;
		this->fat_gain = fat_gain;
		this->protein_gain = protein_gain;
		this->price = price;

	}

	string Food::get_name()const{
		return this->name;
	}

	int Food::get_fat_gain()const{
		return this->fat_gain;
	}

	int Food::get_protein_gain()const{
		return this->protein_gain;
	}

	int Food::get_price()const{
		return this->price;
	}
