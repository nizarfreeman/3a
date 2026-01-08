#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("-"), hp(10), ep(10), att(0)
    { std::cout<<"ClapTrap default constructor called\n"; }

ClapTrap::ClapTrap(const std::string& nname) : name(nname), hp(10), ep(10), att(0)
    { std::cout<<"ClapTrap constructor called for "<<name<<std::endl; }

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hp(other.hp), ep(other.ep), att(other.att)
    { std::cout<<"ClapTrap copy constructor called for "<<name<<std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout<<"ClapTrap assignment operator called for "<<name<<std::endl;
    if (this != &other)
    {
        name = other.name;
        hp = other.hp;
        ep = other.ep;
        att = other.att;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
    { std::cout<<"ClapTrap destructor called for "<<name<<std::endl; }

void ClapTrap::attack(const std::string& target)
{
    if (hp <= 0 || ep <= 0)
        { std::cout<<"ClapTrap "<<name<<" cannot attack (HP: "<<hp<<", EP: "<<ep<<")\n"; return; }
    ep--;
    std::cout<<"ClapTrap "<<name<<" attacks "<<target<<" causing "<<att<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp <= 0)
    {
        std::cout<<"ClapTrap "<<name<<" is already destroyed!"<<std::endl; 
        return;
    }
    hp -= amount;
    if (hp < 0)
        hp = 0;
    std::cout<<"ClapTrap "<<name<<" takes "<<amount<<" of damage (HP: "<<hp<<")"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp <= 0 || ep <= 0)
    {
        std::cout<<"ClapTrap "<<name<<" cannot repair (HP: "<<hp<<", EP: "<<ep<<")"<<std::endl;
        return;
    }
    ep--;
    hp += amount;
    std::cout<<"ClapTrap "<<name<<" repairs "<<amount<<" of HP (HP: "<<hp<< ", EP: "<<ep<<")"<<std::endl;
}