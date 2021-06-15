#include <cstring>
#include "drink.hpp"

Drink::Drink(const char *init_name, const int init_calories, const double &init_quantity, const double &init_price) {
    setFields(init_name, init_calories, init_quantity, init_price);
}

Drink::Drink(const Drink &drink) {
    setFields(drink.name, drink.calories, drink.quantity, drink.price);
}

Drink &Drink::operator=(const Drink &drink) {
    if (this != &drink) {
        delete[] name;
        setFields(drink.name, drink.calories, drink.quantity, drink.price);
    }

    return *this;
}

void Drink::setFields(const char *init_name, const int init_calories, const double &init_quantity,
                      const double &init_price) {
    set_name(init_name);
    calories = init_calories;
    quantity = init_quantity;
    price = init_price;
}

const char *Drink::get_name() const {
    return name;
}

int Drink::get_calories() const {
    return calories;
}

double Drink::get_quantity() const {
    return quantity;
}

double Drink::get_price() const {
    return price;
}

void Drink::set_name(const char *new_name) {
    if (name != nullptr) {
        delete[] name;
    }

    if (new_name == nullptr) {
        name = nullptr;
    } else {
        name = new char[strlen(new_name) + 1];
        strcpy(name, new_name);
    }
}

Drink::Drink() {
    name = nullptr;
    calories = 0;
    quantity = 0;
    price = 0;
}

Drink::~Drink() {
    if (name != nullptr) {
        delete[] name;
    }
}

