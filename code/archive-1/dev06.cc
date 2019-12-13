// dev06.cc
#include <iostream>
#include <thread>
#include <chrono>

void DelayThread(int s) {
  // sleep_for函数使线程睡眠s秒
  std::this_thread::sleep_for(std::chrono::seconds(s));
  std::cout << s << "秒过去了" << std::endl;
}

int main() {
  std::thread trd1(DelayThread, 2);
  std::thread trd2(DelayThread, 8);

  // 分离线程
  trd1.detach();
  trd2.detach();

  // 主线程睡眠5s
  DelayThread(5);
  return 0;
}