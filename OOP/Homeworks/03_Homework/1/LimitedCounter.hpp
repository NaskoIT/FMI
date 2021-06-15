#ifndef INC_03_HOMEWORK_LIMITEDCOUNTER_HPP
#define INC_03_HOMEWORK_LIMITEDCOUNTER_HPP

#include "Counter.hpp"

class LimitedCounter : public virtual Counter {
private:
    int maxValue;

public:
    LimitedCounter(int max);

    LimitedCounter(int max, int initial);

    LimitedCounter(int max, int initial, unsigned int step);

    void increment() override;

    int getMax() const;
};

#endif //INC_03_HOMEWORK_LIMITEDCOUNTER_HPP
