#include "Inventory.h"
#include "booksData.h"




extern  booksData myList[50];

void InventoryMenu()
{
	int userInput = 0;
	while (userInput != 5) {
		std::cout << std::setw(15) << "serendipity booksellers" << std::endl;
		std::cout << std::setw(20) << "inventory database" << std::endl << std::endl;
		std::cout << std::setw(15) << "1. look up a book" << std::endl;
		std::cout << std::setw(1) << "2. add a book" << std::endl;
		std::cout << std::setw(14) << "3. edit a book's record    " << std::endl;
		std::cout << std::setw(14) << "4. delete a book" << std::endl;
		std::cout << std::setw(14) << "5. return to main menu" << std::endl << std::endl;
		std::cout << std::setw(13) << "enter your choice: ";

		std::cin >> userInput;

		switch (userInput)
		{
		case 1:
			lookUpBook();
		case 2:
			addBook();
		case 3:
			editBook();
		case 4:
			deleteBook();
		default:
			std::cout << "Please enter a valid input " << std::endl;


		}



	}
}
	void lookUpBook()
	{
		std::string userString;

		int userChoose;
		std::cout << "What book are you looking for?.\n1.ISBN \n2.Title \n3.Author\n4.Publisher" << std::endl;
		std::cin >> userChoose;
		switch (userChoose)
		{
		case 1:
			std::cout << "Please enter the ISBN 13 Number please in this format xxx-xxxxxxxxxx" << std::endl;
			std::cin.ignore();
			std::cin >> userString;
			for (int i = 0; i < 50; i++)
			{
				std::cout << sizeof(myList[i].getISBN()) << '\n';
				if (userString == myList[i].getISBN())//our ISBN is 28 bytes long?????? need to fix this 
				{
					std::cout << "Found the book!\n" << myList[i] << std::endl;
					break;
				}
			

			}
			//still need to fix this
			std::cout << " Book not found !" << std::endl;
			break;
		case 2:
			std::cout << "Please enter the title of the book." << std::endl;
			std::cin >> userString;
			//strupr(userString) need to find a way to capalitlze whole title
			for (int i = 0; i < 50; i++)
			{
				if (userString == myList[i].getTitle())
				{
					std::cout << "Found the book/s with the title name: !" << userString << '\n' << myList[i] << std::endl;
					break;
				}

			}
			std::cout << " Book not found !" << std::endl;
			break;
		case 3:
			std::cout << "Please enter the author of the book/s." << std::endl;
			std::cin >> userString;
			//strupr(userString) need to find a way to capalitlze whole title

			/*
			Need to figure out way to find duplicates/ multiple books by same author/publisher
			*/
			for (int i = 0; i < 50; i++)
			{
				if (userString == myList[i].getAuthor())
				{
					std::cout << "Found the book/s with the author name: !" << userString << '\n' << myList[i] << std::endl;
					break;
				}

			}
			std::cout << " Book not found !" << std::endl;
			break;
		case 4:
			std::cout << "Please enter the publisher of the book/s." << std::endl;
			std::cin >> userString;
			//strupr(userString) need to find a way to capalitlze whole title

			/*
			Need to figure out way to find duplicates/ multiple books by same author/publisher
			*/
			for (int i = 0; i < 50; i++)
			{
				if (userString == myList[i].getPublisher())
				{
					std::cout << "Found the book/s that were published by: !" << userString << '\n' << myList[i] << std::endl;
					break;
				}

			}
			std::cout << " Book not found !" << std::endl;
			break;

		}
	
	//do something
}

void addBook(booksData temp, booksData arr[], int numOfBooks)
{
	//add to the last position of the array, require sorting
	arr[numOfBooks] = temp;
	//numOfBooks Increment function;
	
	//Sample code for insertion sort by comparing ISBN and then adding into arr
	//Assume the array is sorted

	/*
		int low, mid, high, i;
		low = 0, high = numOfBooks;
		while(true){
			mid = (low + high) / 2;
			if(temp.getISBN() > arr[mid].getISBN()){			//Binary Search logic
				low = mid + 1;
			}else if(temp.getISBN() < arr[mid].getISBN()){
				high = mid - 1;
			}else if(temp.getISBN() > arr[low].getISBN()
				  && temp.getISBN() < arr[high].getISBN()){ 	//If the ISBN is greater than i - 1 and lower than i + 1, i is the sorted position
					  for(i = numOfBooks; i > high; i--){		//Start from the last book, move last book to i + 1(Empty spot)
						  arr[i] = arr[i - 1];
					  }
					  arr[i] = temp;							//Once all book have been shifted to the right, we can insert our book into i, since the
				  }												  initial book have been shifted to the right.
		}
		
	*/
}

void editBook() {

	//do something
}
void deleteBook(int indexToDel, booksData arr[], int numOfBooks) {
	int i;

	for(i = indexToDel; i < numOfBooks; i++){
		arr[i] = arr[i+1];
	}

	//Set it to null? Or use numOfBooks to restrict the output excluding the "deleted" book?

	//numOfBooks decrement function
	
}
