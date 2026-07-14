# sandbox
A test bed for trying things out.

## C++ Learning Resources

This repository now includes a structured C++ learning path to help you improve your C++ programming skills!

### 📚 Directory Structure

```
cpp-learning/
├── 01-basics/          # Fundamental C++ concepts
├── 02-intermediate/    # Object-oriented programming and STL
├── 03-advanced/        # Advanced topics and modern C++ features
└── 04-exercises/       # Practice problems with solutions
```

### 🚀 Getting Started

#### Prerequisites
- A C++ compiler (g++, clang++, or MSVC)
- Make (optional, for using the Makefile)

#### Compiling and Running Examples

**Option 1: Using Make (Recommended)**
```bash
cd cpp-learning
make all          # Compile all examples
make run-basics   # Run basic examples
make run-inter    # Run intermediate examples
make run-advanced # Run advanced examples
make clean        # Remove compiled files
```

**Option 2: Manual Compilation**
```bash
# Compile a single file
g++ -std=c++17 -Wall -o program 01-basics/hello_world.cpp

# Run the program
./program
```

### 📖 Learning Path

#### 1. Basics (Start Here!)
- **hello_world.cpp** - Your first C++ program
- **variables_types.cpp** - Data types and variables
- **input_output.cpp** - Console I/O operations
- **control_flow.cpp** - if/else, loops, switch
- **functions.cpp** - Function declarations and definitions
- **arrays_strings.cpp** - Arrays and string handling

#### 2. Intermediate
- **classes_objects.cpp** - Object-oriented programming basics
- **constructors_destructors.cpp** - Object lifecycle management
- **inheritance.cpp** - Class inheritance and polymorphism
- **stl_vectors.cpp** - Standard Template Library vectors
- **stl_maps.cpp** - Maps and associative containers
- **file_io.cpp** - File reading and writing
- **pointers_references.cpp** - Memory management fundamentals

#### 3. Advanced
- **templates.cpp** - Generic programming with templates
- **smart_pointers.cpp** - Modern memory management
- **lambda_expressions.cpp** - Anonymous functions
- **move_semantics.cpp** - Efficient resource management
- **multithreading.cpp** - Concurrent programming basics
- **design_patterns.cpp** - Common design patterns

#### 4. Exercises
Practice problems with solutions to test your knowledge!

### 💡 Tips for Learning

1. **Start with basics** - Don't skip ahead too quickly
2. **Type the code yourself** - Don't just copy-paste
3. **Experiment** - Modify examples and see what happens
4. **Read compiler errors** - They're your friends!
5. **Practice regularly** - Consistency is key
6. **Use C++17 or later** - Modern C++ is easier and safer

### 📚 Additional Resources

- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ reference
- [learncpp.com](https://www.learncpp.com/) - Free C++ tutorial
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) - Best practices

### 🎯 Next Steps

1. Start with `01-basics/hello_world.cpp`
2. Work through each example in order
3. Try the exercises in `04-exercises/`
4. Experiment with your own projects!

Happy coding! 🚀
