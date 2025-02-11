
#ifndef LR2_MERGESORTER_H
#define LR2_MERGESORTER_H
#include <iostream>
#include "ISorter.h"

template <typename T>
class MergeSorterOpt: public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(const T&, const T&)) override {
        MergeSortOpt(seq, 0, seq->getLength() - 1, cmp);
        return seq;
    }
private:
    void MergeSortOpt(Sequence<T>* seq, int left, int right, int (*cmp)(const T&, const T&)) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            MergeSortOpt(seq, left, mid, cmp);
            MergeSortOpt(seq, mid + 1, right, cmp);
            Merge(seq, left, mid, right, cmp);
        }
    }

    void Merge(Sequence<T>* seq, int left, int mid, int right, int (*cmp)(const T&, const T&)) {
        int i = left;    //начало левой части
        int j = mid + 1; //начало правой части

        while (i <= mid && j <= right) {
            if (cmp(seq->get(i), seq->get(j)) <= 0) {
                i++;
            } else {
                T temp = seq->get(j);
                int index = j;

                //сдвиг влево
                while (index != i) {
                    seq->set(index, seq->get(index - 1));
                    index--;
                }
                seq->set(i, temp);

                i++;
                mid++;
                j++;
            }
        }
    }
};

#endif //LR2_MERGESORTER_H

