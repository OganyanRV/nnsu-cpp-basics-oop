  // Copyright 2020 Oganyan Robert

// Тестирование битового поля и множества

#include <iomanip>

// #define USE_SET // Использовать класс TSet,
                // закоментировать, чтобы использовать битовое поле

#ifndef USE_SET  // Использовать класс TBitField

#include "../include/tbitfield.h"

int main() {
  int n, m, k, count;
  // Тестирование программ поддержки битового поля
  std::cout << "BitField test" << std::endl;
  // Решето Эратосфена
  std::cout << "The Sieve of Eratosthenes" << std::endl;
  // Введите верхнюю границу целых значений
  std::cout << "Enter the upper bound for integer values: ";
  std::cin >> n;
  TBitField s(n + 1);
  // заполнение множества
  for (m = 2; m <= n; ++m) {
    s.SetBit(m);
  }
  // проверка до sqrt(n) и удаление кратных
  for (m = 2; m * m <= n; ++m) {
    // если m в s, удаление кратных
    if (s.GetBit(m)) {
      for (k = 2 * m; k <= n; k += m) {
        if (s.GetBit(k)) {
          s.ClrBit(k);
        }
      }
    }
  }
  // оставшиеся в s элементы - простые числа
  // Печать множества некратных чисел
  std::cout << std::endl << "Set of prime numbers"
                << std::endl << s << std::endl;

  std::cout << std::endl << "Prime numbers:"
                << std::endl;  // Печать простых чисел
  count = 0;
  k = 1;
  for (m = 2; m <= n; ++m) {
    if (s.GetBit(m)) {
      count++;
      std::cout << std::setw(3) << m << " ";
      if (k++ % 10 == 0) {
        std::cout << std::endl;
      }
    }
  }
  std::cout << std::endl;
  /* std::cout << "В первых " << n << " числах "
   << count << " простых" << std::endl; */
  std::cout << count << " primes among "
        << n << " numbers" << std::endl;
}
#else

#include "../include/tset.h"

int main() {
  int n, m, k, count;
  //Тестирование программ поддержки множеств
  std::cout << "Set test" << std::endl;
  // Решето Эратосфена
  std::cout << "The Sieve of Eratosthenes" << std::endl;
  // Введите верхнюю границу целых значений
  std::cout << "Enter the upper bound for integer values: ";
  std::cin >> n;
  TSet s(n + 1);
  // заполнение множества
  for (m = 2; m <= n; ++m) {
    s.InsElem(m);
  }
  // проверка до sqrt(n) и удаление кратных
  for (m = 2; m * m <= n; ++m) {
    // если m в s, удаление кратных
    if (s.IsMember(m)) {
      for (k = 2 * m; k <= n; k += m) {
        if (s.IsMember(k)) {
          s.DelElem(k);
        }
      }
    }
  }
  // оставшиеся в s элементы - простые числа
  // Печать множества некратных чисел
  std::cout << std::endl << "Set of prime numbers"
            << std::endl << s << std::endl;

  std::cout << std::endl << "Prime numbers:"
            << std::endl;  // Печать простых чисел
  count = 0;
  k = 1;
  for (m = 2; m <= n; ++m) {
    if (s.IsMember(m)) {
      count++;
      std::cout << std::setw(3) << m << " ";
      if (k++ % 10 == 0) {
        std::cout << std::endl;
      }
    }
  }
  std::cout << std::endl;
  /* std::cout << "В первых " << n << " числах "
  << count << " простых" << std::endl; */
  std::cout << count << " primes among "
      << n << " numbers" << std::endl;
}

#endif
