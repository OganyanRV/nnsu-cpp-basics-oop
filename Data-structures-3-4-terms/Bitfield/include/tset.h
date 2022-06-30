// Copyright 2020 Oganyan Robert

// Множество

#ifndef  BITFIELD_INCLUDE_TSET_H_
#define  BITFIELD_INCLUDE_TSET_H_

#include "../include/tbitfield.h"

class TSet {
 private:
  int MaxPower;       // максимальная мощность множества
  TBitField BitField;  // битовое поле для хранения характеристического вектора

 public:
  explicit TSet(const int& mp);
  TSet(const TSet &s);       // конструктор копирования
  explicit TSet(const TBitField &bf);  // конструктор преобразования типа
  operator TBitField();      // преобразование типа к битовому полю
  // доступ к битам
  int GetMaxPower(void) const;     // максимальная мощность множества
  void InsElem(const int& Elem);       // включить элемент в множество
  void DelElem(const int& Elem);       // удалить элемент из множества
  int IsMember(const int& Elem) const;  // проверка наличия элемента в множестве
  // теоретико-множественные операции
  int operator== (const TSet &s) const;  // сравнение
  int operator!= (const TSet &s) const;  // сравнение
  TSet& operator=(const TSet &s);   // присваивание
  TSet operator+ (const int& Elem);  // объединение с элементом
                                   // элемент должен быть из того же универса
  TSet operator- (const int& Elem);  // разность с элементом
                                   // элемент должен быть из того же универса
  TSet operator+ (const TSet &s);  // объединение
  TSet operator* (const TSet &s);  // пересечение
  TSet operator~ (void);           // дополнение

  friend std::istream &operator>>(std::istream &istr, TSet &bf);
  friend std::ostream &operator<<(std::ostream &ostr, const TSet &bf);
};

#endif  // BITFIELD_INCLUDE_TSET_H_
