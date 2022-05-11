#pragma once
#include <iostream>

using namespace std;

template <class Type>
class MyVector
{
public:

    MyVector();
    MyVector(const size_t size);
    MyVector(const size_t size, const Type& filler);

    ~MyVector();

    void PushBack(const Type& inserted);
    void Insert(const unsigned int place, const Type& inserted);
    void PopBack();

    void Resize(const size_t size);
    void Reserve(const size_t capacity);
    void ShrinkToFit();

    size_t Size() const;
    size_t Capacity() const;

    template <class T>
    friend ostream& operator<<(ostream& os, const MyVector<T>& myVector);

    Type& operator[](unsigned int index);

    class Iterator
    {
    public:

        Iterator(Type* pointer) : _pointer(pointer) {};

        Iterator() = default;
        Iterator(const Iterator& it) = default;

        Type& operator*() { return *_pointer; };
        Type* operator->() { return _pointer; };

        Iterator operator=(const Iterator& it) { return _pointer = it._pointer; }

        Iterator operator++() { return ++_pointer; };
        Iterator operator--() { return --_pointer; };

        Iterator operator++(int) { return _pointer++; };
        Iterator operator--(int) { return _pointer--; };

        Iterator operator+(const int n) { return _pointer + n; }
        Iterator operator-(const int n) { return _pointer - n; }

        bool operator==(const Iterator& it) {return _pointer == it._pointer;}
        bool operator!=(const Iterator& it) {return _pointer != it._pointer;}
        bool operator<(Iterator& it) { return _pointer < it._pointer; };
        bool operator>(Iterator& it) { return _pointer > it._pointer; };
        bool operator<=(Iterator& it) { return _pointer <= it._pointer; };
        bool operator>=(Iterator& it) { return _pointer >= it._pointer; };

    private:

        Type* _pointer = nullptr;    
    };

    Iterator Begin() { return _data; };
    Iterator End() { return (_size + _data - 1); };

private:

    Type* _data = nullptr;

    size_t _size = 0;
    size_t _capacity = 0;

    unsigned int _coef = 2;

    void ChangeMemory(const size_t newSizeMemory);
};

template <class Type>
MyVector<Type>::MyVector()
    : _capacity(1), _data(reinterpret_cast<Type*>(new int8_t[1 * sizeof(Type)]))
{
}

template <class Type>
MyVector<Type>::MyVector(const size_t size)
    : _size(size), _capacity(size), _data(reinterpret_cast<Type*>(new int8_t[size * sizeof(Type)]))
{
}

template <class Type>
MyVector<Type>::MyVector(const size_t size, const Type& filler)
    : _size(size), _capacity(size), _data(reinterpret_cast<Type*>(new int8_t[size * sizeof(Type)]))
{
    for (unsigned int i = 0; i < _size; i++) {

        new (_data + i) Type(filler);
    }
}

template <class Type>
MyVector<Type>::~MyVector()
{
    for (unsigned int i = 0; i < _size; i++) {

        _data[i].~Type();
    }

    delete[] reinterpret_cast<int8_t*>(_data);
}

template <class Type>
size_t MyVector<Type>::Size() const { return _size; }

template <class Type>
size_t MyVector<Type>::Capacity() const { return _capacity; }

template <class Type>
void MyVector<Type>::ChangeMemory(const size_t newSizeMemory)
{
    Type* buff = reinterpret_cast<Type*>(new int8_t[newSizeMemory * sizeof(Type)]);

    for (unsigned int i = 0; i < _size; i++) {

        new (buff + i) Type(_data[i]);
    }

    for (unsigned int i = 0; i < _size; i++) {

        _data[i].~Type();
    }

    delete[] reinterpret_cast<int8_t*>(_data);
    _data = buff;
}

template <class Type>
void MyVector<Type>::Reserve(const size_t capacity)
{
    if (capacity < _size) { return; }
    if (capacity == _size) { 

        ShrinkToFit();
        return;
    }

    _capacity = capacity;
    ChangeMemory(_capacity);
}

template <class Type>
void MyVector<Type>::Resize(const size_t size)
{
    if (size <= _size) { return; }
    if (size > _capacity) { Reserve(size); };

    _size = size;
}

template <class Type>
void MyVector<Type>::ShrinkToFit()
{
    if (_size == _capacity) { return; }

    _capacity = _size;
    ChangeMemory(_capacity);
}

template <class Type>
void MyVector<Type>::PushBack(const Type& inserted)
{
    if (_size == _capacity) { Reserve(_capacity * _coef); }

    new (_data + _size) Type(inserted);
    _size++;
}

template <class Type>
void MyVector<Type>::PopBack()
{
    if (_size == 0) { return; }

    _data[_size].~Type();
    _size--;
}

template <class Type>
void MyVector<Type>::Insert(const unsigned int place, const Type& inserted)
{
    if (place == 0 || place > _size) { return; } 
    if (_size == _capacity) { _capacity = _capacity * _coef; }
    _size++;

    const unsigned int n = place;

    Type* buff = reinterpret_cast<Type*>(new uint8_t[_capacity * sizeof(Type)]);
    
    for (unsigned int i = 0; i < (n - 1); i++) {

        new(buff + i) Type(_data[i]);
    }

    new (_data + place - 2) Type(inserted);

    for (unsigned int i = (n - 1); i < _size; i++) {

        new(buff + i) Type(_data[i - 1]);
    }

    for (unsigned int i = 0; i < _size - 1; i++) {

        _data[i].~Type();
    }

    delete[] reinterpret_cast<int8_t*>(_data);
    _data = buff;
}

template <class Type>
Type& MyVector<Type>::operator[](unsigned int index)
{
    return _data[index];
}

template <class Type>
ostream& operator<<(ostream& os, const MyVector<Type>& myVector)
{
    for (unsigned int i = 0; i < myVector._size; i++) {

        os << "[" << i + 1 << "]" << endl;
        os << myVector._data[i] << endl;
    }

    return os;
}