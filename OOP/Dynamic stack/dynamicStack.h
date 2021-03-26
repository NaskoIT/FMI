#ifndef STACK_H
#define STACK_H

int const INITIAL_SIZE = 16;

class Stack {
private:
    int *array;
    int top;
    int size;

    bool full() const;

    void grow();

public:
    Stack();

    ~Stack();

    bool empty() const;

    int peek() const;

    void push(int);

    int pop();
};

#endif