#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const string &name) : salary(0), teamLead(nullptr) {
    this->name = name;
}

string Developer::getName() const {
    return name;
}

double Developer::getSalary() const {
    return salary;
}

TeamLead *Developer::getTeamLead() const {
    return teamLead;
}

void Developer::setInitialSalary(double amount) {
    if (salary != 0) {
        return;
    }

    salary = amount;
}

void Developer::sendLeavingRequest() const {
    if (teamLead == nullptr) {
        return;
    }

    LeavingRequest leavingRequest(this->getName());
    teamLead->addLeavingRequest(leavingRequest);
}

void Developer::sendPromotionRequest(double amount) const {
    if (teamLead == nullptr) {
        return;
    }

    PromotionRequest promotionRequest(this->getName(), amount);
    teamLead->addPromotionRequest(promotionRequest);
}

void Developer::setTeamLead(TeamLead *newTeamLead) {
    this->teamLead = newTeamLead;
}

void Developer::setSalary(double amount) {
    this->salary = amount;
}

void Developer::increaseSalary(double amount) {
    salary += amount;
}

void Developer::decreaseSalary(double amount) {
    // TODO: check if the salary becomes negative number

    salary -= amount;
}
