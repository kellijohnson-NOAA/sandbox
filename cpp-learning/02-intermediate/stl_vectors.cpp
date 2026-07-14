/**
 * STL Vectors - Dynamic Arrays
 * 
 * Learn about the Standard Template Library's vector container.
 * 
 * Compile: g++ -std=c++17 -Wall -o vectors stl_vectors.cpp
 * Run: ./vectors
 */

#include <iostream>
#include <vector>
#include <algorithm>  // For sort, find, etc.
#include <numeric>    // For accumulate

int main() {
    std::cout << "=== STL Vectors in C++ ===" << std::endl << std::endl;
    
    // ===== CREATING VECTORS =====
    std::cout << "1. Creating Vectors:" << std::endl;
    
    // Empty vector
    std::vector<int> vec1;
    
    // Vector with initial values
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    
    // Vector with size and default value
    std::vector<int> vec3(5, 10);  // 5 elements, all 10
    
    // Vector of strings
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
    
    std::cout << "  vec2: ";
    for (int num : vec2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "  vec3: ";
    for (int num : vec3) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== ADDING ELEMENTS =====
    std::cout << "2. Adding Elements:" << std::endl;
    
    std::vector<int> numbers;
    numbers.push_back(10);  // Add to end
    numbers.push_back(20);
    numbers.push_back(30);
    
    std::cout << "  After push_back: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Insert at specific position
    numbers.insert(numbers.begin() + 1, 15);  // Insert 15 at index 1
    
    std::cout << "  After insert: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== ACCESSING ELEMENTS =====
    std::cout << "3. Accessing Elements:" << std::endl;
    
    std::vector<int> data = {100, 200, 300, 400, 500};
    
    std::cout << "  Using []: data[0] = " << data[0] << std::endl;
    std::cout << "  Using at(): data.at(2) = " << data.at(2) << std::endl;
    std::cout << "  First element: " << data.front() << std::endl;
    std::cout << "  Last element: " << data.back() << std::endl;
    std::cout << std::endl;
    
    // ===== VECTOR SIZE AND CAPACITY =====
    std::cout << "4. Size and Capacity:" << std::endl;
    
    std::cout << "  Size: " << data.size() << std::endl;
    std::cout << "  Capacity: " << data.capacity() << std::endl;
    std::cout << "  Empty? " << (data.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
    
    // ===== REMOVING ELEMENTS =====
    std::cout << "5. Removing Elements:" << std::endl;
    
    std::vector<int> nums = {1, 2, 3, 4, 5};
    
    nums.pop_back();  // Remove last element
    std::cout << "  After pop_back: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    nums.erase(nums.begin() + 1);  // Remove element at index 1
    std::cout << "  After erase: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    nums.clear();  // Remove all elements
    std::cout << "  After clear, size: " << nums.size() << std::endl;
    std::cout << std::endl;
    
    // ===== ITERATING THROUGH VECTORS =====
    std::cout << "6. Iteration Methods:" << std::endl;
    
    std::vector<int> values = {10, 20, 30, 40, 50};
    
    // Range-based for loop (C++11)
    std::cout << "  Range-based for: ";
    for (int val : values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // Iterator
    std::cout << "  Using iterator: ";
    for (auto it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Index-based
    std::cout << "  Index-based: ";
    for (size_t i = 0; i < values.size(); i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== ALGORITHMS WITH VECTORS =====
    std::cout << "7. Algorithms:" << std::endl;
    
    std::vector<int> unsorted = {50, 20, 60, 10, 30, 40};
    
    std::cout << "  Original: ";
    for (int num : unsorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Sort
    std::sort(unsorted.begin(), unsorted.end());
    std::cout << "  Sorted: ";
    for (int num : unsorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Reverse
    std::reverse(unsorted.begin(), unsorted.end());
    std::cout << "  Reversed: ";
    for (int num : unsorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Find
    auto found = std::find(unsorted.begin(), unsorted.end(), 30);
    if (found != unsorted.end()) {
        std::cout << "  Found 30 at index: " << (found - unsorted.begin()) << std::endl;
    }
    
    // Sum
    int sum = std::accumulate(unsorted.begin(), unsorted.end(), 0);
    std::cout << "  Sum: " << sum << std::endl;
    
    return 0;
}

/*
 * Key Concepts:
 * 1. Vector creation and initialization
 * 2. Adding elements: push_back(), insert()
 * 3. Accessing elements: [], at(), front(), back()
 * 4. Removing elements: pop_back(), erase(), clear()
 * 5. Size vs capacity
 * 6. Different iteration methods
 * 7. STL algorithms: sort, reverse, find, accumulate
 * 8. Iterators and their usage
 * 
 * Try it yourself:
 * - Create a vector of custom objects
 * - Implement a function to remove duplicates
 * - Find min and max elements
 * - Create a 2D vector (vector of vectors)
 * - Use std::count_if with a lambda function
 */
