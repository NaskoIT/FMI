#ifndef INC_03_HOMEWORK_TWOWAYCOUNTER_HPP
#define INC_03_HOMEWORK_TWOWAYCOUNTER_HPP

#include "Counter.hpp"

class TwowayCounter : public virtual Counter {
public:
    TwowayCounter();

    TwowayCounter(int initial);

    TwowayCounter(int initial, unsigned int step);

    virtual void decrement();
};

#endif //INC_03_HOMEWORK_TWOWAYCOUNTER_HPP
