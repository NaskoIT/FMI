#include "dynamicStack.h"

using namespace std;

Stack::Stack()
{
    size = INITIAL_SIZE;
    array = new int[size];
    top = -1;
}

void Stack::grow()
{
    int *newArray = new int[2 * size];
    for (int i = 0; i < size; i++)
        newArray[i] = array[i];
    delete[] array;
    array = newArray;
    size *= 2;
}

Stack::~Stack()
{
    delete[] array;
}

bool Stack::empty() const
{
    return top == -1;
}

int Stack::peek() const
{
    if (empty()) {
        // TODO: throw an exception
        return 0;
    }

    return array[top];
}

void Stack::push(int x) {
    if (full()) {
        grow();
    }

    array[++top] = x;
}

bool Stack::full() const {
    return top == size - 1;
}

int Stack::pop() {
    if (empty()) {
        // TODO: throw an exception
        return 0;
    }

    return array[top--];
}
