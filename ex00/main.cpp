#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    a.attack("Beta");
    b.takeDamage(3);

    b.beRepaired(5);

    // Drain energy
    for (int i = 0; i < 10; i++)
        a.attack("Dummy");

    // Try attacking with no EP
    a.attack("Dummy");

    // Take lethal damage
    b.takeDamage(50);

    // Try repairing with no HP
    b.beRepaired(10);

    // Copy constructor
    ClapTrap c(a);

    // Assignment operator
    ClapTrap d;
    d = b;

    return 0;
}