#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Inventory
{
private:
	//private variables/members
	std::string ISBN, title, author, publisher, dateAdded;
	double retail, wholeSale;
	int bookInStock;
	static int bookCount;
	int quantity;

public:
	//constructors
	Inventory();
	Inventory(std::string, std::string, std::string, std::string, std::string, double, double, int);

	//destructor
	virtual ~Inventory();

	//class member functions
	void static InventoryMenu(Inventory*);
	virtual void lookUpBook(Inventory*);
	void addBook(Inventory*);
	void editBook(Inventory*);
	void deleteBook(Inventory*);
	void deallocatePtr();
	void duplicateChecker(Inventory*);
	void increaseQuant();


	//getters
	std::string getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getPublisher();
	std::string getDateAdded();
	double getRetail();
	double getWholesale();
	int getQuantity();

	//setters
	void setISBN(std::string);
	void setTitle(std::string);
	void setAuthor(std::string);
	void setPublisher(std::string);
	void setDateAdded(std::string);
	void setRetail(double);
	void setWholeSale(double);
	void setQuantity(int quantity);

	//Operator Overloading
	void operator=(const Inventory *in) {
		ISBN = in->ISBN;
		author = in->author;
		title = in->title;
		publisher = in->publisher;
		dateAdded = in->dateAdded;
		retail = in->retail;
		wholeSale = in->wholeSale;
		quantity = in->quantity;
	}

	friend std::ostream &operator<<(std::ostream&, const Inventory*);
	friend std::istream &operator>>(std::istream& in, Inventory&);
	friend bool operator==(const Inventory*, const Inventory&);
	friend bool operator<(const Inventory&, const Inventory&);


	//Getter and setter for bookCount
	int getCount()
	{
		return bookCount;
	}

	void setCount(int c)
	{
		bookCount = c;
	}



};