// Main.cpp
// Лісничук Арсен
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 33(Ітераційний спосіб)
#include <iostream>
using namespace std;

void InitArray(int arr[], const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = -10 + rand() % 21;
	}
}

template<typename T>
void InitArray(T arr[], const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = (T)(-10 + rand() % 21);
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

template<typename T> 
void PrintArray(const T* const arr, const size_t size)
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

int FindIndexMin(const int arr[], const int size, int start)
{
	int min = 22; // 22 = High + 1
	int index = 0;
	for (size_t i = start; i < size; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

template<typename T>
int FindIndexMin(const T arr[], const size_t size, size_t start)
{
	T min = (T)22;
	size_t index = 0;
	for (size_t i = start; i < size; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

void SortArray(int arr[], const int size)
{
	for (int i = 0, index = 0; i < size; i++)
	{
		index = FindIndexMin((const int*)arr, size, i);
		int tmp = arr[index];
		arr[index] = arr[i];
		arr[i] = tmp;
	}
}

template<typename T>
void SortArray(T arr[], const size_t size)
{
	for (size_t i = 0, index = 0; i < size; i++)
	{
		index = FindIndexMin<T>((const T*)arr, size, i);
		T tmp = arr[index];
		arr[index] = arr[i];
		arr[i] = tmp;
	}
}

int main()
{
	srand(time(0));
	int n;
	cout << "n = "; cin >> n;
	int*arr = new int[n];

	InitArray<int>(arr, n);
	PrintArray<int>(arr, n);
	SortArray<int>(arr, n);
	PrintArray<int>(arr, n);

	delete[] arr;
	arr = nullptr;
	return 0;
}