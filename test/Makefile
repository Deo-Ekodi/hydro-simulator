# compiler
CXX = g++

# compiler flags
CXXFLAGS = -g -std=c++23 -Wall -Wextra -pedantic

# executable
TARGET = input

# source files
SRCS = main.cpp inputHandler.cpp wwm.cpp

# object files : derived from source files
OBJS = $(SRCS:.cpp=.o)

# link object files to final executable
$(TARGET): $(OBJS)	
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	
# compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	clear