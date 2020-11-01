# Display menu

This console application use by party guests to see the menu. 
The application written in C++. The data from external text file will store into binary search tree to efficiently provide searching and removing operation. 

## Getting started

Console application created for Programming System at Portland State University.

![Home page](https://github.com/dp4295/restaurant_menu/blob/master/home_page.png)

## System design 

- The application follows object oriented design.
- The different categories of dishes are ''' desert , beverage and main course ''' are choosen as derived classes from ''' food ''' basse class. 
- The data structure classes that manage the application are bst_node and bst_tree. bst_node has reference to food class and bst_tree holds the root of type bst_node (in another word root is reference of type bst_node) 
- The client(main class) create the object of type bst_tree and call the insert(), display(), and remove() methods based on user's choice. 
- Another feature of this application is custom string class which overload operators like ''' =, >> , << , ==, !=, and < '''



