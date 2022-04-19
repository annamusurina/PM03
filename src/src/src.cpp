#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Route {
	string number;
	int ostanovki;
	int time;
	Route* next;
};
class TrolleybusStation {
public:
	Route* first;
	TrolleybusStation() {
		first = NULL;
	};
	~TrolleybusStation() {
		Route* temp;
		while (first != NULL) {
			temp = first;
			first = first->next;
			delete temp;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	int N;
	cout << "Введите количество элементов массива ";
	cin >> N;
	Route* Routes = new Route[N];
	for (int i = 0; i < N; i++) {
		cout << "Введите номер маршрута: ";
		cin >> Routes[i].number;
		cout << "Введите количетсво остановок: ";
		cin >> Routes[i].ostanovki;
		cout << "Введите время в пути в минутах: ";
		cin >> Routes[i].time;
	}
	system("pause");
	return 0;
}