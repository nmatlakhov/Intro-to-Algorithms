#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftDown(std::vector<int>& heap, int idx) {
    int hsize = heap.size() - 1;

    int left = 2 * idx;
    int right = 2 * idx + 1;
    int idx_largest;
    if (hsize < left) { return idx; }

    if ((right <= hsize) & (heap[left] < heap[right])) {
        idx_largest = right;
    }
    else {
        idx_largest = left;
    }

    int return_idx = idx;
    if (heap[idx] < heap[idx_largest]) {
        int temp = heap[idx];
        heap[idx] = heap[idx_largest];
        heap[idx_largest] = temp;
        return_idx = siftDown(heap, idx_largest);
    }

    return return_idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = { -1, 12, 1, 8, 3, 4, 7 };
    assert(siftDown(sample, 2) == 5);
}


int main() {
    test();
}
#endif