
#ifndef LR2_MERGESORTER_H
#define LR2_MERGESORTER_H
#include <iostream>
#include "ISorter.h"
template <typename T>
class MergeSorter: public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* seq, std::function<int(const T&, const T&)> cmp) override {
        MergeSort(seq, 0, seq->getLength() - 1, cmp);
        return seq;
    }
private:
    void MergeSort(Sequence<T>* seq, int left, int right, std::function<int(const T&, const T&)> cmp) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            MergeSort(seq, left, mid, cmp);
            MergeSort(seq, mid + 1, right, cmp);
            Merge(seq, left, mid, right, cmp);
        }
    }

    void Merge(Sequence<T>* seq, int left, int mid, int right, std::function<int(const T&, const T&)> cmp) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        T* L = new T[n1];
        T* R = new T[n2];

        for (int i = 0; i < n1; i++)
            L[i] = seq->get(left + i);
        for (int j = 0; j < n2; j++)
            R[j] = seq->get(mid + 1 + j);

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (cmp(L[i], R[j]) <= 0) {
                seq->set(k, L[i]);
                i++;
            } else {
                seq->set(k, R[j]);
                j++;
            }
            k++;
        }
        while (i < n1) {
            seq->set(k, L[i]);
            i++;
            k++;
        }
        while (j < n2) {
            seq->set(k, R[j]);
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }
};


#endif //LR2_MERGESORTER_H
