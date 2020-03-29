// dev07.cc
#include <iostream>
#include <thread>

void Display(int index) {
  // ...
}

int main() {
  std::thread trd1(Display, 2);
  std::thread trd2(Display, 8);

  std::cout << "交换前：" << std::endl;
  std::cout << "trd1 ID: " << trd1.get_id() << std::endl;
  std::cout << "trd2 ID: " << trd2.get_id() << std::endl;

  // 交换两个线程
  trd1.swap(trd2);
  // 同样可以调用非成员函数交换两个线程
  // swap(trd1, trd2);

  std::cout << "交换后：" << std::endl;
  std::cout << "trd1 ID: " << trd1.get_id() << std::endl;
  std::cout << "trd2 ID: " << trd2.get_id() << std::endl;

  trd1.join();
  trd2.join();

  return 0;
}
