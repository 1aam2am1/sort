//
// Created by MacBook on 24.04.2018.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H


template<typename T, class Compare>
void heapsort(T *t, uint32_t size, const Compare &comp) {
    for (int i = 1; i < size; ++i) {
        int j = i;
        int k = j / 2;
        int tym = t[i];
        while ((k > 0) && (t[k] < tym)) {
            t[j] = t[k];
            j = k;
            k = j / 2;
        }
        t[j] = tym;
    }

// Rozbieramy kopiec

    for (int i = size - 1; i > 0; --i) {
        std::swap(t[0], t[i]);
        int j = 0;
        int k = 1;
        while (k < i) {
            int m;
            if ((k + 1 < i) && (t[k + 1] > t[k]))
                m = k + 1;
            else
                m = k;
            if (t[m] <= t[j]) break;
            std::swap(t[j], t[m]);
            j = m;
            k = j + j;
        }
    }

};


#endif //SORT_HEAPSORT_H
