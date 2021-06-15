#pragma once

class Comparable {
public:
    Comparable() = default;

    virtual ~Comparable() = default;

    virtual bool operator==(const Comparable *comparable) const = 0;

    virtual bool operator!=(const Comparable *comparable) const = 0;
};