//
//  food.h
//  2012PA1
//
//  Created by Tony Wai Sum JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>

using namespace std;

/*-----------------------------
 Food Class

 Food helps a buddy gain protein (which transforms to muscle) and fat,
 but he needs to pay money to buy it.
 ------------------------------*/
class Food {
public:
    /*-----------------------------
     Constructor

     You may assume fat_gain, protain_gain & price are always non-negative
     ------------------------------*/
    Food(string name = "", int fat_gain = 0, int protein_gain = 0, int price = 0);


    /*-----------------------------
     Name getter
     @return: this's name
     ------------------------------*/
    string get_name() const;

    /*-----------------------------
     Fat gain getter
     @return: this's fat_gain
     ------------------------------*/
    int get_fat_gain() const;

    /*-----------------------------
     Protein gain getter
     @return: this's protein_gain
     ------------------------------*/
    int get_protein_gain() const;

    /*-----------------------------
     Price getter
     @return: this's price
     ------------------------------*/
    int get_price() const;

    void print_details(int indent, int index = -1) const {
        string out_indent = string(indent, '\t');
        string in_indent = out_indent + "\t";
        if (index >= 0)
            cout<<out_indent + "Food "<<index<<": "<<endl;
        else
            cout<<out_indent + "Food: "<<endl;
        cout<<in_indent + "Name: "<<name<<endl;
        cout<<in_indent + "Fat Gain: "<<fat_gain<<endl;
        cout<<in_indent + "Protein Gain: "<<protein_gain<<endl;
        cout<<in_indent + "Price: "<<price<<endl;
    }

private:
    // Food's name
    string name;

    // Represents how much fat a person will absorb when eating this food, you may assume it is non-negative
    int fat_gain;
    // Represents how much muscle a person will absorb when eating this food, you may assume it is non-negative
    int protein_gain;

    // Represents how much a person needs to pay in order to eat this food, you may assume it is non-negative
    int price;
};

#endif /* FOOD_H */
