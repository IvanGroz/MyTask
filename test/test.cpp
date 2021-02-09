/*
Задача
На входе функция получает параметр n - натуральное число.
Необходимо сгенерировать n - массивов, заполнить их случайными числами, каждый массив имеет случайный размер.
Размеры массивов не должны совпадать.Далее необходимо отсортировать массивы.
Массивы с четным порядковым номером отсортировать по возрастанию, с нечетным порядковым номером - по убыванию.
На выходе функция должна вернуть массив с отсортированными массивами.
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int to = 10; // максимальное число которое будет содержаться в массивах

void sortInc(int * arr, int size) //по возрастанию
{
	int temp; // временная переменная для обмена элементов местами
	
	// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sortDecr(int * arr, int size)//по убыванию
{
	int temp; // временная переменная для обмена элементов местами

	// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int** gen(int n)
{
	int* sizes = new int[n];
	int **arrays = new int*[n];
	for (int i = 0; i < n; i++)
	{
		sizes[i] = (rand() % n) + 1;//чтобы чисел хватало на все массивы генерируем их в диапазоне количества массивов
		for (int j = 0; j < n; j++)
		{
			if (sizes[j] == sizes[i] && j != i) // сравниваем уже существующие числа с добавленным если они совпадают, то на это же место генерируется новое число
			{
				i--;
				break;
			}
		}
	}
	
	for (int i = 0; i < n; i++) //задаем длину каждого массива из уже отобранного массива 
	{
		arrays[i] = new int[sizes[i]];
		for (int j = 0; j < sizes[i]; j++)
		{
			arrays[i][j] = 1 + (rand() % to);//тут же заполняем массивы числами от 1 до заданного максимального числа
		}
	}
	
	/*cout << "до сортировки\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			cout << " " << arrays[i][j];
		}
		cout << setw(10) << setfill('-') << sizes[i] << endl;
	}*/

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			//sortInc(arrays[i], sizes[i]);
			sort(arrays[i], arrays[i]+sizes[i]); //стандартная сортировка из библиотеки algorithm
		}
		else
		{
			//sortDecr(arrays[i], sizes[i]);
			sort(arrays[i], arrays[i] + sizes[i], [](int first, int second) { return first > second; }); //стандартная сортировка из библиотеки algorithm
		}
	}
	/*cout << "после сортировки\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			cout << " " << arrays[i][j];
		}
		cout << setw(10) << setfill('-') << sizes[i] << endl;
	}*/

	return arrays;
}



int main()
{
	system("chcp 1251 > nul");
	srand(time(NULL));
	gen(10);

	
	return 0;
}

