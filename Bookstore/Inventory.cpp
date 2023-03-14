#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"
#include "InterfaceScreen.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int Inventory::bookCount = 0;
Inventory *invPtr = new Inventory();

//Default constructor
Inventory::Inventory() {
    ISBN = " ";
    author = " ";
    publisher = " ";
    title = " ";
    dateAdded = " ";
    retail = 0;
    wholeSale = 0;
    quantity = 1;
}

//8 argument constructor
Inventory::Inventory(std::string ISBN, std::string title, std::string author, std::string publisher, std::string dateAdded, double retail, double wholeSale, int quantity)
{
    this->ISBN = ISBN;
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->dateAdded = dateAdded;
    this->retail = retail;
    this->wholeSale = wholeSale;
    this->quantity = quantity;

}

//destructor
Inventory::~Inventory()
{
    bookCount--;
}

/*
	Menu for inventory

	@param ptr Pointer to Inventory array
*/
void Inventory::InventoryMenu(Inventory *ptr)
{
	std::cin.clear();
    int userInput = 0;
    std::string userInputString;
    std::cout << std::setw(15) << "\nSerendipity Booksellers" << std::endl;

    while (userInput != 5) {

        std::cout << std::setw(20) << "Inventory Database" << std::endl << std::endl;
        std::cout << std::setw(15) << "1. Look up a book" << std::endl;
        std::cout << std::setw(1) << "2. Add a book" << std::endl;
        std::cout << std::setw(14) << "3. Edit a book's record    " << std::endl;
        std::cout << std::setw(14) << "4. Delete a book" << std::endl;
        std::cout << std::setw(14) << "5. Return to main menu" << std::endl << std::endl;
        std::cout << std::setw(13) << "Enter your choice: ";

		std::getline(std::cin, userInputString);
		std::cin.clear();

		try {
			userInput = stoi(userInputString);
			if (userInputString.length() > 1) {
				throw 1;
			}
			if (userInput < 1 || userInput > 5) {
				throw 2;
			}

		}
		catch (...) {
			userInput = 8;
		}

        switch (userInput)
        {
        case 1:
            invPtr->lookUpBook(ptr);
            break;
        case 2:
            invPtr->addBook(ptr);
            break;
        case 3:
            invPtr->editBook(ptr);
            break;
        case 4:
            invPtr->deleteBook(ptr);
            break;
        case 5:
            std::cout << std::endl;
            mainMenu(ptr);
            break;
        default:
            std::cout << "Please enter a valid input!\n" << std::endl;
            break;

        }
    }
}

