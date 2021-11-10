# CASBACnetStackCompileTest
# https://github.com/chipkin/CompilerTestCASBACnetStack
# Last updated: 2021-Nov-10
# 

NAME := CASBACnetStackCompileTest
CXX := g++

CFLAGS += -g -O2 -Wall -W -pedantic
CXXFLAGS=$(CFLAGS) -std=c++11
CFLAGS += 
LDFLAGS += -lstdc++

# Build Target
TARGET = $(NAME)
all: $(NAME)

$(NAME): CASBACnetStackCompileTest.cpp
	@echo 'Building target: $@'
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(NAME) CASBACnetStackCompileTest.cpp
	@echo 'Finished building target: $@'
	@echo ' '

# make clean
clean:
	$(RM) $(NAME) 
