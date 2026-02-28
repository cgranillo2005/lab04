// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Helper function that gives us heap property
void heapifyDown(std::vector<int>& v, int i) {
  int minIndex = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < v.size() && v[left] < v[minIndex]) minIndex = left;
  if (right < v.size() && v[right] < v[minIndex]) minIndex = right;

  if (i != minIndex) {
    std::swap(v[i], v[minIndex]);
    heapifyDown(v, minIndex);
  }
}

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) : vdata(start, end) {
  if (vdata.empty()) return;
  for (int i = (vdata.size() / 2) - 1; i >= 0; i--) {
    heapifyDown(vdata, i);
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int i = vdata.size() - 1;

  while (i != 0 && vdata[(i - 1) / 2] > vdata[i]) {
    std::swap(vdata[i], vdata[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) return;

  vdata[0] = vdata.back();
  vdata.pop_back();
  
  if (!vdata.empty()) {
    heapifyDown(vdata, 0);
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty()) {
    throw std::out_of_range("Heap is empty");
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    