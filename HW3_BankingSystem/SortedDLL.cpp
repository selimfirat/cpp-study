#include <iostream>
#include "SortedDLL.h"
#include<stdio.h>

using namespace std;

SortedDLL::SortedDLL(): size(0), head(NULL) {

}
SortedDLL::SortedDLL(const SortedDLL& list): size(list.size) {
  if (list.head == NULL) {
    head = NULL;
  } else {
    head = new SortedDLLNode;
    head->item = list.head->item;

    SortedDLLNode *newPtr = head;

    for (SortedDLLNode * org = list.head->next; org != NULL; org = org->next) {

      org->next = new SortedDLLNode;
      newPtr = newPtr->next;
      newPtr->item = org->item;

    }

    newPtr->next = NULL;
  }
}

SortedDLL::~SortedDLL() {
    while (!isEmpty())
        remove(1);
}

bool SortedDLL::removeByCustomerId(int customerId) {
    SortedDLLNode *cur = head;
    for (int i = 1; i <= size; i++) {
        if (cur->item->getId() == customerId)
            return remove(i);

        cur = cur->next;
    }

    return false;
}

Customer * SortedDLL::getCustomerById(int customerId) {
    SortedDLLNode *cur = head;

    for (int i = 1; i <= size; i++) {
        if (cur->item->getId() == customerId)
            return cur->item;

        cur = cur->next;
    }

    return NULL;
}



bool SortedDLL::remove(int index) {
  if ((index < 1) || (index > getSize())) {
    return false;
  }

  size--;

  SortedDLLNode * cur;
  if (index == 1) {
    cur = head;
    head = cur->next;
  } else {
    SortedDLLNode *prev = find(index-1);
    cur = prev->next;
    prev->next = cur->next;
  }

  cur->next = NULL;
  delete cur->item;
  delete cur;
  cur = NULL;

  return true;
}

bool SortedDLL::removeAccountById(const int accountId) {
  SortedDLLNode * cur = head;

  for (int i = 0; i < size; i++) {
        if (cur->item->deleteAccount(accountId))
            return true;

        cur = cur->next;
  }

  return false;
}

SortedDLL::SortedDLLNode *SortedDLL::find(int index) const {

  SortedDLLNode *cur = head;

  for (int i = 1; i < index; i++)
    cur = cur->next;

  return cur;
}

bool SortedDLL::isEmpty() const {
  return size == 0;
}

int SortedDLL::getSize() const {
  return size;
}

void SortedDLL::showAllAccounts() const {

    SortedDLLNode * cur = head;

    for(int i = 1; i < size; i++) {
        cur->item->showAllAccounts();
        cur = cur->next;
    }
}

void SortedDLL::showAllCustomers() const {
    SortedDLLNode * cur = head;

    for (int i = 1; i < size; i++) {
        string name = cur->item->getFirstName() + " " + cur->item->getLastName();
        printf("%-18d%-21s\n", cur->item->getId(), name.c_str());
        cur = cur->next;
    }
}

bool SortedDLL::insert(Customer *newItem) {

    SortedDLLNode *newNode = new SortedDLLNode;
    newNode->item = newItem;
    string newName = newItem->getFirstName() + " " + newItem->getLastName();

    if (isEmpty())
    {
      head = newNode;
      newNode->next = NULL;
      newNode->prev = NULL;
      size++;

      return true;
    }
    SortedDLLNode *cur = head;
    for (int i = 0; i < size; i++) {
        string name = cur->item->getFirstName() + " " + cur->item->getLastName();
        if (cur->item->getId() == newItem->getId()){
            cout << "Customer " << newItem->getId() << " already exists" << endl;
            delete newNode;
            delete newItem;
            return false;
        } else if (name == newName) {
            cout << "Customer " << newName << " already exists" << endl;

            delete newNode;
            delete newItem;

            return false;
        }

        cur = cur->next;
    }

    cur = head;
    for (int i = 0; i < size; i++) {
      string name = cur->item->getFirstName() + " " + cur->item->getLastName();

      if (name.compare(newName) > 0) {

        if (cur->prev == NULL) {
          newNode->next = cur;
          newNode->prev = cur;
          cur->prev = newNode;
          cur->next = newNode;
          head = newNode;
        } else {
          SortedDLLNode *prev = cur->prev;
          newNode->next = cur;
          newNode->prev = prev;
          prev->next = newNode;
        }
        size++;

        return true;
      }
      cur = cur->next;
    }

    cur = head->prev;

    if (cur == NULL) {
        head->prev = newNode;
        head->next = newNode;
        newNode->next = head;
        newNode->prev = head;
        head = newNode;
    } else {
        cur->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = cur;
    }
    size++;

    return true;
}
