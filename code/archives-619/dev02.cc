// dev02.cc
#include <iostream>
#include <thread>

void display(int index) {
  std::cout << "index 的值为 " << index << std::endl;
}

int main() {
  // 创建线程 trd, 传入参数 1
  std::thread trd(display, 1);
  // 移动动构造一个线程对象
  // 该操作不会以任何方式影响被移动线程的执行
  std::thread trd1(std::move(trd));

  // 此时trd对象不再代表任何执行线程
  // trd.join();
  trd1.join();

  return 0;
}
