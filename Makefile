CXX = g++

CXXFLAGS = -Wall -g -std=c++20

TARGET = examheap

$(TARGET): examheap.cpp heap.cpp
	$(CXX) $(CXXFLAGS) examheap.cpp heap.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)