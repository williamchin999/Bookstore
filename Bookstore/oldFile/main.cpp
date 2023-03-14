#include <iostream>
#include <fstream>
#include <string>
#include "booksData.h"
#include "InterfaceScreen.h"
#include "inventory.h"
using namespace std;

 booksData myList[50];

int main() {
	std::string in;
	std::ifstream myFile("bookList.txt");

	int x = 0;


	 

	//set each objects their own attributes directly from txtfile
	while (!myFile.eof())
	{
		getline(myFile, in, '~');
		myList[x].setISBN(in);
		getline(myFile, in, '~');
		myList[x].setTitle(in);
		getline(myFile, in, '~');
		myList[x].setAuthor(in);
		getline(myFile, in, '~');
		myList[x].setPublisher(in);
		getline(myFile, in, '~');
		myList[x].setDateAdded(in);

		x++;
	}

	menu();


	
	
	system("pause");

	return 0;
}





// 
/*



menu()

*/
