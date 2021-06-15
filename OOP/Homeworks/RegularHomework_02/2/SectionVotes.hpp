#pragma once

#include <iostream>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

using namespace std;

enum Party {
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

const int PARTIES_COUNT = 3;

class SectionVotes {
private:
    int votes[PARTIES_COUNT];

public:
    SectionVotes();

    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    bool isEmpty();

    friend ostream &operator<<(ostream &os, SectionVotes &section);

    friend istream &operator>>(istream &is, SectionVotes &section);
};


