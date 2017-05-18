#include <iostream>
#include "BankingSystem.h"
#include "Customer.h"
#include <stdio.h>

using namespace std;


BankingSystem::BankingSystem() {
    customers = new SortedDLL;
    accountCursor = 1;
}

BankingSystem::~BankingSystem() {
  delete customers;
}

void BankingSystem::addCustomer( const int customerId, const string firstName, const string lastName ) {
  Customer * customer = new Customer(customerId, firstName, lastName);

  if( customers->insert(customer))
    cout << "Customer " << customerId << " has been added" << endl;

}

void BankingSystem::deleteCustomer( const int customerId ) {

  if (customers->removeByCustomerId(customerId))
    cout << "Customer " << customerId << " has been deleted" << endl;
  else
    cout << "Customer " << customerId << " does not exist" << endl;

}

int BankingSystem::addAccount( const int customerId, const double amount ) {

  Customer *cur = customers->getCustomerById(customerId);
  if (cur == NULL) {
    cout << "Customer " << customerId << " does not exist" << endl;
    return -1;
  }
  cout << "Account " << accountCursor << " added for customer " << customerId << endl;
  return cur->addAccount(accountCursor++, amount);
}

void BankingSystem::deleteAccount( const int accountId ) {

    if (customers->removeAccountById(accountId))
        cout << "Account " << accountId << " has been deleted" << endl;
    else
        cout << "Account " << accountId << " does not exist" << endl;

}


void BankingSystem::showAllAccounts() {
    cout << endl;
    printf("%-12s%-18s%-21s%-8s\n","Account id", "Customer id", "Customer name", "Balance");
    customers->showAllAccounts();
}

void BankingSystem::showAllCustomers() {
    cout << endl;
    printf("%-18s%-21s\n", "Customer id", "Customer Name");
    customers->showAllCustomers();
}

void BankingSystem::showCustomer( const int customerId ) {
    Customer * customer = customers->getCustomerById(customerId);
    if (customer != NULL)
        customer->showDetails();
    else
        cout << "Customer " << customerId << " does not exist";
    cout << endl;
}
