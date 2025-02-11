#ifndef LR2_DYNAMIC_ARRAY_H
#define LR2_DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>
#include "IndexOutOfRange.h"

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;
    int capacity;
    bool *defined;

    void checkIndex(int index) const {
        if (index < 0 || index >= size) {
            throw IndexOutOfRange(std::string("Index ") + std::to_string(index) + " out of range 0.." + std::to_string(size - 1));
        }
    }

public:
    explicit DynamicArray(int arraySize = 0)
        : size(arraySize), capacity(arraySize > 0 ? arraySize : 1) {
        if (size < 0) throw IndexOutOfRange("Size < 0");
        data = new T[capacity];
        defined = new bool[capacity];
        for (int i = 0; i < capacity; i++) {
            defined[i] = false;
        }
    }


    DynamicArray(const DynamicArray<T>& dynamicArray)
        : size(dynamicArray.size), capacity(dynamicArray.capacity) {
        data = new T[capacity];
        defined = new bool[capacity];

        for (int i = 0; i < size; ++i) {
            data[i] = dynamicArray.data[i];
            defined[i] = dynamicArray.defined[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
        delete[] defined;
    }

    T& get(int index) const {
        checkIndex(index);
        if (!defined[index]) {
            throw IndexOutOfRange(std::string("Element with index ") + std::to_string(index) + " not defined");
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }

    void set(int index, T value) {
        checkIndex(index);
        data[index] = value;
        defined[index] = true;
    }

    void resize(int newSize) {
        if (newSize < 0) {
            throw std::bad_array_new_length();
        }

        if (newSize > capacity) {
            capacity = newSize;
            T* newData = new T[capacity];
            bool* newDefined = new bool[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
                newDefined[i] = defined[i];
            }
            delete[] data;
            delete[] defined;
            data = newData;
            defined = newDefined;
        }
        size = newSize;
        for (int i = size; i < capacity; i++) {
            defined[i] = false;
        }
    }

    void append(T item) {
        resize(size + 1);
        set(size - 1, item);
    }

    void prepend(T item) {
        resize(size + 1);
        for (int i = size - 1; i >= 1; i--) {
            data[i] = data[i - 1];
            defined[i] = defined[i - 1];
        }
        data[0] = item;
        defined[0] = true;
    }

    void insertAt(T item, const int index) {
        resize(size + 1);
        checkIndex(index);
        for (int i = size - 1; i > index; i--) {
            data[i] = data[i - 1];
            defined[i] = defined[i - 1];
        }
        set(index, item);
    }

    void removeAt(const int index) {
        checkIndex(index);
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
            defined[i - 1] = defined[i];
        }
        resize(size - 1);
    }

    void print() const {
        std::cout << "DynamicArray size = " << size << ":";
        for (int i = 0; i < size; i++) {
            if (defined[i]) {
                std::cout << " " << data[i];
            } else {
                std::cout << " - ";
            }
        }
        std::cout << std::endl;
    }

    T operator[](size_t index) const {
        return get(index);
    }

    T& operator[](size_t index) {
        checkIndex(index);
        defined[index] = true;
        return data[index];
    }

    void push_back(const T& value) {
        append(value);
    }

    int getCapacity() const {
        return capacity;
    }
};

#endif // LR2_DYNAMIC_ARRAY_H
