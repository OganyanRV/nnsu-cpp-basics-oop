  // Copyright 2020 Oganyan Robert

// Верхнетреугольная матрица

#include <iostream>

#ifndef TRIANGULAR_MATRIX_INCLUDE_UTMATRIX_H_
#define TRIANGULAR_MATRIX_INCLUDE_UTMATRIX_H_


const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора

template <class ValType>
class TVector {
 protected:
    ValType *pVector;
    int Size;       // размер вектора
    int StartIndex;  // индекс первого элемента вектора

 public:
    explicit TVector(int s = 10, int si = 0);
    TVector(const TVector& v);  // конструктор копирования
    virtual ~TVector();
    std::size_t GetSize(void);  // размер вектора
    std::size_t GetStartIndex(void);  // индекс первого элемента
    ValType& operator[](const int& pos);  // доступ
    bool operator==(const TVector& v) const;  // сравнение
    bool operator!=(const TVector& v) const;  // сравнение
    TVector& operator=(const TVector& v);   // присваивание

  // скалярные операции
    TVector  operator+(const ValType &val);   // прибавить скаляр
    TVector  operator-(const ValType &val);   // вычесть скаляр
    TVector  operator*(const ValType &val);   // умножить на скаляр

  // векторные операции
    TVector  operator+(const TVector &v);     // сложение
    TVector  operator-(const TVector &v);     // вычитание
    ValType  operator*(const TVector &v);     // скалярное произведение

  // ввод-вывод
    friend std::istream &operator>>(std::istream &in, TVector &v) {
      for (std::size_t i = 0; i < v.Size; ++i) {
        in >> v.pVector[i];
      }
    return in;
  }

    friend std:: ostream &operator<<(std::ostream &out, const TVector &v) {
      for (std::size_t i = 0; i < v.Size; ++i) {
        out << v.pVector[i] << ' ';
      }
      return out;
    }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si) {
  if (s > MAX_VECTOR_SIZE || s < 0 || si < 0) {
    throw std::runtime_error("Incorrect input");
  }
  Size = s;
  StartIndex = si;
  pVector = new ValType[Size];
  for (std::size_t i = 0; i < Size; ++i) {
    pVector[i] = (ValType) 0;
  }
}

template <class ValType>  // конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v) {
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[Size];
  for (std::size_t i = 0; i < Size; ++i) {
    pVector[i] = v.pVector[i];
  }
}

template <class ValType>
TVector<ValType>::~TVector() {
  delete[] pVector;
}

template <class ValType>
std::size_t TVector<ValType>::GetSize() {
  return Size;
}

template <class ValType>
std::size_t TVector<ValType>::GetStartIndex() {
  return StartIndex;
}

template <class ValType>  // доступ
ValType& TVector<ValType>::operator[] (const int& pos) {
  if (pos - StartIndex < 0 || pos - StartIndex >= Size) {
    throw std::runtime_error("Incorrect input");
  }

  return pVector[pos - StartIndex];
}

template <class ValType>  // сравнение
bool TVector<ValType>::operator==(const TVector &v) const {
  if (Size == v.Size && StartIndex == v.StartIndex) {
    for (std::size_t i = 0; i < Size; ++i) {
      if (pVector[i] != v.pVector[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <class ValType>  // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const {
  return !(*this == v);
}

template <class ValType>   // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v) {
  if (this == &v) {
    return *this;
  }
  if (pVector != nullptr) {
    delete[] pVector;
  }
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[Size];
  for (std::size_t i = 0; i < Size; ++i) {
    pVector[i] = v.pVector[i];
  }
  return *this;
}

template <class ValType>  // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val) {
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] += val;
  }
  return tmp;
}

template <class ValType>   // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val) {
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] -= val;
  }
  return tmp;
}

template <class ValType>   // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val) {
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] = tmp.pVector[i] * val;
  }
  return tmp;
}

template <class ValType>   // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v) {
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw std::runtime_error("Incorrect input");
  }
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] = tmp.pVector[i] + v.pVector[i];
  }
  return tmp;
}

template <class ValType>   // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v) {
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw std::runtime_error("Incorrect input");
  }
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] = tmp.pVector[i] - v.pVector[i];
  }
  return tmp;
}

template <class ValType>   // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v) {
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw std::runtime_error("Incorrect input");
  }
  ValType tmp = 0;
  for (std::size_t i = 0; i < Size; ++i) {
    tmp += pVector[i] * v.pVector[i];
  }
  return tmp;
}

// Матрицы

template <class ValType>
class TMatrix : public TVector<TVector<ValType>> {
 public:
  explicit TMatrix(int s = 10);
  TMatrix(const TMatrix &mt);   // копирование
  TMatrix(const TVector<TVector<ValType>> &mt);  // преобразование типа
  bool operator==(const TMatrix &mt) const;  // сравнение
  bool operator!=(const TMatrix &mt) const;  // сравнение
  TMatrix& operator= (const TMatrix &mt);   // присваивание
  TMatrix  operator+ (const TMatrix &mt);  // сложение
  TMatrix  operator- (const TMatrix &mt);   // вычитание

  // ввод / вывод
  friend std::istream& operator>>(std::istream &in, TMatrix &mt) {
    for (std::size_t i = 0; i < mt.Size; ++i) {
      in >> mt.pVector[i];
    }
    return in;
  }

  friend std::ostream& operator<<(std::ostream &out, const TMatrix &mt) {
    for (std::size_t i = 0; i < mt.Size; ++i) {
      out << mt.pVector[i] << std::endl;
    }
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType>>(s) {
  if (s > MAX_MATRIX_SIZE || s < 0) {
    throw std::runtime_error("Incorrect input");
  }
  for (std::size_t i = 0; i < s; ++i) {
    this->pVector[i] = TVector<ValType>(s - i, i);
  }
}

template <class ValType>  // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
    TVector<TVector<ValType>>(mt) {
}

template <class ValType>  // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
    TVector<TVector<ValType>>(mt) {
}

template <class ValType>   // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const {
  if (this->Size == mt.Size) {
    for (std::size_t i = 0; i < this->Size; ++i) {
      if (this->pVector[i] != mt.pVector[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <class ValType>  // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const {
  return !(*this == mt);
}

template <class ValType>  // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt) {
  if (this != &mt) {
    delete[] this->pVector;
    this->Size = mt.Size;
    this->StartIndex = mt.StartIndex;
    this->pVector = new TVector<ValType>[this->Size];
    for (int i = 0; i < this->Size; ++i) {
      this->pVector[i] = mt.pVector[i];
    }
  }
  return *this;
}

template <class ValType>  // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt) {
  if (this->Size != mt.Size) {
    throw std::runtime_error("Incorrect input");
  }
  return TVector< TVector<ValType> >::operator + (mt);
}

template <class ValType>  // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt) {
  if (this->Size != mt.Size) {
    throw std::runtime_error("Incorrect input");
  }
  return TVector< TVector<ValType> >::operator - (mt);
}


#endif  // TRIANGULAR_MATRIX_INCLUDE_UTMATRIX_H_
