// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len) : BitLen(len) {
    if (BitLen < 1) throw BitLen;
    if (BitLen < 32) MemLen = (BitLen + 31) >> 5;//MemLen=1
    //MemLen кол-во интов 
    else MemLen = ((BitLen - 1) >> 5) + 1;

    pMem = new TELEM[MemLen];
    if (pMem != nullptr)
    {
        for (int i = 0; i < MemLen; ++i)
        {
            pMem[i] = 0;
        }
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    MemLen = bf.MemLen;
    BitLen = bf.BitLen;
    pMem = new TELEM[MemLen];
    if (pMem != nullptr)
    {
        for (int i = 0; i < MemLen; i++) pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
    pMem = nullptr;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n >> 5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n & 31);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen)
    {
        throw n;
    }
    
    if (n > -1 || n < BitLen)
    {
        pMem[GetMemIndex(n)] |= GetMemMask(n);
    }
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen)
    {
        throw n;
    }

    if (n > -1 || n < BitLen)
    {
        pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & ~GetMemMask(n);
    }
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen)
    {
        throw n;
    }

    if (n > -1 || n < BitLen)
    {
        return 0!=(pMem[GetMemIndex(n)] & GetMemMask(n));
    }
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) return *this;

    BitLen = bf.BitLen;
    if (MemLen != bf.MemLen)
    {
        MemLen = bf.MemLen;
        if (pMem != nullptr)
            delete[] pMem;
    }
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];

    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) return false;
    
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i]) return false;
    }

    return true;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    //;)
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    
    
    if (BitLen > bf.BitLen)
    {
        TBitField answer(*this);
        
        for (int i = 0; i < bf.MemLen; i++)
        {
            answer.pMem[i] = answer.pMem[i] | bf.pMem[i];
        }
        
        return answer;
    }
    else
    {
        TBitField answer(bf);
        for (int i = 0; i < MemLen; i++)
        {
            answer.pMem[i] = answer.pMem[i] | pMem[i];
        }
        
        return answer;
    }   
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    TBitField answer(std::max(BitLen,bf.BitLen));
    for (int i = 0; i < std::min(MemLen,bf.MemLen); i++)
    {
        answer.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return answer;
}

TBitField TBitField::operator~(void) // отрицание
{

    TBitField answer(BitLen);
    for (int i = 0; i < BitLen; i++)
    {
        if (GetBit(i) == 1) answer.ClrBit(i);
        else answer.SetBit(i);
    }
    return answer;
    
}

TBitField TBitField::operator^(const TBitField& bf)
{
    TBitField a(*this), b(bf);
    return a & (~b) | (~a) & b;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    std::string str;
    istr >> str;
    bf = TBitField(str.length());
    for (int i = bf.BitLen-1; i > -1; i--)
    {
        if (str[i] == '1') bf.SetBit(i);
    }
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{

    for ( int i = 0; i < bf.BitLen; i++)
    {
        ostr << bf.GetBit(i);
    }

	return ostr;
}
