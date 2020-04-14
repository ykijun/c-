//
//  restaurant.h
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include "food.h"
#include "buddy.h"

using namespace std;

/*-----------------------------
 Restaurant class (circular array)

 A person (Buddy) need to go to a restaurant to purchase food,
 which can increase his muscle and fat.
 A restaurant's meals menu is a circular array with atmost 5 Foods, for example:

 0 (start_index): "Dumplings", 1: "Bottled Water", 2: "Banana", 3: "Red Tea", 4: "Beer" (end_index)

 More details for manipulating this circular array can be found in each function's declaration comments
 ------------------------------*/
class Restaurant {
public:
    /*-----------------------------
     Constructor
     @appendix:
        list_start_index, curr_num_of_meals should be initialized to 0
        list_end_index should be initialized to 4
     ------------------------------*/
    Restaurant(string name);


    /*-----------------------------
     Name getter
     @return: this's name
     ------------------------------*/
    string get_name() const;


    /*-----------------------------
     'Append' a food to the 'end' of meals_list (circular array)
     @return:
        If the list is full, do nothing and return false;
        otherwise perform the append and return true

     you may need to use modulus operator '%' to create 'circular' indexes

     Example:

     initial: empty list (list_start_index = 0; list_end_index = 4; curr_num_of_meals = 0)

     add_meal: "Banana"
     result: true
        0: "Banana" (list_start_index) (list_end_index)
        curr_num_of_meals = 1

     add_meal: "Bottled Water"
     result: true
        0: "Banana" (list_start_index)
        1: "Bottled Water" (list_end_index)
        curr_num_of_meals = 2

     add_meal: "Burger"
     add_meal: "Beef Fried Rice"
     add_meal: "Chicken Nuggets"
     result: true
        0: "Banana" (list_start_index)
        1: "Bottled Water"
        2: "Burger"
        3: "Beef Fried Rice"
        4: "Chicken Nuggets" (list_end_index)
        curr_num_of_meals = 5
     Please note that list_start_index & list_end_index are now same as initial.
     Therefore, in order to differ empty & full list, we add a variable curr_num_of_meals.

     add_meal: "Pad Thai" (list is now full because curr_num_of_meals == 5)
     result: false
        (list not changed)
     ------------------------------*/
    bool add_meal(Food food);

    /*-----------------------------
     Remove the food at [list_start_index]. (Circular array)
     @return:
        If the list is empty, do nothing and return false,
        otherwise perform the remove and return true

     @appendix:
         This array is in stack, thus you don't need to delete the food. Changing list_start_index & curr_num_of_meals is enough.
         You may need to use modulus operator '%'

     Example:

     initial:
        0: "Banana" (list_start_index)
        1: "Bottled Water"
        2: "Burger" (list_end_index)
        curr_num_of_meals = 3

     remove_first_meal()
     result: true
        1: "Bottled Water" (list_start_index)
        2: "Burger" (list_end_index)
        curr_num_of_meals = 2

     remove_first_meal()
     remove_first_meal()
     result: true
        list_start_index = 3; list_end_index = 2; curr_num_of_meals = 0;

     remove_first_meal()
     result: false
        list_start_index = 3; list_end_index = 2; curr_num_of_meals = 0; (not changed)
     ------------------------------*/
    bool remove_first_meal();

    /*-----------------------------
     Remove the food at [list_end_index]. (Circular array)
     @return:
        If the list is empty, do nothing and return false,
        otherwise perform the remove and return true

     @appendix:
        This array is in stack, thus you don't need to delete the food. Changing list_end_index & curr_num_of_meals is enough.
        You may need to use modulus operator '%'

     Example:

     initial:
     0: "Banana" (list_start_index)
     1: "Bottled Water"
     2: "Burger" (list_end_index)
     curr_num_of_meals = 3

     remove_last_meal()
     result: true
     0: "Banana" (list_start_index)
     1: "Bottled Water" (list_end_index)
     curr_num_of_meals = 2

     remove_last_meal()
     remove_last_meal()
     result: true
     list_start_index = 0; list_end_index = 4; curr_num_of_meals = 0;

     remove_last_meal()
     result: false
     list_start_index = 0; list_end_index = 4; curr_num_of_meals = 0; (not changed)
     ------------------------------*/
    bool remove_last_meal();


    /*-----------------------------
     Serve the buddy with the selected meal

     If the buddy has enough money to buy the meal:
        deduct food's price from buddy's money
        add food's fat_gain to buddy's fat
        add food's protein_gain to buddy's muscle
        return true
     else
        do nothing and return false

     you may assume:
     meal_index is in [0, 4]
     meals_list[meal_index] will never be 'garbage value'
     buddy will never be NULL
     ------------------------------*/
    bool serve_meal(Buddy* buddy, int meal_index) const;

    void print_details(int indent) const {
        string out_indent = string(indent, '\t');
        string in_indent = out_indent + "\t";
        cout<<out_indent + "Restaurant: "<<endl;
        cout<<in_indent + "Name: "<<name<<endl;
        cout<<in_indent + "Meals: "<<endl;

        bool is_garbage[5] = { true, true, true, true, true };
        for (int i=list_start_index; i<list_start_index+curr_num_of_meals; i++) {
            int index = i % 5;
            is_garbage[index] = false;
        }
        // always print out all 5 meals (some may store 'garbage values')
        for (int i=0; i<5; i++) {
            if (is_garbage[i])
                Food("Garbage Value").print_details(indent + 2, i);
            else
                meals_list[i].print_details(indent + 2, i);
        }
    }

private:
    // Restaurant's name
    string name;

    // The meals served by the restaurant. Circular array.
    Food meals_list[5];

    // The start of the circular array, this index should always be in range [0, 4]
    int list_start_index;
    // The end of the circular array, this index should always be in range [0, 4]
    int list_end_index;
    // The current number of meals in meals_list. curr_num_of_meals == 0 means empty, curr_num_of_meals == 5 means full
    int curr_num_of_meals;
};

#endif /* RESTAURANT_H */
