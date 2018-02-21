#include <iostream>

using namespace std;

class Vect_int //описали класс, реализующий динамический одномерный массив (вектор) 
{
private:
	int *v, n; //задание указателя на вектор и n=количества его элементов
public:
	//void new_int(int k)	//создание нового вектора из k элементов, описание метода стилем "инлайн"
	//{
	//	if (v) //означает if (v == NULL); NULL - это НЕ логический ноль
	//	{
	//		n = k; //запомнили в n число элементов нового вектора
	//		v = new int[n]; //выделение памяти под n элементов целочисленного типа
	//		for (int i = 0; i < n; i++) v[i] = 0; //инициализация нового вектора нулями
	//	}
	//}
	int size()
	{
		return n;
	}

	Vect_int() //конструктор по умолчанию
	{
		n = 0;
		v = NULL;
	}

	Vect_int(int k)	//создание нового вектора из k элементов, конструктор
	{
		n = k; //запомнили в n число элементов нового вектора
		v = new int[n]; //выделение памяти под n элементов целочисленного типа
		for (int i = 0; i < n; i++) v[i] = 0; //инициализация нового вектора нулями
	}

	~Vect_int() //деструктор
	{
		if (v) delete[] v;
	}

	void resize(int k); //изменение размера существующего вектора, прототип метода

						/*int get(int i)
						{
						if ((i >= 0) && (i < n)) return v[i];
						else return 0;
						}

						void set(int value, int i)
						{
						if ((i >= 0) && (i < n)) v[i] = value;
						}*/

	void print()
	{
		cout << "Вектор: ";
		for (int i = 0; i < n; i++) cout << v[i] << " ";
	}

	int& set_get(int i)
	{
		if ((i >= 0) && (i < n)) return v[i];
		else cout << "ошибка"; //генерация исключения
	}
};

void Vect_int::resize(int k)
{
	int *temp, i;
	temp = new int[k]; //создали временный вектор
	if (v)
	{
		for (i = 0; i < ((n < k) ? n : k); i++) temp[i] = v[i];//засунули старый вектор в новый
		delete[] v; //удалили старый вектор
	}
	for (i = n; i < k; i++) temp[i] = 0; //обнулили лишние значение если они есть
	v = temp; //запихали в новый вектор значения из временного
	n = k;
}

void main()
{
	setlocale(LC_ALL, "russian");
	cout << "Начало\n";
	int n, value;
	Vect_int vect1;
	vect1.print();
	cout << "\nВведите размер вектора: ";
	cin >> n;
	Vect_int my_vect(n);
	my_vect.print();
	cout << "\nВведите новый размер вектора: ";
	cin >> n;
	my_vect.resize(n);
	cout << "\nВведите " << my_vect.size() << " значений: ";
	for (int i = 0; i < my_vect.size(); i++)
	{
		cin >> value;
		my_vect.set_get(i) = value;
	}
	my_vect.print();
	cout << "\nЧетвертый элемент (my_vect.v[3]) = " << my_vect.set_get(3) << endl;
	//my_vect.free_int();
	system("@pause");
}



