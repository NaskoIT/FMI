#pragma once
#ifndef INC_03_HOMEWORK_TEAMLEAD_HPP
#define INC_03_HOMEWORK_TEAMLEAD_HPP

#include <vector>
#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

using namespace std;

class Developer;

class TeamLead : public Developer {
private:
    vector<Developer *> team;
    vector<LeavingRequest> leavingRequests;
    vector<PromotionRequest> promotionRequests;

    bool isManagerOf(Developer *developer) const;

    int getDeveloperIndex(const string &name);

    bool tryRemoveDeveloper(const string& name);

public:
    TeamLead(const string &name, double salary);

    vector<Developer *> getTeam() const;

    void addDeveloperToTeam(Developer *developer, double salary);

    void removeDeveloperFromTeam(const string &name);

    void increaseTeamSalariesBy(double amount);

    void decreaseTeamSalariesBy(double amount);

    void addLeavingRequest(const LeavingRequest &leavingRequest);

    void addPromotionRequest(const PromotionRequest &promotionRequest);

    void fulfillLeavingRequests();

    void fulfillPromotionRequests();
};

#endif //INC_03_HOMEWORK_TEAMLEAD_HPP
