// Author : DEEP PATEL 
// CS202
// ASSIGNMENT 3
// purpose:  CONTAIN FUNCTION IMPLEMENTATION FOR bst_node and bst_tree classes
// data_structure.h file explain roles of bts_node and bts_tree classes 


#include "data_structure.h" 


// default constructor 
bst_node::bst_node(): data(NULL), right(NULL), left(NULL)  {} 

// deallocate node memory 
// Only if exist
bst_node::~bst_node()
{
	if(data)
	{
		delete data; 
		data = NULL; 
	} 

	if(left) 
	{
		delete left; 
		left = NULL; 
	}

	if(right)
	{
		delete right; 
		right = NULL; 
	} 
}

//  make a copy of main course and assign value to it data members 
bst_node::bst_node(const main_course & to_add)
{
	data = new main_course(to_add); 
}

//  make a copy of desert and assign value to it data members 
bst_node::bst_node(const desert & to_add)
{
	data = new desert(to_add); 
}

//  make a copy of beverage and assign value to it data members 
bst_node::bst_node(const beverage & to_add)
{
	data = new beverage(to_add); 
}

// go to left side 
bst_node * & bst_node::go_left()
{
	return left; 
}

// go to right side 
bst_node * & bst_node::go_right()
{
	return right; 
}

// set_left to passed ptr 
// note: passed the pointer of bast_node
void bst_node::set_left(bst_node * ptr)
{
	left = ptr;
}

// set right to passed ptr 
// note: passed the pointer of bast_node
void bst_node::set_right(bst_node * ptr)
{
	right = ptr; 
}



// It will call by bst_tree class. 
// Display the data 
int bst_node::display(ostream & cout ) const
{
	cout << *data; // oveloaded << operator 

	return 0; 
}


// it will return the number based on its type 
int bst_node::checkType()
{
	if( typeid(*data) == typeid(main_course) )
	{ 
		return 1; 

	}

	if ( typeid(*data) == typeid( desert) )
	{
		return 2; 
	}

	if (typeid(*data) == typeid(beverage))
	{

		return 3; 
	}

	return 0; 
}


// if is less then passed data then insert 
bool bst_node::operator < (const bst_node & sec_obj) const
{

	if(sec_obj.data)
		return this->data < sec_obj.data; 


	return false; 
}
//  -----------------------------------------------------------------------------------------------------------------------------------


// default constructor 
bst_tree::bst_tree(): root(NULL) {} 

// destructor to deallocate memory
bst_tree::~bst_tree()
{
	remove_all(root);  	
}

// remove function. 
// call from main 
int bst_tree::remove()
{
	return remove_all(root); 
}

// recursively traverse in the list and delete root
int bst_tree::remove_all(bst_node * & root)
{
	int count = 1; 

	if(!root) return 0; 

	count += remove_all(root->go_left()) + remove_all(root->go_right());  

	delete root; 
	root  = NULL; 

	return count; 
}



// call from main 
// This function will call all the function that read from external file
int bst_tree::insert()
{
	return insert_main_course() + insert_desert() +	insert_beverage(); 

}


// read from main_course.txt file
// call insert function to pass the information in in tree 
int bst_tree::insert_main_course()
{
	ifstream infile; 


	infile.open("main_course.txt"); 


	char name[50]; 
	char location[50]; 
	char restriction[60]; 
	int cal; 
	int protin; 
	int fiber; 
	bst_node * newnode; 



	infile.get(name, 100, ':'); 
	infile.ignore(100, ':'); 


	while(infile && !infile.eof())
	{
		infile.get(location, 50, ':'); 
		infile.ignore(50, ':'); 


		infile.get(restriction, 50, ':');
		infile.ignore(50, ':'); 


		infile >>cal;
		infile.ignore(50, ':'); 


		infile >> protin ; 
		infile.ignore(50, ':'); 



		infile >> fiber; 
		infile.ignore(50, '\n'); 


		newnode = new bst_node(main_course(name, location, restriction, cal, protin, fiber)); 
		insert(newnode, root); 


		infile.get(name, 100, ':'); 
		infile.ignore(100, ':'); 



	}


	infile.close(); 
	infile.clear(); 


	return 1; 

}


