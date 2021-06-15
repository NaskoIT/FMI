#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest(const string &sender, double amount) : Request("I want a raise!", sender) {
    this->amount = amount;
}

double PromotionRequest::getAmount() const {
    return amount;
}

