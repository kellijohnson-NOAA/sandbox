/**
 * Templates - Generic Programming
 * 
 * Learn about C++ templates for writing generic, reusable code.
 * 
 * Compile: g++ -std=c++17 -Wall -o templates templates.cpp
 * Run: ./templates
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// ===== FUNCTION TEMPLATES =====

// Simple function template
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple type parameters
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Template with non-type parameter
template<typename T, int N>
void printArray(T (&arr)[N]) {
    std::cout << "  Array[" << N << "]: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ===== CLASS TEMPLATES =====

// Simple class template
template<typename T>
class Box {
private:
    T content;

public:
    Box(T val) : content(val) {}
    
    T getContent() const { return content; }
    void setContent(T val) { content = val; }
    
    void display() const {
        std::cout << "  Box contains: " << content << std::endl;
    }
};

// Template class with multiple parameters
template<typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair(T f, U s) : first(f), second(s) {}
    
    T getFirst() const { return first; }
    U getSecond() const { return second; }
    
    void display() const {
        std::cout << "  Pair: (" << first << ", " << second << ")" << std::endl;
    }
};

// Template specialization
template<typename T>
class Container {
public:
    void info() {
        std::cout << "  Generic container" << std::endl;
    }
};

// Specialization for int
template<>
class Container<int> {
public:
    void info() {
        std::cout << "  Specialized container for integers" << std::endl;
    }
};

// ===== TEMPLATE STACK IMPLEMENTATION =====

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(T element) {
        elements.push_back(element);
    }
    
    T pop() {
        if (elements.empty()) {
            throw std::runtime_error("Stack is empty!");
        }
        T top = elements.back();
        elements.pop_back();
        return top;
    }
    
    T top() const {
        if (elements.empty()) {
            throw std::runtime_error("Stack is empty!");
        }
        return elements.back();
    }
    
    bool empty() const {
        return elements.empty();
    }
    
    size_t size() const {
        return elements.size();
    }
};

int main() {
    std::cout << "=== Templates in C++ ===" << std::endl << std::endl;
    
    // ===== FUNCTION TEMPLATES =====
    std::cout << "1. Function Templates:" << std::endl;
    
    std::cout << "  max(10, 20) = " << maximum(10, 20) << std::endl;
    std::cout << "  max(3.14, 2.71) = " << maximum(3.14, 2.71) << std::endl;
    std::cout << "  max('a', 'z') = " << maximum('a', 'z') << std::endl;
    
    // Explicit template argument
    std::cout << "  max<double>(5, 7.5) = " << maximum<double>(5, 7.5) << std::endl;
    std::cout << std::endl;
    
    // ===== MIXED TYPE TEMPLATES =====
    std::cout << "2. Mixed Type Templates:" << std::endl;
    
    std::cout << "  add(5, 3.14) = " << add(5, 3.14) << std::endl;
    std::cout << "  add(2.5, 10) = " << add(2.5, 10) << std::endl;
    std::cout << std::endl;
    
    // ===== NON-TYPE PARAMETERS =====
    std::cout << "3. Non-Type Template Parameters:" << std::endl;
    
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3};
    
    printArray(intArr);
    printArray(doubleArr);
    std::cout << std::endl;
    
    // ===== CLASS TEMPLATES =====
    std::cout << "4. Class Templates:" << std::endl;
    
    Box<int> intBox(42);
    Box<std::string> strBox("Hello");
    Box<double> doubleBox(3.14159);
    
    intBox.display();
    strBox.display();
    doubleBox.display();
    std::cout << std::endl;
    
    // ===== MULTIPLE TYPE PARAMETERS =====
    std::cout << "5. Multiple Type Parameters:" << std::endl;
    
    Pair<int, std::string> person(25, "Alice");
    Pair<std::string, double> product("Apple", 1.99);
    
    person.display();
    product.display();
    std::cout << std::endl;
    
    // ===== TEMPLATE SPECIALIZATION =====
    std::cout << "6. Template Specialization:" << std::endl;
    
    Container<double> genericCont;
    Container<int> intCont;
    
    genericCont.info();
    intCont.info();
    std::cout << std::endl;
    
    // ===== STACK IMPLEMENTATION =====
    std::cout << "7. Generic Stack:" << std::endl;
    
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    std::cout << "  Stack size: " << intStack.size() << std::endl;
    std::cout << "  Top element: " << intStack.top() << std::endl;
    
    std::cout << "  Popping: ";
    while (!intStack.empty()) {
        std::cout << intStack.pop() << " ";
    }
    std::cout << std::endl;
    
    Stack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");
    
    std::cout << "  String stack: ";
    while (!strStack.empty()) {
        std::cout << strStack.pop() << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ===== TEMPLATE WITH ALGORITHMS =====
    std::cout << "8. Templates with STL:" << std::endl;
    
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    auto minElement = *std::min_element(numbers.begin(), numbers.end());
    auto maxElement = *std::max_element(numbers.begin(), numbers.end());
    
    std::cout << "  Min: " << minElement << ", Max: " << maxElement << std::endl;
    
    return 0;
}

/*
 * Key Concepts:
 * 1. Function templates for generic functions
 * 2. Class templates for generic classes
 * 3. Template type parameters (typename/class)
 * 4. Non-type template parameters (int, size_t, etc.)
 * 5. Multiple template parameters
 * 6. Template specialization for specific types
 * 7. Template argument deduction
 * 8. Explicit template instantiation
 * 
 * Template Syntax:
 * - Function: template<typename T> T func(T param)
 * - Class: template<typename T> class ClassName
 * - Multiple: template<typename T, typename U>
 * - Non-type: template<typename T, int N>
 * 
 * Best Practices:
 * - Use templates for type-independent algorithms
 * - Provide meaningful error messages (concepts in C++20)
 * - Consider using auto for return types
 * - Use template specialization sparingly
 * 
 * Try it yourself:
 * - Create a generic swap function
 * - Implement a template-based min/max function
 * - Create a generic LinkedList class
 * - Implement a template-based binary search
 * - Create a template with default type parameters
 */