/*
	Search for a look based on user selection
	@param ptr Pointer to Inventory array
*/
void Inventory::lookUpBook(Inventory *ptr)
{
    std::string userString;
    int userChoose;
    int errorCheck = 0;
    int searchByNum = 0;

	std::cin.clear();
    std::cout << "\n1.ISBN \n2.Title \n3.Author\n4.Publisher\nSearch book by: ";
    std::cin >> userChoose;
    std::cin.ignore();

    try {//Prevent crashing from unexpected input

        if (userChoose == 1) {
            std::cout << "\nCurrent available book ISBN: \n";
            
            for (int i = 0; i < bookCount; i++) {
                std::cout << (i + 1) << ": " << (ptr + i)->getISBN() << std::endl;
            }

            std::cout << "\nPlease enter the ISBN Number/number: ";
            std::getline(std::cin, userString);

            if (userString.length() < 6) { 
                try {
                    userChoose = stoi(userString);
                    if (userChoose < 0 || userChoose > bookCount) {
                        throw 5;
                    }
                    searchByNum = 1;
                    errorCheck = 1;
                }
                catch (std::invalid_argument e) {

                }
            }

            if (searchByNum == 1) {
                std::cout << "\n" << (ptr + (userChoose - 1)) << std::endl << std::endl;
            }

            for (int i = 0; i < bookCount && searchByNum == 0; i++)
            {

                if (userString == (ptr + i)->getISBN())
                {
                    if (errorCheck == 0) {
                        std::cout << "\nFound the book!\n";
                    }
                    std::cout << (ptr + i) << std::endl;
                    errorCheck = 1;
                }


            }

            if (errorCheck == 0) {
                throw 1;
            }
            else {
                std::cout << "------------------------------" << std::endl;
            }

        }
        else if (userChoose == 2) {
            std::cout << "\nCurrent available book title: \n";
            
            for (int i = 0; i < bookCount; i++) {
                std::cout << (i + 1) << ": " << (ptr + i)->getTitle() << std::endl;
            }

            std::cout << "\nPlease enter the book title/number of a book\s: ";
			std::getline(std::cin, userString);

            try {
                userChoose = stoi(userString);

                if (userString.length() > 2) {
                    throw std::invalid_argument("Search by title");
                }

                if (userChoose < 0 || userChoose > bookCount) {
                    throw 6;
                }


                searchByNum = 1;
            }
            catch (std::invalid_argument e) {

            }

            for (int i = 0; i < bookCount; i++)
            {
                if (searchByNum == 0) {
                    if (userString == (ptr + i)->getTitle())
                    {
                        if (errorCheck == 0) {
                            std::cout << "\nFound the book/s with the title name: " << userString << std::endl << std::endl;
                        }
                        std::cout << (ptr + i) << std::endl;
                        errorCheck = 1;
                    }
                }
                else {
                    if ((ptr + (userChoose - 1))->getTitle() == (ptr + i)->getTitle())
                    {
                        if (errorCheck == 0) {
                            std::cout << "\nFound the book/s with the title name: " << (ptr + (userChoose - 1))->getTitle() << std::endl << std::endl;
                        }
                        std::cout << (ptr + i) << std::endl;
                        errorCheck = 1;
                    }
                }

            }

            if (errorCheck == 0) {
                throw 2;
            }
            else {
                std::cout << "------------------------------" << std::endl;
            }

        }
        else if (userChoose == 3) {
            std::cout << "\nCurrent available book author: \n";
            for (int i = 0; i < bookCount; i++) {
                std::cout << (i + 1) << ": " << (ptr + i)->getAuthor() << std::endl;
            }

            std::cout << "\nPlease enter the author/number of the book/s: ";
            std::getline(std::cin, userString);
            try {
                userChoose = stoi(userString);

                if (userChoose < 0 || userChoose > bookCount) {
                    throw 7;
                }

                if (userString.length() > 2) {
                    throw std::invalid_argument("Search by author");
                }
                searchByNum = 1;
            }
            catch (std::invalid_argument e) {

            }

            for (int i = 0; i < bookCount; i++)
            {
                if (searchByNum == 0) {
                    if (userString == (ptr + i)->getAuthor())
                    {
                        if (searchByNum == 0) {
                            if (errorCheck == 0) {
                                std::cout << "\nFound the book/s with the author name: " << userString << "\n\n";
                                errorCheck = 1;
                            }
                            std::cout << (ptr + i) << std::endl;
                        }
                    }
                }
                else {
                    if ((ptr + (userChoose - 1))->getAuthor() == (ptr + i)->getAuthor())
                    {
                        if (errorCheck == 0) {
                            std::cout << "\nFound the book/s with the author name: " << (ptr + (userChoose - 1))->getAuthor() << std::endl << std::endl;
                        }
                        std::cout << (ptr + i) << std::endl;
                        errorCheck = 1;
                    }
                }
            }


            if (errorCheck == 0) {
                throw 3;
            }
            else {
                std::cout << "------------------------------" << std::endl;
            }
        }
        else if (userChoose == 4) {
            std::cout << "\nCurrent available book publisher: \n";
            for (int i = 0; i < bookCount; i++) {
                std::cout << (i + 1) << ": " << (ptr + i)->getPublisher() << std::endl;
            }

            std::cout << "\nPlease enter the publisher/number of the book/s: ";
            std::getline(std::cin, userString);

            try {
                userChoose = stoi(userString);

                if (userString.length() > 2) {
                    throw std::invalid_argument("Search by publisher");
                }

                if (userChoose < 0 || userChoose > bookCount) {
                    throw 8;
                }

                searchByNum = 1;
            }
            catch (std::invalid_argument) {

            }

            for (int i = 0; i < bookCount; i++)
            {
                if (searchByNum == 0) {
                    if (userString == (ptr + i)->getPublisher())
                    {
                        if (errorCheck == 0)
                        {
                            std::cout << "\nFound the book/s that were published by: " << userString << "\n\n";
                            errorCheck = 1;
                        }
                        std::cout << (ptr + i) << std::endl;
                    }
                }
                else {
                    if ((ptr + (userChoose - 1))->getPublisher() == (ptr + i)->getPublisher())
                    {
                        if (errorCheck == 0) {
                            std::cout << "\nFound the book/s with the publisher name: " << (ptr + (userChoose - 1))->getPublisher() << std::endl << std::endl;
                        }
                        std::cout << (ptr + i) << std::endl;
                        errorCheck = 1;
                    }
                }

            }

            if (errorCheck == 0) {
                throw 4;
            }
            else {
                std::cout << "------------------------------" << std::endl;
            }
        }
        else {
            std::cout << "Invalid input\n\n";
        }


    }
    catch (int e) {

        if (e > 4) {
            std::cout << "Number is out of list! \n" << std::endl;
        }
        else {
            std::cout << "Book not found!\n" << std::endl;
        }
    }

}

