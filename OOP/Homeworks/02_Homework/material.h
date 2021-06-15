/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Atanas Vasilev
* @idnumber 62577
* @task 1
* @compiler GCC
*/

#ifndef INC_02_HOMEWORK_MATERIAL_H
#define INC_02_HOMEWORK_MATERIAL_H

#include "materialType.h"

const int ESSENCE_COUNT = 10;
const int DEFAULT_MATERIAL_COUNT = 20;

class Material {
private:
    MaterialType type;
    int quantity;
    int maxQuantity;

    void evaluateMaxQuantity();

public:
    Material();

    Material(MaterialType type);

    int getQuantity() const;

    int getMaxQuantity() const;

    bool isFull() const;

    void addQuantity(int quantity);

    void removeQuantity(int quantity);
};

#endif //INC_02_HOMEWORK_MATERIAL_H
