#ifndef INC_03_HOMEWORK_LIMITEDTWOWAYCOUNTER_HPP
#define INC_03_HOMEWORK_LIMITEDTWOWAYCOUNTER_HPP

#include "TwowayCounter.hpp"
#include "LimitedCounter.hpp"

class LimitedTwowayCounter : public TwowayCounter, public LimitedCounter {
private:
    int minValue;

public:
    LimitedTwowayCounter(int min, int max);

    LimitedTwowayCounter(int min, int max, int initial);

    LimitedTwowayCounter(int min, int max, int initial, unsigned int step);

    void decrement() override;

    int getMin() const;
};

#endif //INC_03_HOMEWORK_LIMITEDTWOWAYCOUNTER_HPP
