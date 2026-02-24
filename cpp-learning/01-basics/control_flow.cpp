/**
 * Control Flow - if/else, loops, and switch
 * 
 * Learn how to control the flow of your program with conditionals and loops.
 * 
 * Compile: g++ -std=c++17 -Wall -o control control_flow.cpp
 * Run: ./control
 */

#include <iostream>

int main() {
    std::cout << "=== Control Flow in C++ ===" << std::endl << std::endl;
    
    // ===== IF-ELSE STATEMENTS =====
    std::cout << "1. If-Else Statements:" << std::endl;
    
    int temperature = 75;
    
    if (temperature > 80) {
        std::cout << "  It's hot outside!" << std::endl;
    } else if (temperature > 60) {
        std::cout << "  Nice weather!" << std::endl;
    } else {
        std::cout << "  It's cold outside!" << std::endl;
    }
    
    // Ternary operator (shorthand for simple if-else)
    std::string weather = (temperature > 70) ? "warm" : "cool";
    std::cout << "  Weather is " << weather << std::endl;
    std::cout << std::endl;
    
    // ===== FOR LOOPS =====
    std::cout << "2. For Loops:" << std::endl;
    
    // Standard for loop
    std::cout << "  Counting 1 to 5: ";
    for (int i = 1; i <= 5; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Counting backwards
    std::cout << "  Countdown 5 to 1: ";
    for (int i = 5; i >= 1; i--) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Stepping by 2
    std::cout << "  Even numbers 0-10: ";
    for (int i = 0; i <= 10; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== WHILE LOOPS =====
    std::cout << "3. While Loops:" << std::endl;
    
    int count = 1;
    std::cout << "  Squares 1-5: ";
    while (count <= 5) {
        std::cout << count * count << " ";
        count++;
    }
    std::cout << std::endl << std::endl;
    
    // ===== DO-WHILE LOOPS =====
    std::cout << "4. Do-While Loops:" << std::endl;
    
    int num = 1;
    std::cout << "  Powers of 2 (up to 32): ";
    do {
        std::cout << num << " ";
        num *= 2;
    } while (num <= 32);
    std::cout << std::endl << std::endl;
    
    // ===== SWITCH STATEMENTS =====
    std::cout << "5. Switch Statements:" << std::endl;
    
    int dayOfWeek = 3;
    
    std::cout << "  Day " << dayOfWeek << " is: ";
    switch (dayOfWeek) {
        case 1:
            std::cout << "Monday";
            break;
        case 2:
            std::cout << "Tuesday";
            break;
        case 3:
            std::cout << "Wednesday";
            break;
        case 4:
            std::cout << "Thursday";
            break;
        case 5:
            std::cout << "Friday";
            break;
        case 6:
        case 7:
            std::cout << "Weekend!";
            break;
        default:
            std::cout << "Invalid day";
            break;
    }
    std::cout << std::endl << std::endl;
    
    // ===== BREAK AND CONTINUE =====
    std::cout << "6. Break and Continue:" << std::endl;
    
    // Break - exits the loop
    std::cout << "  Using break (stop at 5): ";
    for (int i = 1; i <= 10; i++) {
        if (i == 6) break;
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Continue - skips to next iteration
    std::cout << "  Using continue (skip evens): ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) continue;  // Skip even numbers
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== NESTED LOOPS =====
    std::cout << "7. Nested Loops (multiplication table):" << std::endl;
    
    for (int i = 1; i <= 5; i++) {
        std::cout << "  ";
        for (int j = 1; j <= 5; j++) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

/*
 * Key Concepts:
 * 1. if-else statements for conditional execution
 * 2. Ternary operator (?:) for simple conditions
 * 3. for loops for counted iterations
 * 4. while loops for condition-based iterations
 * 5. do-while loops (execute at least once)
 * 6. switch statements for multiple conditions
 * 7. break to exit loops early
 * 8. continue to skip to next iteration
 * 9. Nested loops for multi-dimensional iteration
 * 
 * Try it yourself:
 * - Create a number guessing game
 * - Print different patterns (triangles, diamonds)
 * - Calculate factorial using a loop
 * - Find prime numbers in a range
 */
