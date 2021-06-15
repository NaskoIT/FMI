#include "SectionVotes.hpp"

SectionVotes::SectionVotes() {
    for (int i = 0; i < PARTIES_COUNT; ++i) {
        votes[i] = -1;
    }
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
    votes[0] = party1Votes;
    votes[1] = party2Votes;
    votes[2] = party3Votes;
}

int SectionVotes::votesForParty(Party party) const {
    int index = (int) party;
    return votes[index];
}

ostream &operator<<(ostream &os, SectionVotes &section) {
    for (int i = 0; i < PARTIES_COUNT; ++i) {
        os << section.votes[i] << " ";
    }

    os << "\n";

    return os;
}

std::istream &operator>>(istream &is, SectionVotes &section) {
    for (int i = 0; i < PARTIES_COUNT; ++i) {
        is >> section.votes[i];
    }

    return is;
}

bool SectionVotes::isEmpty() {
    for (int i = 0; i < PARTIES_COUNT; ++i) {
        if (votes[i] != -1) {
            return false;
        }
    }

    return true;
}