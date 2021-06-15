#ifndef INC_03_HOMEWORK_PROMOTIONREQUEST_HPP
#define INC_03_HOMEWORK_PROMOTIONREQUEST_HPP

#include "Request.hpp"

class PromotionRequest : public Request {
private:
    double amount;

public:
    PromotionRequest(const string &sender, double amount);

    double getAmount() const;
};

#endif //INC_03_HOMEWORK_PROMOTIONREQUEST_HPP
