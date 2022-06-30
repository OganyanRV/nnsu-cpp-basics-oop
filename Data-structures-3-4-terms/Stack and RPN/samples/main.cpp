  //  Copyright by Oganyan Robert

#include <iostream>
#include <string>
#include "../include/RPolNotation.h"

int main() {
  TStack<int> st(5);
  int temp;
  std::cout << "Stack testing" << std::endl;
  for (std::size_t i = 0; i < 35; ++i)   {
    if (!st.IsFull()) {
      st.Push(i);
      std::cout << "Put the object: " << i << std::endl;
    }
  }
  while (!st.IsEmpty()) {
    temp = st.Pop();
    std::cout << "Took the object " << temp << std::endl;
  }
  std::cout << "Reverse Polish Notation testing" << std::endl;
  std::cout << "Enter the Formula:  " << std::endl;
  std::string s;
  std::cin >> s;
  int n = 0;
  // Преобразование в массив чаров и удаление const
  char* str = const_cast<char*> (s.c_str());
  auto notation = RPolNotation(str);
  Token* t = notation.Postfix(n);
  std::cout << "\n Postfix form: \n";
  std::cout << std::endl;
  // Better print "Convert method", but its not working
  for (std::size_t i = 0; i < n; ++i) {
    if (t[i].type == Token::kNumber)
      std::cout << t[i].number << ' ';
    else
      std::cout << t[i].symbol << ' ';
  }
  std::cout << "\n The result: " << notation.Calculate();
  return 0;
}
