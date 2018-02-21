#include <iostream>

using namespace std;

class Vect_int //������� �����, ����������� ������������ ���������� ������ (������) 
{
private:
	int *v, n; //������� ��������� �� ������ � n=���������� ��� ���������
public:
	//void new_int(int k)	//�������� ������ ������� �� k ���������, �������� ������ ������ "������"
	//{
	//	if (v) //�������� if (v == NULL); NULL - ��� �� ���������� ����
	//	{
	//		n = k; //��������� � n ����� ��������� ������ �������
	//		v = new int[n]; //��������� ������ ��� n ��������� �������������� ����
	//		for (int i = 0; i < n; i++) v[i] = 0; //������������� ������ ������� ������
	//	}
	//}
	int size()
	{
		return n;
	}

	Vect_int() //����������� �� ���������
	{
		n = 0;
		v = NULL;
	}

	Vect_int(int k)	//�������� ������ ������� �� k ���������, �����������
	{
		n = k; //��������� � n ����� ��������� ������ �������
		v = new int[n]; //��������� ������ ��� n ��������� �������������� ����
		for (int i = 0; i < n; i++) v[i] = 0; //������������� ������ ������� ������
	}

	~Vect_int() //����������
	{
		if (v) delete[] v;
	}

	void resize(int k); //��������� ������� ������������� �������, �������� ������

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
		cout << "������: ";
		for (int i = 0; i < n; i++) cout << v[i] << " ";
	}

	int& set_get(int i)
	{
		if ((i >= 0) && (i < n)) return v[i];
		else cout << "������"; //��������� ����������
	}
};

void Vect_int::resize(int k)
{
	int *temp, i;
	temp = new int[k]; //������� ��������� ������
	if (v)
	{
		for (i = 0; i < ((n < k) ? n : k); i++) temp[i] = v[i];//�������� ������ ������ � �����
		delete[] v; //������� ������ ������
	}
	for (i = n; i < k; i++) temp[i] = 0; //�������� ������ �������� ���� ��� ����
	v = temp; //�������� � ����� ������ �������� �� ����������
	n = k;
}

void main()
{
	setlocale(LC_ALL, "russian");
	cout << "������\n";
	int n, value;
	Vect_int vect1;
	vect1.print();
	cout << "\n������� ������ �������: ";
	cin >> n;
	Vect_int my_vect(n);
	my_vect.print();
	cout << "\n������� ����� ������ �������: ";
	cin >> n;
	my_vect.resize(n);
	cout << "\n������� " << my_vect.size() << " ��������: ";
	for (int i = 0; i < my_vect.size(); i++)
	{
		cin >> value;
		my_vect.set_get(i) = value;
	}
	my_vect.print();
	cout << "\n��������� ������� (my_vect.v[3]) = " << my_vect.set_get(3) << endl;
	//my_vect.free_int();
	system("@pause");
}



