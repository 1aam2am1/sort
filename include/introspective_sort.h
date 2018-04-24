//
// Created by MacBook on 23.04.2018.
//

#ifndef SORT_INTROSPECTIVE_SORT_H
#define SORT_INTROSPECTIVE_SORT_H

#include <cmath>


template<typename T, class Compare>
void introspective_sort(T *t, uint32_t size, const Compare &comp, int maxdepth) {
    if (!maxdepth) {
        for (int i = 1; i < size; ++i) {
            if (!comp(t[i - 1], t[i])) {
                auto tym = t[i - 1];
                t[i - 1] = t[i];
                t[i] = tym;

                int j = i - 1;
                while (j > 0) {
                    if (!comp(t[j - 1], t[j])) {
                        tym = t[j - 1];
                        t[j - 1] = t[j];
                        t[j] = tym;

                        --j;
                    } else {
                        break;
                    }
                }
            }
        }
        return;
    }

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

    introspective_sort(t, a, comp, maxdepth - 1);
    introspective_sort(t + a + 1, size - a - 1, comp, maxdepth - 1);

}

template<typename T, class Compare>
void introspective_sort(T *t, uint32_t size, const Compare &comp) {
    introspective_sort(t, size, comp, 2 * log2(size));
};


#endif //SORT_INTROSPECTIVE_SORT_H
