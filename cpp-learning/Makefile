# Makefile for C++ Learning Examples
# Supports easy compilation and running of all examples

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
BUILD_DIR = build

# Basics
BASICS_DIR = 01-basics
BASICS_SRCS = $(wildcard $(BASICS_DIR)/*.cpp)
BASICS_BINS = $(patsubst $(BASICS_DIR)/%.cpp,$(BUILD_DIR)/%,$(BASICS_SRCS))

# Intermediate
INTER_DIR = 02-intermediate
INTER_SRCS = $(wildcard $(INTER_DIR)/*.cpp)
INTER_BINS = $(patsubst $(INTER_DIR)/%.cpp,$(BUILD_DIR)/%,$(INTER_SRCS))

# Advanced
ADV_DIR = 03-advanced
ADV_SRCS = $(wildcard $(ADV_DIR)/*.cpp)
ADV_BINS = $(patsubst $(ADV_DIR)/%.cpp,$(BUILD_DIR)/%,$(ADV_SRCS))

# Exercises
EX_DIR = 04-exercises
EX_SRCS = $(wildcard $(EX_DIR)/*.cpp)
EX_BINS = $(patsubst $(EX_DIR)/%.cpp,$(BUILD_DIR)/%,$(EX_SRCS))

ALL_BINS = $(BASICS_BINS) $(INTER_BINS) $(ADV_BINS) $(EX_BINS)

# Default target
all: $(BUILD_DIR) $(ALL_BINS)
	@echo "All examples compiled successfully!"
	@echo "Run 'make run-basics', 'make run-inter', or 'make run-advanced' to execute examples"

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Compile basics
$(BUILD_DIR)/%: $(BASICS_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $@

# Compile intermediate
$(BUILD_DIR)/%: $(INTER_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $@

# Compile advanced
$(BUILD_DIR)/%: $(ADV_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $@

# Compile exercises
$(BUILD_DIR)/%: $(EX_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $@

# Run targets
.PHONY: run-basics
run-basics: $(BASICS_BINS)
	@echo "\n=== Running Basic Examples ==="
	@for bin in $(BASICS_BINS); do \
		if [ -f $$bin ]; then \
			echo "\n--- Running $$bin ---"; \
			$$bin; \
		fi \
	done

.PHONY: run-inter
run-inter: $(INTER_BINS)
	@echo "\n=== Running Intermediate Examples ==="
	@for bin in $(INTER_BINS); do \
		if [ -f $$bin ]; then \
			echo "\n--- Running $$bin ---"; \
			$$bin; \
		fi \
	done

.PHONY: run-advanced
run-advanced: $(ADV_BINS)
	@echo "\n=== Running Advanced Examples ==="
	@for bin in $(ADV_BINS); do \
		if [ -f $$bin ]; then \
			echo "\n--- Running $$bin ---"; \
			$$bin; \
		fi \
	done

.PHONY: run-exercises
run-exercises: $(EX_BINS)
	@echo "\n=== Running Exercises ==="
	@for bin in $(EX_BINS); do \
		if [ -f $$bin ]; then \
			echo "\n--- Running $$bin ---"; \
			$$bin; \
		fi \
	done

# Clean
.PHONY: clean
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete!"

# Help
.PHONY: help
help:
	@echo "C++ Learning Makefile"
	@echo ""
	@echo "Usage:"
	@echo "  make              - Compile all examples"
	@echo "  make run-basics   - Run all basic examples"
	@echo "  make run-inter    - Run all intermediate examples"
	@echo "  make run-advanced - Run all advanced examples"
	@echo "  make run-exercises - Run all exercise solutions"
	@echo "  make clean        - Remove all compiled files"
	@echo "  make help         - Show this help message"
