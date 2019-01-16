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
  std::sort(A.begin(), A.end(), std::less<>());
  //Binary_search works only when the object is sorted in ascending order.(less<>())
  if (std::binary_search(A.begin(), A.end(), 3)) {
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
  auto low = std::lower_bound(D.begin(), D.end(), 20, std::less<>());
  //upper_bound : return first position that meets D[x] > 20
  auto upper = std::upper_bound(D.begin(), D.end(), 20, std::less<>());
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

int main() {
  
}