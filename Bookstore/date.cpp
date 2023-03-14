#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

date::date()
{
    
}


void date::setMonth(Inventory *ptr)
{
    
    std::string date = ptr->getDateAdded();
    
    std::stringstream ss;
    ss.str(date);
    //For every encounter of the first element of the date which would be the month
    //Set it to the month variable
    //Then compare and assign a value to int mo.
    ss>>month;
    
    if(month == "January")
        mo = 1;
    else if(month == "February")
        mo = 2;
    else if(month == "March")
        mo = 3;
    else if(month == "April")
        mo = 4;
    else if(month == "May")
        mo = 5;
    else if(month == "June")
        mo = 6;
    else if(month == "July")
        mo = 7;
    else if(month == "August")
        mo = 8;
    else if(month == "September")
        mo = 9;
    else if(month == "October")
        mo = 10;
    else if(month == "November")
        mo = 11;
    else if(month == "December")
        mo = 12;
    
}

void date::setDay(Inventory *ptr)
{
    std::string date = ptr->getDateAdded();
    std::string trashValue;
    std::stringstream ss;
    ss.str(date);
    //Same as month but we ignore first element then we assign second occurence to int day
    ss>>trashValue>>day;
    
    
}

void date::setYear(Inventory *ptr)
{
    std::string date = ptr->getDateAdded();
    std::string trashValue,trashValue2;
    std::stringstream ss;
    ss.str(date);
    
    //Since the year is the final element we ignore the first two
    ss>>trashValue>>trashValue2>>year;
    
}

void date::setBook(Inventory *ptr){

    book = ptr;
}

int date::getMonth()
{
    return mo;
}

int date::getDay()
{
    return day;
}
int date::getYear()
{
    return year;
}
std::string date::getInfo()
{
    //In order to return a string we made string variables to print out info
    std::string da = book->getDateAdded();
    std::string tit = book->getTitle();
    std::string IS = book->getISBN();
    std::string au = book->getAuthor();
    std::string pub = book->getPublisher();
    std::string all = IS + " " + tit + " " +au+" "+ pub +" " + da;
    
    return all;
}



