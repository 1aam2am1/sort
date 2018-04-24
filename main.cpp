#include <iostream>
#include <merge_sort.h>
#include <quicksort.h>
#include <introspective_sort.h>
#include <random>

int main() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, INT_MAX);
    auto rand = std::bind(distribution, generator);

    scanf("%*i");

    auto comp = [](const int &a, const int &b) -> bool { return a <= b; };
    auto comp2 = [](const int &a, const int &b) -> bool { return a >= b; };

    for (int size : {10000, 50000, 100000, 500000, 1000000}) {
        printf("\nTable size: %i\n", size);

        //1 i 3
        for (int i = 0; i < 3; ++i) {
            int *tab;
            tab = new int[size];

            std::chrono::nanoseconds time;

            //1
            switch (i) {
                case 0: {
                    printf("merge_sort\n");

                    time = time.zero();
                    for (int k = 0; k < 100; ++k) {

                        for (int j = 0; j < size; ++j) {
                            tab[j] = rand();
                        }

                        auto start = std::chrono::steady_clock::now();

                        merge_sort(tab, size, comp);

                        time += std::chrono::steady_clock::now() - start;
                    }
                    break;
                }
                case 1: {
                    printf("quicksort\n");

                    time = time.zero();
                    for (int k = 0; k < 100; ++k) {

                        for (int j = 0; j < size; ++j) {
                            tab[j] = rand();
                        }

                        auto start = std::chrono::steady_clock::now();

                        quicksort(tab, size, comp);

                        time += std::chrono::steady_clock::now() - start;
                    }
                    break;
                }
                case 2: {
                    printf("introspective_sort\n");

                    time = time.zero();
                    for (int k = 0; k < 100; ++k) {

                        for (int j = 0; j < size; ++j) {
                            tab[j] = rand();
                        }

                        auto start = std::chrono::steady_clock::now();

                        introspective_sort(tab, size, comp);

                        time += std::chrono::steady_clock::now() - start;
                    }
                    break;
                }
            }


            printf("Execution time: %lli\n", std::chrono::duration_cast<std::chrono::nanoseconds>(time).count());

            //3
            switch (i) {
                case 0: {
                    printf("merge_sort\n");

                    time = time.zero();
                    for (int k = 0; k < 100; ++k) {

                        for (int j = 0; j < size; ++j) {
                            tab[j] = rand();
                        }

                        auto start = std::chrono::steady_clock::now();

                        merge_sort(tab, size, comp2);

                        time += std::chrono::steady_clock::now() - start;
                    }
                    break;
                }
                case 1: {
                    printf("quicksort\n");

                    time = time.zero();
                    for (int k = 0; k < 100; ++k) {

                        for (int j = 0; j < size; ++j) {
                            tab[j] = rand();
                        }

                        auto start = std::chrono::steady_clock::now();

                        quicksort(tab, size, comp2);

                        time += std::chrono::steady_clock::now() - start;
                    }
                    break;
                }
                case 2: {
                    printf("introspective_sort\n");

                    time = time.zero();
                    for (int k = 0; k < 100; ++k) {

                        for (int j = 0; j < size; ++j) {
                            tab[j] = rand();
                        }

                        auto start = std::chrono::steady_clock::now();

                        introspective_sort(tab, size, comp2);

                        time += std::chrono::steady_clock::now() - start;
                    }
                    break;
                }
            }

            printf("Vice execution time: %lli\n", std::chrono::duration_cast<std::chrono::nanoseconds>(time).count());


            delete[] tab;
        }
    }

    printf("Part sorted");
    //2
    for (int size : {10000, 50000, 100000, 500000, 1000000}) {
        printf("\nTable size: %i\n", size);

        for (int k = 0; k < 6; ++k) {
            double sorted;
            switch (k) {
                case 0:
                    sorted = 25;
                    break;
                case 1:
                    sorted = 50;
                    break;
                case 2:
                    sorted = 75;
                    break;
                case 3:
                    sorted = 95;
                    break;
                case 4:
                    sorted = 99;
                    break;
                case 5:
                    sorted = 99.7;
                    break;
            }
            printf("Pre sorted: %lf\n", sorted);

            //2
            for (int i = 0; i < 3; ++i) {
                int *tab;
                tab = new int[size];


                std::chrono::nanoseconds time;

                //2
                switch (i) {
                    case 0: {
                        printf("merge_sort\n");

                        time = time.zero();
                        for (int k = 0; k < 100; ++k) {

                            for (int j = 0; j < size; ++j) {
                                tab[j] = rand();
                            }
                            quicksort(tab, size * sorted / 100, comp);

                            auto start = std::chrono::steady_clock::now();

                            merge_sort(tab, size, comp);

                            time += std::chrono::steady_clock::now() - start;
                        }
                        break;
                    }
                    case 1: {
                        printf("quicksort\n");

                        time = time.zero();
                        for (int k = 0; k < 100; ++k) {

                            for (int j = 0; j < size; ++j) {
                                tab[j] = rand();
                            }
                            quicksort(tab, size * sorted / 100, comp);

                            auto start = std::chrono::steady_clock::now();

                            quicksort(tab, size, comp);

                            time += std::chrono::steady_clock::now() - start;
                        }
                        break;
                    }
                    case 2: {
                        printf("introspective_sort\n");

                        time = time.zero();
                        for (int k = 0; k < 100; ++k) {

                            for (int j = 0; j < size; ++j) {
                                tab[j] = rand();
                            }
                            quicksort(tab, size * sorted / 100, comp);

                            auto start = std::chrono::steady_clock::now();

                            introspective_sort(tab, size, comp);

                            time += std::chrono::steady_clock::now() - start;
                        }
                        break;
                    }
                }


                printf("Execution time: %lli\n", std::chrono::duration_cast<std::chrono::nanoseconds>(time).count());


                delete[] tab;
            }
        }
    }

    return 0;
}