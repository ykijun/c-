//
//  RelaxPlan.h
//  2012PA1
//
//  Created by TONY WAI SUM JI on 3/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#ifndef RELAXPLAN_H
#define RELAXPLAN_H

#include <iostream>
#include <string>
#include "relaxation.h"

using namespace std;

/*-----------------------------
 RelaxPlan Class (Linked list)

 A buddy use relax plans to gain energy.
 It manipulates a linked list of Relaxations, for exmaple:

 RelaxPlan("Weekend!"):
    Relaxation("Sleep", 10) next ->
    Relaxation("Watch Movie with GF/BF/F/ALONE", 15) next ->
    Relaxation("Sleep", 5) next ->
    Relaxation("Play Switch with GF/BF/F/ALONE", 100) -> NULL
 ------------------------------*/
class RelaxPlan {
public:

    /*-----------------------------
     Constructor
     @param name: string
     @appendix: initialize head to NULL
     ------------------------------*/
    RelaxPlan(string name);

    /*-----------------------------
     Copy Constructor

     Copy name, and DEEP COPY the linked list: for every node (Relaxation*) in rp,
     copy a new node of it, and link all copied nodes in the same sequence
     ------------------------------*/
    RelaxPlan(RelaxPlan const & rp);

    /*-----------------------------
     Destructor

     Deallocate all (Relaxation*) linked in this's linked list
     ------------------------------*/
    ~RelaxPlan();


    /*-----------------------------
     Head getter
     @return: this's head
     ------------------------------*/
    Relaxation* get_head() const;


    /*-----------------------------
     Append an relaxation to the START of the linked list,
     @param r: a relaxation in STACK. You need to create a copy of it in HEAP, then do the append.
        DON'T DIRECTLY USE &r to append.

     Example:

     initial: "Sleep for 1h" (head) -> "Play for 15 min" -> NULL
     addToStart: "Complete 2012 PA1"
     result: "Complete 2012 PA1" (head) -> "Sleep for 1h" -> "Play for 15 min" -> NULL

     initial: NULL
     addToEnd: "Complete 2012 PA1"
     result: "Complete 2012 PA1" -> NULL
     ------------------------------*/
    void addToStart(Relaxation r);

    /*-----------------------------
     Append an relaxation to the END of the linked list, for
     @param r: a relaxation in STACK. You need to create a copy of it in HEAP, then do the append.
     DON'T DIRECTLY USE &r to append.

     Example:

     initial: "Sleep for 1h" (head) -> "Play for 15 min" -> NULL
     addToEnd: "Complete 2012 PA1"
     result: "Sleep for 1h" (head) -> "Play for 15 min" -> "Complete 2012 PA1" -> NULL

     initial: NULL
     addToEnd: "Complete 2012 PA1"
     result: "Complete 2012 PA1" -> NULL
     ------------------------------*/
    void addToEnd(Relaxation r);

    /*-----------------------------
     Remove and deallocate a node at a given index
     @ return: whether the removal is success or not

     Example:

     initial: "Sleep for 1h" (head) -> "Play for 15 min" -> "Complete 2012 PA1" -> NULL

     remove: 3
     result: false, nothing happened to the list

     remove: 1
     result: true, "Sleep for 1h" (head) -> "Complete 2012 PA1" -> NULL

     remove: 1
     result: true, "Sleep for 1h" (head) -> NULL

     remove: 0
     result: true, NULL (head)

     remove: 0
     result: false, nothing happened to the list
     ------------------------------*/
    bool remove(int remove_index);

    void print_details(int indent) const {
        string out_indent = string(indent, '\t');
        string in_indent = out_indent + "\t";
        cout<<out_indent + "Relax Plan: "<<endl;
        cout<<in_indent + "Name: "<<name<<endl;
        if (head) {
            cout<<in_indent + "Schedule: "<<endl;
            Relaxation* curr = head;
            int index = 0;
            while (curr) {
                curr->print_details(indent + 2, index, true);
                curr = curr->get_next();
                index++;
            }
        } else {
            cout<<in_indent + "Schedule: NULL"<<endl;
        }
    }

private:
    // Relax plan's name
    string name;

    // The pointer to the start of the relaxation linked list
    Relaxation* head;

};

#endif /* RELAXPLAN_H */
