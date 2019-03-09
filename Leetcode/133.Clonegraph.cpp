#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
struct Node {
  int val;
  std::vector<Node*> neighbors;
  Node(int num, std::vector<Node*> nodes): val(num), neighbors(nodes) {}
};
Node* clonegraph(Node* src) {
  std::unordered_map<Node*, Node*> map;
  std::queue<Node*> q;
  map[src] = new Node(src->val, {});
  q.push(src);
  while (!q.empty()) {
    Node* cur = q.front();
    for (Node* neighbor : cur->neighbors) {
      if (!map.count(neighbor)) {
        map[neighbor] = new Node(neighbor->val, {});
        q.push(neighbor);
      }
      map[cur]->neighbors.push_back(map[neighbor]);
    }
    q.pop();
  }
  return map[src];
}