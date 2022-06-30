// Copyright 2020 Oganyan Robert

// Множество - реализация через битовые поля

#include "../include/tset.h"

TSet::TSet(const int& mp) : MaxPower(mp), BitField(mp) {
}

// конструктор копирования
TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField) {
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : MaxPower(bf.GetLength()), BitField(bf) {
}

TSet::operator TBitField() {
  TBitField tmp(this->BitField);
  return tmp;
}

int TSet::GetMaxPower() const {  // получить макс. к-во эл-тов
  return MaxPower;
}

int TSet::IsMember(const int& Elem) const {  // элемент множества?
  if (Elem > MaxPower || Elem < 0) {
    std::runtime_error("incorrect Elem");
  }
  return BitField.GetBit(Elem);
}

void TSet::InsElem(const int& Elem) {  // включение элемента множества
  if (Elem > MaxPower || Elem < 0) {
    std::runtime_error("incorrect Elem");
  }
  BitField.SetBit(Elem);
}

void TSet::DelElem(const int& Elem) {  // исключение элемента множества
  if (Elem > MaxPower || Elem < 0) {
    std::runtime_error("incorrect Elem");
  }
  BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) {  // присваивание
  if (this != &s) {
    BitField = s.BitField;
    MaxPower = s.MaxPower;
  }
  return *this;
}

int TSet::operator==(const TSet &s) const {  // сравнение
  return BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const {  // сравнение
  if (MaxPower == s.MaxPower) {
    return BitField != s.BitField;
  }
  return 1;
}

TSet TSet::operator+(const TSet &s) {  // объединение
  TSet tmp(BitField | s.BitField);
  return tmp;
}

TSet TSet::operator+(const int& Elem) {  // объединение с элементом
  if (Elem > MaxPower || Elem < 0) {
    std::runtime_error("incorrect Elem");
  }
  BitField.SetBit(Elem);
  return *this;
}

TSet TSet::operator-(const int& Elem) {  // разность с элементом
  if (Elem > MaxPower || Elem < 0) {
    std::runtime_error("incorrect Elem");
  }
  BitField.ClrBit(Elem);
  return *this;
}

TSet TSet::operator*(const TSet &s) {  // пересечение
  TSet tmp(BitField & s.BitField);
  return tmp;
}

TSet TSet::operator~(void) {  // дополнение
  TSet tmp(~BitField);
  return tmp;
}

// перегрузка ввода/вывода

std::istream &operator>>(std::istream &istr, TSet &s) {  // ввод
  istr >> s.BitField;
  return istr;
}

std::ostream& operator<<(std::ostream &ostr, const TSet &s) {  // вывод
  ostr << s.BitField << ' ';
  return ostr;
}
