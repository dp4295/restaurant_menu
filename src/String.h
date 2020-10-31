// Author : DEEP PATEL 
// version : 0.0
// Purpose : It provide below features: 
// 			 cout with << operator 
// 			 cin with  >> operator 
// 			 assignment with = operator 
//			 comparing with == operator. 
//           copy the char * into string object 
//           copy the string object into another strng object. 
// 			 deallocating memory whenever sting object is declared 
// ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ +++ ++ ++  ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++

#ifndef DEEP_STRING_H
#define DEEP_STRING_H

#include <iostream> 
#include <cstring>
#include <cctype> 

using namespace std; 

class String 
{
	protected: 

	char * str; 
	int len;   



	public: 

	String(); 
	String(const char * c); 
	String(const String & s);	// coping passed string object  
	~String();  				// destructor 

	
	String &operator=(const String & s);     

	String & operator= (const char * c); 
	// Friend function when first operand is non - class member 
	friend istream & operator>>(istream & in, String & s); 
	friend ostream & operator<<(ostream & out , const String & s); 
	

	friend bool operator ==(const String & s, const char * c); 	
	bool operator==(const String & s) const;  
	bool operator!=(const String & s) const; 
	bool operator<(const String & s) const; 


}; 

#endif
