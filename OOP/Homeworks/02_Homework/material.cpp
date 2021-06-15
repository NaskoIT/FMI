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

#include "material.h"

Material::Material() {
    this->quantity = 0;
    this->type = MaterialType::essence;
    this->evaluateMaxQuantity();
}

Material::Material(MaterialType type) {
    this->type = type;
    this->quantity = 0;
    this->evaluateMaxQuantity();
}

int Material::getQuantity() const {
    return quantity;
}

int Material::getMaxQuantity() const {
    return this->maxQuantity;
}

bool Material::isFull() const {
    return this->quantity >= this->maxQuantity;
}

void Material::addQuantity(int quantityToAdd) {
    if (this->quantity + quantityToAdd > this->maxQuantity) {
        this->quantity = this->maxQuantity;
    } else {
        this->quantity += quantityToAdd;
    }
}

void Material::removeQuantity(int quantityToRemove) {
    if (this->quantity - quantityToRemove < 0) {
        this->quantity = 0;
    } else {
        this->quantity -= quantityToRemove;
    }
}

void Material::evaluateMaxQuantity() {
    if (type == MaterialType::essence) {
        this->maxQuantity = ESSENCE_COUNT;
    } else {
        this->maxQuantity = DEFAULT_MATERIAL_COUNT;
    }
}