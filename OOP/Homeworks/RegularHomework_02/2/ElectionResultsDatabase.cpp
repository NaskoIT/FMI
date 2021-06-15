#include <fstream>
#include "ElectionResultsDatabase.hpp"

using namespace std;

void ElectionResultsDatabase::addResultsFromFile(const char *filename) {
    ifstream database(filename);

    if (!database) {
        return;
    }

    while (!database.eof()) {
        SectionVotes votes;
        database >> votes;
        if (votes.isEmpty()) {
            database.close();
            return;
        }

        this->sections.push_back(votes);
    }

    database.close();
}

int ElectionResultsDatabase::numberOfSections() const {
    return sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const {
    int votesForParty = 0;
    for (const SectionVotes &section : sections) {
        votesForParty += section.votesForParty(party);
    }

    return votesForParty;
}

Party ElectionResultsDatabase::winningParty() const {
    int totalVotes[PARTIES_COUNT];
    for (int i = 0; i < PARTIES_COUNT; ++i) {
        totalVotes[i] = 0;
    }

    Party parties[PARTIES_COUNT] = {PARTY1, PARTY2, PARTY3};

    for (const SectionVotes &section : sections) {
        for (int j = 0; j < PARTIES_COUNT; ++j) {
            totalVotes[j] += section.votesForParty(parties[j]);
        }
    }

    int maxElementIndex = -1;
    int maxElement = -1;
    for (int i = 0; i < PARTIES_COUNT; ++i) {
        if (totalVotes[i] > maxElement) {
            maxElement = totalVotes[i];
            maxElementIndex = i;
        }
    }

    return (Party) maxElementIndex;
}

ostream &operator<<(ostream &os, ElectionResultsDatabase &election) {
    for (int i = 0; i < election.sections.size(); i++) {
        os << election.sections[i];
    }

    return os;
}

istream &operator>>(istream &is, ElectionResultsDatabase &election) {
    SectionVotes section;
    while (is >> section) {
        if (!section.isEmpty()) {
            election.sections.push_back(section);
        }
    }

    return is;
}
