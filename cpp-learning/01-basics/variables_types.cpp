/**
 * Variables and Data Types
 * 
 * Learn about different data types in C++ and how to declare variables.
 * 
 * Compile: g++ -std=c++17 -Wall -o variables variables_types.cpp
 * Run: ./variables
 */

#include <iostream>
#include <string>    // For std::string
#include <iomanip>   // For formatting output

int main() {
    std::cout << "=== C++ Data Types ===" << std::endl << std::endl;
    
    // Integer types
    int age = 25;                    // Standard integer (usually 4 bytes)
    short smallNum = 100;            // Smaller integer (usually 2 bytes)
    long bigNum = 1000000L;          // Larger integer (at least 4 bytes)
    long long veryBigNum = 9876543210LL;  // Very large integer (at least 8 bytes)
    
    std::cout << "Integer Types:" << std::endl;
    std::cout << "  int: " << age << std::endl;
    std::cout << "  short: " << smallNum << std::endl;
    std::cout << "  long: " << bigNum << std::endl;
    std::cout << "  long long: " << veryBigNum << std::endl;
    std::cout << std::endl;
    
    // Floating-point types
    float pi = 3.14159f;             // Single precision (usually 4 bytes)
    double e = 2.71828;              // Double precision (usually 8 bytes)
    long double precise = 3.141592653589793238L;  // Extended precision
    
    std::cout << "Floating-Point Types:" << std::endl;
    std::cout << std::fixed << std::setprecision(5);  // Format output
    std::cout << "  float: " << pi << std::endl;
    std::cout << "  double: " << e << std::endl;
    std::cout << std::setprecision(15);
    std::cout << "  long double: " << precise << std::endl;
    std::cout << std::endl;
    
    // Character type
    char initial = 'A';              // Single character
    std::cout << "Character Type:" << std::endl;
    std::cout << "  char: " << initial << std::endl;
    std::cout << "  ASCII value: " << static_cast<int>(initial) << std::endl;
    std::cout << std::endl;
    
    // Boolean type
    bool isLearning = true;          // true or false
    bool isConfused = false;
    
    std::cout << "Boolean Type:" << std::endl;
    std::cout << "  isLearning: " << std::boolalpha << isLearning << std::endl;
    std::cout << "  isConfused: " << isConfused << std::endl;
    std::cout << std::endl;
    
    // String type (from C++ standard library)
    std::string name = "C++ Programmer";
    
    std::cout << "String Type:" << std::endl;
    std::cout << "  name: " << name << std::endl;
    std::cout << "  length: " << name.length() << " characters" << std::endl;
    std::cout << std::endl;
    
    // Constants - values that cannot be changed
    const double PI = 3.14159265359;
    const int MAX_USERS = 100;
    
    std::cout << "Constants:" << std::endl;
    std::cout << "  PI: " << PI << std::endl;
    std::cout << "  MAX_USERS: " << MAX_USERS << std::endl;
    std::cout << std::endl;
    
    // Type inference with auto (C++11 and later)
    auto autoInt = 42;               // Compiler deduces type as int
    auto autoDouble = 3.14;          // Compiler deduces type as double
    auto autoString = "Hello";       // Compiler deduces type as const char*
    
    std::cout << "Auto Type Inference:" << std::endl;
    std::cout << "  autoInt: " << autoInt << std::endl;
    std::cout << "  autoDouble: " << autoDouble << std::endl;
    std::cout << "  autoString: " << autoString << std::endl;
    
    return 0;
}

/*
 * Key Concepts:
 * 1. Fundamental types: int, double, char, bool
 * 2. Type modifiers: short, long, signed, unsigned
 * 3. std::string for text (needs #include <string>)
 * 4. const keyword for constants
 * 5. auto keyword for type inference
 * 6. Literals: L for long, f for float, LL for long long
 * 
 * Try it yourself:
 * - Declare your own variables
 * - Try unsigned types (unsigned int, etc.)
 * - Experiment with sizeof() operator to see type sizes
 * - Try to modify a const variable (you'll get an error!)
 */
