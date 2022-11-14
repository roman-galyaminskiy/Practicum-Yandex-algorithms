// #include "solution.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <limits>

int bs_count = 0;
int os_count = 0;

size_t index_with_offset(size_t i, size_t size, size_t offset) {
    return (i + offset) % size;
}

int broken_binary_search(const std::vector<int>& vec, size_t l, size_t r, size_t offset, int k) {
    bs_count++;
    if (l <= r) {
        size_t m = l + (r - l)/2;
        size_t m_with_offset = index_with_offset(m, vec.size(), offset);

        if (vec[m_with_offset] == k) {
            return m_with_offset;
        }
        else if (vec[m_with_offset] > k) {
            return broken_binary_search(vec, l, m - 1, offset, k);
        }
        else {
            return broken_binary_search(vec, m + 1, r, offset, k);
        }
    }
    else {
        return -1;
    }
}

size_t offset_search(const std::vector<int>& vec, size_t l, size_t r) {
    if (l < r) {
        os_count++;
        int m = l + (r - l)/2;
        // printf("l=%ld r=%ld m=%d os_count=%d\n", l, r, m, os_count);

        if (vec[m] < vec[m - 1] && vec[m] < vec[m + 1]) {
            return m;
        } else if (vec[l] > vec[m]) {
            return offset_search(vec, l, m - 1);
        } else {
            return offset_search(vec, m + 1, r);
        }
    } else {
        return 0;
    }
}

int broken_search(const std::vector<int>& vec, int k) {
    if (vec.size() == 0) {
        return -1;
    } else if (vec.size() == 1) {
        if (vec[0] == k) return 0;
        return -1;
    } else {
        size_t offset;
        if (vec[0] < vec[1] && vec[0] < vec[vec.size() - 1]) {
            offset = 0;
        } else if (vec[vec.size() - 1] < vec[vec.size() - 2] && vec[vec.size() - 1] < vec[0]) {
            offset = vec.size() - 1;
        }
        else {
            offset = offset_search(vec, 0, vec.size() - 1);
        }

        int min_value = vec[offset];
        int max_value;

        if (offset == 0) {
            max_value = vec[vec.size() - 1];
        } else {
            max_value = vec[offset - 1];
        }

        if (k < min_value || k > max_value) {
            return -1;
        } else {
            return broken_binary_search(vec, 0, vec.size() - 1, offset, k);
        }
    }    
}



// void test() {
//     std::vector<int> arr = {9, 1, 3, 8};
//     assert(3 == broken_search(arr, 8));
//     assert(2 == broken_search(arr, 3));
//     assert(1 == broken_search(arr, 1));
//     assert(0 == broken_search(arr, 9));
// }

void test() {
    // std::vector<int> arr = {167, 168, 169, 170, 171, 172, 176, 178, 179, 181, 183, 184, 185, 187, 190, 193, 195, 196, 197, 198, 199, 200, 202, 204, 206, 207, 208, 209, 210, 211, 212, 213, 215, 217, 218, 220, 225, 226, 234, 236, 243, 245, 247, 252, 253, 254, 255, 260, 261, 264, 268, 269, 270, 271, 272, 274, 278, 284, 287, 288, 291, 293, 296, 297, 299, 302, 303, 304, 306, 309, 311, 312, 313, 320, 321, 322, 325, 331, 332, 333, 337, 339, 340, 342, 343, 346, 347, 349, 350, 353, 354, 355, 356, 359, 362, 366, 369, 373, 375, 378, 384, 390, 393, 397, 399, 403, 410, 414, 415, 417, 418, 419, 424, 425, 428, 435, 436, 440, 444, 454, 456, 457, 458, 460, 461, 465, 467, 468, 470, 472, 473, 474, 478, 479, 480, 481, 484, 485, 487, 489, 495, 501, 504, 506, 512, 514, 515, 517, 518, 521, 525, 526, 534, 535, 546, 557, 559, 562, 565, 566, 568, 569, 578, 582, 586, 589, 590, 592, 594, 595, 598, 599, 600, 602, 609, 610, 613, 614, 616, 617, 618, 619, 620, 621, 623, 625, 632, 634, 637, 639, 647, 648, 649, 650, 658, 665, 666, 670, 671, 673, 677, 678, 679, 681, 685, 686, 687, 688, 689, 691, 692, 693, 695, 697, 701, 702, 703, 706, 708, 709, 711, 712, 713, 715, 718, 720, 721, 723, 724, 729, 730, 731, 733, 734, 736, 737, 738, 739, 740, 742, 743, 745, 747, 750, 751, 763, 769, 771, 772, 773, 774, 775, 777, 778};
    // assert(208 == broken_search(arr, 689))
    std::vector<int> arr = {19, 21, 100, 101, 1, 4, 5, 7, 12};
    assert(6 == broken_search(arr, 5));
}

// int main() {
//     test();
//     // printf("os_count=%d bs_count=%d\n", os_count, bs_count);
//     return 0;
// }