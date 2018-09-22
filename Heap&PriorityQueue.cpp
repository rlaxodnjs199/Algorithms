#include <iostream>
#include <vector>
#include <queue>
#include <functional>
template<typename T> void print_queue(T& q) {
  std::cout << "[ ";
  while (!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  }
  std::cout << "]" << std::endl;
}

template<typename T> void print_heap(T& h) {
  std::cout << "[ ";
  for (auto& n: h) {
    std::cout << n << " ";
  }
  std::cout << "]" << std::endl;
}

struct compare {
  bool operator() (int a, int b) {
    return a > b;
  }
};

int main() {
  std::priority_queue<int> nums1;
  for (int n : {1,3,5,7,9,11,2,6,8}) {
    nums1.push(n);
  }
  std::cout << nums1.top() << std::endl;
  print_queue(nums1);

  std::priority_queue<int, std::vector<int>, std::greater<int>> nums2;
  for (int n : {1,3,5,7,9,11,2,6,8}) {
    nums2.push(n);
  }
  std::cout << nums2.top() << std::endl;
  print_queue(nums2);

  std::priority_queue<int, std::vector<int>, compare> nums3;
  for (int n : {1,3,5,7,9,11,2,6,8}) {
    nums3.push(n);
  }
  print_queue(nums3);

  std::vector<int> nums4 = {1,3,5,7,9,11,2,6,8};
  std::make_heap(nums4.begin(), nums4.end());
  print_heap(nums4);

  nums4.push_back(16);
  std::push_heap(nums4.begin(), nums4.end());
  print_heap(nums4);
  
  std::pop_heap(nums4.begin(), nums4.end());
  nums4.pop_back();
  print_heap(nums4);
}
