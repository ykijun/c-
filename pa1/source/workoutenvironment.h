//
//  workoutenvironment.h
//  2012PA1
//
//  Created by Tony Wai Sum JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#ifndef WORKOUTENVIRONMENT_H
#define WORKOUTENVIRONMENT_H

#include <iostream>
#include <string>
#include "workout.h"
#include "buddy.h"

using namespace std;

/*-----------------------------
 WorkoutEnvironment class (dynamic arrays)

 A person (Buddy) needs to go to an env (WorkoutEnvironemnt) to do workouts.
 In order to start doing workouts, he needs to register at the env, which requires an entry fee.
 Afterwards, he can do all the workouts that the env has.

 Moreover, doing workouts consumes a lot of energy, thus he can't do more workouts if he doesn't have enough energy. In this case, he may need to have some Relaxations, and he will be filled with determination (energy)
 ------------------------------*/
class WorkoutEnvironment {
public:
    /*-----------------------------
     Constructor
     @appendix:
        available_workouts = dynamic array with length MAX_NUM_OF_WORKOUTS
        current_num_of_workouts = 0
        participants = NULL
        current_num_of_participants = 0

     you may assume:
        entry_fee is non-negative
        MAX_NUM_OF_WORKOUTS is positive
     ------------------------------*/
    WorkoutEnvironment(string name, int entry_fee, int MAX_NUM_OF_WORKOUTS);

    /*-----------------------------
     Destructor

     Delete the available_workouts array
     Delete the participants array
     DO NOT delete the buddy objects inside the participants array, their life cycles are managed elsewhere
     ------------------------------*/
    ~WorkoutEnvironment();


    /*-----------------------------
     Name getter
     @return this's name
     ------------------------------*/
    string get_name() const;

    /*-----------------------------
     Entry fee getter
     @return this's entry_fee
     ------------------------------*/
    int get_entry_fee() const;


    /*-----------------------------
     Insert a workout at available_workouts[add_index]. (Fix length dynamic array)
     @return: whether the add is success or not

     @appendix:
        You need to check whether the index is valid or not.
        Valid indices are in [0, current_num_of_workouts], and the array shouldn't be full.

        If the insertion cannot be done, do nothing and return false;
        otherwise perform the adding and return true.

        The workout inserted is actually a copy of the passed in workout.

     Example:

     initial: MAX_NUM_OF_WORKOUTS = 4; current_num_of_workouts = 0;

     add_workout: "Wrestling", 2
     result: false (index invalid)

     add_workout: "Wrestling", 0
     result: true
        0: "Wrestling"

     add_workout: "Bicep Dumbbell Curl", 1
     add_workout: "Machine Shoulder Press", 2
     result: true
        0: "Wrestling"
        1: "Bicep Dumbbell Curl"
        2: "Machine Shoulder Press"

     add_workout: "Machine Chest Fly", 1
     result: true
        0: "Wrestling"
        1: "Machine Chest Fly"
        2: "Bicep Dumbbell Curl"
        3: "Machine Shoulder Press"

     add_workout: "Type Code", 1
     result: false (array full)
        (array not changed)
     ------------------------------*/
    bool add_workout(const Workout& workout, int add_index);

    /*-----------------------------
     Remove a workout at available_workouts[remove_index]. (Fix length dynamic array)
     @return: whether the remove is successful or not

     @appendix:
        You need to check whether the index is valid or not.
        Valid indices are in [0, current_num_of_workouts), and the array shouldn't be empty.

        If the removal cannot be done, do nothing and return false;
        otherwise perform the removal and return true.

     Example:

     initial: MAX_NUM_OF_WORKOUTS = 4; current_num_of_workouts = 4;
        0: "Wrestling"
        1: "Machine Chest Fly"
        2: "Bicep Dumbbell Curl"
        3: "Machine Shoulder Press"

     remove_workout: 4
     result: false

     remove_workout: 3
     result: true
        0: "Wrestling"
        1: "Machine Chest Fly"
        2: "Bicep Dumbbell Curl"

     remove_workout: 1
     result: true
        0: "Wrestling"
        1: "Bicep Dumbbell Curl"

     remove_workout: 2
     result: false

     remove_workout: 0
     remove_workout: 0
     result: true
        empty array; current_num_of_workouts = 0;

     remove_workout: 0
     result: false
     ------------------------------*/
    bool remove_workout(int remove_index);


    /*-----------------------------
     Get the buddy's index in the participants array
     @return:
        the index of the buddy if he is registered.
        If he is not registered, return -1.

     You may assume buddy is not NULL
     ------------------------------*/
    int participant_index(const Buddy* buddy) const;

    /*-----------------------------
     Add the buddy to the end of the participants array
     @return: whether the add is successful or not

     If the buddy is already registered or he does not have enough money:
        - do nothing and return false
     otherwise
        - deduct money!
        - Update array
            1. create a new double pointer array with length (current_num_of_participants + 1).
            2. copy all previous Buddy* to the new array. This is only copying addresses, not the Buddy objects.
            3. assign the passed in buddy* to the new array's 'current_num_of_participants' element, this is also copying addresses.
            4. delete[] participants, DO NOT delete the pointers to the Buddy objects inside the array.
            5. participants = new array, update 'current_num_of_participants'.

     If you get stuck in this function, we strongly recommend you revise 2011 (or Google) to have a clearer understanding of memory & addresses.
     You may assume buddy is not NULL.
     ------------------------------*/
    bool register_participant(Buddy* buddy);


    /*-----------------------------
     Let a Buddy start his workout in this env
     @return: true if the participant finishes the workout; otherwise false

     1. check if participant_index & workout_index are valid
     2. check if buddy has enough energy to do this workout
     3. buddy's fat += workout's fat_change
        buddy's muscle += workout's muscle_change
        buddy's energy += workout's energy_change
     ------------------------------*/
    bool start_workout(int participant_index, int workout_index) const;

    void print_details(int indent) const {
        string out_indent = string(indent, '\t');
        string in_indent = out_indent + "\t";
        cout<<out_indent + "Workout Environment: "<<endl;
        cout<<in_indent + "Name: "<<name<<endl;
        cout<<in_indent + "Entry Fee: "<<entry_fee<<endl;
        cout<<in_indent + "Available Workouts: address "<<available_workouts<<" (Max Number "<<MAX_NUM_OF_WORKOUTS<<")"<<endl;
        for (int i=0; i<current_num_of_workouts; i++) {
            available_workouts[i].print_details(indent + 2, i, true);
        }
        cout<<in_indent + "Participants: address "<<participants<<endl;
        for (int i=0; i<current_num_of_participants; i++) {
            participants[i]->print_details(indent + 2, i, true);
        }
    };

private:
    // Workout Enviroment's name. e.g. "GYM"
    string name;

    // the money that a buddy needs to pay in order to be registered, you may assume it is non-negative
    const int entry_fee;

    // a const pointer to a dynamic array of Workouts. Initialized in constructor.
    Workout* const available_workouts;
    // the max number of workouts that this env can held.
    // You can't put 1000 bench press machines into a single gym, right? :-)
    const int MAX_NUM_OF_WORKOUTS;
    // the current number of workouts added to this env
    int current_num_of_workouts;

    // (a pointer to a dynamic array of (pointer to buddy / buddies)
    // (pointer to buddy) means keeping track of the buddy object, not copying one.
    // an array of (pointer to buddy) means a 'form' storing all those buddies' addresses
    Buddy** participants;
    // the current number of participants registered at this env
    // no max number. A gym won't reject 1000 participants, right? :-)
    int current_num_of_participants;
};

#endif /* WORKOUTENVIRONMENT_H */
