#ifndef CIRCULARLL_H
#define CIRCULARLL_H

#include<iostream>
#include "Account.h"

using namespace std;

class CircularLL {

  public:
    CircularLL();
    CircularLL( const CircularLL& cpy );
    ~CircularLL();
    bool isEmpty() const;
    int getLength() const;
    bool insert( Account *item);
    bool remove(int index);
    bool removeAccountById(int accountId);
    bool retrieve(int index, Account & retriever) const;
    void showAll();
    void showAllDetailed(int customerId, string customerName);

  private:
    struct CircularLLNode {
      Account * item;
      CircularLLNode * next;
    };
    int length;
    CircularLLNode *head;
    CircularLLNode *tail;
    CircularLLNode *find( int index ) const;


};

#endif
