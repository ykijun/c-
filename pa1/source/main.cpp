//
//  main.cpp
//  2012PA1
//
//  Created by Tony Wai Sum JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include <iostream>
#include "buddy.h"
#include "workout.h"
#include "food.h"
#include "relaxation.h"
#include "workoutenvironment.h"
#include "restaurant.h"
#include "relaxplan.h"

using namespace std;

void test_food();
void test_relaxation();
void test_workout();

void test_relaxplan();
void test_buddy();
void test_restaurant();
void test_workoutenvironment();

int main() {
    cout<<"Test functions are carried out sequentially, thus later results will be affected by previous ones. \nIf you want to debug a function, read main.cpp and make sure its 'previous' ones work well.\n"<<endl;

    cout<<"This program only tests part of the assignment's requirements. If you want to get full marks, you need to change main() and do some testing yourself.\n"<<endl;

    int part_to_test = -1;
    while (part_to_test) {
        cout<<"Select a part you want to test: "<<endl;
        cout<<"\t1. Food"<<endl;
        cout<<"\t2. Relaxation"<<endl;
        cout<<"\t3. Workout"<<endl;
        cout<<"\t4. RelaxPlan"<<endl;
        cout<<"\t5. Buddy"<<endl;
        cout<<"\t6. Restaurant"<<endl;
        cout<<"\t7. WorkoutEnvironment"<<endl;
        cout<<"\t8. All of the above"<<endl;
        cout<<"\t0. Exit"<<endl;
        cout<<"\nInput: ";
        string input_str = "default string";
        cin>>input_str;
        cout<<endl;
        try {
            part_to_test = stoi(input_str);
        } catch (...) {
            part_to_test = -1;
        }
        switch (part_to_test) {
        case 1:
            test_food();
            break;
        case 2:
            test_relaxation();
            break;
        case 3:
            test_workout();
            break;
        case 4:
            test_relaxplan();
            break;
        case 5:
            test_buddy();
            break;
        case 6:
            test_restaurant();
            break;
        case 7:
            test_workoutenvironment();
            break;
        case 8:
            test_food();
            test_relaxation();
            test_workout();
            test_relaxplan();
            test_buddy();
            test_restaurant();
            test_workoutenvironment();
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input, try again."<<endl<<endl;
            break;
        }
    }
}

void test_food() {
    cout<<"------- Food Class -------"<<endl<<endl;

    cout<<"Constructor: "<<endl;
    Food food0 = Food("Egg White Powder", 0, 20, 5);
    food0.print_details(1);
    cout<<endl;

    cout<<"get_name: "<<endl;
    cout<<"\tname: "<<food0.get_name()<<endl;
    cout<<endl;

    cout<<"get_fat_gain: "<<endl;
    cout<<"\tfat_gain: "<<food0.get_fat_gain()<<endl;
    cout<<endl;

    cout<<"get_protein_gain:"<<endl;
    cout<<"\tprotein_gain: "<<food0.get_protein_gain()<<endl;
    cout<<endl;

    cout<<"get_price:"<<endl;
    cout<<"\tprice: "<<food0.get_price()<<endl;
    cout<<endl;

    cout<<"------- Food Class Completed! -------"<<endl<<endl;
}

void test_relaxation() {
    cout<<"------- Relaxation Class -------"<<endl<<endl;
    cout<<"Constructor: "<<endl;
    Relaxation r = Relaxation("Sleep 24 hours", 1000);
    r.print_details(1);
    cout<<endl;

    cout<<"get_name: "<<endl;
    cout<<"\tname: "<<r.get_name()<<endl;
    cout<<endl;

    cout<<"get_energy_gain: "<<endl;
    cout<<"\tenergy_gain: "<<r.get_energy_gain()<<endl;
    cout<<endl;

    cout<<"get_next: (currently NULL)"<<endl;
    cout<<"\tnext: "<<r.get_next()<<endl;
    cout<<endl;

    cout<<"set_next: "<<endl;
    Relaxation* r1 = new Relaxation("Sleep 48 hours", 1500);
    r.set_next(r1);
    r.print_details(1);
    cout<<endl;

    delete r1;
    cout<<"------- Relaxation Class Completed! -------"<<endl<<endl;
}

void test_workout() {
    cout<<"------- Workout Class -------"<<endl<<endl;
    cout<<"Constructor: "<<endl;
    Workout w = Workout("Wrestling", -20, -5, -50);
    w.print_details(1);
    cout<<endl;

    cout<<"get_name: "<<endl;
    cout<<"\tname: "<<w.get_name()<<endl;
    cout<<endl;

    cout<<"get_fat_change: "<<endl;
    cout<<"\tfat_change: "<<w.get_fat_change()<<endl;
    cout<<endl;

    cout<<"get_muscle_change: "<<endl;
    cout<<"\tmuscle_change: "<<w.get_muscle_change()<<endl;
    cout<<endl;

    cout<<"get_energy_change: "<<endl;
    cout<<"\tenergy_change: "<<w.get_energy_change()<<endl;
    cout<<endl;

    cout<<"------- Workout Class Completed! -------"<<endl<<endl;
}

