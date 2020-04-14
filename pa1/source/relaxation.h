//
//  relaxation.h
//  2012PA1
//
//  Created by Tony Wai Sum JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#ifndef RELAXATION_H
#define RELAXATION_H

#include <iostream>
#include <string>

using namespace std;

/*-----------------------------
 Relaxation Class

 Relaxation helps a buddy gain energy.
 For example, ("Sleep", 10) will increase a buddy's energy by 10.

 This class is also a linked list, which means a relaxation can be followed by another one ('next' variable).
 For example, ("Sleep", 10) -> ("Play Nintendo Switch", 100)
 Life cycle of Relaxations will be managed by other classes, so destructors are not needed.
 ------------------------------*/
class Relaxation {
public:

    /*-----------------------------
     Constructor

     @param name: string
     @param energy_gain: accept all integers, but you may assume it is always non-negative
     @appendix: next should be initialized to NULL
     ------------------------------*/
    Relaxation(string name, int energy_gain = 0);


    /*-----------------------------
     Name getter
     @return: this's name
     ------------------------------*/
    string get_name() const;

    /*-----------------------------
     Energy gain getter
     @return: this's energy_gain
     ------------------------------*/
    int get_energy_gain() const;

    /*-----------------------------
     Next pointer getter for linked list purpose
     @return: this's 'next' pointer
     ------------------------------*/
    Relaxation* get_next() const;


    /*-----------------------------
     Next pointer setter for linked list purpose
     Set this's 'next'
     ------------------------------*/
    void set_next(Relaxation* next);

    void print_details(int indent, int index = -1, bool print_addr = false) const {
        string out_indent = string(indent, '\t');
        string in_indent = out_indent + "\t";
        if (index < 0)
            cout<<out_indent + "Relaxation: "<<endl;
        else
            cout<<out_indent + "Relaxation "<<index<<": "<<endl;
        if (print_addr)
            cout<<in_indent + "Address: "<<this<<endl;
        cout<<in_indent + "Name: "<<name<<endl;
        cout<<in_indent + "Energy Gain: "<<energy_gain<<endl;
        if (next)
            cout<<in_indent + "Next's name: "<<next->name<<endl;
        else
            cout<<in_indent + "Next: NULL"<<endl;
    }
    
private:
    // Relaxation's name
    string name;

    // Represents how much energy a buddy can gain by relaxing this way. You may assume it is always non-negative
    int energy_gain;

    // Linked list. A relaxation can be followed by another one
    // e.g. "Play NS" after "Sleeping"
    Relaxation* next;
};

#endif /* RELAXATION_H */
