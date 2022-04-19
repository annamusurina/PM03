#include <iostream>
#include <fstream>
using namespace std;
struct Route {
	char number[10];
	int ostanovki;
	int time;
	Route* next;
};
class TrolleybusStation {
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
public:
	static TrolleybusStation* getInstance() {
		static TrolleybusStation* uniqueInstance;
		if (!uniqueInstance) {
			uniqueInstance = new TrolleybusStation;
		}
		return uniqueInstance;
	}
	Route* one() {
		if (first)
			return first;
		else
			return NULL;
	}
	int save(Route* mas, string name, int n) {// вводить данные в файл
		ofstream fout(name);
		if (fout)
		{
			for (int i = 0; i < n; i++) {
				//Выводим все элементы структуры в файл
				fout << mas[i].number << "  ";
				fout << mas[i].ostanovki << "  ";
				fout << mas[i].time << endl;
			}
			fout.close();
			return 1;
		}
		else {
			cout << "Ошибка с файлом" << endl;
			return 0;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	int N;
	cout << "Введите количество элементов массива ";
	do {
		cin >> N;
		if (N < 0 || N == 0) {
			cout << "Количество элементов было введено неверно. Введите повторно" << endl;
		}
	} while (N > 0);

	TrolleybusStation* P = TrolleybusStation::getInstance();
	Route* Routes = new Route[N];
	for (int i = 0; i < N; i++) {
		cout << "Введите номер маршрута: ";
		cin >> Routes[i].number[10];
		cout << "Введите количетсво остановок: ";
		cin >> Routes[i].ostanovki;
		cout << "Введите время в пути в минутах: ";
		cin >> Routes[i].time;
	}

	string fl;
	cout << "Введите имя файла: ";
	cin >> fl;
	

	system("pause");
	return 0;
}