/**
 * Smart Pointers - Modern Memory Management
 * 
 * Learn about C++11's smart pointers for automatic memory management.
 * 
 * Compile: g++ -std=c++17 -Wall -o smart_ptrs smart_pointers.cpp
 * Run: ./smart_ptrs
 */

#include <iostream>
#include <memory>  // For smart pointers
#include <string>
#include <vector>

// Example class to track object creation/destruction
class Resource {
private:
    std::string name;
    static int instanceCount;

public:
    Resource(std::string n) : name(n) {
        instanceCount++;
        std::cout << "  [+] Resource '" << name << "' created (total: " << instanceCount << ")" << std::endl;
    }
    
    ~Resource() {
        instanceCount--;
        std::cout << "  [-] Resource '" << name << "' destroyed (remaining: " << instanceCount << ")" << std::endl;
    }
    
    void use() const {
        std::cout << "  Using resource: " << name << std::endl;
    }
    
    std::string getName() const { return name; }
};

int Resource::instanceCount = 0;

int main() {
    std::cout << "=== Smart Pointers in C++ ===" << std::endl << std::endl;
    
    // ===== UNIQUE_PTR =====
    std::cout << "1. unique_ptr (Exclusive Ownership):" << std::endl;
    {
        // Create unique_ptr - owns the resource exclusively
        std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>("unique1");
        ptr1->use();
        
        // Cannot copy unique_ptr
        // std::unique_ptr<Resource> ptr2 = ptr1;  // ERROR!
        
        // Can move ownership
        std::unique_ptr<Resource> ptr2 = std::move(ptr1);
        
        if (ptr1 == nullptr) {
            std::cout << "  ptr1 is now null after move" << std::endl;
        }
        
        ptr2->use();
        
        // Automatic cleanup when going out of scope
        std::cout << "  Leaving unique_ptr scope..." << std::endl;
    }
    std::cout << "  unique_ptr automatically destroyed" << std::endl << std::endl;
    
    // ===== SHARED_PTR =====
    std::cout << "2. shared_ptr (Shared Ownership):" << std::endl;
    {
        std::shared_ptr<Resource> sharedPtr1 = std::make_shared<Resource>("shared1");
        std::cout << "  Reference count: " << sharedPtr1.use_count() << std::endl;
        
        {
            // Can copy shared_ptr - increases reference count
            std::shared_ptr<Resource> sharedPtr2 = sharedPtr1;
            std::cout << "  Reference count after copy: " << sharedPtr1.use_count() << std::endl;
            
            sharedPtr2->use();
            
            std::cout << "  Leaving inner scope..." << std::endl;
        }
        
        std::cout << "  Reference count after inner scope: " << sharedPtr1.use_count() << std::endl;
        std::cout << "  Leaving outer scope..." << std::endl;
    }
    std::cout << "  shared_ptr automatically destroyed when ref count reaches 0" << std::endl << std::endl;
    
    // ===== WEAK_PTR =====
    std::cout << "3. weak_ptr (Non-owning Observer):" << std::endl;
    {
        std::shared_ptr<Resource> sharedPtr = std::make_shared<Resource>("observed");
        std::weak_ptr<Resource> weakPtr = sharedPtr;  // Doesn't increase ref count
        
        std::cout << "  shared_ptr use_count: " << sharedPtr.use_count() << std::endl;
        
        if (auto locked = weakPtr.lock()) {  // Convert weak_ptr to shared_ptr
            std::cout << "  Resource still exists" << std::endl;
            locked->use();
        }
        
        sharedPtr.reset();  // Destroy the resource
        
        if (weakPtr.expired()) {
            std::cout << "  Resource has been destroyed" << std::endl;
        }
    }
    std::cout << std::endl;
    
    // ===== PRACTICAL EXAMPLE: UNIQUE_PTR WITH VECTOR =====
    std::cout << "4. Smart Pointers in Containers:" << std::endl;
    {
        std::vector<std::unique_ptr<Resource>> resources;
        
        resources.push_back(std::make_unique<Resource>("resource1"));
        resources.push_back(std::make_unique<Resource>("resource2"));
        resources.push_back(std::make_unique<Resource>("resource3"));
        
        std::cout << "  Iterating through resources:" << std::endl;
        for (const auto& res : resources) {
            res->use();
        }
        
        std::cout << "  Leaving scope..." << std::endl;
    }
    std::cout << "  All resources automatically cleaned up" << std::endl << std::endl;
    
    // ===== CUSTOM DELETER =====
    std::cout << "5. Custom Deleters:" << std::endl;
    {
        auto customDeleter = [](Resource* r) {
            std::cout << "  Custom deleter called for " << r->getName() << std::endl;
            delete r;
        };
        
        std::unique_ptr<Resource, decltype(customDeleter)> ptr(
            new Resource("custom_delete"),
            customDeleter
        );
        
        std::cout << "  Leaving scope..." << std::endl;
    }
    std::cout << std::endl;
    
    // ===== COMPARISON WITH RAW POINTERS =====
    std::cout << "6. Why Smart Pointers?" << std::endl;
    std::cout << "  ✓ Automatic memory management" << std::endl;
    std::cout << "  ✓ Exception-safe" << std::endl;
    std::cout << "  ✓ No memory leaks" << std::endl;
    std::cout << "  ✓ Clear ownership semantics" << std::endl;
    std::cout << "  ✓ No double-delete errors" << std::endl;
    
    return 0;
}

/*
 * Key Concepts:
 * 1. std::unique_ptr - exclusive ownership, cannot be copied
 * 2. std::shared_ptr - shared ownership, reference counted
 * 3. std::weak_ptr - non-owning observer, doesn't affect ref count
 * 4. std::make_unique and std::make_shared (preferred way)
 * 5. Automatic cleanup when going out of scope
 * 6. move semantics with unique_ptr
 * 7. Reference counting with shared_ptr
 * 8. Custom deleters for special cleanup logic
 * 
 * Best Practices:
 * - Prefer unique_ptr by default
 * - Use shared_ptr only when truly needed
 * - Use weak_ptr to break circular references
 * - Use make_unique/make_shared for exception safety
 * - Avoid raw new/delete in modern C++
 * 
 * Try it yourself:
 * - Create a linked list using unique_ptr
 * - Implement a simple object pool with shared_ptr
 * - Create a circular reference and break it with weak_ptr
 * - Use smart pointers with inheritance
 */
