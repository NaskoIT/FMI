#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include <vector>
#include "SectionVotes.hpp"

using namespace std;

class ElectionResultsDatabase {
private:
    vector<SectionVotes> sections;

public:

    void addResultsFromFile(const char *filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;

    friend ostream &operator<<(ostream &os, ElectionResultsDatabase &database);

    friend istream &operator>>(istream &is, ElectionResultsDatabase &database);
};
