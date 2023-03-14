#define _CRT_SECURE_NO_WARNINGS
#include "cashier.h"

Inventory *ptrToCash = new cashier[70];
cashier *ptrr;

//cashier constructor
cashier::cashier() : Inventory::Inventory()
{
    
}
//cashier destructor
cashier::~cashier()
{
    
}
void cashier::setBook(Inventory *ptr)
{
    this->book = ptr;
}

Inventory* cashier::getBook()
{
    return book;
}

//This is the cashier Menu
void cashier::cashierMenu(Inventory *ptr)
{
    ptrToCash = ptr;
    std::cout << "\nCurrent available book ISBN: \n";

    static Inventory shoppingCart[70];

    int shoppingCartCount = 0;
    std::string userString;
    int userChoose;
    int errorCheck = 1;
    int searchByNum = 0;
    bool noStock, repeat;

    //Displays all the books in the book database
    while(userString != "~"){//need to find better delim
        searchByNum = 0;
        noStock = false;
        do {
            repeat = false;
            ptrToCash = ptr;
            for (int i = 0; i < ptr->getCount(); i++) {
                (shoppingCart + i)->setQuantity(0);
                std::cout << (i + 1) << ": " << (ptrToCash + i)->getISBN() << "  " << (ptrToCash + i)->getTitle() << "  " << (ptrToCash + i)->getQuantity() << std::endl;
            }

            //checking for exceptions out of book database
            try {
                std::cout << "\nPlease enter the number corresponding to the book to add to cart(Type '~' to check out): ";
                std::getline(std::cin, userString);
                
                if(userString == "~")
                {
                    break;
                }

                if (userString.length() < 3) {
                    try {
                        userChoose = stoi(userString);
                        if (userChoose < 1 || userChoose > ptrToCash->getCount()) {
                            throw userChoose;
                        }
                        searchByNum = 1;
                        errorCheck = 1;
                    }
                    catch (int e) {
                        std::cout << "Number: " << e << " is not in the list!.\n\n";
                    }
                }
                else {
                    std::cout << "Invalid input!\n\n";
                    repeat = true;
                }

                //checking if there are any books left in the database
                if (searchByNum == 1) {
                    if ((ptrToCash + (userChoose - 1))->getQuantity() == 0)
                    {
                        std::cout << "Sorry that book is out of stock!" << std::endl;//does work kinda
                        noStock = true;
                        repeat = true;
                    }

                    if (noStock != true) {

                        *(shoppingCart + shoppingCartCount) = ((ptr + (userChoose - 1)));
                        (shoppingCart + shoppingCartCount)->increaseQuant();
                        (ptr + (userChoose - 1))->setQuantity((ptr + (userChoose - 1))->getQuantity() - 1);
                        std::cout << "Added Book Title: " << (shoppingCart + (userChoose - 1))->getTitle() << " to your shopping cart.\nYou have " << (shoppingCartCount + 1) << " items in your cart\n" << std::endl;
                        shoppingCartCount++;

                        if ((ptr + (userChoose - 1))->getQuantity() == 0) {
                            for (int k = (userChoose - 1); k < ptr->getCount(); k++) {
                                *(ptr + k) = (ptr + k + 1);
                            }
                            ptr->setCount((ptr->getCount()) - 1);
                        }
                    }
                }

                if (errorCheck == 0) {
                    throw 1;
                }
            }
            catch (std::invalid_argument e) {

            }
        } while (repeat);

    }

  
    //Interface Screen of Cashier to screen
    std::string date = ptrr->getDate();
    
    std:: cout << "\n\nSerendipity Book Sellers \n" << std:: endl;
    std:: cout << "Date: " <<date<< std::endl << std::endl;
    std:: cout << "ISBN 13" << std::setw(14)
    << "Title" << std::setw(30) << "Price" << std::endl;
    std:: cout << "---------------------------------------------------------"<<std::endl;
    
    double total = 0;
    double taxTotal=0;
    double lastPrice=0;
    const double tax = 0.08;
    for(int i = 0; i < shoppingCartCount; i++)
    {
        std::cout << (shoppingCart + i)->getISBN() << " "
        <<(shoppingCart + i)->getTitle()<<" "<<(shoppingCart + i)->getRetail()<<std::endl;
        total += (shoppingCart + i)->getRetail();
        taxTotal+=(shoppingCart + i)->getRetail()*tax;
    }
    lastPrice = (taxTotal + total) + lastPrice;
    
    //formating cashier output
    if(taxTotal <10)
        std::cout<< "\nTotal Tax: $" <<std::setprecision (3)<< taxTotal <<std::endl;//test
    else
        std::cout<< "\nTotal Tax: $" <<std::setprecision (4)<< taxTotal <<std::endl;//test
        
    if(total <10)
        std::cout<< "\nTotal price: $" <<std::setprecision (3)<< total <<std::endl;//test
    else
        std::cout<< "\nTotal price: $" <<std::setprecision (4)<< total <<std::endl;//test
    
    if(lastPrice<10)
        std::cout<< "\nTotal Taxed Price: $" <<std::setprecision (3)<< lastPrice <<std::endl;//test
    else
        std::cout<< "\nTotal Taxed Price: $" <<std::setprecision (4)<< lastPrice <<std::endl;//test

    std::cout <<std::endl;
    std::cout << "\nThanks for purchasing the books!\n" << std::endl;
    std::cout << "---------------------------------------" << std::endl << std::endl;
    
}

//gets the current date you are accessing the cashier
std::string cashier::getDate()
{
    std::string date;
    time_t t = time(0);
    struct tm ts;
    char buff[20];
    ts = *localtime(&t);
    strftime(buff, sizeof(buff), "%m-%d-%y",&ts);
    date = buff;
    
    return date;
}
/*
void cashier::printInfo(Inventory *ptr) {
    std::cout << std::setw(18) << "Book Information" << std::endl;
    std::cout << "ISBN            : " << ptr->getISBN() << std::endl;
    std::cout << "Title           : " << ptr->getTitle() << std::endl;
    std::cout << "Author          : " << ptr->getAuthor() << std::endl;
    std::cout << "Publisher       : " << ptr->getPublisher() << std::endl;
    std::cout << "Date Added      : " << ptr->getDateAdded() << std::endl;
    std::cout << "Quantity-on-hand: " << ptr->getQuantity() << std::endl;
    std::cout << "Wholesale Cost  : " << ptr->getWholesale() << std::endl;
    std::cout << "Retail Price    : " << ptr->getRetail() << std::endl;

}
*/
void cashier::deallocatePtr() {
    delete[] ptrToCash;
}

/*
void cashier::lookUpBook(Inventory*ptr)
{
   
    for (int i = 0; i < ptr->getCount(); i++) {
        std::cout << (ptr + i);
    }
    
    
}
 */
