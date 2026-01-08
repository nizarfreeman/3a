#include <iostream>
// WRONG VERSION - Causes infinite recursion
class Wrong {
public:
    int data;
    
    Wrong(int d) : data(d) {
        std::cout << "Constructor\n";
    }
    
    // ❌ WRONG: Pass by VALUE instead of reference
    Wrong(Wrong other) {  // This is the problem!
        std::cout << "Copy constructor\n";
        data = other.data;
    }
};

// Why does this cause infinite recursion?
// 
// Wrong a(5);        // Creates object a
// Wrong b = a;       // Tries to call copy constructor
//
// Step-by-step what happens:
// 1. Call Wrong(Wrong other) with 'a' as argument
// 2. To pass 'a' BY VALUE, C++ must COPY it
// 3. To COPY 'a', C++ calls the copy constructor
// 4. To call copy constructor, pass 'a' BY VALUE
// 5. To pass BY VALUE, must COPY it
// 6. To COPY, call copy constructor...
// 7. INFINITE RECURSION! Stack overflow!

// ================================================================

// CORRECT VERSION - Uses const reference
class Correct {
public:
    int data;
    
    Correct(int d) : data(d) {
        std::cout << "Constructor\n";
    }
    
    // ✅ CORRECT: Pass by const REFERENCE
    Correct(const Correct& other) {
        std::cout << "Copy constructor\n";
        data = other.data;
    }
};

// Why does reference work?
//
// Correct a(5);
// Correct b = a;
//
// 1. Call Correct(const Correct& other) with 'a'
// 2. 'other' is just an ALIAS/REFERENCE to 'a'
// 3. No copying needed to pass the parameter!
// 4. Just passes the address of 'a'
// 5. No recursion - it works!

// ================================================================

int main() {
    std::cout << "=== Testing CORRECT version ===\n";
    Correct c1(42);
    Correct c2 = c1;  // ✅ Works fine
    std::cout << "c2.data = " << c2.data << "\n\n";
    
    std::cout << "=== Testing WRONG version ===\n";
    std::cout << "Uncommenting the lines below will cause:\n";
    std::cout << "- Infinite recursion\n";
    std::cout << "- Stack overflow\n";
    std::cout << "- Program crash\n\n";
    
    // Wrong w1(42);
    // Wrong w2 = w1;  // ❌ CRASH! Infinite recursion
    
    std::cout << "Note: Modern compilers won't even compile the Wrong class!\n";
    std::cout << "You'll get an error like:\n";
    std::cout << "  'error: copy constructor must pass its first argument by reference'\n";
    
    return 0;
}

/* COMPILER OUTPUT if you try to compile Wrong class:
   
   error: copy constructor must pass its first argument by reference
   
   This is why the compiler FORCES you to use a reference!
   It's protecting you from this infinite recursion bug.
*/