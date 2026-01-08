#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
    {this->hp = 100; this->ep = 100; this->att = 30; std::cout<<"FragTrap default constructor called"<<std::endl;}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
    {this->hp = 100; this->ep = 100; this->att = 30; std::cout<<"FragTrap constructor called for "<<name<<std::endl;}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
    {std::cout<<"FragTrap copy constructor called for "<<name<<std::endl; }

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout<<"FragTrap assignment operator called for "<<name<<std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap()
    {std::cout<<"FragTrap destructor called for "<<name<<std::endl;}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"FragTrap "<<name<<" requesting a positive high-fives!"<<std::endl;
}