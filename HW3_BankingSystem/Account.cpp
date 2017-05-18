#include <iostream>
#include "Account.h"

using namespace std;

Account::Account( const int accountId, const double amount ) {
  this->amount = amount;
  this->id = accountId;
}

Account::Account(Account &acc) {
    this->amount = acc.amount;
    this->id = acc.id;
}

Account::~Account() {
  this->amount = 0.0;
  this->id = 0;
}
Account::Account() {
  this->amount = 0.0;
  this->id = 0;
}

int Account::getId() {
  return id;
}

double Account::getAmount() {
  return amount;
}
