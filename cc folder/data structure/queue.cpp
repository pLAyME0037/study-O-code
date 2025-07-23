#include <iostream>
#include <queue>

int main () {
  std::queue<int> queue;

  for (int i = 0; i < 4; i++) {
    int x;
    std::cin >> x;
    queue.push(x);
  }

  for (int i = 0; i < 4; i++) {
    std::cout << queue.front() << " ";
    queue.pop();
  }
  return 0;
}