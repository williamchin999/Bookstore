#include "books.h"

//this counts how many books we have in inventory
int books::count = 0;
books::books()
{
	ISBN = " ";
	author = " ";
	publisher = " ";
	title = " ";
	dateAdded = " ";
	retail = 0.0;
	wholeSale = 0.0;
	count++;
	
}

books::books(std::string ISBN, std::string title, std::string author, std::string publisher, std::string dateAdded, double retail, double wholeSale)
{
	this->ISBN = ISBN;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->dateAdded = dateAdded;
	this->retail = retail;
	this->wholeSale = wholeSale;
	count++;
	
}
//destructor
books::~books()
{
	
	count--;
	std::cout << "Destroyed a book we have  " << count << " books left" << std::endl;
}

std::string books::getISBN()
{
	return ISBN;
}
std::string books::getTitle()
{
	return title;
}
std::string books::getAuthor()
{
	return author;
}
std::string books::getPublisher()
{
	return publisher;
}
std::string books::getDateAdded()
{
	return dateAdded;
}

double books::getRetail()
{
	return retail;
}
double books::getWholesale()
{
	return wholeSale;
}


void books::setISBN(std::string ISB)
{
	ISBN = ISB;
}
void books::setAuthor(std::string auth)
{
	author = auth;

}
void books::setTitle(std::string titl)
{
	title = titl;
}
void books::setPublisher(std::string pub)
{
	publisher = pub;

}
void books::setDateAdded(std::string date)
{
	dateAdded = date;
}
void books::setRetail(double re)
{
	retail = re;
}
void books::setWholesale(double wh)
{
	wholeSale = wh;
}


//Checks if two books are the same........ must do somewthing with this?
 bool operator==( const books &bookLeft,  const books &bookRight)
{
	 if (bookLeft.author == bookRight.author && bookLeft.title == bookRight.title && bookLeft.ISBN == bookRight.ISBN
		 && bookLeft.publisher == bookRight.publisher && bookLeft.dateAdded == bookRight.dateAdded)
		 return true;
	 else
		 return false;
}

 std::ostream &operator<< (std::ostream &out, const books &cons) 
 {
	return out << cons.author << std::endl;
 }
 
