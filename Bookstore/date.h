#include "report.h"
#include <sstream>
#include <string>

class date
{

private:
    //points to a instance in Inventory
    Inventory *book;
    std::string month;
    int day,mo,year;
public:
    date();
    void setDay(Inventory *ptr);
    void setMonth(Inventory *ptr);
    void setYear(Inventory *ptr);
    void setBook(Inventory *ptr);
   /* void setDatedAdded(Inventory *ptr);*/
    
    int getDay();
    int getYear();
    int getMonth();
    std::string getInfo();
    
};
