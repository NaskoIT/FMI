#ifndef STACK_H
#define STACK_H

int const MAX = 100;

class Stack {
private:
    int arr[MAX];
    int top;

    bool full() const;

public:

    Stack();

    bool empty() const;

    int peek() const;

    void push(int);

    int pop();
};

#endif /* STACK_H_ */