void test_relaxplan() {
    cout<<"------- RelaxPlan Class -------"<<endl<<endl;
    cout<<"Constructor: "<<endl<<endl;
    RelaxPlan rp = RelaxPlan("Dayoff!");
    rp.print_details(1);
    cout<<endl;

    cout<<"get_head: (currently NULL)"<<endl;
    cout<<"\thead: "<<rp.get_head()<<endl;
    cout<<endl;

    Relaxation r0 = Relaxation("Take a walk", 15);
    Relaxation r1 = Relaxation("Steam start!", 20);
    Relaxation r2 = Relaxation("Afternoon nap", 30);
    Relaxation r3 = Relaxation("Nintendo Switch Start!", 25);
    Relaxation r4 = Relaxation("Chat with GF/BF/F/ALONE", 10);

    cout<<"add_to_start: (two times)"<<endl<<endl;
    rp.addToStart(r1);
    rp.addToStart(r0);
    rp.print_details(1);
    cout<<endl;

    cout<<"add_to_end: (three times)"<<endl<<endl;
    rp.addToEnd(r2);
    rp.addToEnd(r3);
    rp.addToEnd(r4);
    rp.print_details(1);
    cout<<endl;

    cout<<"remove: 6; -1; (should not change)"<<endl<<endl;
    rp.remove(6);
    rp.remove(-1);
    rp.print_details(1);
    cout<<endl;

    cout<<"remove: 4"<<endl<<endl;
    rp.remove(4);
    rp.print_details(1);
    cout<<endl;

    cout<<"remove: 1"<<endl<<endl;
    rp.remove(1);
    rp.print_details(1);
    cout<<endl;

    cout<<"remove: 0; 0; 0;"<<endl<<endl;
    rp.remove(0);
    rp.remove(0);
    rp.remove(0);
    rp.print_details(1);
    cout<<endl;

    cout<<"Copy Constructor: "<<endl<<endl;
    rp.addToEnd(r0);
    rp.addToEnd(r1);
    rp.addToEnd(r2);
    rp.addToEnd(r3);
    rp.addToEnd(r4);
    cout<<"RelaxPlan to be copied: "<<endl<<endl;
    rp.print_details(1);
    cout<<endl;
    cout<<"RelaxPlan copied: "<<endl<<endl;
    cout<<"Make sure the Relaxations' addresses are different from above!"<<endl<<endl;
    RelaxPlan rpc = RelaxPlan(rp);
    rpc.print_details(1);
    cout<<endl;

    cout<<"------- RelaxPlan Class Completed! -------"<<endl<<endl;
}

void test_buddy() {
    cout<<"------- Buddy Class -------"<<endl<<endl;
    cout<<"Constructor: "<<endl;
    Buddy* b1 = new Buddy("Mona", 40, 600, 200, 8000);
    b1->print_details(1);
    cout<<endl;

    cout<<"get_name: "<<endl;
    cout<<"\tname: "<<b1->get_name()<<endl;
    cout<<endl;

    cout<<"get_fat: "<<endl;
    cout<<"\tfat: "<<b1->get_fat()<<endl;
    cout<<endl;

    cout<<"get_muscle: "<<endl;
    cout<<"\tmuscle: "<<b1->get_muscle()<<endl;
    cout<<endl;

    cout<<"get_energy: "<<endl;
    cout<<"\tenergy: "<<b1->get_energy()<<endl;
    cout<<endl;

    cout<<"get_money: "<<endl;
    cout<<"\tmoney: "<<b1->get_money()<<endl;
    cout<<endl;

    cout<<"set_fat: 100"<<endl;
    b1->set_fat(100);
    cout<<"\tnew fat: "<<b1->get_fat()<<endl;
    cout<<endl;

    cout<<"set_muscle: 700"<<endl;
    b1->set_muscle(700);
    cout<<"\tnew muscle: "<<b1->get_muscle()<<endl;
    cout<<endl;

    cout<<"set_energy: 10"<<endl;
    b1->set_energy(10);
    cout<<"\tnew energy: "<<b1->get_energy()<<endl;
    cout<<endl;

    cout<<"set_money: 50000"<<endl;
    b1->set_money(50000);
    cout<<"\tnew money: "<<b1->get_money()<<endl;
    cout<<endl;

    cout<<"earn_money(500, 10): "<<endl;
    b1->earn_money(500, 10);
    cout<<"\tnew money: "<<b1->get_money()<<endl;
    cout<<endl;

    cout<<"Make sure your Relaxation & RelaxPlan class works, otherwise comment out the test functions below."<<endl<<endl;
    cout<<"gain_energy: "<<endl<<endl;
    RelaxPlan rp = RelaxPlan("Dayoff!");
    Relaxation r0 = Relaxation("Take a walk", 15);
    Relaxation r1 = Relaxation("Steam start!", 20);
    Relaxation r2 = Relaxation("Afternoon nap", 30);
    Relaxation r3 = Relaxation("Nintendo Switch Start!", 25);
    Relaxation r4 = Relaxation("Chat with GF/BF/F/ALONE", 10);
    Relaxation r5 = Relaxation("Sleep", 50);
    rp.addToEnd(r0);
    rp.addToEnd(r1);
    rp.addToEnd(r2);
    rp.addToEnd(r3);
    rp.addToEnd(r4);
    rp.addToEnd(r5);
    cout<<"Before Gain Energy: "<<endl<<endl;
    rp.print_details(1);
    b1->print_details(1);
    cout<<endl<<"After Gain Energy: "<<endl<<endl;
    b1->gain_energy(rp);
    b1->print_details(1);
    cout<<endl;

    delete b1;
    cout<<"------- Buddy Class Completed!-------"<<endl<<endl;
}

