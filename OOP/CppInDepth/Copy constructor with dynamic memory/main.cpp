#include <iostream>
#include "product.h"

using namespace std;

int main() {
    char name[] = "BMW";
    Product p(name, 10000);
    // copy and p will share the same dynamic memory which leads to errors
    // run the program and see the problem by yourself :)
    Product copy = p;
    cout << copy.getName() << endl;
}