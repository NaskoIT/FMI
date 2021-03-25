#include "stack.h"

using namespace std;

Stack::Stack() {
    top = -1;
}

bool Stack::empty() const {
    return top == -1;
}

int Stack::peek() const {
    if (empty()) {
        // TODO: throw an exception
        return 0;
    }

    return arr[top];
}

void Stack::push(int x) {
    if (full()) {
        // TODO: throw an exception with descriptive error message
    } else {
        arr[++top] = x;
    }
}

bool Stack::full() const {
    return top == MAX - 1;
}

int Stack::pop() {
    if (empty()) {
        // TODO: throw an exception with descriptive error message
        return 0;
    }

    return arr[top--];
}
