/**
 * Exercise 3: Simple Calculator with Classes
 * 
 * Create a calculator class that supports basic operations.
 * This demonstrates OOP principles in a practical example.
 */

#include <iostream>
#include <string>
#include <stdexcept>

class Calculator {
private:
    double lastResult;
    int operationCount;

public:
    // Constructor
    Calculator() : lastResult(0.0), operationCount(0) {
        std::cout << "Calculator initialized!" << std::endl;
    }
    
    // Basic operations
    double add(double a, double b) {
        lastResult = a + b;
        operationCount++;
        return lastResult;
    }
    
    double subtract(double a, double b) {
        lastResult = a - b;
        operationCount++;
        return lastResult;
    }
    
    double multiply(double a, double b) {
        lastResult = a * b;
        operationCount++;
        return lastResult;
    }
    
    double divide(double a, double b) {
        if (b == 0) {
            throw std::runtime_error("Division by zero!");
        }
        lastResult = a / b;
        operationCount++;
        return lastResult;
    }
    
    double power(double base, int exponent) {
        lastResult = 1.0;
        for (int i = 0; i < exponent; i++) {
            lastResult *= base;
        }
        operationCount++;
        return lastResult;
    }
    
    // Getters
    double getLastResult() const {
        return lastResult;
    }
    
    int getOperationCount() const {
        return operationCount;
    }
    
    // Reset calculator
    void reset() {
        lastResult = 0.0;
        operationCount = 0;
        std::cout << "Calculator reset!" << std::endl;
    }
    
    // Display statistics
    void displayStats() const {
        std::cout << "Last result: " << lastResult << std::endl;
        std::cout << "Operations performed: " << operationCount << std::endl;
    }
};

int main() {
    std::cout << "=== Calculator Class Example ===" << std::endl << std::endl;
    
    Calculator calc;
    
    // Perform operations
    std::cout << "Operations:" << std::endl;
    std::cout << "  10 + 5 = " << calc.add(10, 5) << std::endl;
    std::cout << "  20 - 8 = " << calc.subtract(20, 8) << std::endl;
    std::cout << "  6 * 7 = " << calc.multiply(6, 7) << std::endl;
    std::cout << "  100 / 4 = " << calc.divide(100, 4) << std::endl;
    std::cout << "  2 ^ 8 = " << calc.power(2, 8) << std::endl;
    
    std::cout << std::endl;
    calc.displayStats();
    
    // Test error handling
    std::cout << std::endl << "Testing error handling:" << std::endl;
    try {
        std::cout << "  Attempting 10 / 0..." << std::endl;
        calc.divide(10, 0);
    } catch (const std::exception& e) {
        std::cout << "  Error caught: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    // Chain operations using last result
    std::cout << "Chaining operations:" << std::endl;
    double result = calc.add(5, 5);
    std::cout << "  5 + 5 = " << result << std::endl;
    
    result = calc.multiply(result, 2);
    std::cout << "  Result * 2 = " << result << std::endl;
    
    result = calc.subtract(result, 10);
    std::cout << "  Result - 10 = " << result << std::endl;
    
    std::cout << std::endl;
    calc.displayStats();
    
    return 0;
}

/*
 * Learning Points:
 * 1. Class design with private and public members
 * 2. Constructor initialization
 * 3. Method implementation for operations
 * 4. Exception handling with try-catch
 * 5. State management (lastResult, operationCount)
 * 6. Const member functions for getters
 * 
 * Enhancements to try:
 * - Add more operations (sqrt, factorial, modulo)
 * - Implement a history of operations
 * - Add memory functions (M+, M-, MR, MC)
 * - Create a scientific calculator subclass
 * - Add input validation
 * - Implement operator overloading
 */
