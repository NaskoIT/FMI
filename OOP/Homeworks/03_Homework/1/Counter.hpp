#ifndef INC_03_HOMEWORK_COUNTER_HPP
#define INC_03_HOMEWORK_COUNTER_HPP

class Counter {
protected:
    unsigned int step;
    int value;

public:
    Counter();

    Counter(int initial);

    Counter(int initial, unsigned int step);

    virtual void increment();

    int getTotal() const;

    unsigned int getStep() const;
};

#endif //INC_03_HOMEWORK_COUNTER_HPP
