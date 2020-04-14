//
//  buddy.h
//  2012PA1
//
//  Created by Tony Wai Sum JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#ifndef BUDDY_H
#define BUDDY_H

#include <iostream>
#include <string>
#include "relaxplan.h"

using namespace std;

/*-----------------------------
 Buddy Class

 The class which represents a person.
  - A Buddy need to pay money when entering workout environments and ordering meals in restaurants.
  - Doing workouts in workout environments will affect his fat & muscle, and decrease his energy & money.
  - Eating meals in restaurants will affect his fat & muscle, and decrease his money.
  - Relax plans help him gain energy.
 ------------------------------*/
class Buddy {
public:
    /*-----------------------------
     Constructor
     @param name: string
     @param fat: accept all integers
     @param muscle: accept all integers
     @param energy:
        DOES NOT accept negative integers,
        in this case set this's energy to 0
     @param money:
        DOES NOT accept negative integers,
        in this case set this's money to 0
     ------------------------------*/
    Buddy(string name, int fat = 1000, int muscle = 0, int energy = 100, int money = 1000);

    /*-----------------------------
     Name getter
     @return: this's name
     ------------------------------*/


    string get_name() const;

    /*-----------------------------
     Fat getter
     @return: this's fat
     ------------------------------*/
    int get_fat() const;

    /*-----------------------------
     Muscle getter
     @return: this's muscle
     ------------------------------*/
    int get_muscle() const;

    /*-----------------------------
     Energy getter
     @return: this's energy
     ------------------------------*/
    int get_energy() const;

    /*-----------------------------
     Money getter
     @return: this's money
     ------------------------------*/
    int get_money() const;

    /*-----------------------------
     Fat setter
     @param fat: accept all integers
     ------------------------------*/
    void set_fat(int fat);

    /*-----------------------------
     Muscle setter
     @param muscle: accept all integers
     ------------------------------*/
    void set_muscle(int muscle);

    /*-----------------------------
     Energy setter
     @param energy:
        DOES NOT accept negative integers,
        in this case set this's energy to 0
     ------------------------------*/
    void set_energy(int energy);

    /*-----------------------------
     Money setter
     @param money:
        DOES NOT accept negative integers,
        in this case set this's money to 0
     ------------------------------*/
    void set_money(int money);


    /*-----------------------------
     Increase this's money according to inputs,
     No need to consider negative money input / negative times
     for example:
        this->money = 100
        input money = 8
        input times = 9
     result:
        this->money = 100 + 8*9 = 172
     ------------------------------*/
    void earn_money(int money, int times);

    /*-----------------------------
     Increase this's energy according to the input linked list
     for each node in plan's linked list:
        this's energy += node->energy_gain

     for exmaple:
        this->energy = 100
        plan: ("Sleep", 10) -> ("Hang out", 15)
     result:
        this->energy = 100 + 10 + 15 = 125
     ------------------------------*/
    void gain_energy(RelaxPlan plan);

    void print_details(int indent, int index = -1, bool print_addr = false) const {
        string out_indent = string(indent, '\t');
        string in_indent = out_indent + "\t";
        if (index >= 0)
            cout<<out_indent + "Buddy "<<index<<": "<<endl;
        else
            cout<<out_indent + "Buddy: "<<endl;
        if (print_addr)
            cout<<in_indent + "Address: "<<this<<endl;
        cout<<in_indent + "Name: "<<name<<endl;
        cout<<in_indent + "Fat: "<<fat<<endl;
        cout<<in_indent + "Muscle: "<<muscle<<endl;
        cout<<in_indent + "Energy: "<<energy<<endl;
        cout<<in_indent + "Money: "<<money<<endl;
    }

private:
    // Buddy's name
    string name;

    // Represents how fat he is. Can be all integers
    int fat;
    // Represents how strong he is. Can be all integers
    int muscle;
    // Represents how energetic he is. Doing workouts will decrease it. CANNOT be negative integers
    int energy;
    // Represents how rich he is. CANNOT be negative integers
    int money;
};

#endif /* BUDDY_H */
