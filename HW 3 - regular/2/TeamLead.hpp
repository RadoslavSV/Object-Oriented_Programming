/// Radoslav Velkov, 1 group, FN 62528

#pragma once
#include <string>
#include <vector>
#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead: public Developer {
private:
    std::vector<Developer*> devs;
    std::vector<LeavingRequest> leavingRequests;
    std::vector<PromotionRequest> promotionRequests;
public:
    std::vector<Developer*> getTeam() const;
    void setTeam(std::vector<Developer*>);
    std::vector<LeavingRequest> getLeavingRequests() const;
    void setLeavingRequests(std::vector<LeavingRequest>);
    std::vector<PromotionRequest> getPromotionRequests() const;
    void setPromotionRequests(std::vector<PromotionRequest>);

    TeamLead(const std::string& name="", double salary=0);
    void addDeveloperToTeam(Developer* developer, double salary);
    void removeDeveloperFromTeam(const std::string& name);
    void increaseTeamSalariesBy(double amount);
    void decreaseTeamSalariesBy(double amount);
    void addLeavingRequest(const LeavingRequest& leavingRequest);
    void addPromotionRequest(const PromotionRequest& promotionRequest);
    void fulfillLeavingRequests();
    void fulfillPromotionRequests();
};




