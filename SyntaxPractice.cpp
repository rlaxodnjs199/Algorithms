#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
bool comparison(int A, int B) {
  return A > B;
}
void vector_practice() {
  //#include <vector> -> std::vector<>
  std::vector<int> A = {1, 2, 3, 4};
  A.push_back(5);
  //#include <algorithm> -> std::sort(begin_iterator, end_iterator, comparison), 
  //std::binary_search(begin_iterator, end_iterator, target)
  //#include <functional> -> std::greater<>(), std::less<>() ...
  std::sort(A.begin(), A.end(), std::less<>()); // O(N logN)
  //Binary_search works only when the object is sorted in ascending order.(less<>())
  if (std::binary_search(A.begin(), A.end(), 3)) { // O(logN)
    std::cout << "3 is included" << std::endl;
  }
  std::cout << A.size() << std::endl;
  std::cout << A[2] << std::endl;

  //initialize vector<int> of size 10, value of 300 for all entries
  std::vector<int> B(10, 300);
  int i = 1;
  //Writing down the vector in reverse order
  for (auto reverse_iter = B.rbegin(); reverse_iter != B.rend(); reverse_iter++, i++) {
    *reverse_iter = i;
  }
  //in range-based for loop, note element is not an iterator but an element
  for (const int& element : B) {
    std::cout << element << ", ";
  }
  std::cout << std::endl;

  std::vector<int> C = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //Erase C[5] == 6(C.begin() is C[0]) and decrement size of C by 1
  C.erase(C.begin()+5);
  //Erase [C[0]~C[5]) and decrement size by 5
  //쉽게 이해하기: C.begin() 이랑 C.begin()+5 랑 5<칸> 차이나.
  //시작지점은 포함, 끝 지점은 불포함이므로 4<칸> 차이나는게 되는거야.
  //그래서 4<칸> 차이니까 5<개>를 지우게 돼.
  C.erase(C.begin(), C.begin()+5);
  for (const int& element : C) {
    std::cout << element << ", ";
  }
  std::cout << std::endl;

  std::vector<int> D = {10, 10, 10, 20, 20, 20, 30, 30, 30};
  
  //#include<algorithm> -> lower/upper_bound(begin_itr, end_itr, target)
  //return value: iterator. If nothing meets condition, return .end()
  //lower_bound : return first position that meets D[x] >= 20
  auto low = std::lower_bound(D.begin(), D.end(), 20, std::less<>()); // O(logN)
  //upper_bound : return first position that meets D[x] > 20
  auto upper = std::upper_bound(D.begin(), D.end(), 20, std::less<>()); // O(logN)
  //Print element
  std::cout << *low << ", " << *upper << std::endl;
  //Print position
  std::cout << low - D.begin() << std::endl;
  std::cout << upper - D.begin() << std::endl;

  //What if we want to increment all the elements of vectors by 3?
  for (int& i : D) {
    i += 3;
  }
  for (int& i : D) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}

#include <set>
#include <unordered_set>
//set: store unique elements following specific order
//unordered_set: store unique elements in random order
void set_practice() {
  std::set<int> hashset;
  hashset.insert(3); // O(logN)
  hashset.insert(5);
  hashset.erase(3); // O(logN)
  std::cout << hashset.size() << std::endl;
  auto itr1 = hashset.find(5); // O(logN)
  if (itr1 != hashset.end()) std::cout << "We found it" << std::endl;
  //Note <set> provides upper_bound and lower_bound itself.
  auto itr2 = hashset.upper_bound(3);
  std::cout << *itr2 << std::endl; // O(logN)

  //unordered_set is using <hashtable> data structure
  std::unordered_set<int> unordered_hashset;
  unordered_hashset.insert(3); // Average: O(1), Worst: O(n)
  //Worst case occur when container grows and it forces rehash
  unordered_hashset.erase(3); // Average: O(1)
  auto itr3 = unordered_hashset.find(5); // Average: O(1)
  if (itr3 == unordered_hashset.end()) std::cout << "We couldn't find it" << std::endl;

  //Store elements in no particular order but can store multiple elements with same value.
  std::unordered_multiset<int> unordered_hash_multiset;
  unordered_hash_multiset.insert({3, 3, 3}); //Average: O(1)
  unordered_hash_multiset.erase(3); //Erase all the elements with value 3. 
  //Running time: Linear to number of elemenets erased
  std::cout << unordered_hash_multiset.count(3) << std::endl; //Average: Linear to number of elements counted
}

//Store elements formed by <Key, Value> pair
#include <unordered_map>
void map_practice() {
  std::unordered_map<std::string, int> hashmap = {{"hana", 1}, {"yena", 2}, {"yuna", 3}};
  hashmap.insert({"yuna", 4}); // Average: O(1), insert is succesful only when the "key" doesn't already exist.
  //unordered_map.count works like a 'find' function. It returns 1 if element exists and 0 otherwise.
  std::cout << hashmap.count("taewon") << std::endl; //Average: O(1)

  for (auto i : hashmap) {
    std::cout << i.first << " " << i.second << std::endl;
  }
}

#include <stack>
#include <queue>
void stack_queue_practice() {
  //Stack is a LIFO data structure that utilize one pointer at the top of it.
  std::stack<int> stk;
  stk.push(3); // O(1)
  std::cout << stk.top(); // O(1)
  stk.pop(); // O(1)
  if (stk.empty()) std::cout << "I'm empty" << std::endl;

  //Queue is a FIFO data structure that utilize two pointers at the beginning and end of it.
  std::queue<int> que;
  que.push(2); // O(1)
  que.push(3);
  que.push(4);
  que.pop(); // O(1) : Pop que.front()
  std::cout << que.front() << " " << que.back() << std::endl;
  //.front() : Oldest element     .back() : Latest element
}


void heap_priorityqueue_practice() {
  //heap operations are included in #include <algorithm>
  //We still need to use vector as a container.
  std::vector<int> heap = {1, 3, 2, 7, 4, 5, 9, 6};
  //make_heap takes range as a parameter, it is a function not a data structure.
  //It is a max_heap by default.
  std::make_heap(heap.begin(), heap.end()); // O(n)
  for (int i : heap) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
  //Insert new element: Push element first to the end than call push_heap
  heap.push_back(30);
  std::push_heap(heap.begin(), heap.end()); // O(logN)
  std::cout << heap.front() << std::endl; // O(1) : return root

  //Pop root element: Call pop_heap first, send root to the end and pop_back
  std::pop_heap(heap.begin(), heap.end()); // O(logN)
  heap.pop_back();
  std::cout << heap.front() << std::endl;
  //Heap sort: Best, Average, Worst O(NlogN), O(1) space needed.
  //Achieve O(N) when all the elements are same (push_heap needs only 1 comparison)
  //We need O(1) space for heap sort since we can achieve it in place.
  std::sort_heap(heap.begin(), heap.end());

  //Make min_heap by inserting comparison
  std::make_heap(heap.begin(), heap.end(), std::greater<>());
  for (int i : heap) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
  std::cout << heap.front() << std::endl;

  //priority queue is included in #include <queue>
  std::priority_queue<int> pq;
  pq.push(3); // Call push_heap: O(logN)
  pq.push(5);
  pq.push(2);
  std::cout << pq.top() << std::endl; // Access root: O(1)
  pq.pop(); // Call pop_heap: O(logN)
  std::cout << pq.top() << std::endl;
}