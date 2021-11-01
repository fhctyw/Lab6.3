// Main.cpp
// ˳������ �����
// ����������� ������ � 6.3
// ����������� ����������� ������ �� ��������� ��������� ������� �� �������
// ������ 33(����������� �����)
#include <iostream>
using namespace std;

void InitArray(int arr[], const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = -10 + rand() % 21;
	}
}

void PrintArray(const int* const arr, const int size)
{
	cout << "{";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

void SortArray(int arr[], const int size)
{
	for (size_t i = 0, index = 0; i < size; i++)
	{
		int m = numeric_limits<int>::max();
		for (size_t j = i; j < size; j++)
		{
			if (arr[j] < m) {
				m = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = m;
	}
}

int main()
{
	srand(time(0));
	int n;
	cout << "n = "; cin >> n;
	int *arr = new int[n];

	InitArray(arr, n);
	PrintArray(arr, n);
	SortArray(arr, n);
	PrintArray(arr, n);

	delete[] arr;
	arr = nullptr;
	return 0;
}