#include <iostream>
#include "product.h"

using namespace std;

int main() {
    char firstProductName[] = "BMW";
    char secondProductName[] = "Mercedes";
     Product bmw(firstProductName, 10000);
     Product mercedes(secondProductName, 12000);

     cout << mercedes.getName() << endl;
     cout << bmw.getName() << endl;

     mercedes = bmw;

     cout << mercedes.getName() << endl;
     cout << bmw.getName() << endl;
}