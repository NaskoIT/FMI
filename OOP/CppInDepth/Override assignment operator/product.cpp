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
    copy(product);
}

Product &Product::operator=(const Product & product) {
    cout << "the = operator was invoked" << endl;
    if(this != &product) {
        delete this->name;
        copy(product);
    }

    return *this;
}

void Product::copy(const Product &product) {
    this->name = new char[strlen(product.name) + 1];
    strcpy(this->name, product.name);
    this->price = product.price;
}
