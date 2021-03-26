#include <stdexcept>

using namespace std;

#ifndef STACK_H
#define STACK_H

template<typename T>
class LinkedStack {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *top;

public:
    LinkedStack() {
        top = nullptr;
    }

    ~LinkedStack<T>() {
        Node *toDelete;
        while (top != nullptr) {
            toDelete = top;
            top = top->next;
            delete toDelete;
        }
    }

    bool empty() const {
        return top == nullptr;
    }

    T peek() const {
        if (empty()) {
            throw logic_error("The stack is empty.");
        }

        return top->data;
    }

    void push(T element) {
        Node *p = new Node;
        p->data = element;
        p->next = top;
        top = p;
    }

    T pop() {
        if (empty()) {
            throw logic_error("The stack is empty.");
        }

        Node *tempTop = top;
        top = top->next;
        T x = tempTop->data;
        delete tempTop;
        return x;
    }
};

#endif