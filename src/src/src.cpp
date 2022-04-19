#include <iostream>
#include <fstream>
using namespace std;
struct Route {
	string number[10];
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
	int add(string n, double o, int t) {
		Route* current, * previous, * tmp;
		previous = NULL;
		if (first) {
			current = first;
			do {
				if (current->ostanovki > o && current->time > t) {
					tmp = new Route;
					tmp->number = n;
					tmp->ostanovki = o;
					tmp->time = t;					
					tmp->next = current;
					if (previous)
						previous->next = tmp;
					else
						first = tmp;
					break;
				}
				if (current->ostanovki == o && current->time == t)
					return 0;
				previous = current;
				current = current->next;
			} while (current);
			if (!current) {
				previous->next = new Route;
				previous->next->number = n;
				previous->next->ostanovki = o;
				previous->next->time = t;
				previous->next->next = NULL;
			}
		}
		else {
			Route* h = new Route;
			h->number = n;
			h->ostanovki = o;
			h->time = t;
			h->next = NULL;
			first = h;
		}
		return 1;
	}
	int save(string name, int n) {// вводить данные в файл
		ofstream fout(name);
		if (fout)
		{
			Route* current;
			if (first) {
				current = first;
				for (int i = 0; i < n; i++) {
					//Выводим все элементы структуры в файл
					fout << current->number << "  ";
					fout << current->ostanovki << "  ";
					fout << current->time << endl;
					current = current->next;
				}
				fout.close();
				return 1;
			}
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
	
	for (int i = 0; i < N; i++) {
		string n;
		int o, t;
		cout << "Введите номер маршрута: ";
		cin >> n;
		cout << "Введите количетсво остановок: ";
		cin >> o;
		cout << "Введите время в пути в минутах: ";
		cin >> t;
		P->add(n, o, t);
	}
	Route* Routes = P->one();
	string fl;
	cout << "Введите имя файла: ";
	cin >> fl;
	P->save(fl, N);
	

	system("pause");
	return 0;
}