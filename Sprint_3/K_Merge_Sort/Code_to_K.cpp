#include <vector>
#include <cassert>
//#include <iostream>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;

std::vector<int> merge(
	CIterator left_begin, CIterator left_end,
	CIterator right_begin, CIterator right_end) {

	int mid = left_end - left_begin, rest = right_end - right_begin;
	int n = mid + rest;
	std::vector<int> result(n);
	
	int l = 0, r = 0, k = 0;
	while ((l < mid) && (r < rest)) {

		if (*(left_begin + l) < *(right_begin + r)) {
			result[k] = *(left_begin + l);
			l += 1;
		}
		else {
			result[k] = *(right_begin + r);
			r += 1;
		}
		k += 1;
	}

	while (l < mid) {
		result[k] = *(left_begin + l);
		l += 1;
		k += 1;
	}

	while (r < rest) {
		result[k] = *(right_begin + r);
		r += 1;
		k += 1;
	}


	return result;
}

void merge_sort(Iterator begin, Iterator end) {
	int n = end - begin;
	if (n == 1) { return; }
	int mid = (n / 2) + (n % 2);
	int rest = n - mid;

	std::vector<int> left_temp(begin, begin + mid);
	std::vector<int> right_temp(begin + mid, end);

	Iterator l_begin = left_temp.begin(), l_end = left_temp.end();
	Iterator r_begin = right_temp.begin(), r_end = right_temp.end();

	merge_sort(l_begin, l_end);
	merge_sort(r_begin, r_end);

	int l = 0, r = 0, k = 0;
	while ((l < mid) && (r < rest)) {

		if (*(l_begin + l) < *(r_begin + r)) {
			*(begin + k) = *(l_begin + l);
			l += 1;
		}
		else {
			*(begin + k) = *(r_begin + r);
			r += 1;
		}
		k += 1;
	}

	while (l < mid) {
		*(begin + k) = *(l_begin + l);
		l += 1;
		k += 1;
	}

	while (r < rest) {
		*(begin + k) = *(r_begin + r);
		r += 1;
		k += 1;
	}
}

void test_merge_sort() {
	std::vector<int> a = { 1, 4, 9 };
	std::vector<int> b = { 2, 10, 11 };
	std::vector<int> c = merge(a.cbegin(), a.cend(), b.cbegin(), b.cend());
	std::vector<int> expected = { 1, 2, 4, 9, 10, 11 };
	assert(c == expected);
	std::vector<int> d = { 1, 4, 2, 10, 1, 2 };
	std::vector<int> sorted = { 1, 1, 2, 2, 4, 10 };
	merge_sort(d.begin(), d.end());
	assert(d == sorted);
}

//int main() {
//	test_merge_sort();
//
//	return 0;
//}