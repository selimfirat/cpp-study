#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <iostream>
#include "SortedDLL.h"

using namespace std;

class BankingSystem {

  public:
      BankingSystem();
      ~BankingSystem();

      void addCustomer( const int customerId, const string firstName, const string lastName );
      void deleteCustomer( const int customerId );

      int addAccount( const int customerId, const double amount );
      void deleteAccount( const int accountId );

      void showAllAccounts();
      void showAllCustomers();
      void showCustomer( const int customerId );

  private:
      SortedDLL *customers;
      int accountCursor;

};

#endif // PHONEBOOK_H