void test_restaurant() {
    cout<<"------- Restaurant Class -------"<<endl<<endl;

    cout<<"Constructor: "<<endl<<endl;
    Restaurant r = Restaurant("Silver Rice Bowl");
    r.print_details(1);
    cout<<endl;

    cout<<"get_name: "<<endl;
    cout<<"\tname: "<<r.get_name()<<endl;
    cout<<endl;

    cout<<"add_meal: "<<endl<<endl;
    Food f0 = Food("Egg White Powder", 0, 20, 5);
    Food f1 = Food("Banana", 0, 5, 3);
    Food f2 = Food("Double Cheese Burger With French Fries", 1000, 10, 45);
    Food f3 = Food("Air", 0, 0, 0);
    Food f4 = Food("Ramen with Deep Fried Chicken", 30, 10, 30);

    cout<<"\tadd 2 meals"<<endl<<endl;
    r.add_meal(f0);
    r.add_meal(f1);
    r.print_details(2);
    cout<<endl;

    cout<<"\tadd 5 meals"<<endl<<endl;
    r.add_meal(f2);
    r.add_meal(f3);
    r.add_meal(f4);
    r.print_details(2);
    cout<<endl;

    cout<<"remove_first_meal: "<<endl<<endl;
    cout<<"\t2 times: "<<endl;
    r.remove_first_meal();
    r.remove_first_meal();
    r.print_details(2);
    cout<<endl;

    cout<<"\t4 times: "<<endl<<endl;
    r.remove_first_meal();
    r.remove_first_meal();
    r.print_details(2);
    cout<<endl;

    cout<<"add_meal: (Circular add 2 meals)"<<endl<<endl;
    r.add_meal(f0);
    r.add_meal(f1);
    r.print_details(1);
    cout<<endl;

    cout<<"remove_last_meal: "<<endl<<endl;
    cout<<"\t 2 times: "<<endl;
    r.remove_last_meal();
    r.remove_last_meal();
    r.print_details(2);
    cout<<endl;

    cout<<"\t 4 times: (4th time should return false and do nothing)"<<endl<<endl;
    r.remove_last_meal();
    r.remove_last_meal();
    r.print_details(2);
    cout<<endl;

    cout<<"Make sure your Buddy class works, otherwise comment out the lines below"<<endl;
    cout<<"serve_meal:"<<endl<<endl;
    cout<<"Before serving: "<<endl;
    Buddy* b1 = new Buddy("Van", 50, 500, 100, 10000);
    r.add_meal(f0);
    r.add_meal(f1);
    r.add_meal(f2);
    r.print_details(1);
    cout<<endl;
    b1->print_details(1);
    cout<<endl;
    int meal_index = 0;
    r.serve_meal(b1, meal_index);
    cout<<"After serving meal number "<<meal_index<<": "<<endl;
    b1->print_details(1);
    cout<<endl;

    delete b1;
    cout<<"------- Restaurant Class Completed! -------"<<endl<<endl;
}

