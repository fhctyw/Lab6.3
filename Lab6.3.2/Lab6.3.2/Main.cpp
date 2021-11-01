// Main.cpp
// Лісничук Арсен
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 33(Ітераційний спосіб)
#include <iostream>
using namespace std;

void InitArray(int arr[], const int size, int i)
{
	if (i < size)
	{
		arr[i] = -10 + rand() % 21;
		InitArray(arr, size, i + 1);
		return;
	}
}

void PrintArray(const int* const arr, const int size, int i)
{
	if (i < size)
	{
		if (i == 0)
			cout << "{";
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";
		else cout << "}" << endl;
		PrintArray(arr, size, i + 1);
		return;
	}
}

int Min(int arr[], int size, int &index, int i)
{
	index = 0;
	if (i < size)
	{
		if (arr[i] < Min(arr, size, index, i + 1)) {
			index = i;
			return arr[i];
		}
		else
			return Min(arr, size, index, i + 1);
	}
	else return numeric_limits<int>::max();
}

void SortArray(int arr[], const int size, int i)
{
	if (i < size)
	{
		int index;
		int m = Min(arr, size, index, i);
		arr[index] = arr[i];
		arr[i] = m;
		SortArray(arr, size, i+1);
		return;
	}

}

int main()
{
	srand(time(0));
	int n;
	cout << "n = "; cin >> n;
	int* arr = new int[n];

	InitArray(arr, n, 0);
	PrintArray(arr, n, 0);
	SortArray(arr, n, 0);
	PrintArray(arr, n, 0);

	delete[] arr;
	arr = nullptr;
	return 0;
}