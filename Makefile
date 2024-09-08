CXX := g++
CXXFLAGS := -g -std=c++23 -Wall -Wextra -O2 -Iinclude

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
EXEC := $(BIN_DIR)/hydro

# recursively locate all .cpp files under src/
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp')
# associate all .o files with their respective named .cpp files
OBJS := $(patsubst SRCS:$(SRC_DIR)/%.cpp,$(BUILD_DIR/%.o),$(SRCS))

all: $(EXEC)

# link .o files to final executable
$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $@

# compile all .cpp to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	clear

rebuild: clean all

.PHONY: all clean rebuild
