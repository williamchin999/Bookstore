#pragma once
#pragma warning (disable:4996)
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Inventory.h"


class cashier: public Inventory{
    
private:
    int tax;
    Inventory* book;

public:
	//Constructor
    cashier();

	//Destructor
	~cashier();
	
	//Class member function
    void static cashierMenu(Inventory *);
   	void deallocatePtr();
    
	//Setter
    void setBook(Inventory*);
    
	//Getter
    Inventory* getBook();
	std::string getDate();
    
    
   // void lookUpBook(Inventory *);
   // void printInfo(Inventory *);

};



