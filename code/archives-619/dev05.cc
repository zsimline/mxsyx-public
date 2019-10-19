// dev05.cc
#include <iostream>
#include <thread>

void display(int index) {
  //std::cout << "我是线程 " << index << std::endl;
}

int main() {
  // 默认构造 trd1
  std::thread trd1;
  // 正常构造 trd2
  std::thread trd2(display, 1);
  // 移动构造 trd3
  std::thread trd3(std::move(trd2));

  if(trd1.joinable()) {
    std::cout << "线程对象trd1可连接" << std::endl;
    trd1.join();
  } else {
    std::cout << "线程对象trd1不可连接，它是默认构造的" << std::endl;
  }
  
  if(trd2.joinable()) {
    std::cout << "线程对象trd2可连接" << std::endl;
    trd2.join();
  } else {
    std::cout << "线程对象trd2不可连接，它已经被移动了" << std::endl;
  }

  if(trd3.joinable()) {
    std::cout << "线程对象trd3可连接" << std::endl;
    trd3.join();
  } else {
    std::cout << "线程对象trd3不可连接" << std::endl;
  }

  if(trd3.joinable()) {
    std::cout << "线程对象trd3可连接" << std::endl;
    trd3.join();
  } else {
    std::cout << "线程对象trd3现在不可连接了" << std::endl;
  }
  
  return 0;
}
