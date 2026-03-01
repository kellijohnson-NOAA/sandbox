/**
 * Pointers and References - Memory Management Fundamentals
 * 
 * Learn about pointers, references, and dynamic memory allocation.
 * 
 * Compile: g++ -std=c++17 -Wall -o pointers pointers_references.cpp
 * Run: ./pointers
 */

#include <iostream>
#include <string>

int main() {
    std::cout << "=== Pointers and References in C++ ===" << std::endl << std::endl;
    
    // ===== BASIC POINTERS =====
    std::cout << "1. Basic Pointers:" << std::endl;
    
    int number = 42;
    int* ptr = &number;  // Pointer to number (& = address-of operator)
    
    std::cout << "  number = " << number << std::endl;
    std::cout << "  address of number = " << &number << std::endl;
    std::cout << "  ptr = " << ptr << std::endl;
    std::cout << "  *ptr (dereferenced) = " << *ptr << std::endl;
    
    // Modifying through pointer
    *ptr = 100;
    std::cout << "  After *ptr = 100, number = " << number << std::endl;
    std::cout << std::endl;
    
    // ===== REFERENCES =====
    std::cout << "2. References:" << std::endl;
    
    int original = 10;
    int& ref = original;  // Reference to original (alias)
    
    std::cout << "  original = " << original << std::endl;
    std::cout << "  ref = " << ref << std::endl;
    
    ref = 20;  // Modifying through reference
    std::cout << "  After ref = 20, original = " << original << std::endl;
    std::cout << std::endl;
    
    // ===== POINTER VS REFERENCE =====
    std::cout << "3. Pointer vs Reference:" << std::endl;
    
    int a = 5, b = 10;
    int* ptrVar = &a;  // Pointer can be reassigned
    int& refVar = a;   // Reference cannot be reassigned
    
    std::cout << "  Initial: a=" << a << ", b=" << b << std::endl;
    
    ptrVar = &b;  // Point to different variable
    std::cout << "  After ptrVar = &b, *ptrVar = " << *ptrVar << std::endl;
    
    // refVar = b;  // This doesn't reassign reference, it copies b's value to a
    std::cout << std::endl;
    
    // ===== NULL POINTERS =====
    std::cout << "4. Null Pointers:" << std::endl;
    
    int* nullPtr = nullptr;  // Modern C++ (C++11)
    // int* oldNull = NULL;  // Old style (avoid)
    
    if (nullPtr == nullptr) {
        std::cout << "  nullPtr is null" << std::endl;
    }
    
    // Always check before dereferencing!
    if (nullPtr != nullptr) {
        std::cout << "  *nullPtr = " << *nullPtr << std::endl;
    } else {
        std::cout << "  Cannot dereference null pointer" << std::endl;
    }
    std::cout << std::endl;
    
    // ===== DYNAMIC MEMORY ALLOCATION =====
    std::cout << "5. Dynamic Memory (new/delete):" << std::endl;
    
    // Allocate single integer
    int* dynamicInt = new int(42);
    std::cout << "  Dynamic int: " << *dynamicInt << std::endl;
    
    // Allocate array
    int* dynamicArray = new int[5];
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i * 10;
    }
    
    std::cout << "  Dynamic array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;
    
    // IMPORTANT: Always delete what you new!
    delete dynamicInt;
    delete[] dynamicArray;  // Use delete[] for arrays
    
    std::cout << "  Memory cleaned up" << std::endl;
    std::cout << std::endl;
    
    // ===== POINTERS AND ARRAYS =====
    std::cout << "6. Pointers and Arrays:" << std::endl;
    
    int arr[5] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;  // Array name is a pointer to first element
    
    std::cout << "  Using array notation: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "  Using pointer arithmetic: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(arrPtr + i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    // ===== CONST POINTERS =====
    std::cout << "7. Const Pointers:" << std::endl;
    
    int value1 = 10, value2 = 20;
    
    // Pointer to const int (can't modify value through pointer)
    const int* ptrToConst = &value1;
    std::cout << "  ptrToConst: " << *ptrToConst << std::endl;
    // *ptrToConst = 15;  // ERROR: can't modify
    ptrToConst = &value2;  // OK: can reassign pointer
    
    // Const pointer to int (can't reassign pointer)
    int* const constPtr = &value1;
    *constPtr = 15;  // OK: can modify value
    std::cout << "  constPtr after modification: " << *constPtr << std::endl;
    // constPtr = &value2;  // ERROR: can't reassign pointer
    
    // Const pointer to const int (can't modify value or reassign pointer)
    const int* const constPtrToConst = &value1;
    // *constPtrToConst = 25;  // ERROR
    // constPtrToConst = &value2;  // ERROR
    
    std::cout << std::endl;
    
    // ===== FUNCTION POINTERS =====
    std::cout << "8. Passing Pointers and References:" << std::endl;
    
    // Example of why we use pointers/references
    auto modifyByValue = [](int x) { x = 100; };
    auto modifyByPointer = [](int* x) { *x = 100; };
    auto modifyByReference = [](int& x) { x = 100; };
    
    int testVal = 50;
    modifyByValue(testVal);
    std::cout << "  After modifyByValue: " << testVal << std::endl;
    
    modifyByPointer(&testVal);
    std::cout << "  After modifyByPointer: " << testVal << std::endl;
    
    testVal = 50;
    modifyByReference(testVal);
    std::cout << "  After modifyByReference: " << testVal << std::endl;
    
    return 0;
}

/*
 * Key Concepts:
 * 1. Pointers store memory addresses
 * 2. & operator gets address, * dereferences pointer
 * 3. References are aliases to variables
 * 4. nullptr for null pointers (modern C++)
 * 5. new/delete for dynamic memory
 * 6. delete[] for dynamically allocated arrays
 * 7. Pointer arithmetic
 * 8. const pointers and pointers to const
 * 9. Passing by pointer vs reference
 * 
 * Important Rules:
 * - Always initialize pointers
 * - Check for nullptr before dereferencing
 * - Delete what you new (avoid memory leaks)
 * - Use smart pointers in modern C++ (see advanced examples)
 * 
 * Try it yourself:
 * - Create a function that swaps two values using pointers
 * - Implement a simple linked list node with pointers
 * - Experiment with double pointers (int**)
 * - Practice with const correctness
 */
