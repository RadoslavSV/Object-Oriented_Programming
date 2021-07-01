/// Radoslav Velkov, 1 group, FN 62528

#include "Developer.hpp"
#include "TeamLead.hpp"

std::string Developer::getName() const
{
    return this->name;
}

void Developer::setName(const std::string& name)
{
    this->name = name;
}

double Developer::getSalary() const
{
    return this->salary;
}

void Developer::setSalary(double salary)
{
    this->salary = salary;
}

TeamLead* Developer::getTeamLead() const
{
    return this->teamleader;
}

void Developer::setTeamLead(TeamLead* teamleader)
{
    this->teamleader = teamleader;
}

Developer::Developer()
{
    setName("");
    setSalary(0);
    setTeamLead(nullptr);
}

Developer::Developer(const std::string& name)
{
    setName(name);
    setSalary(0);
    setTeamLead(nullptr);
}

void Developer::setInitialSalary(double amount)
{
    if( getSalary()==0 )
    {
        setSalary(amount);
    }
}

void Developer::sendLeavingRequest()
{
    if(teamleader!=nullptr)
	{
		LeavingRequest lr(this->name);
		teamleader->addLeavingRequest(lr);
	}
}

void Developer::sendPromotionRequest(double amount)
{
    if(teamleader!=nullptr)
	{
		PromotionRequest pr(this->name, amount);
		teamleader->addPromotionRequest(pr);
	}
}












