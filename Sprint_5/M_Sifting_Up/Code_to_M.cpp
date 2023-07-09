#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftUp(std::vector<int>& heap, int idx) {
    if (idx == 1) { return idx; }
    int parent_idx = idx / 2;
    int return_idx = idx;
    if (heap[parent_idx] < heap[idx]) {
        int temp = heap[idx];
        heap[idx] = heap[parent_idx];
        heap[parent_idx] = temp;
        return_idx = siftUp(heap, parent_idx);
    }
    return return_idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = { -1, 12, 6, 8, 3, 15, 7 };
    assert(siftUp(sample, 5) == 1);
}


int main() {
    test();
}
#endif