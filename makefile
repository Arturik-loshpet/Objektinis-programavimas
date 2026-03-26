CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = programa
SRC = main.cpp objektinis_patikrinimai.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
