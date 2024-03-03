CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++23 -march=native -O3
NCURSES_LIBS := -lncurses

TARGET := demo

SRC := misc/menu_demo.cpp src/menu.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(NCURSES_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
