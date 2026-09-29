CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = calculator
LIB = libcalculator.a

all: $(TARGET)

calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculator.cpp -o calculator.o

main.o: main.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

$(LIB): calculator.o
	ar rcs $(LIB) calculator.o

$(TARGET): main.o $(LIB)
	$(CXX) $(CXXFLAGS) main.o -L. -lcalculator -o $(TARGET)

clean:
	rm -f *.o *.a $(TARGET)