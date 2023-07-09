/* https://contest.yandex.ru/contest/22450/run-report/74889312/ */
#include<iostream>
#include<vector>
using namespace std;

void minDistance(vector<int>& dist) {
	int counter = 0, zero_counter = 0, zero_nums;
	int dist_size = dist.size();
	//Производим проход по вектору слева направо.
	for (int i = 0; i < dist_size; i++) {
		if (dist[i] > 0) {			 
			counter++;
		}
		else { 
			counter = 0; 
			zero_counter++; //Замеряем количество пустых мест слева.
		}

		if (zero_counter > 0) { //Пока не дошли до первого пустого места слева, расстояния не вносим.
			dist[i] = counter; 
		}
		
	}

	// Фиксируем общее число нулей и производим проход по вектору справа налево.
	zero_nums = zero_counter;
	for (int j = dist_size - 1; j >= 0; j--) {

		if ((dist[j] > 0)||(zero_counter == 0)) { //Измерям расстояние, если место не пустое, либо все пустые места мы уже прошли.
			counter++; 
		} else { 
			counter = 0;  
			zero_counter--; //Замеряем количество пустых мест слева.
		}

		if(zero_counter != zero_nums) { //Пока не дошли до первого пустого места справа (последнего слева), расстояние не вносим.
			if (zero_counter > 0) { // Если не дошли до последнего пустого места справа, то сравниваем откуда расстояние меньше.
				if(dist[j] > counter) dist[j] = counter; // Если расстояние меньше справа, то вносим новое расстояние. Если расстояние меньше слева, то ничего не делаем.
			}
			else {
				dist[j] = counter; // Как только прошли последнее пустое место справа, то вносим расстояние безусловно.
			}
		}


	}
}

void print(const vector<int>& result) {
	int result_size = result.size();
	for (int i = 0; i < result_size; i++) {
		cout << result[i] << " ";
	}
}

int main() {
	int n = 0, temp_num, cnt = 0, zero_num = 0;
	cin >> n;

	vector<int> dist(n);

	for (int i = 0; i < n; i++) {
		cin >> temp_num;
		dist[i] = temp_num;
	}

	minDistance(dist);
	print(dist);
	return 0;
}