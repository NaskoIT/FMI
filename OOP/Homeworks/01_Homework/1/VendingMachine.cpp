#include <cstring>
#include "VendingMachine.hpp"

VendingMachine::VendingMachine() {
    drinks = new Drink[INITIAL_CAPACITY];
    count = 0;
    capacity = INITIAL_CAPACITY;
    income = 0;
}

VendingMachine::VendingMachine(const VendingMachine &from) {
    copy(from);
}

VendingMachine &VendingMachine::operator=(const VendingMachine &from) {
    copy(from);
    return *this;
}

double VendingMachine::get_income() const {
    return income;
}

int VendingMachine::get_drinks_count() const {
    return count;
}

bool VendingMachine::add_drink(const Drink &to_add) {
    if (indexOfDrink(to_add.get_name()) > -1) {
        return false;
    }

    if (count == capacity) {
        grow();
    }

    drinks[count++] = to_add;
    return true;
}

int VendingMachine::buy_drink(const char *drink_name, const double money) {
    int index = indexOfDrink(drink_name);

    if (index == -1) {
        return 2;
    }

    Drink drink = drinks[index];
    income += money;

    if (drink.get_price() > money) {
        return 1;
    }

    for (int i = index; i < count; ++i) {
        drinks[i] = drinks[i + 1];
    }

    count--;

    return 0;
}

void VendingMachine::copy(const VendingMachine &from) {
    if (drinks != nullptr) {
        delete[] drinks;
    }

    capacity = from.capacity;
    drinks = new Drink[from.capacity];

    for (int i = 0; i < from.count; ++i) {
        drinks[i] = Drink(from.drinks[i]);
    }

    count = from.count;
    income = from.income;
}

int VendingMachine::indexOfDrink(const char *drink_name) const {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (strcmp(drinks[i].get_name(), drink_name) == 0) {
            index = i;
            break;
        }
    }

    return index;
}

void VendingMachine::grow() {
    capacity *= 2;
    Drink *newDrinks = new Drink[capacity];

    for (int i = 0; i < count; ++i) {
        newDrinks[i] = Drink(drinks[i]);
    }

    delete[] this->drinks;
    this->drinks = newDrinks;
}

VendingMachine::~VendingMachine() {
    if(drinks != nullptr) {
        delete[] drinks;
    }
}