void test_workoutenvironment() {
    cout<<"------- WorkoutEnvironment Class Completed! -------"<<endl<<endl;

    cout<<"Constructor: "<<endl<<endl;
    WorkoutEnvironment we = WorkoutEnvironment("My House", 20, 5);
    we.print_details(1);
    cout<<endl;

    cout<<"get_name: "<<endl<<endl;
    cout<<"\tname: "<<we.get_name()<<endl;
    cout<<endl;

    cout<<"get_entry_fee: "<<endl<<endl;
    cout<<"\tentry_fee: "<<we.get_entry_fee()<<endl;
    cout<<endl;

    Workout w0 = Workout("Wrestling", -20, -5, -50);
    Workout w1 = Workout("Bicep Dumbbell Curl", -5, 15, -10);
    Workout w2 = Workout("Machine Shoulder Press", -5, 15, -10);
    Workout w3 = Workout("Machine Chest Fly", -5, 15, -10);
    Workout w4 = Workout("Jogging", -15, -5, -20);
    Workout w5 = Workout("Dead Lift", -5, 20, -15);

    cout<<"add_workout: "<<endl;
    cout<<"\t\"Wrestling\", 1: (not changed because index invalid)"<<endl<<endl;
    we.add_workout(w0, 1);
    we.print_details(2);
    cout<<endl;

    cout<<"\t\"Wrestling\", 0:"<<endl<<endl;
    we.add_workout(w0, 0);
    we.print_details(2);
    cout<<endl;

    cout<<"\t\"Bicep Dumbbell Curl\", 0:"<<endl<<endl;
    we.add_workout(w1, 0);
    we.print_details(2);
    cout<<endl;

    cout<<"\t\"Machine Shoulder Press\", 2:"<<endl<<endl;
    we.add_workout(w2, 2);
    we.print_details(2);
    cout<<endl;

    cout<<"\t\"Jogging\", 1:"<<endl<<endl;
    we.add_workout(w4, 1);
    we.print_details(2);
    cout<<endl;

    cout<<"\t\"Dead Lift\", 4:"<<endl<<endl;
    we.add_workout(w5, 4);
    we.print_details(2);
    cout<<endl;

    cout<<"\t\"Machine Chest Fly\", 1: (not changed because list is full)"<<endl<<endl;
    we.add_workout(w3, 1);
    we.print_details(2);
    cout<<endl;

    cout<<"remove_workout: "<<endl<<endl;

    cout<<"\t remove 3:"<<endl<<endl;
    we.remove_workout(3);
    we.print_details(2);
    cout<<endl;

    cout<<"\t remove 4: (not changed because index invalid)"<<endl<<endl;
    we.remove_workout(4);
    we.print_details(2);
    cout<<endl;

    cout<<"\t remove 0; 0; 1;"<<endl<<endl;
    we.remove_workout(0);
    we.remove_workout(0);
    we.remove_workout(1);
    we.print_details(2);
    cout<<endl;

    Buddy* b0 = new Buddy("Van", 50, 500, 100, 10000);
    Buddy* b1 = new Buddy("Mona", 40, 600, 200, 8000);
    Buddy* b2 = new Buddy("Billy", 0, 1000, 1000, 10000);
    Buddy* b3 = new Buddy("Jagger", 1000, 0, 30, 10000);
    Buddy* b4 = new Buddy("Way", 10, 10, 10, 10);

    cout<<"register_participant: "<<endl<<endl;

    cout<<"\tAdd Jagger: "<<endl<<endl;
    we.register_participant(b3);
    we.print_details(2);
    cout<<endl;

    cout<<"\tAdd Way: (not changed because Way doesn't have enough money)"<<endl<<endl;
    we.register_participant(b4);
    we.print_details(2);
    cout<<endl;

    cout<<"\tAdd Van; Mona; Billy; "<<endl;
    cout<<"\tNote that participants' address is changed, but Jagger's address is not changed."<<endl<<endl;
    we.register_participant(b0);
    we.register_participant(b1);
    we.register_participant(b2);
    we.print_details(2);
    cout<<endl;

    cout<<"\tAdd Jagger: (not changed because Jagger is already added)"<<endl<<endl;
    we.register_participant(b3);
    we.print_details(2);
    cout<<endl;

    cout<<"participant_index: "<<endl<<endl;
    cout<<"\tJagger: Index "<<we.participant_index(b3)<<endl;
    cout<<"\tBilly: Index "<<we.participant_index(b2)<<endl;
    cout<<"\tWay: Index "<<we.participant_index(b4)<<endl;
    cout<<endl;

    cout<<"start_workout: "<<endl<<endl;

    cout<<"\t participant 0, workout 0: (not changed because not enough energy)"<<endl<<endl;
    we.start_workout(0, 0);
    we.print_details(2);
    cout<<endl;

    cout<<"\t participant 1, workout 0: "<<endl<<endl;
    we.start_workout(1, 0);
    we.print_details(2);
    cout<<endl;

    cout<<"\t participant 5, workout 5: (not changed because index invalid)"<<endl<<endl;
    we.start_workout(5, 5);
    we.print_details(2);
    cout<<endl;


    cout<<"------- WorkoutEnvironment Class Completed! -------"<<endl<<endl;
}
