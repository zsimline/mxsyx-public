// dev04.cc
#include <iostream>
#include <thread>

void display(int index) {
  //std::cout << "我是线程 " << index << std::endl;
}

int main() {
  std::thread trds[3];

  for(int i = 0; i < 3; i++)
    trds[i] = std::thread(display, i + 1);

  for(int i = 0; i < 3; i++) {
    // 线程ID 的类型为 std::thread::id
    std::thread::id tid = trds[i].get_id();
    std::cout << "线程" << i + 1 << " " << tid << std::endl;
    trds[i].join();
  }

  return 0;
}