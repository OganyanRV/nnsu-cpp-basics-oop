//  Copyright by Oganyan Robert

#ifndef STACK_AND_RPN_INCLUDE_TSTACK_H_
#define STACK_AND_RPN_INCLUDE_TSTACK_H_

#include <string.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

template <class T>
class TStack {
 protected:
  T* v;
  int size;
  int top;

 public:
  TStack() = delete;
  explicit TStack(int _size = 20);  //  конструктор
  explicit TStack(const TStack<T>& s);  //  конструктор копирования
  ~TStack();  //  деструктор

  void Push(const T& val);  // Положить элемент
  T Pop();  // Взять элемент
  T Top();  // Узнать значение верхнего элемента (без изъятия)
  bool IsFull();  //  Полный ли стэк
  bool IsEmpty();  //  Пустой ли стэк
  int GetSize();  //  Размер стэка
  int GetTop();  //  Номер следующего за последним элементом

  friend std::ostream& operator<<(std::ostream& ostr, const TStack<T>& st) {
    for (std::size_t i = 0; i < st.size; ++i) {
      if (i < st.top)
        ostr << st.v[i] << ' ';
      else
        ostr << "x ";
    }
    return ostr;
  }
};

template<class T>
TStack<T>::TStack(int _size) {
  if (_size < 0) {
    throw std::runtime_error("Wrong size");
  }
  size = _size;
  top = 0;
  if (size == 0) {
    v = nullptr;
  } else {
    v = new T[size];
  }
}

template<class T>
TStack<T>::TStack(const TStack<T>& s) :size(s.size), top(s.top) {
  if (size == 0) {
    v = nullptr;
  } else {
    v = new T[size];
    for (std::size_t i = 0; i < size; ++i) {
      v[i] = s.v[i];
    }
  }
}

template<class T>
TStack<T>::~TStack() {
  if (v != nullptr) {
    delete[] v;
  }
}

template<class T>
bool TStack<T>::IsFull() {
  return top >= size;
}

template<class T>
bool TStack<T>::IsEmpty() {
  return (top == 0);
}

template<class T>
T TStack<T>::Pop() {
  if (IsEmpty()) {
    throw std::runtime_error("Stack is empty");
  }
  return v[--top];
}

template<class T>
T TStack<T>::Top() {
  return v[top - 1];
}

template<class T>
void TStack<T>::Push(const T& val) {
  if (IsFull()) {
    throw std::runtime_error("Stack is full");
  }
  v[top++] = val;
}

template<class T>
int TStack<T>::GetSize() {
  return size;
}

template<class T>
int TStack<T>::GetTop() {
  return top;
}

#endif  //  STACK_AND_RPN_INCLUDE_TSTACK_H_
