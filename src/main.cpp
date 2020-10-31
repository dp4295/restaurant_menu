// Author : DEEP PATEL 
// CS202
// ASSIGNMENT 3
// This is main file mostly deal with customer interface. 
// This file implemented options function. So user can choose their options. 



#include "data_structure.h" 
#include <stdlib.h> 

using namespace std;

void welcome(); 
void menu(); 

int main()
{

	char response; 
	int type; 
	welcome(); 
	bst_tree my_menu; 
	my_menu.insert(); 



	do
	{


		menu(); 
		cout << "INPUT		: "; 
		cin  >> response; 
		cin.ignore(100, '\n'); 


		switch(toupper(response))
		{


			case 'D':
				my_menu.display(); 

				break; 

			case 'R':

	
				cout << "\nRemoved all node\n\n"; 
				my_menu.remove(); 


				break; 

			case 'S':

				cout << "\n\n\tTYPE 1 TO SEE MAIN COURSE\n";
				cout << "\tTYPE 2 TO SEE DESERT\n"; 
				cout << "\tTYPE 3 TO SEE BEVERAGE\n"; 
				cout << "\t_______________________________\n";
				cout << "ENTER YOUR CHOICE ( 1-3) : " ; 
				cin >> type; 
				cin.ignore(100, '\n'); 

				// my_menu.search(input); 


				my_menu.display_food_type(type); 

				break;

			case 'E':

				cout << "SEE YOU AGAIN\n"; 

				break; 

			default: 

				cout << "\nPLEASE ENTER A CORRECT ALPHABET\n\n\n"; 

		} 


	}while(toupper(response) != 'E'); 








	return 0; 
}
void welcome()
{
	cout << "\t___________________ WELCOME TO PARTY ___________________\n" 
		<< "\t|         BELOW IS MENU FOR DIFFERENT DISHES             |\n"
		<< "\t|________________________________________________________|\n\n"; 

}

void menu()
{
	cout << "\n\n\t________ SELECT YOUR OPTIONS ___________\n"
		<< "\t| 'D' TO DISPLAY ALL AVAILABLE MENU     |\n"
		<< "\t| 'S' DISPLAY MENU BASED ON YOUR CHOICES|\n"
		<< "\t| 'R' TO REMOVE DISH FROM MENU          |\n"
		<< "\t| 'E' TO EXIST THE PROGRAM              |\n" 
		<< "\t|_______________________________________|\n"; 

}
