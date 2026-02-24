# Quick Start Guide - C++ Learning

Get started with C++ in 5 minutes!

## Prerequisites

You need a C++ compiler. Check if you have one:

```bash
g++ --version
# or
clang++ --version
```

If you don't have a compiler:
- **Linux/Ubuntu**: `sudo apt-get install g++`
- **macOS**: Install Xcode Command Line Tools: `xcode-select --install`
- **Windows**: Install MinGW or Visual Studio

## Your First Steps

### 1. Navigate to the learning directory

```bash
cd cpp-learning
```

### 2. Compile your first program

```bash
g++ -std=c++17 -Wall -o hello 01-basics/hello_world.cpp
./hello
```

You should see:
```
Hello, World!
Welcome to C++ programming!
Learning C++ is fun and rewarding!
```

### 3. Use the Makefile for easier compilation

Compile all examples:
```bash
make all
```

Run all basic examples:
```bash
make run-basics
```

### 4. Start Learning!

Work through the examples in order:

#### Week 1: Basics (01-basics/)
- Day 1: `hello_world.cpp` - Get started
- Day 2: `variables_types.cpp` - Learn about data types
- Day 3: `control_flow.cpp` - If statements and loops
- Day 4: `functions.cpp` - Write reusable code

#### Week 2: Intermediate (02-intermediate/)
- Day 1: `classes_objects.cpp` - Object-oriented programming
- Day 2: `stl_vectors.cpp` - Dynamic arrays
- Day 3: `pointers_references.cpp` - Memory management

#### Week 3: Advanced (03-advanced/)
- Day 1: `smart_pointers.cpp` - Modern memory management
- Day 2: `lambda_expressions.cpp` - Anonymous functions
- Day 3: `templates.cpp` - Generic programming

#### Week 4: Practice (04-exercises/)
- Solve the exercises
- Build your own projects
- Experiment and explore!

## Workflow Tips

### 1. Read → Compile → Run → Experiment

```bash
# Read the code first
cat 01-basics/hello_world.cpp

# Compile it
g++ -std=c++17 -Wall -o hello 01-basics/hello_world.cpp

# Run it
./hello

# Modify and experiment!
```

### 2. Using an IDE

Popular C++ IDEs:
- **VS Code** with C++ extensions (recommended for beginners)
- **CLion** by JetBrains (powerful, free for students)
- **Code::Blocks** (lightweight, free)
- **Visual Studio** (Windows, feature-rich)

### 3. Debugging

Add debug output:
```cpp
std::cout << "Debug: x = " << x << std::endl;
```

Use a debugger:
```bash
g++ -g -std=c++17 hello_world.cpp -o hello
gdb ./hello
```

### 4. Common Errors and Solutions

**Error: "iostream: No such file"**
- Solution: Make sure you have `#include <iostream>` at the top

**Error: "undefined reference to 'main'"**
- Solution: Every C++ program needs a `main()` function

**Compilation warnings**
- Solution: Fix them! Warnings often indicate real problems

## Next Steps

1. **Complete all basic examples** - Don't skip ahead!
2. **Try the exercises** - Practice makes perfect
3. **Build small projects** - Apply what you learn
4. **Read other people's code** - Learn from examples
5. **Join the community** - Ask questions, help others

## Resources

- This repository: Start here!
- [cppreference.com](https://en.cppreference.com/) - Language reference
- [learncpp.com](https://www.learncpp.com/) - Tutorial
- [Stack Overflow](https://stackoverflow.com/questions/tagged/c++) - Q&A

## Need Help?

- Read the comments in the code examples
- Check the "Try it yourself" sections
- Experiment with modifications
- Search for error messages online
- Break problems into smaller pieces

## Congratulations!

You're ready to start your C++ journey! 🚀

Remember: **Every expert was once a beginner.**

Happy coding! 💻
