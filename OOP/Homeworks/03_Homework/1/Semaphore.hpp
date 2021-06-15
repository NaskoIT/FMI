#ifndef INC_03_HOMEWORK_SEMAPHORE_HPP
#define INC_03_HOMEWORK_SEMAPHORE_HPP

#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter {
public:
    Semaphore();

    Semaphore(int isAvailable);

    bool isAvailable() const;

    void wait();

    void signal();
};

#endif //INC_03_HOMEWORK_SEMAPHORE_HPP
