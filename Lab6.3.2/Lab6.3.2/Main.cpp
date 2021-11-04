// Main.cpp
// Лісничук Арсен
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 33(Рекурсивний спосіб)
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

template<typename T>
void InitArray(T arr[], const size_t size, size_t i)
{
	if (i < size)
	{
		arr[i] = (T)(-10 + rand() % 21);
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

template<typename T>
void PrintArray(const T* const arr, const size_t size, size_t i)
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

void FindIndexMin(int arr[], int size, int & min, int &index, int i)
{
	if (i < size)
	{
		if (arr[i] < min) {
			index = i;
			min = arr[i];
			FindIndexMin(arr, size, min, index, i + 1);
		}
		else
			return FindIndexMin(arr, size, min, index, i + 1);
	}
}

template<typename T>
void FindIndexMin(T arr[], size_t size, T& min, size_t& index, size_t i)
{
	if (i < size)
	{
		if (arr[i] < min) {
			index = i;
			min = arr[i];
			FindIndexMin<T>(arr, size, min, index, i + 1);
		}
		else
			return FindIndexMin<T>(arr, size, min, index, i + 1);
	}
}

void SortArray(int arr[], const int size, int i)
{
	if (i < size)
	{
		int index = i;
		int min = arr[i];
		FindIndexMin(arr, size, min, index, i);
		arr[index] = arr[i];
		arr[i] = min;
		SortArray(arr, size, i+1);
		return;
	}
}

template<typename T>
void SortArray(T arr[], const size_t size, size_t i)
{
	if (i < size)
	{
		size_t index = i;
		T min = arr[i];
		FindIndexMin<T>(arr, size, min, index, i);
		arr[index] = arr[i];
		arr[i] = min;
		SortArray<T>(arr, size, i + 1);
		return;
	}

}

int main()
{
	srand(time(0));
	int n;
	cout << "n = "; cin >> n;
	int* arr = new int[n];

	InitArray<int>(arr, n, 0);
	PrintArray<int>(arr, n, 0);
	SortArray<int>(arr, n, 0);
	PrintArray<int>(arr, n, 0);

	delete[] arr;
	arr = nullptr;
	return 0;
}