// read from desert.txt file
// call insert function to pass the information in in tree 
int bst_tree::insert_desert()
{
	ifstream infile; 


	infile.open("desert_menu.txt"); 


	char name[50]; 
	char location[50]; 
	char restriction[60]; 
	int cal; 
	int sat_fat; 
	int sdm; 
	int car; 


	bst_node * newnode; 



	infile.get(name, 100, ':'); 
	infile.ignore(100, ':'); 


	while(infile && !infile.eof())
	{
		infile.get(location, 50, ':'); 
		infile.ignore(50, ':'); 


		infile.get(restriction, 50, ':');
		infile.ignore(50, ':'); 


		infile >>cal;
		infile.ignore(50, ':'); 


		infile >> sat_fat; 
		infile.ignore(50, ':'); 



		infile >> sdm;  
		infile.ignore(50, ':'); 

		infile >> car;  
		infile.ignore(50, '\n'); 

		newnode = new bst_node(desert(name, location, restriction, cal, sat_fat, sdm , car)); 
		insert(newnode, root); 


		infile.get(name, 100, ':'); 
		infile.ignore(100, ':'); 



	}


	infile.close(); 
	infile.clear(); 


	return 1;
}


// read from beverage.txt file
// call insert function to pass the information in in tree 
int bst_tree::insert_beverage()
{
	ifstream infile; 


	infile.open("beverage.txt"); 


	char name[50]; 
	char location[50]; 
	char restriction[60]; 
	int cal; 
	int sugar;  
	int sdm;  
	int carb;  


	bst_node * newnode; 



	infile.get(name, 100, ':'); 
	infile.ignore(100, ':'); 


	while(infile && !infile.eof())
	{
		infile.get(location, 50, ':'); 
		infile.ignore(50, ':'); 


		infile.get(restriction, 50, ':');
		infile.ignore(50, ':'); 


		infile >>cal;
		infile.ignore(50, ':'); 


		infile >> sugar; 
		infile.ignore(50, ':'); 



		infile >> sdm;  
		infile.ignore(50, ':'); 

		infile >> carb;   
		infile.ignore(50, '\n'); 

		newnode = new bst_node(beverage(name, location, restriction, cal, sugar, sdm , carb)); 
		insert(newnode, root); 


		infile.get(name, 100, ':'); 
		infile.ignore(100, ':'); 



	}


	infile.close(); 
	infile.clear(); 



	return 1; 

}


// recursive function for insertion in tree
int bst_tree::insert(bst_node * add, bst_node * & root)
{
	if(!root)
	{ 
		// root = new bst_node;
		root = add; 
		root->set_left(NULL); 
		root->set_right(NULL); 
		return 1; 

	} 

	else if(root < add ) // operator overloading 
	{
		return insert(add, root->go_left()); 
	}
	else
	{

		return insert(add, root->go_right());
	}

	return 0; 

}

int bst_tree::display() const
{
	if(!root) 
	{
		cout << "\n\t THERE IS NO ITEM IN MENU \n\n"; 
	}
	return display(root); 

}


// helper display function for << operator
int bst_tree::display(bst_node * root) const 
{
	if(!root) return 0; 

	cout << root; // overloaded << operator    ||   //	root->display(); 

	return display(root->go_left()) + display(root->go_right()); 

}

// call from display fnction to 
// another layer of extraction. 
// If client want to display directly using cout << root; 
ostream & operator <<(ostream & out , const bst_node * sec_obj)
{
	sec_obj->display(out); 

	return out; 
}


// used by main file to display specific type of food 
// passed the choise 
int bst_tree::display_food_type(int type) const
{


	if(!root) return 0; 

	if(type == 1 || type == 2 || type == 3)
	{
		return display_food_type(root, type);
	}
	else
	{
		cout << "\nPLEASE INPUT 1, 2 or 3\n\n"; 
	} 

	return 0; 

}

// used within bst_tree class to display root data based on customer choice
int bst_tree::display_food_type(bst_node * root, const int type) const
{

	if(!root) 
	{
//		cout <<  "\nTHERE NOTHING TO DISPLAY\n";  
		return 0; 
	}

	if(root->checkType()  == type) 
	{

		if(type == 1)
		{

			cout << "\n\n\t MAIN COURSE MENU \n"; 
			cout << "\t_________________________\n"; 
		}

		if(type == 2)
		{
			cout << "\n\n\t DESERT MENU \n"; 
			cout << "\t_________________________\n"; 
		}


		if(type == 3) 
		{
			cout << "\n\n\t BEVERAGE MENU \n"; 
			cout << "\t_________________________\n"; 
		}

		cout << root; // operator overloading  same as root->display(); 

	}


	return display_food_type(root->go_left(), type) + display_food_type(root->go_right(), type); 
}

