#pragma once

#ifndef INC_03_HOMEWORK_DEVELOPER_HPP
#define INC_03_HOMEWORK_DEVELOPER_HPP

#include <string>
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead;

using namespace std;

class Developer {
protected:
    string name;
    double salary;
    TeamLead *teamLead;

public:
    Developer(const string &name);

    string getName() const;

    double getSalary() const;

    TeamLead *getTeamLead() const;

    void setInitialSalary(double amount);

    void sendLeavingRequest() const;

    void sendPromotionRequest(double amount) const;

    void setTeamLead(TeamLead *newTeamLead);

    void setSalary(double amount);

    void increaseSalary(double amount);

    void decreaseSalary(double amount);
};

#endif //INC_03_HOMEWORK_DEVELOPER_HPP
