#pragma once
#include <string>
#include <iostream>
#include <iomanip>


//not finished still need few more variables
class booksData
{

private:
	std::string ISBN;
	std::string title;
	std::string author;
	std::string publisher;
	std::string dateAdded;
	double retail, wholeSale;

	static int count;


public:


	booksData();
	booksData(std::string ISBN, std::string title, std::string author, std::string publisher, std::string dateAdded, double retail, double wholeSale);

	~booksData();

	//gettors
	std::string getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getPublisher();
	std::string getDateAdded();
	double getRetail();
	double getWholesale();
	//setters

	void setISBN(std::string ISB);
	void setTitle(std::string titl);
	void setAuthor(std::string auth);
	void setPublisher(std::string pub);
	void setDateAdded(std::string date);
	void setRetail(double re);
	void setWholesale(double whole);


	void operator=(const booksData &in) {
		this->author = in.author;
	
	}

	friend std::ostream &operator<< ( std::ostream &out, const booksData &cons );
	friend std::istream &operator>> (std::istream &in,  booksData &book);

	friend bool operator==(const booksData &bookL,  const booksData &bookR);
	friend bool operator<(const booksData &bookL, const booksData &bookR);

	static int getCount() { return count; }
	static void setCount(int c) { count = c; }
	



};
