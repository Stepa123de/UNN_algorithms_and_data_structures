// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);          //                            (#О1)
  TVector(const TVector &v);                // конструктор копирования    (#Л1)
  ~TVector();                               //                            (#О2)
  int GetSize()      { return Size;       } // размер вектора              (#О)
  int GetStartIndex(){ return StartIndex; } // индекс первого элемента     (#О)
  ValType& operator[](int pos);             // доступ                     (#П2)
  bool operator==(const TVector &v) const;  // сравнение                  (#П3)
  bool operator!=(const TVector &v) const;  // сравнение                  (#П3)
  TVector& operator=(const TVector &v);     // присваивание              (#О3)

  // скалярные операции
  TVector  operator+(const ValType &val);   // прибавить скаляр           (#Л2)
  TVector  operator-(const ValType &val);   // вычесть скаляр             (#С1)
  TVector  operator*(const ValType &val);   // умножить на скаляр         (#С2)

  // векторные операции
  TVector  operator+(const TVector &v);     // сложение                   (#С3)
  TVector  operator-(const TVector &v);     // вычитание                  (#С4)
  ValType  operator*(const TVector &v);     // скалярное произведение     (#С5)

  // ввод-вывод
  friend istream& operator>>(istream &in, TVector &v) //                  (#П4)
  {
    return in;                                                      
  }
  friend ostream& operator<<(ostream &out, const TVector &v) //           (#С6)
  {
    return out;                                                     // SKIP_OFF
  }
};

template <class ValType>
TVector<ValType>::TVector(int size, int startInd) {
    size == 0 ? throw size : data = new T[size];
    this->size = size;
    this->startInd = startInd;
} /*-------------------------------------------------------------------------*/

template<class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector& vector) {
    this->size = vector.size;
    this->startInd = vector.startInd;
    std::copy(vector.data, data);
}

template <class ValType>
TVector<ValType>::~TVector() {
    delete[] data;
    data = nullptr;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
    return *(new ValType());
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
    return false;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const {
    if (this == &v)
    {
        return true;
    }
    else
    {
        if (size != v.size)
        {
            return false;
        }
        else
        {
            if (startInd != v.startInd)
            {
                return false;
            }
            else
            {
                for (int i = 0; i < size; ++i)
                {
                    if (data[i] != v.data[i])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

}
/*-------------------------------------------------------------------------*/


template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
    if (this == &v) {
        return *this;
    }
    if (size != v.size)
    {
        T* tmp = data;
        data = new T[size];
        size = v.size;
        startInd = v.startInd;
        if (data == nullptr)
            data = tmp;
    }
    for (int i = 0; i < size; ++i) {
        data[i] = v.data[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
  return NULL;                                                      // SKIP_OFF
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
    return NULL;                                                         // SKIP_OFF
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
    return NULL;                                                         // SKIP_OFF
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
    return NULL;                                                        // SKIP_OFF
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
    return NULL;                                                         // SKIP_OFF
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
    return NULL;                                                         // SKIP_OFF
} /*-------------------------------------------------------------------------*/


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
  TMatrix(int s = 10);                           //                       (#О1)
  TMatrix(const TMatrix &mt);                    // копирование           (#Л1)
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа   (#Л2)
  bool operator==(const TMatrix &mt) const;      // сравнение             (#П1)
  bool operator!=(const TMatrix &mt) const;      // сравнение             (#П1)
  TMatrix& operator= (const TMatrix &mt);        // присваивание          (#О2)
  TMatrix  operator+ (const TMatrix &mt);        // сложение              (#П2)
  TMatrix  operator- (const TMatrix &mt);        // вычитание             (#С1)

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)                //  (#П3)
  {
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt) //        (#С3)
  {                                
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s){} 
template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt){}                 
template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt){}                        
template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
    return false;
} 
template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
    return false;
} 
template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
  return *this;
}
template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
    return NULL;
}

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
    return NULL;        
} 

#endif
