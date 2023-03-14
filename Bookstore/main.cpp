/*
 
CIS 22B Serendipity Booksellers Project
Final Project: Make a POS program with Inevntory, Cashier, and Report Modules
Author: Jun Yi Chuah, William Chin, Christian Rojas
Date:03/19/2020
Professor Goel
PseudoCode:
Read in txt file containing all book info.
We used '~' as delimitter
As it reads the file it will set their attribute for each instance of the Inventory Class
The Inventory class has all the book information
After the program set their attributes the user is sent to a main menu
They have the option to choose between Inventory,Cashier, and Reports.
If user chooses Cashier they will be sent to the Cashier menu.
There they can see a list of avaiable books and their quantity.
The user can add to their cart by choosing the number corresponding to the book
Once the user adds to the cart the quantity is reduced by one.
If user decides to choose an item with quantity 0 display proper message
User can checkout with delimitter '~".
Once in checkout there is a total.
And it will send the user back to the main menu.
If user chooses Inventory they are sent to the Inventory Main Menu
There the user can choose among 4 options.
They can look up a book, add a book, delete a book, or edit a book.
If user exits Inventory menu it will send them back to main menu
If user chooses Reports they are sent to Reports menu
They will will be displayed a list of options where they can print out a report list.
For 3 of the list, they are sorted.
Once user decides to exit it will send them back to main menu
User can choose another module or exit
End of program.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "InterfaceScreen.h"
#include "inventory.h"
#include "report.h"
#include "cashier.h"
using namespace std;


int main() {
	std::string in;
	std::string inFile("bookList.txt");
	std::ifstream myFile(inFile);

	Inventory *myList = new reportModule[70];
	Inventory *cashierList = new cashier[70];

	int x = 0;

	if (!myFile) {
		cerr << inFile << " doesn't exist." << endl;
		exit(1);
	}
	 
	
	//set each objects their own attributes directly from txtfile
	while (!myFile.eof())
	{
	
		getline(myFile, in, '~');
		(myList + x)->setISBN(in);
		getline(myFile, in, '~');
		(myList + x)->setTitle(in);
		getline(myFile, in, '~');
		(myList + x)->setAuthor(in);
		getline(myFile, in, '~');
		(myList + x)->setPublisher(in);
		getline(myFile, in, '~');
		(myList + x)->setDateAdded(in);
		getline(myFile, in, '~');
		(myList + x)->setWholeSale(stod(in));
		getline(myFile, in, '~');
		(myList + x)->setRetail(stod(in));

		getline(myFile, in, '\n');
		
		x++;
	}

	cashierList = myList;

	mainMenu(myList);
	
	delete[] myList;

}

