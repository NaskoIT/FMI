
#include "TeamLead.hpp"

const int NOT_FOUND_INDEX = -1;

TeamLead::TeamLead(const string &name, double salary) : Developer(name) {
    this->salary = salary;
    this->teamLead = this;
}

vector<Developer *> TeamLead::getTeam() const {
    return team;
}

void TeamLead::addDeveloperToTeam(Developer *developer, double salary) {
    if (developer == nullptr) {
        return;
    }

    developer->setInitialSalary(salary);

    if (!isManagerOf(developer)) {
        team.push_back(developer);
    }

    developer->setTeamLead(this);
}

bool TeamLead::isManagerOf(Developer *developer) const {
    for (Developer *currentDeveloper : team) {
        if (currentDeveloper == developer) {
            return true;
        }
    }

    return false;
}

void TeamLead::removeDeveloperFromTeam(const string &name) {
    tryRemoveDeveloper(name);
}

void TeamLead::increaseTeamSalariesBy(double amount) {
    for (Developer *developer : team) {
        developer->increaseSalary(amount);
    }
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
    for (Developer *developer : team) {
        developer->decreaseSalary(amount);
    }
}

void TeamLead::addLeavingRequest(const LeavingRequest &leavingRequest) {
    leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest &promotionRequest) {
    promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
    for (int i = 0; i < leavingRequests.size(); ++i) {
        bool isDeveloperRemoved = tryRemoveDeveloper(leavingRequests[i].getSender());
        if(isDeveloperRemoved) {
            leavingRequests.erase(leavingRequests.begin() + i);
            i--;
        }
    }
}

void TeamLead::fulfillPromotionRequests() {
    for (int i = 0; i < promotionRequests.size(); ++i) {
        PromotionRequest promotionRequest = promotionRequests[i];
        int developerIndex = getDeveloperIndex(promotionRequest.getSender());
        if (developerIndex == NOT_FOUND_INDEX) {
            continue;
        }

        Developer *developer = team[developerIndex];
        developer->increaseSalary(promotionRequest.getAmount());

        promotionRequests.erase(promotionRequests.begin() + i);
        i--;
    }
}

bool TeamLead::tryRemoveDeveloper(const string& name) {
    int developerIndex = getDeveloperIndex(name);
    if (developerIndex == NOT_FOUND_INDEX) {
        return false;
    }

    team[developerIndex]->setTeamLead(nullptr);
    team.erase(team.begin() + developerIndex);

    return true;
}

int TeamLead::getDeveloperIndex(const string &name) {
    for (int i = team.size() - 1; i >= 0; i--) {
        if (team[i]->getName() == name) {
            return i;
        }
    }

    return NOT_FOUND_INDEX;
}

