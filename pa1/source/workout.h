//
//  workout.h
//  2012PA1
//
//  Created by Tony Wai Sum JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#ifndef WORKOUT_H
#define WORKOUT_H

#include <iostream>
#include <string>

using namespace std;

/*-----------------------------
 Workout class

 A Buddy can do all kinds of workouts in order to gain muscle and reduce fat
 It is the most effective way to become STRONG, but it consumes a lot of energy,
 thus if he doesn't have enough energy, he won't be able to do the workout
 ------------------------------*/
class Workout {
public:
    /*-----------------------------
     Constructor

     fat_change, muscle_change & energy_change accept all integers
     ------------------------------*/
    Workout(string name = "Attend Lecture", int fat_change = 0, int muscle_change = 0, int energy_change = 0);


    /*-----------------------------
     Name getter
     @return: this's name
     ------------------------------*/
    string get_name() const;

    /*-----------------------------
     Fat change getter
     @return: this's fat_change
     ------------------------------*/
    int get_fat_change() const;

    /*-----------------------------
     Muscle change getter
     @return: this's muscle_change
     ------------------------------*/
    int get_muscle_change() const;

    /*-----------------------------
     Energy change getter
     @return: this's energy_change
     ------------------------------*/
    int get_energy_change() const;

    void print_details(int indent, int index = -1, bool print_addr = false) const {
        string out_indent = string(indent, '\t');
        string in_indent = out_indent + "\t";
        if (index >= 0)
            cout<<out_indent + "Workout "<<index<<": "<<endl;
        else
            cout<<out_indent + "Workout: "<<endl;
        if (print_addr)
            cout<<in_indent + "Address: "<<this<<endl;
        cout<<in_indent + "Name: "<<name<<endl;
        cout<<in_indent + "Fat Change: "<<fat_change<<endl;
        cout<<in_indent + "Muscle Change: "<<muscle_change<<endl;
        cout<<in_indent + "Energy Change: "<<energy_change<<endl;
    };

private:
    // Workout's name
    string name;

    // Workout's affect on a buddy's fat
    int fat_change;
    // Workout's affect on a buddy's muscle
    int muscle_change;
    // Workout's affect on a buddy's energy
    int energy_change;
};

#endif /* WORKOUT_H */
