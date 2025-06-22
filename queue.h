#ifndef QUEUE_H
#define QUEUE_H

#include "linked.h"

class Queue : private List {
public:
  void push(int value) {
    push_back(value);  // usa List::push_back
  }

  int pop() {
    return pop_front();  // usa List::pop_front
  }

  int size() const {
    return List::size();  // usa List::size
  }
};

#endif // QUEUE_H