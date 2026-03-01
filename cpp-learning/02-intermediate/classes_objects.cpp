/**
 * Classes and Objects - Object-Oriented Programming
 * 
 * Learn the fundamentals of OOP in C++.
 * 
 * Compile: g++ -std=c++17 -Wall -o classes classes_objects.cpp
 * Run: ./classes
 */

#include <iostream>
#include <string>

// Class definition
class BankAccount {
private:  // Private members (encapsulation)
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:  // Public interface
    // Constructor
    BankAccount(std::string accNum, std::string name, double initialBalance) {
        accountNumber = accNum;
        ownerName = name;
        balance = initialBalance;
    }
    
    // Getter methods (accessors)
    std::string getAccountNumber() const {
        return accountNumber;
    }
    
    std::string getOwnerName() const {
        return ownerName;
    }
    
    double getBalance() const {
        return balance;
    }
    
    // Setter methods (mutators)
    void setOwnerName(std::string name) {
        ownerName = name;
    }
    
    // Member functions (methods)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "  Deposited $" << amount << std::endl;
        } else {
            std::cout << "  Invalid deposit amount!" << std::endl;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "  Withdrew $" << amount << std::endl;
            return true;
        } else {
            std::cout << "  Insufficient funds or invalid amount!" << std::endl;
            return false;
        }
    }
    
    void displayInfo() const {
        std::cout << "  Account: " << accountNumber << std::endl;
        std::cout << "  Owner: " << ownerName << std::endl;
        std::cout << "  Balance: $" << balance << std::endl;
    }
};

// Another class example
class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor with default parameters
    Rectangle(double w = 1.0, double h = 1.0) : width(w), height(h) {}
    
    // Inline methods
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    void setWidth(double w) {
        if (w > 0) width = w;
    }
    
    void setHeight(double h) {
        if (h > 0) height = h;
    }
    
    double calculateArea() const {
        return width * height;
    }
    
    double calculatePerimeter() const {
        return 2 * (width + height);
    }
    
    bool isSquare() const {
        return width == height;
    }
};

int main() {
    std::cout << "=== Classes and Objects in C++ ===" << std::endl << std::endl;
    
    // ===== CREATING OBJECTS =====
    std::cout << "1. Creating Objects:" << std::endl;
    BankAccount myAccount("123456", "John Doe", 1000.0);
    myAccount.displayInfo();
    std::cout << std::endl;
    
    // ===== CALLING METHODS =====
    std::cout << "2. Calling Methods:" << std::endl;
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.displayInfo();
    std::cout << std::endl;
    
    // ===== USING GETTERS AND SETTERS =====
    std::cout << "3. Using Getters and Setters:" << std::endl;
    std::cout << "  Current owner: " << myAccount.getOwnerName() << std::endl;
    myAccount.setOwnerName("Jane Doe");
    std::cout << "  Updated owner: " << myAccount.getOwnerName() << std::endl;
    std::cout << std::endl;
    
    // ===== CREATING MULTIPLE OBJECTS =====
    std::cout << "4. Multiple Objects:" << std::endl;
    Rectangle rect1(5.0, 3.0);
    Rectangle rect2(4.0, 4.0);
    
    std::cout << "  Rectangle 1:" << std::endl;
    std::cout << "    Dimensions: " << rect1.getWidth() << " x " << rect1.getHeight() << std::endl;
    std::cout << "    Area: " << rect1.calculateArea() << std::endl;
    std::cout << "    Perimeter: " << rect1.calculatePerimeter() << std::endl;
    std::cout << "    Is square? " << (rect1.isSquare() ? "Yes" : "No") << std::endl;
    
    std::cout << "  Rectangle 2:" << std::endl;
    std::cout << "    Dimensions: " << rect2.getWidth() << " x " << rect2.getHeight() << std::endl;
    std::cout << "    Area: " << rect2.calculateArea() << std::endl;
    std::cout << "    Is square? " << (rect2.isSquare() ? "Yes" : "No") << std::endl;
    
    return 0;
}

/*
 * Key Concepts:
 * 1. Class definition with private and public members
 * 2. Constructors for object initialization
 * 3. Member variables (attributes)
 * 4. Member functions (methods)
 * 5. Getters and setters for encapsulation
 * 6. const member functions (don't modify object)
 * 7. Member initializer lists in constructors
 * 8. Creating and using multiple objects
 * 
 * Try it yourself:
 * - Add a transfer() method to BankAccount
 * - Create a Circle class with radius and area calculation
 * - Add validation to prevent negative dimensions
 * - Create a Student class with name, ID, and GPA
 * - Experiment with static members
 */
