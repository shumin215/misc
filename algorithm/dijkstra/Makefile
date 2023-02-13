.SUFFIXES : .cc .cpp .o

# Compiler
CXX = g++

# Compiler options
CXXFLAGS = -W -Wall -std=c++14

# Linker
LD = ld 

# Linker options
LDFLAGS =

# Source directory
SRC_DIR = ./src

# Object directory
OBJ_DIR = ./obj

# Include path
INC = -Iinclude/

# Libraries
LIBS =

# Source files
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))

# Object files
OBJS = $(SRCS:.cpp=.o)
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))

# Dependency check files
DEPS = $(SRCS:.cpp=.d)
DEPS = $(OBJECTS:.o=.d)

# Target binary
TARGET := a.out

.PHONY: clean all

all: $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)
