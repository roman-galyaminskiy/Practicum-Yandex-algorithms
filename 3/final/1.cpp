// Отчет: https://contest.yandex.ru/contest/23815/run-report/74064906/

// #include "solution.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <limits>

// первые 9 попыток пытался решить задачу в два прохода: ищем минимальный 
// элемент бинарным поиском, вызываем бинарный поиск с учетом смещения. Slack
// навел на идею сделать в один проход
//
// UPD: нашел ошибку в поиске минимального элемента, не было проверки на 
// базовый случай
int binary_search(const std::vector<int>& vec, int l, int r, int k) {
    if (l <= r) {        
        int m = l + (r - l)/2;

        if (vec[m] == k) {
            return m;
        } else {
            if (vec[l] < vec[r]) {
                if (vec[m] > k) {
                    return binary_search(vec, l, m - 1, k);
                }
                else {
                    return binary_search(vec, m + 1, r, k);
                }
            } else {
                if (vec[l] < vec[m - 1]) {
                    if (k >= vec[l] && k <= vec[m - 1]) {
                        return binary_search(vec, l, m - 1, k);
                    }
                    else {
                        return binary_search(vec, m + 1, r, k);
                    }
                } else {
                    if (k >= vec[m + 1] && k <= vec[r]) {
                        return binary_search(vec, m + 1, r, k);
                    }
                    else {
                        return binary_search(vec, l, m - 1, k);
                    }
                }
            }
        }
    }
    else {
        return -1;
    }
}

int broken_search(const std::vector<int>& vec, int k) {
    if (vec.size() == 0) {
        return -1;
    } else if (vec.size() == 1) {
        if (vec[0] == k) return 0;
        return -1;
    } else {   
        return binary_search(vec, 0, vec.size() - 1, k);
    }    
}

void test() {
    std::vector<int> arr = {19, 21, 100, 101, 1, 4, 5, 7, 12};
    assert(6 == broken_search(arr, 5));
}