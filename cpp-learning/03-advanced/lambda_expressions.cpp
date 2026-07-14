/**
 * Lambda Expressions - Anonymous Functions
 * 
 * Learn about C++11 lambda expressions for inline functions.
 * 
 * Compile: g++ -std=c++17 -Wall -o lambdas lambda_expressions.cpp
 * Run: ./lambdas
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

int main() {
    std::cout << "=== Lambda Expressions in C++ ===" << std::endl << std::endl;
    
    // ===== BASIC LAMBDA =====
    std::cout << "1. Basic Lambda:" << std::endl;
    
    // Lambda with no parameters
    auto hello = []() {
        std::cout << "  Hello from lambda!" << std::endl;
    };
    hello();
    
    // Lambda with parameters and return value
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    std::cout << "  5 + 3 = " << add(5, 3) << std::endl;
    
    // Return type can often be deduced
    auto multiply = [](int a, int b) { return a * b; };
    std::cout << "  4 * 6 = " << multiply(4, 6) << std::endl;
    std::cout << std::endl;
    
    // ===== CAPTURE CLAUSES =====
    std::cout << "2. Capture Clauses:" << std::endl;
    
    int x = 10;
    int y = 20;
    
    // Capture by value [=]
    auto captureByValue = [=]() {
        std::cout << "  Captured by value: x=" << x << ", y=" << y << std::endl;
    };
    captureByValue();
    
    // Capture by reference [&]
    auto captureByRef = [&]() {
        x += 5;  // Can modify original
        y += 5;
        std::cout << "  Modified through reference: x=" << x << ", y=" << y << std::endl;
    };
    captureByRef();
    
    // Capture specific variables
    int a = 1, b = 2;
    auto captureSpecific = [a, &b]() {
        // a is by value, b is by reference
        b += 10;
        std::cout << "  a=" << a << ", b=" << b << std::endl;
    };
    captureSpecific();
    std::cout << "  After lambda, b=" << b << std::endl;
    std::cout << std::endl;
    
    // ===== LAMBDAS WITH STL ALGORITHMS =====
    std::cout << "3. Lambdas with STL Algorithms:" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Count even numbers
    int evenCount = std::count_if(numbers.begin(), numbers.end(),
                                   [](int n) { return n % 2 == 0; });
    std::cout << "  Even numbers: " << evenCount << std::endl;
    
    // Find first number > 5
    auto found = std::find_if(numbers.begin(), numbers.end(),
                              [](int n) { return n > 5; });
    if (found != numbers.end()) {
        std::cout << "  First number > 5: " << *found << std::endl;
    }
    
    // Transform: square all numbers
    std::vector<int> squared(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squared.begin(),
                   [](int n) { return n * n; });
    
    std::cout << "  Squared: ";
    for (int n : squared) {
        std::cout << n << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== MUTABLE LAMBDAS =====
    std::cout << "4. Mutable Lambdas:" << std::endl;
    
    int counter = 0;
    auto incrementer = [counter]() mutable {
        counter++;  // Can modify captured value (but not original)
        return counter;
    };
    
    std::cout << "  Call 1: " << incrementer() << std::endl;
    std::cout << "  Call 2: " << incrementer() << std::endl;
    std::cout << "  Call 3: " << incrementer() << std::endl;
    std::cout << "  Original counter: " << counter << std::endl;
    std::cout << std::endl;
    
    // ===== LAMBDA AS FUNCTION PARAMETER =====
    std::cout << "5. Lambda as Function Parameter:" << std::endl;
    
    auto applyOperation = [](const std::vector<int>& vec, 
                             std::function<int(int)> operation) {
        std::vector<int> result;
        for (int n : vec) {
            result.push_back(operation(n));
        }
        return result;
    };
    
    std::vector<int> data = {1, 2, 3, 4, 5};
    
    auto doubled = applyOperation(data, [](int n) { return n * 2; });
    std::cout << "  Doubled: ";
    for (int n : doubled) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    auto plusTen = applyOperation(data, [](int n) { return n + 10; });
    std::cout << "  Plus 10: ";
    for (int n : plusTen) {
        std::cout << n << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== SORTING WITH LAMBDAS =====
    std::cout << "6. Custom Sorting:" << std::endl;
    
    std::vector<std::string> words = {"apple", "zoo", "cat", "dog", "elephant"};
    
    // Sort by length
    std::sort(words.begin(), words.end(),
              [](const std::string& a, const std::string& b) {
                  return a.length() < b.length();
              });
    
    std::cout << "  Sorted by length: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    // Sort by last character
    std::sort(words.begin(), words.end(),
              [](const std::string& a, const std::string& b) {
                  return a.back() < b.back();
              });
    
    std::cout << "  Sorted by last char: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== GENERIC LAMBDAS (C++14) =====
    std::cout << "7. Generic Lambdas (C++14):" << std::endl;
    
    auto printer = [](const auto& value) {
        std::cout << "  Value: " << value << std::endl;
    };
    
    printer(42);
    printer(3.14);
    printer("Hello!");
    printer(std::string("World!"));
    
    return 0;
}

/*
 * Key Concepts:
 * 1. Lambda syntax: [capture](parameters) -> return_type { body }
 * 2. Capture clauses: [=] by value, [&] by reference
 * 3. Specific captures: [x, &y] captures x by value, y by reference
 * 4. mutable keyword for modifying captured values
 * 5. auto keyword with lambdas
 * 6. std::function for storing lambdas
 * 7. Generic lambdas with auto parameters (C++14)
 * 8. Using lambdas with STL algorithms
 * 
 * Capture Options:
 * [] - capture nothing
 * [=] - capture all by value
 * [&] - capture all by reference
 * [x] - capture x by value
 * [&x] - capture x by reference
 * [=, &x] - capture all by value except x by reference
 * [&, x] - capture all by reference except x by value
 * 
 * Try it yourself:
 * - Create a calculator using lambdas for operations
 * - Use lambdas to filter and transform data
 * - Implement callbacks with lambdas
 * - Create a lambda that returns another lambda
 * - Use lambdas for custom comparison in sets/maps
 */
