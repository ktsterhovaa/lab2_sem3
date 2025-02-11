
#ifndef LR2_ISORTER_H
#define LR2_ISORTER_H
#include "Sequence.h"
#include <iostream>

template<typename T>
class ISorter {
public:
    virtual Sequence<T>* Sort(Sequence<T>* seq, std::function<int(const T&, const T&)> cmp) = 0;
    virtual ~ISorter() {}
};



#endif // LR2_ISORTER_H
