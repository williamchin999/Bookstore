#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Inventory.h"
#include "report.h"
#include "cashier.h"

//Main menu for every class
void mainMenu(Inventory *ptr)
{
	cashier *tempPtr = nullptr;
    int cond = 0;
    
   do
    {
    int input;
	std::string ISBN, title, userString;

    std:: cout << std::setw(15) << "Serendipity Booksellers" << std::endl;
    std:: cout << std::setw(15) << "Main Menu" <<  std::endl <<std::endl;
    std:: cout << std::setw(14)<< "1. Cashier Model" << std::endl;
    std:: cout << std::setw(14)<< "2. Inventory Database Model" << std::endl;
    std:: cout << std::setw(14)<< "3. Report Module" << std::endl;
    std:: cout << std::setw(1)<< "4. Exit" << std::endl << std:: endl;
    std:: cout << std::setw(13) << "Enter your choice: ";

	std::getline(std::cin, userString, '\n');
	try {
		
		input = stoi(userString);
		if (userString.length() > 1) {
			throw 1;
		}
		if (input < 0 || input > 4) {
			throw 2;
		}
		
	}
	catch (...) {
		input = 5;
	}

	ptr->duplicateChecker(ptr);

    switch (input)
        {
            //cashier screen
            case 1:
            {
                cashier::cashierMenu(ptr);
                break;
            }
            
            //inventory screen
            case 2:
            {
                Inventory::InventoryMenu(ptr);
                break;
            }
            //report screen
            case 3:
            {
                reportModule::reportMenu(ptr);
                break;
            }
            //exit
            case 4:
            { 
				ptr->deallocatePtr();
				tempPtr->deallocatePtr(); //Deallocate the dynamic array in Inventory and cashier
				cond = 4;
                break;
            }

			default:
			{
				std::cout << "Invalid input\n\n";
			}
        }
        
    }while(cond != 4);

	std::cout << "\nBye! Have a good day!";
    
}

