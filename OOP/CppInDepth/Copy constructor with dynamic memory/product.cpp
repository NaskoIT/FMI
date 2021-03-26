#include <cstring>
#include <iostream>
#include "product.h"

using namespace std;

Product::Product(char *name, double price) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->price = price;
}

Product::~Product() {
    cout << this->name << " will be deleted" << endl;
    delete this->name;
}

char *Product::getName() const {
    return this->name;
}

Product::Product(const Product &product) {
    cout << "the copy constructor was invoked" << endl;
   this->name = new char[strlen(product.name) + 1];
   strcpy(this->name, product.name);
   this->price = product.price;
}
