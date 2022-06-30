//  Copyright by Oganyan Robert
#include <iostream>
#include "../include/TQueue.h"

int main() {
  TQueue<int> tst(5);
  for (std::size_t i = 0; i < 10; ++i) {
    if (!tst.IsFull()) {
      std::cout << i*i << "has been put" << std::endl;
      tst.Push(i * i);
    }
  }
  std::cout << "Let`s remove first 3 objects and put negative values instead" << std::endl;
  for (std::size_t i = 1; i <= 3; ++i) {
    tst.Get();
    tst.Push(i * -1);
  }

  while (!tst.IsEmpty()) {
    std::cout << tst.Get() << " ";
  }
}