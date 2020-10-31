// Author : DEEP PATEL 
// CS202
// ASSIGNMENT 3
// PURPOSE: PURPOSE OF THIS FILE IS TO IMPLEMENT FUNCTION PROTO TPYES DEFINED IN data.cpp 
// ROLES OF EACH CLASSES : FOOD IS BASE CLASS. DERIVED CLASSES  ARE MAIN_COURSE, DESERT and BEVERAGE 
// EACH CLASS ARE RESPONSIBLE TO ALLOCATE MEMORY. DEALLOCATE MEMORY, COPY PASSED MEMORY. DISPLAY, 


#include "String.h"


class food
{
	protected: 
		String dish_name; 
		String origin; 
		String restriction; 
		int calories; 
		virtual void display(ostream & out ) const; 

	public: 
		food(); 
		virtual ~food(); 
		food(char * dish_name, char *  origin, char * restriction, int cal); 
		food(const food & copy); // copy constructor 
		void copy_food(const food & copy); // explicit copy constructor require to make copy where derived object is assigned to pointer to base class. 
		virtual food & operator=(const food & ); // deep copy
		friend ostream & operator << (ostream & out, const food & second_obj); 
		bool operator < (const food & sec_obj) const;  

}; 


class main_course: public food
{
	protected: 
		int protin;  
		int dietary_fiber; 
		void display(ostream & out) const; 


	public: 
		main_course(); 
		main_course(char * d_name, char * origin, char * restriction,int cal, int c_protin, int d_fiber); 
		main_course(const main_course & copy); 
		~main_course(); 
		main_course & operator=(const main_course & sec_obj); // deep copy 
		friend ostream & operator<< ( ostream & out, const main_course & second_obj); 

}; 


class desert: public food
{
	// chocolate Chip Cookie Sundae:Applebee's:calories:Saturated fat(g):Sodium(mg):Carbohydrates(9)
	protected: 
	    int saturated_fat; // (g) 
		int sodium; 		// (mg) 
		int carbohydrates;  // (g)	
		void display(ostream & out) const;    // display helper function

	public:
		desert(); 
		desert(char * d_name, char * origin, char * restriction, int cal, int sat, int sodm, int car); 
		desert(const desert & copy); 
		~desert(); 
		desert & operator = (const desert & sec_obj); // deep copy 
		friend ostream & operator<< (ostream & out , const desert & sec_obj); 


}; 


class beverage: public food
{
	protected: 
	int sugar; // gram 
	int sodium ; // mg 
	int carbohydrates;   // g 
	void display(ostream & out) const;   // display helper fucntion

	public: 
	beverage(); 
	beverage(char * d_name, char * origin, char * restriction, int cal, int sweet, int sodm, int carb); 
	beverage(const beverage & copy); 
	~beverage(); 
	beverage & operator = (const beverage & sec_obj); // deep copy
	friend ostream & operator << (ostream & out, const beverage & sec_obj); 

}; 
