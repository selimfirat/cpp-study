#ifndef SORTEDDLL_H
#define SORTEDDLL_H

#include "Customer.h"

typedef Customer ListItemType;

class SortedDLL {

    public:
      SortedDLL();
      SortedDLL(const SortedDLL& copy );
      ~SortedDLL();
      bool isEmpty() const;
      int getSize() const;
      bool insert(Customer* item);
      bool remove( int index );
      bool removeByCustomerId( int customerId );
      Customer * getCustomerById( int customerId );
      bool removeAccountById( int accountId);
      void showAllAccounts() const;
      void showAllCustomers() const;

    private:
      struct SortedDLLNode {
        Customer * item;
        SortedDLLNode *next;
        SortedDLLNode *prev;
      };
      SortedDLLNode * find( int index ) const;
      int size;
      SortedDLLNode *head;

};

#endif
