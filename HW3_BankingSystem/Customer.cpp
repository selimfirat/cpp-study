#include <iostream>
#include "Customer.h"
#include "CircularLL.h"
#include <stdio.h>

using namespace std;

Customer::Customer( const int customerId, const string firstName, const string lastName ) {
  this->customerId = customerId;
  this->firstName = firstName;
  this->lastName = lastName;
  this->accounts = new CircularLL;
}

Customer::~Customer() {
  this->customerId = 0;
  this->firstName = "";
  this->lastName = "";
  delete accounts;
}

int Customer::addAccount(const int accountId, const double amount) {
  Account * account = new Account(accountId, amount);
  accounts->insert(account);
  return accountId;
}

bool Customer::deleteAccount( const int accountId) {

  return accounts->removeAccountById(accountId);
}

string Customer::getFirstName() {
  return this->firstName;
}

string Customer::getLastName() {
  return this->lastName;
}

int Customer::getId() {
  return this->customerId;
}

void Customer::showAllAccounts() const {

    string name = firstName + " " + lastName;
    accounts->showAllDetailed(customerId, name);
}

void Customer::showDetails() const {

    cout << endl << "Customer id: " << customerId << "\t" << "Customer Name: " << firstName << " " << lastName << "\t" << "Number of accounts: " << accounts->getLength();
    if (accounts->getLength() > 0) {
        cout << endl << "Accounts of this customer:" << endl;
        printf("%-18s%-16s\n", "Account id", "Balance");

        accounts->showAll();
    }
}
