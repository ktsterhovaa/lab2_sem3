
#ifndef LR2_SELECTIONSORTER_H
#define LR2_SELECTIONSORTER_H
#include <iostream>
#include "ISorter.h"
template <typename T>
class SelectionSorter: public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* seq, std::function<int(const T&, const T&)> cmp) override {
        for (int i = 0; i < seq->getLength() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < seq->getLength(); j++) {
                if (cmp(seq->get(j), seq->get(minIndex)) < 0) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(seq->get(i), seq->get(minIndex));
            }
        }
        return seq;
    }
};
#endif //LR2_SELECTIONSORTER_H
