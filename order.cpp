#include "order.h"

order::order() {
  notifyObservers();
  tax = 0.0725;
  closed = false;
}

order::order(double tax) {
  notifyObservers();
  this->tax = tax;
  closed = false;
}

void order::addItem(item i) {
  if( !closed )
  {
    notifyObservers();
    itemList.push_back(i);
  }
}

std::vector<item> order::getItems() {
  return itemList;
}

double order::getSubtotal() {
  double subtotal = 0;
  for(int i = 0; i < itemList.size(); i++) {
    subtotal += itemList[i].getPrice();
  }
  return subtotal;
}

double order::getTax() {
  return tax;
}

double order::getTotal() {
  return getSubtotal() * (1 + tax);
}

double order::balance(double paid) {
  if(closed == false) {
    notifyObservers();
  }
  closed = true;
  return getTotal() - paid;
}