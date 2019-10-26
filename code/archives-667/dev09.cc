// dev09.cc
#include <iostream>
#include <thread>
#include <chrono>

bool ready = false;

void SetReady() {
  // 等待 5 秒钟后设置全局变量 ready 的值为 true
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "Display 函数即将继续执行" << std::endl;
  ready = true;
}

void Display() {
  // 阻塞当前线程的执行，直到SetReady 函数设置
  // 全局变量 ready 的值为 true 的时候才继续执行
  while (!ready) {
    std::this_thread::yield();
  }
  std::cout << "线程ID: " << std::this_thread::get_id() << std::endl;
}


int main () {
  std::thread trd1(SetReady);
  std::thread trd2(Display);
  trd1.join();
  trd2.join();

  return 0;
}
