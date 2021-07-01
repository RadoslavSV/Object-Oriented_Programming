/// Radoslav Velkov, 1 group, FN 62528

#include "TeamLead.hpp"
#include <cstring>

std::vector<Developer*> TeamLead::getTeam() const
{
    return this->devs;
}

void TeamLead::setTeam(std::vector<Developer*> devs)
{
    this->devs = devs;
}

std::vector<LeavingRequest> TeamLead::getLeavingRequests() const
{
    return this->leavingRequests;
}

void TeamLead::setLeavingRequests(std::vector<LeavingRequest> leavingRequests)
{
    this->leavingRequests = leavingRequests;
}

std::vector<PromotionRequest> TeamLead::getPromotionRequests() const
{
    return this->promotionRequests;
}

void TeamLead::setPromotionRequests(std::vector<PromotionRequest> promotionRequests)
{
    this->promotionRequests = promotionRequests;
}

TeamLead::TeamLead(const std::string& name, double salary)
{
    setName(name);
    setSalary(salary);
    setTeamLead(this);
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
    developer->setSalary(salary);
    developer->setTeamLead(getTeamLead());
    devs.push_back(developer);
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
    for(size_t i=devs.size()-1; i>=0; i--)
    {
        if( devs[i]->getName().compare(name)==0 )
        {
            devs[i]->setTeamLead(nullptr);
            devs.erase( devs.begin()+i );
            break;
        }
    }
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
    for(size_t i=0; i<devs.size();i++)
    {
        double newSalary = devs[i]->getSalary()+amount;
        devs[i]->setSalary(newSalary);
    }
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
    for(size_t i=0; i<devs.size();i++)
    {
        double newSalary = devs[i]->getSalary()-amount;
        devs[i]->setSalary(newSalary);
    }
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
    leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
    promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
    for(size_t i=0; i<leavingRequests.size(); i++)
    {
        for(size_t j=0; j<devs.size(); j++)
        {
            if( devs[j]->getName()==leavingRequests[i].getSender() )
            {
                devs[j]->setTeamLead(nullptr);
                devs.erase( devs.begin()+j );
                leavingRequests.erase( leavingRequests.begin()+i );
            }
        }
    }
}

void TeamLead::fulfillPromotionRequests()
{
    for(size_t i=0; i<promotionRequests.size(); i++)
    {
        for(size_t j=0; j<devs.size(); j++)
        {
            if( devs[j]->getName()==promotionRequests[i].getSender() )
            {
                devs[j]->setSalary( promotionRequests[i].getAmount() );
                promotionRequests.erase( promotionRequests.begin()+i );
            }
        }
    }
}











