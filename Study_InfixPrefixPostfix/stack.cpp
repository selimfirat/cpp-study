#include "stack.h"

Stack::Stack():topPtr(NULL) {
}

Stack::Stack(Stack &stack) {
  if (stack.isEmpty())
    topPtr = NULL;
  else {
    topPtr = new StackNode;
    topPtr->item = stack.topPtr->item;

    StackNode *tmp = topPtr;
    for (StackNode *ptr = stack.topPtr->next; ptr != NULL; ptr = ptr->next) {
      tmp->next = new StackNode;
      tmp->next->item = ptr->item;
      tmp = tmp->next;
    }
    tmp->next = NULL;
  }
}

Stack::~Stack() {
  while (!isEmpty())
    pop();
}

bool Stack::isEmpty() {
  return topPtr == NULL;
}

bool Stack::push(char ch) {
  StackNode *newNode = new StackNode;
  newNode->item = ch;
  newNode->next = topPtr;
  topPtr = newNode;

  return true;
}

bool Stack::pop() {
  if (isEmpty()) {
    return false;
  }
  StackNode *tmp = topPtr;
  topPtr = topPtr->next;

  tmp->next = NULL;
  delete tmp;
  return true;
}

bool Stack::pop(char &ch) {
  if (isEmpty()) {
    return false;
  }

  ch = topPtr->item;
  StackNode *tmp = topPtr;
  topPtr = topPtr->next;

  tmp->next = NULL;
  delete tmp;
  return true;
}

bool Stack::getTop(char &ch) {
  if (isEmpty()) {
    return false;
  }

  ch = topPtr->item;

  return true;
}
