#ifndef LR2_MUTABLE_ARRAY_SEQUENCE_H
#define LR2_MUTABLE_ARRAY_SEQUENCE_H

#include <cwchar>
#include "DynamicArray.h"
#include "Sequence.h"
template <typename T>
class MutableArraySequence : public Sequence<T> {
private:
    DynamicArray<T> data;
public:

    MutableArraySequence(T *data, int arraySize) : data(data, arraySize){}

    MutableArraySequence() : data() {};

    explicit  MutableArraySequence(const DynamicArray<T> &array) : data(array) {};

    T getFirst() const override {
        return data.get(0);
    };

    T getLast() const override {
        return data.get(data.getSize() - 1);
    };

    T& get(int index) override{
        return data[index];
    }
    const T& get(int index) const override{
        return data[index];
    }
    void set(int index, const T& value) override {
        data[index] = value;
    }

    T operator[](int i) const override {
        return data[i];
    }
    T &operator[](int i) override {
        return data[i];
    }

    Sequence<T> *getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex > endIndex) {
            throw IndexOutOfRange(string("Index startIndex <= endIndex"));
        }
        int size = endIndex - startIndex + 1;
        DynamicArray<T> dynamicArray(size);
        for (int i = 0; i < size; i++) {
            dynamicArray[i] = get(startIndex + i);
        }
        return new  MutableArraySequence<T>(dynamicArray);
    }

    int getLength() const override {
        return data.getSize();
    }

    void append(T item) override{
        data.append(item);
    };

    void prepend(T item) override{
        data.prepend(item);
    };

    void insertAt(T item, int index) override{
        data.insertAt(item, index);
    };

    Sequence<T> *concat(Sequence<T> *list) override {
        auto *result = new  MutableArraySequence<T>(this->data);
        result->data.resize(getLength() + list->getLength());
        for (int i = 0; i < list->getLength(); i++) {
            result->data.set(getLength() + i, list->get(i));
        }
        return result;
    };

    void removeAt(int index) override{
        data.removeAt(index);
    }

    void print() override{
        data.print();
    }

    virtual ~MutableArraySequence<T>() = default;

    Sequence<T> *map(T (*f)(T)) const override{
        Sequence<T> *res = new  MutableArraySequence<T>();
        for (int i = 0; i < getLength(); i++){
            res->append(f(data.get(i)));
        }
        return res;
    }

    T reduce(T (*f)(T, T)) const override{
        T result = data.get(0);
        for (int i = 1; i < data.getSize(); i++){
            result = f(result, data.get(i));
        }
        return result;
    }

    Sequence<T> *where(bool (*h)(T)) const override {
        auto *res = new  MutableArraySequence<T>;
        for (int i = 0; i < getLength(); i++){
            T item = data.get(i);
            if (h(item)){
                res->append(item);
            }
        }
        return res;
    }
    void push_back(const T& value) {
        data.push_back(value);
    }
    int getSize() const {
        return data.getSize();
    }

};





#endif
