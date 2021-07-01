/// Radoslav Velkov, 1 group, FN 62528

#pragma once
#include <string>
class TeamLead;  //forward declaration

class Developer{
private:
    std::string name = "";
    double salary = 0;
    TeamLead* teamleader = nullptr;
public:
    std::string getName() const;
    void setName(const std::string&);
    double getSalary() const;
    void setSalary(double);
    TeamLead* getTeamLead() const;
    void setTeamLead(TeamLead*);
    Developer();
    Developer(const std::string& name);
    void setInitialSalary(double amount);
    void sendLeavingRequest();
    void sendPromotionRequest(double amount);
};
