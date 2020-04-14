//
//  workoutenvironment.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workoutenvironment.h"

WorkoutEnvironment::WorkoutEnvironment(string name, int entry_fee, int MAX_NUM_OF_WORKOUTS):MAX_NUM_OF_WORKOUTS(MAX_NUM_OF_WORKOUTS),entry_fee(entry_fee),available_workouts (new Workout[MAX_NUM_OF_WORKOUTS]){
	this->name = name;
	this->current_num_of_workouts = 0;
    this->participants = NULL;
    this->current_num_of_participants = 0;
}

string WorkoutEnvironment::get_name()const{
	return this->name;
}

int WorkoutEnvironment::get_entry_fee()const{
	return this->entry_fee;
}

bool WorkoutEnvironment::add_workout(const Workout& workout, int add_index){

	if (add_index > this->current_num_of_workouts){
		return false;
	}
	else if(this->current_num_of_workouts == this->MAX_NUM_OF_WORKOUTS){
		return false;
	}
	else{
		if (add_index < this->current_num_of_workouts){
			for (int i = this->current_num_of_workouts; i >(add_index); i--){
				this->available_workouts[i] = this->available_workouts[i-1];
			}
		}
		this->available_workouts[add_index] = workout;
		this->current_num_of_workouts++;
	}
	return true;
}
bool WorkoutEnvironment::remove_workout(int remove_index){
	if(remove_index >= this->current_num_of_workouts){
		return false;
	}
	else{
		for (int i = remove_index; i <(this->current_num_of_workouts-1); i++){
			this->available_workouts[i] = this->available_workouts[i+1];
		}
		this->current_num_of_workouts--;
	}
	return true;
}
int WorkoutEnvironment::participant_index(const Buddy* buddy)const{
	for (int i = 0;i < current_num_of_participants; i++){
		if (buddy->get_name() == participants[i]->get_name())
			return i;
		else continue;
	}
	return -1;
}

bool WorkoutEnvironment::register_participant(Buddy* buddy){

	if (buddy->get_money() < this->entry_fee){
		return false;
	}
	else if (participant_index(buddy) >= 0){
		return false;
	}

	else{
		buddy->set_money((buddy->get_money()) - (this->entry_fee));
		Buddy** arry = new Buddy*[current_num_of_participants + 1];
		for (int i = 0; i <current_num_of_participants; i++){
			arry[i] = participants[i];
		}
		arry[current_num_of_participants] = buddy;
		delete [] participants;
		participants = arry;

	}
	current_num_of_participants++;

	return true;

}

bool WorkoutEnvironment::start_workout(int participant_index, int workout_index)const{
	if (participant_index >= current_num_of_participants || workout_index >= current_num_of_workouts){
		return false;
	}
	else if((participants[participant_index]->get_energy() + available_workouts[workout_index].get_energy_change()) < 0){
		return false;
	}
	else{
		participants[participant_index]->set_fat(participants[participant_index]->get_fat()+available_workouts[workout_index].get_fat_change());
		participants[participant_index]->set_muscle(participants[participant_index]->get_muscle()+available_workouts[workout_index].get_muscle_change());
		participants[participant_index]->set_energy(participants[participant_index]->get_energy()+available_workouts[workout_index].get_energy_change());
	}
	return true;
}

WorkoutEnvironment::~WorkoutEnvironment(){
	delete[] available_workouts;
	delete[] participants;
}
