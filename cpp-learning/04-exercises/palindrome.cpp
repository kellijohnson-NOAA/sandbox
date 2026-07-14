/**
 * Exercise 2: Palindrome Checker
 * 
 * Write a program that checks if a string is a palindrome.
 * A palindrome reads the same forwards and backwards.
 * Examples: "radar", "level", "racecar"
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Function to check if a string is a palindrome
bool isPalindrome(std::string str) {
    // Convert to lowercase and remove spaces
    std::string cleaned;
    for (char c : str) {
        if (std::isalnum(c)) {
            cleaned += std::tolower(c);
        }
    }
    
    // Check if the string reads the same forwards and backwards
    int left = 0;
    int right = cleaned.length() - 1;
    
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

// Alternative method using string reversal
bool isPalindromeReverse(std::string str) {
    // Clean the string
    std::string cleaned;
    for (char c : str) {
        if (std::isalnum(c)) {
            cleaned += std::tolower(c);
        }
    }
    
    // Reverse the string
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    
    // Compare
    return cleaned == reversed;
}

int main() {
    std::cout << "=== Palindrome Checker ===" << std::endl << std::endl;
    
    // Test cases
    std::string testWords[] = {
        "radar",
        "hello",
        "level",
        "world",
        "racecar",
        "A man a plan a canal Panama",
        "Was it a car or a cat I saw"
    };
    
    std::cout << "Method 1: Two-pointer approach" << std::endl;
    for (const std::string& word : testWords) {
        std::cout << "  \"" << word << "\" is ";
        if (isPalindrome(word)) {
            std::cout << "a palindrome" << std::endl;
        } else {
            std::cout << "NOT a palindrome" << std::endl;
        }
    }
    
    std::cout << std::endl << "Method 2: Reverse and compare" << std::endl;
    for (const std::string& word : testWords) {
        std::cout << "  \"" << word << "\" is ";
        if (isPalindromeReverse(word)) {
            std::cout << "a palindrome" << std::endl;
        } else {
            std::cout << "NOT a palindrome" << std::endl;
        }
    }
    
    return 0;
}

/*
 * Learning Points:
 * 1. String manipulation and character processing
 * 2. Two-pointer technique for string comparison
 * 3. Using std::isalnum() and std::tolower()
 * 4. String reversal with std::reverse()
 * 5. Cleaning and normalizing input data
 * 
 * Enhancements to try:
 * - Add user input to test custom strings
 * - Handle Unicode characters
 * - Check for numeric palindromes
 * - Find the longest palindrome in a string
 * - Case-sensitive palindrome checking
 */
