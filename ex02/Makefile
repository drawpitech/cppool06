##
## EPITECH PROJECT, 2024
## MyCat
## File description:
## Makefile
##

CXX := g++ -std=c++20
CXXFLAGS := -W -Wall -Wextra -Wunused -Wpedantic
CXXFLAGS += -Wundef -Wshadow -Wcast-align
CXXFLAGS += -Waggregate-return -Wcast-qual
CXXFLAGS += -Wunreachable-code
CXXFLAGS += -U_FORTIFY_SOURCE
CXXFLAGS += -iquote ./.
LDFLAGS :=

NAME := StupidUnitConverter

VPATH := .
SRC := StupidUnitConverter.cpp

BUILD_DIR := .build
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(BUILD_DIR)/%.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

.PHONY: $(NAME)

re: fclean
	$(MAKE)

.PHONY: re

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) -r $(BUILD_DIR)
	$(RM) $(NAME)

.PHONY: clean fclean
