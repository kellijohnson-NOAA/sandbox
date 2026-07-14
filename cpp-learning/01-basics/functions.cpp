/**
 * Functions - Reusable Code Blocks
 * 
 * Learn how to create and use functions to organize your code.
 * 
 * Compile: g++ -std=c++17 -Wall -o functions functions.cpp
 * Run: ./functions
 */

#include <iostream>
#include <string>
#include <cmath>  // For mathematical functions

// Function declaration (prototype)
void printGreeting();
int add(int a, int b);
double calculateCircleArea(double radius);
void printArray(int arr[], int size);
int factorial(int n);
void swapByValue(int a, int b);
void swapByReference(int& a, int& b);
std::string createGreeting(std::string name = "Guest");

// ===== MAIN FUNCTION =====
int main() {
    std::cout << "=== Functions in C++ ===" << std::endl << std::endl;
    
    // ===== SIMPLE FUNCTION CALLS =====
    std::cout << "1. Simple Functions:" << std::endl;
    printGreeting();
    std::cout << std::endl;
    
    // ===== FUNCTIONS WITH RETURN VALUES =====
    std::cout << "2. Functions with Return Values:" << std::endl;
    int sum = add(10, 20);
    std::cout << "  10 + 20 = " << sum << std::endl;
    
    double area = calculateCircleArea(5.0);
    std::cout << "  Area of circle (r=5): " << area << std::endl;
    std::cout << std::endl;
    
    // ===== FUNCTIONS WITH ARRAYS =====
    std::cout << "3. Functions with Arrays:" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "  Array contents: ";
    printArray(numbers, 5);
    std::cout << std::endl;
    
    // ===== RECURSIVE FUNCTIONS =====
    std::cout << "4. Recursive Functions:" << std::endl;
    int n = 5;
    std::cout << "  Factorial of " << n << " = " << factorial(n) << std::endl;
    std::cout << std::endl;
    
    // ===== PASS BY VALUE VS REFERENCE =====
    std::cout << "5. Pass by Value vs Reference:" << std::endl;
    int x = 10, y = 20;
    
    std::cout << "  Before: x=" << x << ", y=" << y << std::endl;
    swapByValue(x, y);
    std::cout << "  After swapByValue: x=" << x << ", y=" << y << std::endl;
    
    swapByReference(x, y);
    std::cout << "  After swapByReference: x=" << x << ", y=" << y << std::endl;
    std::cout << std::endl;
    
    // ===== DEFAULT PARAMETERS =====
    std::cout << "6. Default Parameters:" << std::endl;
    std::cout << "  " << createGreeting("Alice") << std::endl;
    std::cout << "  " << createGreeting() << std::endl;
    
    return 0;
}

// ===== FUNCTION DEFINITIONS =====

// Simple function with no parameters or return value
void printGreeting() {
    std::cout << "  Hello from a function!" << std::endl;
}

// Function that returns a value
int add(int a, int b) {
    return a + b;
}

// Function with floating-point calculation
double calculateCircleArea(double radius) {
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

// Function that works with arrays
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

// Recursive function (calls itself)
int factorial(int n) {
    if (n <= 1) {
        return 1;  // Base case
    }
    return n * factorial(n - 1);  // Recursive case
}

// Pass by value - changes don't affect original variables
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // a and b are changed here, but not in main()
}

// Pass by reference - changes affect original variables
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    // a and b in main() are actually swapped
}

// Function with default parameter
std::string createGreeting(std::string name) {
    return "Hello, " + name + "!";
}

/*
 * Key Concepts:
 * 1. Function declaration vs definition
 * 2. Return types (void, int, double, etc.)
 * 3. Parameters and arguments
 * 4. Pass by value vs pass by reference (&)
 * 5. Default parameters
 * 6. Recursion (function calling itself)
 * 7. Arrays as function parameters
 * 8. Function prototypes (forward declarations)
 * 
 * Try it yourself:
 * - Write a function to check if a number is prime
 * - Create a function to find the maximum of three numbers
 * - Write a recursive function for Fibonacci sequence
 * - Create a function to reverse a string
 * - Experiment with const references for efficiency
 */
