#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
    {this->hp = 100; this->ep = 50; this->att = 20; std::cout<<"ScavTrap default constructor called"<<std::endl;}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
    {this->hp = 100; this->ep = 50; this->att = 20; std::cout<<"ScavTrap constructor called for "<<name<<std::endl;}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
    {std::cout<<"ScavTrap copy constructor called for "<<name<<std::endl;}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout<<"FragTrap assignment operator called for "<<name<<std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap()
    {std::cout<<"ScavTrap destructor called for "<<name<<std::endl;}

void ScavTrap::attack(const std::string &target)
{
    if (hp <= 0 || ep <= 0)
        { std::cout<<"ScavTrap "<<name<<" cannot attack (HP: "<<hp<<", EP: "<<ep<<")\n"; return; }
    ep--;
    std::cout<<"ScavTrap "<<name<<" attacks "<<target<<" causing "<<att<<" points of damage!"<<std::endl;
}

void ScavTrap::guardGate()
{
    if (ep <= 0 || hp <= 0)
    {
        std::cout<<"ScavTrap "<<name<<" can't guard (HP: "<<hp<<", EP: "<<ep<<")\n";
        return ;
    }
    ep--;
    std::cout<<"ScavTrap is in guard mode now !"<<std::endl;
}