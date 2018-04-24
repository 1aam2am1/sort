//
// Created by MacBook on 23.04.2018.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H


template<typename T, class Compare>
void quicksort(T *t, uint32_t size, const Compare &comp) {
    if (size <= 1) {
        return;
    }

    auto tym = t[size / 2];
    t[size / 2] = t[size - 1];
    t[size - 1] = tym;


    uint a = 0;
    for (int it = 0; it < (size - 1); ++it) {
        if (comp(t[it], t[size - 1])) {
            tym = t[it];
            t[it] = t[a];
            t[a] = tym;
            ++a;
        }
    }

    tym = t[size - 1];
    t[size - 1] = t[a];
    t[a] = tym;

    quicksort(t, a, comp);
    quicksort(t + a + 1, size - a - 1, comp);

};


#endif //SORT_QUICKSORT_H
