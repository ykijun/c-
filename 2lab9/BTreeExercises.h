//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"

template<class T>
int treeHeight(BtreeNode<T> *root){
	if (root == NULL)
		return 0;
	else {
		int lh = treeHeight(root->get_left());
		int rh = treeHeight(root->get_right());

		if (lh > rh){
			return (lh + 1);
		}
		else return (rh + 1);
		}

}

template<class T>
int countNodes(BtreeNode<T> *root){
	int init_count_num = 1;
	if (root == NULL)
	return 0;
	else{

		if (root->get_left() != NULL){
			init_count_num += countNodes(root->get_left());
		}
		if (root->get_right() != NULL){
			init_count_num += countNodes(root->get_right());
		}
	}
	return init_count_num;
}

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root){
	if (root == NULL)
	return root;

	else {
		BtreeNode<T> *mirrored = new BtreeNode<T>(root->get_data(), root->get_right(), root->get_left());
		mirror(root->get_right());
		mirror(root->get_left());
		return mirrored;
	}

}

template<class T>
bool isComplete(BtreeNode<T> *root){ // optional
//	bool c = false;
//	if (root == NULL)
//		return c;
//	else {
//		if (root->get_right() != NULL && root->get_left() == NULL)
//			return c;
//		else {
//			c = true;
//		}
//		c = (isComplete(root->get_right()) && isComplete(root->get_left()));
//
//	}
//	return c;
	return false;
}

#endif //LAB9_BTREEEXERCISES_H
