#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== MULTIPLE ASSIGNMENT CHAINING ===\n";

    FragTrap a("A");
    FragTrap b("B");
    FragTrap c("C");

    std::cout << "\n--- BEFORE ---\n";
    a.attack("x");
    b.attack("x");
    c.attack("x");

    std::cout << "\n--- a = b = c ---\n";
    a = b = c;

    std::cout << "\n--- AFTER ---\n";
    a.attack("x");
    b.attack("x");
    c.attack("x");

    std::cout << "\n=== SELF + CHAIN MIX ===\n";
    a = b = a;

    a.attack("y");
    b.attack("y");

    std::cout << "\n=== END ===\n";
    return 0;
}
