#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "CircularLL.h"

using namespace std;

class Customer {

  public:
    Customer( const int customerId, const string firstName, const string lastName );
    ~Customer();
    int addAccount( const int accountId, const double amount );
    bool deleteAccount( const int accountId );
    int getId();
    string getFirstName();
    string getLastName();
    void showAllAccounts() const;
    void showDetails() const;

  private:
    int customerId;
    int accountCursor;
    string firstName;
    string lastName;
    CircularLL * accounts;


};
#endif // CUSTOMER_H