/*
	Add a book to the database
	User get to make their choice

	@param ptr Pointer to Inventory array
*/
void Inventory::addBook(Inventory *arr)
{
    std::cout << "\nEnter book information to be added into database." << std::endl;
	(arr + bookCount)->setWholeSale(17.12);
	(arr + bookCount)->setRetail(12.32);

	std::cin >> *(arr + bookCount - 1);

    std::cout << "\n\n" << (arr + bookCount - 1) << "Added to database.\n" << std::endl;

}

/*
	Delete a book from database
	Remove it completely from the array

	@param ptr Pointer to Inventory array
*/
void Inventory::deleteBook(Inventory *ptr)
{
    int userOption, deletedBook = 0;
    bool delBookFound, repeat = true;
    std::string userString, temp;


    std::cout << "\nBook List\n----------------------------------------\n";
    std::cout << "\nCurrent available book title: \n";

    for (int i = 0; i < bookCount; i++) {
        std::cout << (i+1) << ": " << (ptr + i)->getTitle() << std::endl;
    }

    std::cout << "\nPlease enter the title/number of the book to be deleted: ";
    std::getline(std::cin, userString);
    std::cout << std::endl;

    try {
        userOption = stoi(userString);
        temp = (ptr + (userOption - 1))->getTitle();

        if (userString.length() > 2) {
            throw std::invalid_argument("Search by title.");
        }

        if (userOption < 0 || userOption > bookCount) {
            throw 10;
        }

    }
    catch (int e) {
        std::cout << "Number: " << e << " is out of the list!\n" << std::endl;
    }
    catch (std::invalid_argument f) {
        temp = userString;

    }

    for (int k = 0; k < bookCount; k++) {
        delBookFound = false;

        if (temp == (ptr + k)->getTitle()) {
            delBookFound = true;
            if (repeat) {
                deletedBook = (ptr + k)->getQuantity();
                std::cout << (ptr + k) << "\bHas been deleted." << std::endl;
                (ptr + k)->setQuantity(0);
                repeat = false;
            }
        }

        if (delBookFound) {
            for (int l = k; l < bookCount; l++) {
                *(ptr + l) = (ptr + l + 1);
            }
            bookCount--;
        }
    }


    std::cout << "Total copies deleted: " << deletedBook << std::endl << std::endl;

}

//Deallocated dynamic array in this class
void Inventory::deallocatePtr() {
    delete invPtr;
}

/*
	Removes duplicated book from array
	Increment the original book quantity by 1 whenever a duplicate is found

	@param ptr Pointer to Inventory array
*/
void Inventory::duplicateChecker(Inventory *ptr) {
    for (int k = 0; k < bookCount; k++) {
        for (int i = k + 1; i < bookCount; i++) {
            if ((ptr + k)->getTitle() == (ptr + i)->getTitle()) {
                (ptr + k)->increaseQuant();
                
                for (int l = i; l < bookCount; l++) {
                    *(ptr + l) = (ptr + l + 1);
                }
                    bookCount--;
                
            }
        }
    }
}

//Increase quantity of book
void Inventory::increaseQuant() {
    quantity++;
}
/*
	Gives user the option to edit a book
	User get to choose which attribute to edit

	@param ptr Pointer to Inventory array
*/
void Inventory::editBook(Inventory *ptr)
{
    std::string userString, bookEdit;
    int userChoose, option;
    int searchByNum;
    bool invalid;

    std::cout << "\nCurrent available book title: \n";
    for (int i = 0; i < bookCount; i++) {
        std::cout << (i + 1) << ": " << (ptr + i)->getTitle() << std::endl;
    }

    std::cout << "\nPlease enter the title/number of the book to be edited: ";
    std::getline(std::cin, userString, '\n');

    try {
        userChoose = stoi(userString);

        if (userString.length() > 2) {
            throw std::invalid_argument("Search by title");
        }

        if (userChoose < 0 || userChoose > bookCount) {
            throw 9;
        }

        searchByNum = 1;
    }
    catch (std::invalid_argument e) {

    }

    std::cout << (ptr + (userChoose - 1)) << std::endl;


    std::cout << "Which part would you like to edit:\n1: ISBN\n2: Title\n3: Author Name\n4: Publisher\n5: Date added\n6: Back to menu" << std::endl;
    do {
        invalid = false;
        std::cout << "Enter an option: ";
        std::cin >> option;

        if (option < 1 || option > 6) {
            std::cout << "Enter a valid option!\n" << std::endl;
            invalid = true;
        }

    } while (invalid);

    std::cin.clear();
    userString = "";
    if (option < 6) {
        if (option == 1) {
            std::cout << "Enter a new ISBN:    ";
            std::cin.ignore();
            std::getline(std::cin, userString);

            (ptr + (userChoose - 1))->setISBN(userString);
        }
        else if (option == 2) {
            std::cout << "Enter a new title: ";
            std::cin.ignore();
            std::getline(std::cin, userString);

            (ptr + (userChoose - 1))->setTitle(userString);
        }
        else if (option == 3) {
            std::cout << "Enter a new author: ";
            std::cin.ignore();
            std::getline(std::cin, userString);

            (ptr + (userChoose - 1))->setAuthor(userString);
        }
        else if (option == 4) {
            std::cout << "Enter a new publisher: ";
            std::cin.ignore();
            std::getline(std::cin, userString);

            (ptr + (userChoose - 1))->setPublisher(userString);
        }
        else if (option == 5) {
            std::cout << "Enter a new date : ";
            std::cin.ignore();
            std::getline(std::cin, userString);

            (ptr + (userChoose - 1))->setDateAdded(userString);
        }

        std::cout << "\n\nNew book information:\n";
        std::cout << (ptr + (userChoose - 1));
    }

    if (option == 6) {
        std::cout << "\n\n";
        invPtr->InventoryMenu(ptr);
    }

}

