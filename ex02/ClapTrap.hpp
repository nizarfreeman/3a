#ifndef CT_H
# define CT_H
# include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int hp;
        int ep;
        int att;

    public:
        ClapTrap();
        ClapTrap(const std::string& nname);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        virtual ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif