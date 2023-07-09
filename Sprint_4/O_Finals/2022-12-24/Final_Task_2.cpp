/*
 https://contest.yandex.ru/contest/24414/run-report/79980076/
ПРИНЦИП РАБОТЫ :
Непосредственно из описания задачи.
1) Создается класс hashTable содержащий массив листов из пар, каждая пара = {ключ, значение};
2) Коллизии разрешаются с помощью метода цепочек и контейнера STL list;
3) Вычисление номера корзины проводится с помощью простого деления по модулю;
4) Размер контейнера берется в 10 раз меньше, чем объем поступаемых запросов из фиксированного списка простых чисел;
5) Хэш-функция: hash(i) = i;

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ :
1) Метод цепочек (через массив листов из пар) - разрешает коллизии;
2) Вычисление номера корзины проводится с помощью простого деления по модулю, число запросов не больше n = 10^6, обещанное число корзин при этом не должно превосходить N = 10^5, предположим, что 
число корзин в 10 раз меньше, чем число запросов: n ~ 10*N, тогда число корзин возьмем равным M = p_k из фиксированного возрастающего списка простых чисел (взятого из STL контейнера) так, 
чтобы: M = p_k > n/10 ~ N, но p_{k-1} <= n/10 ~ N, то есть первое простое число превосходящее число запросов / 10. Всего таких чисел возьмем 15, чтобы последнее простое число было больше 10^5.
Тогда N/M < 1 => операции вставки/удаления будут выполняться в среднем за O(1 + N/M) ~ O(1);
3) Рехеширование по условию не добавляется;
4) При запросе по ключу, сначала вычисляется хэш (hash(i) = i), затем номер корзины. После чего в листе корзины ищется требуемый ключ и приписывается ссылка либо на найденный ключ в листе,
либо на конец листа в котором осуществлялся поиск;
5) Операция - put_value =>
	(1) если ссылка == конец листа, то добававляется новый элемент в начало листа;
	(2) если ссылка != конец листа, то значение по ссылке переписывается;
6) Если операция - get_value =>
	(1) возвращается значение по ссылке, если ссылка != конец листа;
	(2) если ссылка == конец листа, то возвращается -1;
7) Если операция - erase_value =>
	(1) если ссылка != конец листа, то элемент удаляется из листа и значение элемента возвращается в место вызова функции;
	(2) если ссылка == конец листа, то возвращается -1;
8) Если в операциях get_value, erase_value были значения -1, то печатается "None", иначе выводится значение элемента;
9) Чтобы скорость ввода/вывода была эффективной, в конце вывода используется "\n" вместо endl. Также убирается синхронизация потоков ввода/вывода и синхронизация со
стандартными C потоками, что значительно ускоряет выполнение программы;

ВРЕМЕННАЯ СЛОЖНОСТЬ:
Пусть N = number_of_commands - число комманд, M = выбранное простое число для размера массива из листов;
0) Поиск простого числа для создания массива из листов: ~O(1) - прохождение константного списка из 15 элементов;
1) Создание массива из листов: ~O(M);
2) Добавление элемента: в среднем O(1), в худшем случае (когда все элементы попадают в одну и ту же корзину), возможна сложность ~O(N);
3) Ввод N команд: ~O(N);
4) Вывод результата: в худшем случае (когда каждая команда это либо get, либо erase) ~O(N);
3) Вывод за счет рассинхронизации потоков: O(1);
Итого: временная сложность ~O(M + N);

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ :
0) Массив из простых чисел: ~O(1);
1) Массив из листов: ~O(M);
2) Ввод комманд: ~O(N);
3) Вывод результата: в худшем случае (когда каждая команда это либо get, либо erase) ~O(N);
Итого: пространственная сложность ~O(M + N);

*/

#include<iostream>
#include<string>
#include<cmath>
#include<list>
#include<utility>
using namespace std;
using Iterator = list<pair<int, int>>::iterator;
constexpr uint32_t num_distinct_sizes = 15;
static const uint32_t g_a_sizes[num_distinct_sizes] =
{
	/* 0     */              5ul,
	/* 1     */              11ul,
	/* 2     */              23ul,
	/* 3     */              47ul,
	/* 4     */              97ul,
	/* 5     */              199ul,
	/* 6     */              409ul,
	/* 7     */              823ul,
	/* 8     */              1741ul,
	/* 9     */              3469ul,
	/* 10    */              6949ul,
	/* 11    */              14033ul,
	/* 12    */              28411ul,
	/* 13    */              57557ul,
	/* 14    */              116731ul,
};

class hashTable {
public:

	explicit hashTable(size_t query_size) {
		setHashSize(query_size);
		container = new list<pair<int, int>>[bucketSize];
	}

	~hashTable() {
		delete[] container;
	}

	void put_value(int key, int value) {
		setListIterators(key);

		if (itListKey == itListEnd) {
			contBucket->push_front({ key, value });
		}
		else {
			itListKey->second = value;
		}


	};

	int get_value(int key) {
		setListIterators(key);

		if (itListKey == itListEnd) { return -1; }

		return itListKey->second;
	};

	int erase(int key) {
		setListIterators(key);

		if (itListKey == itListEnd) { return -1; }
		int result = itListKey->second;

		contBucket->erase(itListKey);

		return result;
	};

	int bucketNumber(int hash_value)  {
		return hash_value % bucketSize;
	}

	int hashValue(int key)  {
		return key;
	}

	void setHashSize(size_t query_size) {
		size_t check_value = query_size / 10;
		for (size_t i = 0; i < num_distinct_sizes; i++) {
			if (check_value < g_a_sizes[i]) {
				bucketSize = g_a_sizes[i];
				break;
			}
		}

	}

	Iterator searchContainer(Iterator itContainerBegin, Iterator itContainerEnd, int key) {

		auto itCont = itContainerBegin;
		while (itCont != itContainerEnd) {
			if (itCont->first == key) { break; }
			itCont++;
		}
		return itCont;
	}

	void setListIterators(int key) {
		int bucket = bucketNumber(hashValue(key));
		contBucket = &container[bucket];

		itListBegin = contBucket->begin(), itListEnd = contBucket->end();
		itListKey = searchContainer(itListBegin, itListEnd, key);
	}

private:
	list<pair<int, int>>* container = nullptr;
	Iterator itListBegin, itListEnd, itListKey;
	list<pair<int, int>>* contBucket = nullptr;
	size_t bucketSize;
};

void print_result(int value) {
	if (value == -1) {
		cout << "None" << "\n";
	}
	else {
		cout << value << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	size_t number_of_commands;
	int key_value, value, result;
	string command;

	cin >> number_of_commands;

	hashTable hash_map(number_of_commands);

	for (size_t i = 0; i < number_of_commands; i++) {
		cin >> command;

		try {
			if (command == "get") {
				cin >> key_value;
				result = hash_map.get_value(key_value);
				print_result(result);
			}
			else if (command == "put") {
				cin >> key_value >> value;
				hash_map.put_value(key_value, value);
			}
			else if (command == "delete") {
				cin >> key_value;
				result = hash_map.erase(key_value);
				print_result(result);
			}

		}
		catch (runtime_error& err) {
			cout << err.what() << endl;
		}
	}

	return 0;
};