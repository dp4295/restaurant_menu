// Author : DEEP PATEL 
// CS202
// ASSIGNMENT 3
// purpose: This file has defined proto type for data strucuture class



#ifndef DATA_STRUCTURE_H_
#define DATA_STRUCTURE_H_ 

#include <iostream>
#include "data.h"
#include <fstream>
#include <typeinfo> 


class bst_node
{
	protected: 
	food * data; 
	bst_node * right; 
	bst_node * left; 
		


	public: 
	bst_node(); 
	bst_node(const main_course & to_add);
	bst_node(const beverage  & to_add); 
	bst_node(const desert  & to_add); 
	~bst_node(); 
	bst_node * & go_left(); 
	bst_node * & go_right(); 
	void set_left(bst_node * ptr); 
	void set_right(bst_node * ptr); 
	int display(ostream &  = cout) const;  
	int checkType();
	bool operator < (const bst_node & sec_obj) const; 
	friend ostream & operator<<(ostream & out , const bst_node * sec_obj); 

}; 


class bst_tree
{
	protected: 
		bst_node * root; 
		int insert_main_course(); 
		int insert_desert(); 
		int insert_beverage(); 
		int insert(bst_node * add, bst_node * & root); 
		int display( bst_node * root) const; 
		int remove_all(bst_node * & root); 
		int display_food_type(bst_node * root, const int type) const; 

	public: 
		bst_tree(); 
		~bst_tree(); 
		int insert(); 
		int display() const; 
		int remove(); 
		int display_food_type(int type) const;  

}; 

	
#endif
