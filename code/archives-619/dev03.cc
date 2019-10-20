// dev03.cc
#include <iostream>
#include <thread>

void Display(int index) {
  std::cout << "我是线程 " << index << std::endl;
}

int main() {
  // 创建线程对象数组
  // 调用类的默认构造函数
  std::thread trds[3];

  // 使用赋值操作符移动赋值
  // 该操作不会以任何方式影响被移动线程的执行
  for(int i = 0; i < 3; i++)
    trds[i] = std::thread(Display, i + 1);

  // 等待线程结束
  for(int i = 0; i < 3; i++)
    trds[i].join();

  return 0;
}
