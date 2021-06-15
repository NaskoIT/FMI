#include "drink.hpp"

const int INITIAL_CAPACITY = 16;

class VendingMachine {
public:
    VendingMachine();

    VendingMachine(const VendingMachine &from);

    VendingMachine &operator=(const VendingMachine &from);

    ~VendingMachine();

    bool add_drink(const Drink &to_add);

    int buy_drink(const char *drink_name, const double money);

    double get_income() const;

    int get_drinks_count() const;

private:
    Drink *drinks;
    int count;
    int capacity;
    double income;

    void copy(const VendingMachine &from);

    void grow();

    int indexOfDrink(const char *drink_name) const;
};
