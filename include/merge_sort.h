//
// Created by MacBook on 23.04.2018.
//

#ifndef SORT_MERGE_SORT_H
#define SORT_MERGE_SORT_H


template<typename T, class Compare>
void merge_sort(T *t, uint32_t size, const Compare &comp) {
    if (size <= 1) {
        return;
    }

    merge_sort(t, size / 2, comp);
    merge_sort(t + size / 2, size - size / 2, comp);


    auto *wsk = new T[size];
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0; //destignation

    while (true) {
        if (a >= (size / 2)) {
            while (b < (size - size / 2)) {
                wsk[c] = t[(size / 2) + b];
                ++c;
                ++b;
            }
            break;
        }
        if (b >= (size - size / 2)) {
            while (a < (size / 2)) {
                wsk[c] = t[a];
                ++c;
                ++a;
            }
            break;
        }
        if (comp(t[a], t[(size / 2) + b])) {
            wsk[c] = t[a];
            ++c;
            ++a;
        } else {
            wsk[c] = t[(size / 2) + b];
            ++c;
            ++b;
        }
    }

    memmove(t, wsk, sizeof(T) * size);

    delete[] wsk;
}


#endif //SORT_MERGE_SORT_H
