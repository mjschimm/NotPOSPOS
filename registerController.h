#ifndef _REGISTERCONTROLLER_H_
#define _REGISTERCONTROLLER_H_
#include "cashierView.h"
#include "StoreInventory.h"
#include "order.h"

class registerController : public IObserver
{
private:
  void update();
  StoreInventory *database;
  order *cart;
  cashierView screen;
public:
  registerController(StoreInventory *, order *);
  void processOrder();
};

#endif