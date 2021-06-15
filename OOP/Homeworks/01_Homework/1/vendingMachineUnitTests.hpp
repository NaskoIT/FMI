#include <assert.h>
#include "VendingMachine.hpp"
#include <iostream>

using namespace std;

void assertConstructorWithoutParametersIsWorking();

void assertAddMethodIsWorking();

void assertVendingMachineAddWithMultipleInvocationsIsWorking();

void assertWhenAddingTheSameDrinkTwiceShouldAddTheDrinkOnlyOnce();

VendingMachine createVendingMachine();

void assertBuyDrinkWhenTheDrinkDoNotExistsDoNothing();

void assertBuyDrinkWithoutEnoughMoneyIsWorking();

void assertBuyDrinkWithValidStateIsWorking();

void assertCopyConstructorIsWorking();

void runVendingMachineUnitTests() {
    cout << "Start executing vending machine unit tests!" << endl;

    assertConstructorWithoutParametersIsWorking();

    assertAddMethodIsWorking();

    assertVendingMachineAddWithMultipleInvocationsIsWorking();

    assertWhenAddingTheSameDrinkTwiceShouldAddTheDrinkOnlyOnce();

    assertBuyDrinkWhenTheDrinkDoNotExistsDoNothing();

    assertBuyDrinkWithoutEnoughMoneyIsWorking();

    assertBuyDrinkWithValidStateIsWorking();

    assertCopyConstructorIsWorking();

    cout << "Finish executing vending machine unit tests!" << endl;
}

void assertCopyConstructorIsWorking() {
    VendingMachine vendingMachine = createVendingMachine();
    VendingMachine copy = VendingMachine(vendingMachine);
    assert(copy.get_drinks_count() == vendingMachine.get_drinks_count());
    assert(copy.get_income() == vendingMachine.get_income());

    int result = copy.add_drink(Drink("1_drink", 15, 25, 5));
    assert(result == false);
}

void assertBuyDrinkWithValidStateIsWorking() {
    VendingMachine vendingMachine = createVendingMachine();
    int count = vendingMachine.get_drinks_count();
    assert(vendingMachine.buy_drink("1_drink", 7) == 0);
    assert(vendingMachine.get_drinks_count() == count - 1);
    assert(vendingMachine.get_income() == 7);
    assert(vendingMachine.buy_drink("1_drink", 7) == 2);
}

void assertBuyDrinkWithoutEnoughMoneyIsWorking() {
    VendingMachine vendingMachine = createVendingMachine();
    int count = vendingMachine.get_drinks_count();
    assert(vendingMachine.buy_drink("1_drink", 3) == 1);
    assert(vendingMachine.get_drinks_count() == count);
    assert(vendingMachine.get_income() == 3);
}

void assertBuyDrinkWhenTheDrinkDoNotExistsDoNothing() {
    VendingMachine vendingMachine = createVendingMachine();
    int count = vendingMachine.get_drinks_count();
    assert(vendingMachine.buy_drink("A_drink", 50) == 2);
    assert(vendingMachine.get_drinks_count() == count);
    assert(vendingMachine.get_income() == 0);
}

VendingMachine createVendingMachine() {
    VendingMachine vendingMachine = VendingMachine();

    for (int i = 0; i < 10; ++i) {
        char name[] = "x_drink";
        name[0] = char(i + '0');
        vendingMachine.add_drink(Drink(name, 15, 25, 5));
    }

    return vendingMachine;
}

void assertWhenAddingTheSameDrinkTwiceShouldAddTheDrinkOnlyOnce() {
    VendingMachine vendingMachine = VendingMachine();
    Drink drink = Drink("drink1", 15, 25, 35);
    assert(vendingMachine.add_drink(drink) == true);
    assert(vendingMachine.add_drink(drink) == false);

    assert(vendingMachine.get_drinks_count() == 1);
}

void assertVendingMachineAddWithMultipleInvocationsIsWorking() {
    VendingMachine vendingMachine;

    for (int i = 0; i < 20; ++i) {
        char name[] = "x_drink";
        name[0] = (char) (i + '0');
        assert(vendingMachine.add_drink(Drink(name, 15, 25, 35)) == true);
    }

    assert(vendingMachine.get_drinks_count() == 20);
}

void assertAddMethodIsWorking() {
    VendingMachine vendingMachine = VendingMachine();
    assert(vendingMachine.add_drink(Drink("drink1", 15, 25, 35)) == true);

    assert(vendingMachine.get_drinks_count() == 1);
}

void assertConstructorWithoutParametersIsWorking() {
    VendingMachine vendingMachine = VendingMachine();
    assert(vendingMachine.get_income() == 0);
    assert(vendingMachine.get_drinks_count() == 0);
}
