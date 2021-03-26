#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
private:
    char* name;
    double price;

public:
    Product(char* name, double price);
    Product(const Product& product);
    ~Product();
    char* getName() const;
};

#endif
