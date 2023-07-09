/*
https://contest.yandex.ru/contest/24414/run-report/79872693/
ПРИНЦИП РАБОТЫ :
Непосредственно из описания задачи.
1) Создается класс hashTable содержащий массив листов из пар, каждая пара = {ключ, значение};
2) Коллизии разрешаются с помощью метода цепочек и контейнера STL list;
3) Вычисление номера корзины проводится с помощью простого деления по модулю;
4) Размер контейнера берется так, чтобы перекрыть указанное число ключей в 10^5 и при этом быть простым числом: 100'019;
5) Хэш-функция: hash(i) = i;

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ :
1) Метод цепочек (через массив листов из пар) - разрешает коллизии;
2) Вычисление номера корзины проводится с помощью простого деления по модулю, число элементов не больше N = 10^5, число корзин M = 100'019, N/M ~ 1 => операции вставки/удаления будут выполняться 
в среднем за O(N/M) ~ O(1);
3) Рехеширование/масштабирование по условию не добавляется;
4) При запросе по ключу, сначала вычисляется номер корзины, затем в листе корзины ищется требуемый ключ и приписывается ссылка либо на найденный ключ в листе,
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
Пусть N = number_of_commands - число комманд;
1) Создание массива из листов: ~O(10^5);
2) Добавление элемента: в среднем O(1), в худшем случае (когда все элементы попадают в одну и ту же корзину), возможна сложность ~O(N);
3) Ввод N команд: ~O(N);
4) Вывод результата: в худшем случае (когда каждая команда это либо get, либо erase) ~O(N);
3) Вывод за счет рассинхронизации потоков: O(1);
Итого: временная сложность ~O(10^5 + N);

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ :
1) Массив из листов: ~O(10^5);
2) Ввод комманд: ~O(N);
3) Вывод результата: в худшем случае (когда каждая команда это либо get, либо erase) ~O(N);
Итого: пространственная сложность ~O(10^5 + N);

*/
#include<iostream>
#include<string>
#include<cmath>
#include<list>
#include<utility>
using namespace std;
using Iterator = list<pair<int, int>>::iterator;
constexpr int hashSize = 100'019;

class hashTable {
public:

	explicit hashTable() {
		container = new list<pair<int, int>>[hashSize];
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

	int bucketNumber(int hash_value) const {
		return hash_value % hashSize;
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
		int bucket = bucketNumber(key);
		contBucket = &container[bucket];

		itListBegin = contBucket->begin(), itListEnd = contBucket->end();
		itListKey = searchContainer(itListBegin, itListEnd, key);
	}

private:
	list<pair<int, int>>* container = nullptr;
	Iterator itListBegin, itListEnd, itListKey;
	list<pair<int, int>>* contBucket = nullptr;
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

	int number_of_commands, key_value, value, result;
	string command;
	
	cin >> number_of_commands;

	hashTable hash_map;

	for (int i = 0; i < number_of_commands; i++) {
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