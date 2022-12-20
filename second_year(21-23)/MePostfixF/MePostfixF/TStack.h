//
// Created by Стёпа on 15.11.2022.
//

#ifndef UNTITLED4_TSTACK_H
#define UNTITLED4_TSTACK_H
#define TEN 10
#include <cstddef>
#include <algorithm>
#include <iostream>

template<typename T>
class TStack {
private:
    T* data;
    size_t size;
    size_t topIndex;
    // add ram to stack
    void Resize()
    {
        T* newData = new T[size*2];
        std::copy(data,data+size,newData);
        size *= 2;
        delete[] data;
        data = newData;
    }

public:

    TStack(size_t count = 1):size(count),topIndex(0)
    {
        if(size == 0) size = TEN;

        data = new T[size];

        if (data == nullptr) throw "none memory";
    };

    TStack(const TStack& ts):size(ts.size),topIndex(ts.topIndex)
    {
        data = new T[size];

        for (int i = 0; i < size; ++i)
        {
            data[i] = ts.data[i];
        }
    }

    TStack(TStack && ts):size(ts.size),topIndex(ts.topIndex),data(nullptr)
    {
        data = ts.data;
        ts.data = nullptr;
        ts.size = 0;
    }


    ~TStack()
    {
        delete[] data;
        data = nullptr;
    }

    // add new element to the end
    void Push(const T& val)
    {
        if(topIndex >= size)
        {
            this->Resize();
        }

        data[topIndex++] = val;
    }

    // return top el and del it
    T Pop()
    {
        if (topIndex == 0)
        {
            throw "isEmpty == true";
        }

        return data[--topIndex];
    }

    //
    T Top()
    {
        if (topIndex == 0)
        {
            throw "isEmpty == true";
        }
        return data[topIndex-1];
    }

    T operator[](const size_t index) const
    {
        if(index >= topIndex) throw "Out of Array";
        return data[index];
    }

    size_t getSize() const noexcept
    {
        return topIndex;
    }

    friend std::ostream& operator << (std::ostream &os, const TStack<T>& stack)
    {
        for (size_t i = 0; i < stack.topIndex;i++)
        {
            os<<stack.data[i]<<" ";
        }
        return os;
    }



};


#endif //UNTITLED4_TSTACK_H
