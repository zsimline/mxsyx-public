// dev08.cc
#include <iostream>
#include <thread>

int main() {
  std::cout << std::thread::hardware_concurrency();
  return 0;
}