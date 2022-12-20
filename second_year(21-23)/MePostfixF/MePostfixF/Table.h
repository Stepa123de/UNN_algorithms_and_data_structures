//
// Created by Стёпа on 02.12.2022.
//

#ifndef UNTITLED4_TABLE_H
#define UNTITLED4_TABLE_H

#include <cstddef>
#include <iostream>

template <typename T1, typename T2>
class Table {
private:
    T1* keys;
    T2* values;
    size_t size;
    size_t topIndex;
public:
    Table(size_t sz): size(sz)
    {
        keys = new T1[size];
        values = new T2[size];
        topIndex = 0;
    }

    // add new pair key/value
    void Add(const T1& key, const T2& value)
    {
        if(topIndex >= size)
        {
            return;
        }
        keys[topIndex] = key;
        values[topIndex] = value;
        topIndex++;
    }

    //realize slovar model
    T2& operator[](const T1& key) const
    {
        for(int i = 0; i < topIndex; i++)
        {
            if (keys[i] == key)
            {
                return values[i];
            }
        }
        throw "not this key";
    }

    bool isIn(const T1& key) const {
        for (int i = 0; i < topIndex; i++) {
            if (keys[i] == key) {
                return true;
            }
        }
        return false;
    }

    ~Table()
    {
        delete[] keys;
        delete[] values;
        keys = nullptr;
        values = nullptr;
    }

};


#endif //UNTITLED4_TABLE_H
