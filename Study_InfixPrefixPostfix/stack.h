#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack {
private:
  struct StackNode {
    char item;
    StackNode *next;
  };
  StackNode *topPtr;

public:
  Stack ();
  Stack(Stack &stack);
  virtual ~Stack ();
  bool push(char ch);
  bool pop();
  bool pop(char &ch);
  bool push(char &ch);
  bool isEmpty();
  bool getTop(char &ch);

};

#endif
