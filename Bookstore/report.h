#pragma once
#include <iomanip>
#include "Inventory.h"
#include <string>
class reportModule : public Inventory
{

public:
    
    void static reportMenu(Inventory *invPtr);
    
    void listByInfo(Inventory*);
    void wholeSaleList(Inventory*);
    void retailList(Inventory*);
    void listByCost(Inventory*);
    void listByAge(Inventory*);
    void listByQuantity(Inventory*);

};
