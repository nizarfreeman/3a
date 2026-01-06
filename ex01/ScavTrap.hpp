#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap(): ClapTrap() {this->hp = 100; this->ep = 50; this->att = 20; std::cout<<"ScavTrap default constructor called"<<std::endl;}
        ScavTrap(const std::string name): ClapTrap(name) {this->hp = 100; this->ep = 50; this->att = 20; std::cout<<"ScavTrap constructor called"<<std::endl;}
        ScavTrap(const ScavTrap &other): ClapTrap(other) {std::cout<<"ScavTrap copy constructor called for "<<name<<std::endl; *this = other;}
        ScavTrap& operator=(const ScavTrap& other)
        {
            if (this != &other)
            {
                this->name = other.name;
                this->hp = other.hp;
                this->ep = other.ep;
                this->att = other.att;
            }
            std::cout<<"ScavTrap assignment operator called for "<<name<<std::endl;
            return (*this);
        }
        ~ScavTrap() {std::cout<<"ScavTrap destructor called for "<<name<<std::endl;}

        void attack(const std::string &target)
        {
            if (hp <= 0 || ep <= 0)
                { std::cout<<"ScavTrap "<<name<<" cannot attack (HP: "<<hp<<", EP: "<<ep<<")\n"; return; }
            ep--;
            std::cout<<"ScavTrap "<<name<<" attacks "<<target<<" causing "<<att<<" points of damage!"<<std::endl;
        }

        void guardGate()
        {
            if (ep <= 0 || hp <= 0)
            {
                std::cout<<"ScavTrap "<<name<<" can't guard (HP: "<<hp<<", EP: "<<ep<<")\n";
                return ;
            }
            ep--;
            std::cout<<"ScavTrap is in guard mode now !"<<std::endl;
        }
};