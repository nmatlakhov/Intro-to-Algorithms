/* https://contest.yandex.ru/contest/23815/run-report/78630627/ */
/*
ПРИНЦИП РАБОТЫ:

Поскольку изначально массив vec был отсортирован по возрастанию, то чтобы найти конкретный элемент за O(log n) мы будем пользоваться модификацией бинарного поиска. В зависимости от того, где будет
отсортированная половина мы будем выбирать интервал поиска либо отсортированную половину, либо половину с разрывом последовательности. Если требуемый элемент не найдется - вернем -1.
Если элемент найдется, то он будте находится в середине массива на соответствующем этапе поиска. Поскольку алгортим будет являтся по сути бинарным поиском со сложным критерием выбора интервала,
то его временная сложность будет равна O(log n).

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ:
Следует непосредственно из процесса описанного ниже, а также принципа работы бинарного поиска с добавлением модификации к правлу определения левой или правой части массива;
На каждом шаге будет сужаться диапазон поиска, в какой-то момент левая граница станет равной правой => вернется -1, иначе элемент найдется => будет находится в значении med;

1) Обозначим индексы начала и конца массива как left и right соответственно;

2) Находим серединный элемент vec[mid] аналогично тому, как это делается в бинарном поиске: mid = (left + right) / 2, где деление является целочисленным;

3) Проверяем, является ли элемент посередине искомым элементом k:
    а) vec[mid] == k - возвращаем индекс середины;
    б) vec[mid] != k - продолжаем дальше;

4) Разделим массив на две части по его середине mid, поскольку мы пользуемся полуинтервалами, то mid не будет входить ни в один из них;

5) Если k > vec[mid], то в зависимости от того, какая половина отсортирована мы будем искать элемент в правой или левой части массива:
    (1) Правая половина отсортирована: vec[mid] <= vec[right-1], где равенство нужно для случая массива с двумя элементами, поскольку vec[mid] принадлежит правому полуинтервалу; 
        В этом случае проверяем: в каком случае мы попадаем на левую часть массива:
        а) Если k > vec[right - 1], то попадаем => смотрим левую половину массива, поскольку слева будет возрастающая последовательность до разрыва и k > всех элементов из [mid,right);
        б) Если k <= vec[right - 1], то не попадаем => смотрим правую половину массива, поскольку k > vec[mid], но k <= vec[right - 1];
    (2) Правая половина не отсортирована: vec[mid] > vec[right-1]; 
        В этом случае безусловно рассмматриваем правую часть, поскольку искомый элемент больше элемента посередине и всех элементов из [left, mid);
    Таким образом мы проверяем условие: (vec[mid] <= vec[right-1]) && (k > vec[right]) => смотрим левую часть массива => сдвигаем правую границу на середину right = mid, 
    иначе - правую часть массива => сдвигаем левую границу на середину left = mid + 1; 

6) Аналогично, если k < vec[mid], то в зависимости от того, какая половина отсортирована мы будем искать элемент в правой или левой части массива:
    (1) Левая половина отсортирована: vec[left] < vec[mid], где нет равенства, поскольку vec[mid] принадлежит правому полуинтервалу; 
        В этом случае проверяем: в каком случае мы попадаем на правую часть массива:
        а) Если k < vec[left], то попадаем => смотрим правую половину массива, поскольку справа будет возрастающая последовательность от разрыва и k < всех элементов из [left,mid);
        б) Если k >= vec[left], то не попадаем => смотрим левую половину массива, поскольку k < vec[mid] и k >= vec[left];
    (2) Правая половина не отсортирована: vec[left] >= vec[mid]; 
        В этом случае безусловно рассмматриваем левую часть, поскольку искомый элемент меньше элемента посередине и всех элементов из [mid, right);
    Таким образом мы проверяем условие: (vec[left] < vec[mid]) && (k < vec[left]) => смотрим правую часть массива => сдвигаем левую границу на середину left = mid + 1, 
    иначе - левую часть массива => сдвигаем правую границу на середину right = mid; 


7) Базовых случаев у нас два: требуемый элемент окажется посередине в vec[mid], либо окажется, что left >= right и тогда функция вернёт -1;

ВРЕМЕННАЯ СЛОЖНОСТЬ:
Пусть длина исходного вектора равна n, используемый алгоритм есть бинарный поиск с модифицированными константными проверками выбора половины => временная сложность O(log n).
Итого: O(log n)

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ:
Будет соответствовать размеру входного вектора в поиске O(n), остальные создаваемые перменные  занимают константное пространство.
Итого: O(n)

*/


#include "solution.h"
#include <vector>
#include <cassert>

int broken_search(const std::vector<int>& vec, int k) {
    int left = 0, right = vec.size();
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (k == vec[mid]) {
            return mid;
        } else if(k > vec[mid]){
            if ((vec[mid] <= vec[right - 1]) && (k > vec[right - 1])) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if ((vec[left] < vec[mid]) && (k < vec[left])) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
    }
    return -1;
}


void test() {
    std::vector<int> arr = {19, 21, 100, 101, 1, 4, 5, 7, 12};
    assert(6 == broken_search(arr, 5));
}
