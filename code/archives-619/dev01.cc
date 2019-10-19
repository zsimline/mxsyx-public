// dev01.cc
#include <iostream>
#include <thread>

void display(int index) {
  std::cout << "index 的值为 " << index << std::endl;
}

int main() {
  // 创建线程 trd, 传入参数 1
  std::thread trd(display, 1);

  // 等待线程 trd 结束
  trd.join();

  return 0;
}
