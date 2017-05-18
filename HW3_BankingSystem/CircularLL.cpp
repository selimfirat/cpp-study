#include "CircularLL.h"
#include <iostream>
#include <stdio.h>

using namespace std;

CircularLL::CircularLL(): length(0), head(NULL) {

}

CircularLL::CircularLL(const CircularLL& cpy): length(cpy.length) {
  if (cpy.head == NULL) {
    head = NULL;
  } else {
    head = new CircularLLNode;
    head->item = cpy.head->item;

    CircularLLNode *newPtr = head;

    for (CircularLLNode* org = cpy.head->next; org != NULL; org = org->next) {

      org->next = new CircularLLNode;
      newPtr = newPtr->next;
      newPtr->item = org->item;

    }
    newPtr->next = head;
  }
}

bool CircularLL::retrieve(int index, Account & retriever) const {
  if (index < 1 || index > getLength()) {
    return false;
  }

  CircularLLNode *cur = find(index);
  retriever = *(cur->item);

  return true;
}

bool CircularLL::remove(int index) {
  if ((index < 1) || (index > getLength())) {
    return false;
  }

  CircularLLNode *cur;
  length--;

  if (index == 1) {
    cur = head;
    head = cur->next;
  } else {
    CircularLLNode *prev = find(index-1);
    cur = prev->next;
    prev->next = cur->next;
  }

  cur->next = NULL;
  delete cur->item;
  delete cur;
  cur = NULL;

  return true;
}


CircularLL::CircularLLNode * CircularLL::find(int index) const {

  CircularLLNode *cur = head;

  for (int i = 1; i < index; i++)
    cur = cur->next;

  return cur;
}

CircularLL::~CircularLL() {
  while (!isEmpty()) {
    remove(1);
  }
}

bool CircularLL::isEmpty() const {
  return length == 0;
}

int CircularLL::getLength() const {
  return length;
}

bool CircularLL::insert(Account *newItem) {

    CircularLLNode *newNode = new CircularLLNode;
    newNode->item = newItem;


    if (isEmpty()) {
        head = newNode;
        newNode->next = NULL;
    } else {
        CircularLLNode *last = find(length);
        last->next = newNode;
        newNode->next = head;
    }

    length++;
    return true;
}

bool CircularLL::removeAccountById(const int accountId) {
    CircularLLNode *cur = head;
    for (int i = 1; i <= length; i++) {
        if (cur->item->getId() == accountId) {
            remove(i);
            return true;
        }

        cur = cur->next;
    }
    return false;
}

void CircularLL::showAll() {
    CircularLLNode *cur = head;
    for (int i = 1; i <= length; i++) {
        printf("%-18d%.2f\n", cur->item->getId(), cur->item->getAmount());
        cur = cur->next;
    }

}

void CircularLL::showAllDetailed(int customerId, string customerName) {
    CircularLLNode *cur = head;
    for (int i = 1; i <= length; i++) {
        printf("%-12d%-18d%-21s%.2f\n", cur->item->getId(), customerId, customerName.c_str(), cur->item->getAmount());
        cur = cur->next;
    }

}
