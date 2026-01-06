#include "ScavTrap.hpp"

int main()
{
    std::cout << "========== BASIC CONSTRUCTION ==========\n";
    ScavTrap a("Alpha");
    std::cout << std::endl;

    std::cout << "========== STATS CHECK ==========\n";
    a.attack("TargetDummy");   // should use ScavTrap attack message
    a.guardGate();             // special ability
    std::cout << std::endl;

    std::cout << "========== ENERGY / HP BEHAVIOR ==========\n";
    for (int i = 0; i < 3; i++)
        a.attack("EnergySink");
    std::cout << std::endl;

    std::cout << "========== COPY CONSTRUCTOR ==========\n";
    ScavTrap b(a);
    b.attack("CopyTarget");
    b.guardGate();
    std::cout << std::endl;

    std::cout << "========== ASSIGNMENT OPERATOR ==========\n";
    ScavTrap c("Temp");
    c = a;
    c.attack("AssignedTarget");
    c.guardGate();
    std::cout << std::endl;

    std::cout << "========== POLYMORPHISM TEST ==========\n";
    ClapTrap* basePtr = new ScavTrap("HeapScav");
    basePtr->attack("BasePointerTarget"); // should call ClapTrap unless virtual
    delete basePtr; // destructor chaining must be visible
    std::cout << std::endl;

    std::cout << "========== SCOPE DESTRUCTION ORDER ==========\n";
    {
        ScavTrap scoped("ScopedScav");
        scoped.guardGate();
    } // ScavTrap destroyed first, then ClapTrap
    std::cout << std::endl;

    std::cout << "========== END OF MAIN ==========\n";
    return 0;
}