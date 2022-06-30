// Copyright 2020 Oganyan Robert

// Битовое поле
#include <stdexcept>
#include <string>
#include <algorithm>
#include "../include/tbitfield.h"

TBitField::TBitField(const int& len) {
  if (len <= 0) {
    throw std::runtime_error("Negative length");
  }
  BitLen = len;
  int size = 8 * sizeof(TELEM);
  MemLen = BitLen / size;
  if (BitLen % size > 0) {
    MemLen++;
  }
  pMem = new TELEM[MemLen];
  for (std::size_t i = 0; i < MemLen; ++i) {
    pMem[i] = 0;
  }
}

TBitField::TBitField(const TBitField &bf) {  //  конструктор копирования
  BitLen = bf.BitLen;
  MemLen = bf.MemLen;
  pMem = new TELEM[MemLen];
  if (pMem != nullptr) {
    for (std::size_t i = 0; i < MemLen; ++i) {
      pMem[i] = bf.pMem[i];
    }
  }
}


TBitField::~TBitField() {
  delete[] pMem;
}

int TBitField::GetMemIndex(const int& n) const {  // индекс Мем для бита n
  if ((n < 0) || (n >= BitLen)) {
    throw std::runtime_error("Index does not exist");
  }

  return n / (8 * sizeof(TELEM));
}

TELEM TBitField::GetMemMask(const int& n) const {  // битовая маска для бита n
  if ((n < 0) || (n >= BitLen)) {
    throw std::runtime_error("Index does not exist");
  }

  return 1 << (n % (8 * sizeof(TELEM)));
}

// доступ к битам битового поля

int TBitField::GetLength() const  {  // получить длину (к-во битов)
  return BitLen;
}

void TBitField::SetBit(const int& n) {  // установить бит
  if ((n < 0) || (n >= BitLen)) {
    throw std::runtime_error("Index does not exist");
  }

  pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int& n) {  // очистить бит
  if ((n < 0) || (n >= BitLen)) {
    throw std::runtime_error("Index does not exist");
  }

  pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int& n) const {  // получить значение бита
  if ((n < 0) || (n >= BitLen)) {
    throw std::runtime_error("Index does not exist");
  }

  TELEM result = pMem[GetMemIndex(n)] & GetMemMask(n);
  if (result != 0) {
    return 1;
  }
  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) {  // присваивание
  if (&bf != this) {
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    if (pMem != nullptr) {
      delete[] pMem;
    }
    pMem = new TELEM[MemLen];
    for (std::size_t i = 0; i < MemLen; ++i) {
      pMem[i] = bf.pMem[i];
    }
  }
  return *this;
}

int TBitField::operator==(const TBitField &bf) const {  // сравнение
  std::size_t minMem;
  minMem = std::min(MemLen, bf.MemLen);
  for (std::size_t i = 0; i < minMem; ++i) {
    if (pMem[i] != bf.pMem[i]) {
      return 0;
    }
  }
  if (MemLen > bf.MemLen) {
    for (std::size_t i = minMem; i < MemLen; ++i) {
      if (pMem != 0) {
        return 0;
      }
    }
  } else {
    for (std::size_t i = minMem; i < bf.MemLen; ++i) {
      if (pMem != 0) {
        return 0;
      }
    }
  }
  return 1;
}

int TBitField::operator!=(const TBitField &bf) const {  // сравнение
  if (*this == bf) {
    return 0;
  }
  return 1;
}

TBitField TBitField::operator|(const TBitField &bf) {  // операция "или"
  int MaxBit = std::max(BitLen, bf.BitLen);
  TBitField tmp(MaxBit);
  for (std::size_t i = 0; i < MemLen; ++i) {
    tmp.pMem[i] = pMem[i];
  }
  for (std::size_t i = 0; i < bf.MemLen; ++i) {
    tmp.pMem[i] |= bf.pMem[i];
  }
  return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) {  // операция "и"
  int MinBit = std::min(BitLen, bf.BitLen);
  TBitField tmp(MinBit);
  for (std::size_t i = 0; i < tmp.MemLen; ++i) {
    tmp.pMem[i] = bf.pMem[i] & pMem[i];
  }
  return tmp;
}

TBitField TBitField::operator~(void) {  // отрицание
  TBitField tmp(BitLen);
  for (std::size_t i = 0; i < BitLen; ++i) {
    if (GetBit(i)) {
      tmp.ClrBit(i);
    } else {
      tmp.SetBit(i);
    }
  }
  return tmp;
}

// ввод/вывод

std::istream &operator>>(std::istream &istr, TBitField &bf) {  // ввод
  std::string new_bfield;
  istr >> new_bfield;
  if (new_bfield.size() > bf.GetLength()) {
    throw std::runtime_error("incorrect length");
  }
  for (std::size_t i = 0; i < bf.BitLen; ++i) {
    if (new_bfield[i] == '0') {
      bf.ClrBit(i);
    } else if (new_bfield[i] == '1') {
      bf.SetBit(i);
    } else {
      throw std::runtime_error("incorrect symbol");
    }
  }
  return istr;
}

std::ostream &operator<<(std::ostream &ostr, const TBitField &bf) {  // вывод
  int len = bf.GetLength();
  for (std::size_t i = 0; i < len; ++i) {
    if (bf.GetBit(i)) {
      ostr << '1';
    } else {
      ostr << '0';
    }
  }
  return ostr;
}
