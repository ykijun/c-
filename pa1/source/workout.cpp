//
//  workout.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workout.h"


Workout::Workout(string name, int fat_change, int muscle_change, int energy_change){
	this->name = name;
	this->fat_change = fat_change;
	this->muscle_change = muscle_change;
	this->energy_change = energy_change;
}

string Workout::get_name()const{
	return this->name;
}

int Workout::get_fat_change()const{
	return this->fat_change;
}

int Workout::get_muscle_change()const{
	return this->muscle_change;
}

int Workout::get_energy_change()const{
	return this->energy_change;
}

