	/*
	 * todo.cpp
	 *
	 *  Created on: Oct 31, 2018
	 *  submitted by : Yu,Kijun (20319196/kyuac)
	 *      Author: kevinw
	 */
	#include "matrix.h"

	/**
	 * Important Notes:
	 *
	 * 1) All the code that you have written should be in this file.
	 * 2) You can add any helper functions. And we suggest you to do it.
	 * 3) Global varibles are not allowed, regardless of whether it is const or non const.
	 * 4) Two class member functions, namely, print and debug, have been written for you in helper.cpp
	 *    and you should not move these two function here, nor reimplement it.
	 * 5) You can modify the main function for testing purpose. However, you should also
	 *    expect that we will modify the main function when we grade your assignment.
	 *
	 *
	 * If it crashes, take a deep breath.
	 *
	 */


	/*
	 * TODO: Constructor of the Matrix class
	 * Hint: 1) Remember to initial all data members; if you don't know what values to be used, put nullptr or 0 first.
	 *       2) You need to create dynamic Element objects in the constructor. As mentioned in the .h file,
	 *          you need to create it using the syntax:
	 *              Element* dynamicObject = new Element{nullptr, nullptr, nullptr, nullptr, id};
	 *       3) You are advised to create some helper global functions to help you to do this task.
	 */

	Matrix::Matrix(int height, int width){
		this->height = height;
		this->width = width;
		Element* p1;
		Element* p2;
		rowHeads[height] = nullptr;
		colHeads[width] = nullptr;
		for(int i = 0; i < height ; i++){
			for (int j = 0; j < width; j++)
			{
				if (j == 0 && i == 0){
					p2 = new Element {nullptr, nullptr, nullptr, nullptr, width * i + (j + 1)};
					colHeads[j] = rowHeads[i] = p2;
					p1 = p2;
				}

				else if (j == 0 && i > 0){
					p2 = new Element {nullptr, nullptr, nullptr, nullptr, width * i + (j + 1)};
					rowHeads[i] = p2;
					p1 = p2;
				}
				else if (i == 0 && j > 0){

					if(j == width - 1){
						p2 = new Element {nullptr, nullptr, p1, rowHeads[i], width * i + (j + 1)};
						rowHeads[i]->left = p2;
						colHeads[j] = p2;

					}
					else{
						p2 = new Element {nullptr, nullptr, p1, nullptr, width * i + (j + 1)};
						p1->right = p2;
						colHeads[j] = p2;
						p1= p2;
					}

				}
				else{
					if(j == width - 1){
						p2 = new Element {nullptr, nullptr, p1, rowHeads[i], width * i + (j + 1)};
						rowHeads[i]->left = p2;
					}

					else{
						p2 = new Element {nullptr, nullptr, p1, nullptr, width * i + (j + 1)};
						p1 = p2;
					}
				}
			}
		}


		for(int i = 0; i < height ; i++){
			if (width > 1){
				p2 = rowHeads[i];
				p1 = p2->left;
				for(int j = 0; j < width ; j++){
					p1->right = p2;
					p2 = p1;
					p1 = p1->left;
				}
			}
			else{
				rowHeads[i]->left = rowHeads[i]->right = rowHeads[i];
			}
		}


		for (int i = 0; i < height ; i++){
			if (height > 1){

				if (i == 0){

					p1 = rowHeads[height - 1];
					p2 = rowHeads[0];
					for (int j = 0; j < width; j++){
						p1->down = p2;
						p2->up = p1;
						p1 = p1->right;
						p2 = p2->right;

					}
				}
				else{
					p1 = rowHeads[i-1];
					p2 = rowHeads[i];
					for (int j = 0; j < width; j++){
						p1->down = p2;
						p2->up = p1;
						p1 = p1->right;
						p2 = p2->right;
					}
				}
			}
			else {
				for (int j = 0; j < width; j++){
				colHeads[j]->up = colHeads[j]->down = colHeads[j];
				}
			}

		}
	}

	/*
	 * TODO: isReverse() of the Matrix class
	 * Hint: This should be a easier task, comparing with the others. Try to do it after the constructor is implemented.
	 *
	 */

	bool Matrix::isReverse()const{
		Element* P;
		int num = height * width;
		for(int i = 0 ; i < height ; i++){
			P = rowHeads[i];
			for(int j = 0 ; j < width ; j++){
				if (P->id == num){
					num--;
					P = P->right;
				}
				else return false;
			}
		}
			return true;
	}

	/*
	 * TODO: reverseRow() of the Matrix class
	 * Hint: This is not supposed to be simple and easy if you are not using recursion.
	 */
	void Matrix::reverseRow(int a){
		Element* p = rowHeads[a];
		Element*up = rowHeads[a]->up;
		Element*down = rowHeads[a]->down;
		for(int i = 0 ; i < width; i++){
			if (i == width - 1) {
				rowHeads[a] = p;
				p->left = p->right;
				p = p->right;
			}
			p->left = p->right;
			p = p->right;

		}

		p = rowHeads[a];
		for(int i = 0 ; i < width; i++){
			Element* pset = p;

			for (int j = 0; j < width - 1; j++)
				pset = pset -> left;
			p->right = pset;
			p = p->right;
		}

		p = rowHeads[a];
		for (int i = 0; i < width; i++){
			p->up = up;
			p->down= down;
			p->up->down = p;
			p->down->up = p;
			up=up->right;
			down=down->right;
			p = p->right;
		}

		if (a == 0){
			p = rowHeads[0];
			for(int i = 0; i < width;i++){
			colHeads[i] = p;
			p = p->right;
			}
		}
	}


	/*
	 * TODO: circularShift() of the Matrix class
	 * Hint: 1) You might first split this function into two parts, UP/DOWN and LEFT/RIGHT.
	 * 	 2) Remember to update both horizontal linked list and vertical linked list.
	 *
	 */

	void Matrix::circularShift(Direction dir, int a){

		Element* p;
		switch (dir) {
			case UP:{
				if (a == 0){
					p = colHeads[a];
					for (int i = 0 ; i < height; i++){
						p->left = p->left->up;
						p->left->right = p;
						p->right = p->right->up;
						p->right->left = p;
						p = p->down;
						rowHeads[i]= p;
					}
					colHeads[0] = rowHeads[0];
					break;
				}

				else if (a > 0){
					p = colHeads[a];
					colHeads[a] = p->down;
					for (int i = 0 ; i < height; i++){
						p->left = p->left->up;
						p->left->right = p;
						p->right = p->right->up;
						p->right->left = p;
						p = p->down;
					}
				}
				break;
			}

			case DOWN:{
				if (a==0){
					p = colHeads[0];
					for (int i = 0; i < height; i++){
						rowHeads[i] = p->up;
						p= p->down;
					}
					for (int i = 0 ; i < height; i++)
					{
						p->left = p->left->down;
						p->left->right = p;
						p->right = p->right->down;
						p->right->left = p;
						p = p->down;
					}
					colHeads[0]=rowHeads[0];
					break;
				}
				else if (a > 0){
					p = colHeads[a];
					colHeads[a] = p->up;
					for (int i = 0 ; i < height; i++){
						p->left = p->left->down;
						p->left->right = p;
						p->right = p->right->down;
						p->right->left = p;
						p = p->down;
					}
				}
				break;

			}

			case LEFT:{
				if (a == 0){
					p = rowHeads[a];
					for (int i = 0 ; i < width; i++){
						p->up = p->up->left;
						p->up->down = p;
						p->down = p->down->left;
						p->down->up = p;
						p = p->right;
						colHeads[i] = p;
					}
					rowHeads[0] = colHeads[0];
					break;

				}
				else{
					p = rowHeads[a];
					rowHeads[a]= p->right;
					for (int i = 0 ; i < width; i++){
						p->up = p->up->left;
						p->up->down = p;
						p->down = p->down->left;
						p->down->up = p;
						p = p->right;
					}
				}
				break;
			}
			case RIGHT :{
				if (a == 0){
					p = rowHeads[a];
					for (int i = 0; i < height; i++){
						colHeads[i] = p->left;
						p= p->right;}
					for (int i = 0 ; i < width; i++){
						p->up = p->up->right;
						p->up->down = p;
						p->down = p->down->right;
						p->down->up = p;
						p = p->right;
					}
					rowHeads[0] = colHeads[0];
					break;
				}
				else{
					p = rowHeads[a];
					rowHeads[a]= p->left;
					for (int i = 0 ; i < width; i++){
						p->up = p->up->right;
						p->up->down = p;
						p->down = p->down->right;
						p->down->up = p;
						p = p->left;
					}

				}
				break;
			}
		}

	}

	/*
	 * TODO: Destructor of the Matrix class
	 * Hint: 1) Leave this task to the very end of your assignment. The worst case is you don't pick up the
	 * 	    memory leak point. Fail to do this will not affect the correctness of your program output.
	 * 	    However, if you do it wrongly, your program may crash.
	 *
	 */


	Matrix::~Matrix(){
		for (int i = 0; i < height; i++){
			Element* p = rowHeads[i];
			Element* ps = p->right;
			for (int j = 0; j < width; j++){
				delete p;
				if(j == width -1)
					break;
				p = ps;
				ps = p->right;
			}
		}
	}


