/**
 * Exercise 1: FizzBuzz
 * 
 * Write a program that prints numbers from 1 to 100.
 * - For multiples of 3, print "Fizz" instead of the number
 * - For multiples of 5, print "Buzz" instead of the number
 * - For multiples of both 3 and 5, print "FizzBuzz"
 * 
 * This is a classic programming interview question!
 */

#include <iostream>

int main() {
    std::cout << "=== FizzBuzz Solution ===" << std::endl << std::endl;
    
    for (int i = 1; i <= 100; i++) {
        // Check if divisible by both 3 and 5 first
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "FizzBuzz";
        }
        // Check if divisible by 3
        else if (i % 3 == 0) {
            std::cout << "Fizz";
        }
        // Check if divisible by 5
        else if (i % 5 == 0) {
            std::cout << "Buzz";
        }
        // Otherwise, print the number
        else {
            std::cout << i;
        }
        
        // Print comma and space, except for the last number
        if (i < 100) {
            std::cout << ", ";
        }
        
        // Print newline every 20 items for readability
        if (i % 20 == 0) {
            std::cout << std::endl;
        }
    }
    
    std::cout << std::endl;
    
    return 0;
}

/*
 * Learning Points:
 * 1. Using the modulo operator (%) to check divisibility
 * 2. if-else statement chains
 * 3. Order matters: check combined condition first
 * 4. Formatting output for readability
 * 
 * Variations to try:
 * - Change the range (1-50, 1-200, etc.)
 * - Use different numbers (e.g., 2 and 7)
 * - Add a third number (e.g., 7 -> "Jazz")
 * - Make it configurable with function parameters
 */
