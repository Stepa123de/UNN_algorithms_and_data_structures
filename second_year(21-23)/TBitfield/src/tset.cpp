// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp), MaxPower(mp) {};


// конструктор копирования
TSet::TSet(const TSet &set) : BitField(set.BitField), MaxPower(set.MaxPower) {};


// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength()) {};

TSet::operator TBitField()
{
    return TBitField(BitField);
}

int TSet::GetMaxPower(void) const// получить макс. к-во эл-тов
{
    return  MaxPower;
}

int TSet::IsMember(const int elem) const // элемент множества?
{
    return BitField.GetBit(elem);
}

void TSet::InsElem(const int elem) // включение элемента множества
{
    BitField.SetBit(elem);
}

void TSet::DelElem(const int elem) // исключение элемента множества
{
    BitField.ClrBit(elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &set) // присваивание
{
    MaxPower = set.MaxPower;
    BitField = set.BitField;
    return  *this;
}

int TSet::operator==(const TSet &set) const // сравнение
{
    return set.BitField == BitField;
}

int TSet::operator!=(const TSet &set) const // сравнение
{
    return set.BitField != BitField;
}

TSet TSet::operator+(const TSet &set) // объединение
{
    TSet T(BitField | set.BitField);
    return T;
}

TSet TSet::operator+(const int elem) // объединение с элементом
{
    TSet T(BitField);
    T.InsElem(elem);
    return T;
}

TSet TSet::operator-(const int elem) // разность с элементом
{
    TSet T(BitField);
    T.DelElem(elem);
    return T;
}

TSet TSet::operator*(const TSet &set) // пересечение
{
    TSet T(BitField & set.BitField);
    return  T;
}

TSet TSet::operator~(void) // дополнение
{
    return TSet(~BitField);
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    ostr << "{";
    int n = s.GetMaxPower();
    for (int i = 0; i < n; i++)
    {
        if (s.IsMember(i))
        {
            ostr << i << " ";
        }
    }

    ostr << "}";
    return  ostr;
}
