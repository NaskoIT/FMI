#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
private:
    char* name;
    double price;
    void copy(const Product& product);

public:
    Product(char* name, double price);
    Product(const Product& product);
    ~Product();
    Product& operator=(const Product&);
    char* getName() const;
};

#endif
