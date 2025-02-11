
#ifndef LR2_QUICKSORTER_H
#define LR2_QUICKSORTER_H
#include <iostream>
#include "ISorter.h"

template<typename T>
class QuickSorter : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* seq, std::function<int(const T&, const T&)> cmp) override {
        QuickSort(seq, 0, seq->getLength() - 1, cmp);
        return seq;
    }
private:
    void QuickSort(Sequence<T>* seq, int left, int right, std::function<int(const T&, const T&)> cmp) {
        if (left >= right) {
            return;
        }
        int pivotIndex = Partition(seq, left, right, cmp);
        QuickSort(seq, left, pivotIndex - 1, cmp);
        QuickSort(seq, pivotIndex + 1, right, cmp);
    }

    int Partition(Sequence<T>* seq, int left, int right, std::function<int(const T&, const T&)> cmp) {
        T pivot = seq->get(right);
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (cmp(seq->get(j), pivot) <= 0) {
                i++;
                std::swap(seq->get(i), seq->get(j));
            }
        }
        std::swap(seq->get(i + 1), seq->get(right));
        return i + 1;
    }
};
#endif //LR2_QUICKSORTER_H
