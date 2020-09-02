#include<iostream>
#include <cstdlib> 
#include<ctime>
#include "windows.h"
using namespace std;



int generateA(int* a, int arr_size)

{





	cout << "Массив A:" << endl;
	for (int i = 0; i < arr_size; i++)
	{
		a[i] = rand() % 50;
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}


int generateB(int* a, int arr_size)

{





	cout << "Массив B:" << endl;
	for (int i = 0; i < arr_size; i++)
	{
		a[i] = rand() % 25;
		cout << a[i] << " ";
	}
	cout << endl;
	int max = a[0];
	for (int i = 0; i < arr_size; i++)
	{
		if (a[i] > max) {
			max = a[i];
		}

	}
	cout << endl << "max = " << max << endl;

	return max;
}

int SuzeC(int* b, int max, int arr_size, int* a) {
	int count = 0;
	for (int i = 0; i < arr_size; i++) {
		if (a[i] > max) {
			count++;
		}
	}
	return count;
}

int* generateС(int* c, int count, int max, int arr_size, int* a) {

	c = new int[count];
	int j = 0;

	for (int i = 0; i < arr_size; i++) {

		if (a[i] > max)
		{
			c[j] = a[i];
			j++;
		}

	}



	cout << "Массив C:" << endl;
	for (int i = 0; i < count; i++)
	{

		cout << c[i] << " ";
	}

	cout << endl;
	return c;
}

void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
				system("cls");
				for (int p = 0; p < n; p++)
					cout << a[p] << " ";
				Sleep(20);

			}
}

void shakerSort(int* a, int n) {
	int left, right, i;
	left = 0;
	right = n - 1;
	while (left <= right)
	{
		for (i = right; i >= left; i--) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
			}
		}
		right--;

		system("cls");
		for (int p = 0; p < n; p++)
			cout << a[p] << " ";
		Sleep(30);
	}
}

void selectSort(int A[], int size)
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (A[j] < A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;

		system("cls");
		for (int p = 0; p < size; p++)
			cout << A[p] << " ";
		Sleep(30);
	}
}


void insertSort(int* A, int size)
{
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
		system("cls");
		for (int p = 0; p < size; p++)
			cout << A[p] << " ";
		Sleep(30);
	}
}

void shellSort(int x[], int n)         //SHELL SORT - SHELL'S INCREMENTS
{
	int i, j, k, increment, temp;
	int swp = 0, comp = 0; increment = n / 2;
	while (increment > 0)
	{
		for (i = 0; i < increment; i++)
		{
			for (j = 0; j < n; j += increment)
			{
				temp = x[j];
				for (k = j - increment; k >= 0 && temp < x[k]; k -= increment)
				{
					comp++;
					swp++;
					x[k + increment] = x[k];
					system("cls");
					for (int p = 0; p < n; p++)
						cout << x[p] << " ";
					Sleep(30);
				}
				x[k + increment] = temp;
				swp++;
			}
		}
		comp++;
		if (increment / 2 != 0)
			increment = increment / 2;
		else if (increment == 1)
			increment = 0;
		else
			increment = 1;
	}
}


int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;

		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		system("cls");
		for (int p = sm; p < em; p++)
		{
			cout << A[p] << " ";
			Sleep(10);
		}
		sortHoar(A, sm, hb);
		system("cls");
		for (int p = sm; p < em; p++)
		{
			cout << A[p] << " ";
			Sleep(10);
		}

		sortHoar(A, hb + 1, em);
		system("cls");
		for (int p = sm; p < em; p++)
		{
			cout << A[p] << " ";
			Sleep(10);
		}

	}
	return A;
};



void menu()
{
	fflush(stdin);
	system("cls");
	cout << "-------------------------------------------" << endl;
	cout << "1-Сгенерировать массивы" << endl;
	cout << "2-Отсортирвать массив B пузырьком" << endl;
	cout << "3-Отсортирвать массив В шейкерной сортировкой" << endl;
	cout << "4-Отсортирвать массив В сортировкой выбором" << endl;
	cout << "5-Отсортирвать массив В сортировкой вставкаии" << endl;
	cout << "6-Отсортирвать массив В сортировкой Шелла" << endl;
	cout << "7-Отсортирвать массив В сортировкой Хоара" << endl;
	cout << "0-Выход" << endl;
	cout << "-------------------------------------------";
	cout << endl;




}



int main()
{

	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	cout << "Введите размер массивов: ";
	int arr_size;
	cin >> arr_size;
	int* a = new int[arr_size];
	int* b = new int[arr_size];
	int* c = nullptr;
	int arrC_size = 0;


	int choice = 100;
	int max = 0;

	while (choice != 0)
	{
		menu();

		switch (choice)
		{

		case 1:
		{
			generateA(a, arr_size);
			max = generateB(b, arr_size);
			arrC_size = SuzeC(b, max, arr_size, a);
			c = generateС(c, arrC_size, max, arr_size, a);

			break;
		}

		case 2:
		{
			bubbleSort(c, arrC_size);
			break;
		}
		case 3:
		{
			shakerSort(c, arrC_size);
			break;
		}
		case 4:
		{
			selectSort(c, arrC_size);
			break;
		}
		case 5:
		{
			insertSort(c, arrC_size);
			break;
		}
		case 6:
		{
			shellSort(c, arrC_size);
			break;
		}
		case 7:
		{
			sortHoar(c, 1, arrC_size);
			break;
		}




		}





		cin >> choice;
	}




	return 0;
}