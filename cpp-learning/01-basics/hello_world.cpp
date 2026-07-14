/**
 * Hello World - Your First C++ Program
 * 
 * This is the traditional first program in any programming language.
 * It demonstrates the basic structure of a C++ program.
 * 
 * Compile: g++ -std=c++17 -Wall -o hello hello_world.cpp
 * Run: ./hello
 */

#include <iostream>  // Include the input/output stream library

// Every C++ program must have a main() function
// This is where program execution begins
int main() {
    // std::cout is used to print output to the console
    // << is the stream insertion operator
    // std::endl adds a newline and flushes the output buffer
    std::cout << "Hello, World!" << std::endl;
    
    // Multiple outputs on one line
    std::cout << "Welcome to C++ programming!" << std::endl;
    
    // You can chain multiple << operators
    std::cout << "Learning C++ is " << "fun " << "and " << "rewarding!" << std::endl;
    
    // return 0 indicates successful program execution
    return 0;
}

/*
 * Key Concepts:
 * 1. #include <iostream> - includes standard input/output library
 * 2. main() function - entry point of every C++ program
 * 3. std::cout - standard output stream
 * 4. << operator - sends data to output stream
 * 5. std::endl - end line (newline + flush)
 * 6. return 0 - indicates success
 * 
 * Try it yourself:
 * - Change the message
 * - Add more cout statements
 * - Try using "\n" instead of std::endl
 */
