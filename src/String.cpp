// Author : DEEP PATEL
// version : 0.0
// Purpose : Implementing the proto types definded in Deep_string.h class. It provide below features:
// 			 cout with << operator
// 			 cin with  >> operator
// 			 assignment with = operator
//			 comparing with == operator.
//           copy the char * into string object
//           copy the string object into another strng object.
// 			 deallocating memory whenever sting object is declared
// ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ +++ ++ ++  ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++

// #include "Deep_string.h"
#include "String.h"
// using namespace std;

// empty string constructor
String::String() : str(NULL), len(0) {}

// Coping from passed Char * data type into String object
String::String(const char *c)
{
	str = new char[strlen(c) + 1];
	strcpy(str, c);
}

// coping from passed string object into String object
String::String(const String &s)
{
	str = new char[s.len + 1];
	strcpy(str, s.str);
}

// destructor will automatically invoked at the end of the program whenever String object is declared
String::~String()
{
	if (str)
		delete[] str;
}

String &String::operator=(const char *c)
{
	if (str)
	{
		delete[] str;
		str = NULL;
		len = 0;
	}

	str = new char[strlen(c) + 1];
	strcpy(str, c);
	len = strlen(c);
	return *this;
}

// Assign second operand data to first operand
// NOTE: both is object of type String
String &String::operator=(const String &s)
{
	if (this == &s) // check for self assignment
		return *this;

	if (str) // if current object has a value
	{

		delete[] str;
		str = NULL;
		len = 0;
	}

	if (s.str) // check s.str is not NULL
	{
		str = new char[s.len + 1];
		strcpy(str, s.str);
		len = s.len;
	}

	return *this;
}

// input pass object using >> operator
istream &operator>>(istream &in, String &s)
{
	char temp[100];
	in.get(temp, 100, '\n');
	in.ignore(100, '\n');

	/*
	if(s.str)
		delete [] str; 
		*/

	s.len = strlen(temp);
	s.str = new char[s.len + 1];
	strcpy(s.str, temp);

	return in;
}

// display passed string object with use of <<
ostream &operator<<(ostream &out, const String &s)
{
	out << s.str;

	return out;
}

bool operator==(const String &s, const char *c)
{
	return (s == String(c));
}

// compare to String object and return 0 or 1
bool String::operator==(const String &s) const
{
	if (!s.str) // second operand is NULL. @istrue return 0, @isfalse go next line
	{
		cout << "NO STRING TO COMPARE\n";
		return false;
	}

	if (str)
	{
		if (strcmp(str, s.str) == 0)
		{
			return true;
		}
	}
	return false;
}

// compare first and second operand are same or not
bool String::operator!=(const String &s) const
{
	if (!s.str)
	{
		cout << "NO STRING TO COMPARE\n";
		return false;
	}

	if (str)
	{
		if (strcmp(str, s.str) != 0)
		{
			return true;
		}
	}
	return false;
}

// compare first operand is less then second operand
bool String::operator<(const String &s) const
{
	if (!s.str)
	{
		cout << "Second operand is NULL\n";
		return false;
	}

	if (!str)
	{
		cout << "First operand is NULL\n";
		return false;
	}

	if (strcmp(str, s.str) < 0)
	{
		return true;
	}
	else
		return false;
}