//Getter Functions
std::string Inventory::getISBN()
{
    return ISBN;
}

std::string Inventory::getTitle()
{
    return title;
}

std::string Inventory::getAuthor()
{
    return author;
}

std::string Inventory::getPublisher()
{
    return publisher;
}

std::string Inventory::getDateAdded()
{
    return dateAdded;
}

double Inventory::getRetail()
{
    return retail;
}

double Inventory::getWholesale()
{
    return wholeSale;
}
int Inventory::getQuantity()
{
    return quantity;
}

//Setter Functions
void Inventory::setISBN(std::string code)
{
    ISBN = code;

}

void Inventory::setTitle(std::string title)
{
    this->title = title;
}

void Inventory::setAuthor(std::string author)
{
    this->author = author;
}

void Inventory::setPublisher(std::string publish)
{
    publisher = publish;
}

void Inventory::setDateAdded(std::string date)
{
    dateAdded = date;
}

void Inventory::setRetail(double price)
{
    retail = price;
    bookCount++;
}

void Inventory::setWholeSale(double price) {
    wholeSale = price;
}

void Inventory::setQuantity(int quantity) {
    this->quantity = quantity;
}


/*
	Overloading << operator to print out necessary information of the class

	@param out ostream
	@param book Pointer to inventory array
*/
std::ostream &operator<<(std::ostream& out, const Inventory *book)
{
	
    out << std::setw(18) << "Book Information" << std::endl;
    out << "ISBN      : " << book->ISBN << std::endl;
    out << "Title     : " << book->title << std::endl;
    out << "Author    : " << book->author << std::endl;
    out << "Publisher : " << book->publisher << std::endl;
    out << "Date Added: " << book->dateAdded << std::endl;

    return out;

}

/*
	Overloading >> operator to print out necessary information of the class

	@param in istream
	@param book Pointer to inventory array
*/
std::istream &operator>>(std::istream &in, Inventory &book)
{
    std::cout << std::endl << std::setw(18) << "Book Information" << std::endl;
    std::cout << "ISBN            : ";
    std::getline(in,book.ISBN);
    std::cout << "Title           : ";
    std::getline(in,book.title);
    std::cout << "Author          : ";
    std::getline(in,book.author);
    std::cout << "Publisher       : ";
    std::getline(in,book.publisher);
    std::cout << "Date Added      : ";
    std::getline(in,book.dateAdded);
    return in;
}

/*
	Overloading == to compare the attributs of 2 book

	@param bookL pointer to inventory, book to compare
	@param bookR pointer to inventory, book to be compared to
*/
bool operator==(const Inventory *bookL, const Inventory& bookR)
{
    return bookL->author == bookR.author
        && bookL->title == bookR.title
        && bookL->ISBN == bookR.ISBN
        && bookL->publisher == bookR.publisher
        && bookL->dateAdded == bookR.dateAdded;
}


/*
	Overloading < operator to compare the book

	@param bookL Inventory book to compare
	@param bookR Inventory book to be compared to
*/
bool operator<(const Inventory& bookL, const Inventory& bookR)
{
    return bookL.author < bookR.author
        && bookL.title < bookR.title
        && bookL.ISBN < bookR.ISBN
        && bookL.publisher < bookR.publisher
        && bookL.dateAdded < bookR.dateAdded;
}


