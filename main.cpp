#include <iostream>
#include <iomanip>
#include <string>
#include "order.h"
#include "item.h"
#include "StoreInventory.h"
#include "cashierView.h"
#include "registerController.h"
#include "keypadController.h"
#include "ObserverPattern.cpp"

const char DB_FILE[] = "fruit.db";

int main()
{
  StoreInventory *inventory  = new StoreInventory(DB_FILE);
  std::cout<<"======================\n"
           <<"NotPOSPOS  Version 0.1\n"
           <<"======================\n";

  order *current = new order;
  
  keypadController* keypad = new keypadController(current);
  current->addObserver(keypad);
  
  registerController* ticket = new registerController(inventory, current);
  current->addObserver(ticket);
  
  ticket->processOrder();

  return 0;
}