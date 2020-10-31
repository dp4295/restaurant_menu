// Author : DEEP PATEL 
// CS202
// ASSIGNMENT 3
// purpose: This file have implementation function defined in  data.h file 

#include "data.h"

// ++ ++ ^^^^^^ ^^^ ^^^ START IMPLEMETATION OF FOOD FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^
food::food() {} 


// copy constructor with argument list
food::food(char * d_name, char * orign , char * diatary_restriction,int cal)
{
	dish_name = d_name; 

	origin = orign; 

	restriction = diatary_restriction; 

	calories = cal; 
}


food::food(const food & copy) // copy construcutor 
{
	// since we have Custom String class assignment operator will allocate memory 
	dish_name = copy.dish_name; 

	origin = copy.origin;  

	restriction = copy.restriction; 	

	calories = copy.calories; 

}


void food::copy_food(const food & copy)
{
	// since we have Custom String class assignment operator will allocate memory 
	dish_name = copy.dish_name; 

	origin = copy.origin;  

	restriction = copy.restriction; 	

	calories = copy.calories; 

}

// make copy of my data 
food  & food::operator=(const food & food_object2) // deep copy
{
	if(this == & food_object2) // self assignment
		return *this; 

	// since we have Custom String class assignment operator will allocate memory 
	dish_name = food_object2.dish_name; 

	origin = food_object2.origin;

	restriction = food_object2.restriction; 

	calories = food_object2.calories; 

	return *this; //return current assign memory to fucntion call
} 

food::~food()
{
	// empty body because we have custom String class implemented; 
	// that will take care for the deallocation of memory 
} 


// return true and false 
bool food::operator < (const food & sec_obj) const
{
	
	if(!sec_obj.calories)
	{
		cout << "Second operand is NULL\n" ; 
		return 0; 
	} 


	
	if(calories < sec_obj.calories) 
	{
		return true;
	}
	else
	{
		return false;  
	}

	return false;  

}


// display helper function
void food::display(ostream & out ) const
{
	out << "\tdish_name          : " << dish_name  << endl; 
	out << "\torigin             : " << origin << endl; 
	out << "\tdiatary restriction: " << restriction << endl; 
	out << "\tCalories           : " << calories << endl; 
}


// extraction operator 
ostream & operator << (ostream & out, const food & second_obj)
{
	second_obj.display(out); 

	return out; 
}
// ++ ++ ^^^^^^ ^^^ ^^^ END IMPLEMETATION OF FOOD FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^



// ++ ++ ^^^^^^ ^^^ ^^^ START IMPLEMETATION OF MAIN_COURSE FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^
main_course::main_course() {} 

main_course::main_course(char * d_name, char * origin, char * restriction,int cal, int c_protin, int d_fiber):food(d_name, origin, restriction,cal), protin(c_protin), dietary_fiber(d_fiber) { } // initilization list

main_course::main_course(const main_course & copy): food(copy) 
{
	protin = copy.protin; 
	dietary_fiber = copy.dietary_fiber; 
} 

main_course & main_course::operator=(const main_course & sec_obj) // deep copy 
{
	if(this == &sec_obj) // self assignment 
		return *this; 


	food::copy_food(sec_obj); 
	protin = sec_obj.protin; 

	dietary_fiber = sec_obj.dietary_fiber; 


	return *this; 

}


void main_course::display(ostream & out) const
{
	cout << "\n\n"; 
	food::display(out); 
	out << "\tProtin             : " << protin << endl; 
	out << "\tDietary Fiber      : " << dietary_fiber << endl; 

}

ostream & operator<< ( ostream & out, const main_course & second_obj)
{

	second_obj.display(out); 

	return out; 
} 

main_course::~main_course(){ }; 

// ++ ++ ^^^^^^ ^^^ ^^^ END IMPLEMETATION OF MAIN_COURSE FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^

// ++ ++ ^^^^^^ ^^^ ^^^ START IMPLEMETATION OF DESERT FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^

desert::desert() {}; 

desert::desert(char * d_name, char * origin, char * restriction, int cal, int sat, int sodm, int car): food(d_name, origin, restriction, cal), saturated_fat(sat), sodium(sodm), carbohydrates(car) 
{ }


desert::desert(const desert & copy): food(copy)
{

	saturated_fat = copy.saturated_fat; 

	sodium  = copy.sodium; 

	carbohydrates = copy.carbohydrates; 

}

desert::~desert() {};  


desert & desert::operator = (const desert & sec_obj)
{

	if(this == &sec_obj) // self assignment 
		return *this; 


	food::copy_food(sec_obj); 


	saturated_fat = sec_obj.saturated_fat; 

	sodium  = sec_obj.sodium; 

	carbohydrates = sec_obj.carbohydrates; 


	return *this; 


} 

void desert::display(ostream & out) const  // display helper function
{
	cout << "\n\n"; 
	food::display(out); 
	out << "\tSaturated_fat(g)   : "<< saturated_fat << endl; 
	out << "\tSodium       (mg)  : " << sodium << endl; 
	out << "\tCarbohydrates (g)  : " << carbohydrates << endl; 
}

ostream & operator<< (ostream & out , const desert & sec_obj)
{
	sec_obj.display(out); 

	return out; 
}


// ++ ++ ^^^^^^ ^^^ ^^^ END IMPLEMETATION OF DESERT FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^


// ++ ++ ^^^^^^ ^^^ ^^^ START IMPLEMETATION OF BEVERAGE FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^
beverage::beverage() {}; 

// derivation list to invoked base class constructor
beverage::beverage(char * d_name, char * origin, char * restriction, int cal, int sweet, int sodm, int carb): food(d_name, origin, restriction, cal), sugar(sweet), sodium(sodm), carbohydrates(carb)
{}

beverage::beverage(const beverage & copy): food(copy)
{
	sugar = copy.sugar; 

	sodium = copy.sodium; 

	carbohydrates = copy.carbohydrates;

}
	
beverage::~beverage() {} 

beverage & beverage::operator = (const beverage & sec_obj) // deep copy
{
	if(this == & sec_obj)
		return *this; 

	food::copy_food(sec_obj); 

	sugar = sec_obj.sugar; 

	sodium = sec_obj.sodium;

	carbohydrates = sec_obj.carbohydrates; 

	return *this; 
}

void beverage::display(ostream & out) const   // display helper fucntion
{
	cout << "\n\n"; 
	food::display(out); 
	out << "\tsugar              : " << sugar << endl; 
	out << "\tSodium             : " << sodium << endl; 
	out << "\tCarbohydrates      : "<< carbohydrates << endl; 

}
	

ostream & operator << (ostream & out, const beverage & sec_obj)
{
	sec_obj.display(out); 
	return out; 

}
	
	
// ++ ++ ^^^^^^ ^^^ ^^^ END IMPLEMETATION OF BEVERAGE FUNCTION ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^
