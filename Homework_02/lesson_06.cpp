#include <iostream>
#include <math.h>

int** createNewArray(int** arr, size_t arrHeight, size_t arrWidth);

void deleteArray(int** arr);

void fillArray(int** arr, size_t arrHeight, size_t arrWidth);

// 01 ////////////////////////////////////

void printArr(int** mass, size_t h, size_t w);

void bubbleSortA(int** mass, size_t h, size_t w);

void bubbleSortB(int** mass, size_t h, size_t w);


int main()
{
	//// 01 //////////////////////////////

	const int arrHeight = 3; // высота массива
	const int arrWidth = 3;  // ширина массива

	int** arr1 = nullptr;
	arr1 = createNewArray(arr1, arrHeight, arrWidth);
	fillArray(arr1, arrHeight, arrWidth);
	arr1[arrHeight-1][arrWidth-1] = 0; // худший случай 0 в конце массива

	std::cout << " No sort:\n";
	printArr(arr1, arrHeight, arrWidth);
	bubbleSortA(arr1, arrHeight, arrWidth);
	//bubbleSortB(arr1, arrHeight, arrWidth);  //только для массивов с последовательным расположением адресов

	std::cout << " Result:\n";
	printArr(arr1, arrHeight, arrWidth);

	deleteArray(arr1);

	//// 02  /////////////////////////////

	size_t numbers = 11; // количество чисел для ввода пользователем

	float arr2[numbers] = { 0 };

	for (size_t x = 0; x < numbers; x++)
	{
		std::cout << "Enter number " << x + 1 << " :";
		std::cin >> arr2[x];
	}

	float temp = 0;

	for (size_t x = 0; x < numbers / 2; x++)
	{
		temp = arr2[x];
		arr2[x] = arr2[numbers - 1 - x];
		arr2[numbers - 1 - x] = temp;
	}

	for (size_t x = 0; x < numbers; x++)
	{
		arr2[x] = sqrt(abs(arr2[x])) + 5 * pow(arr2[x], 3);
		if (arr2[x] > 400)
		{
			std::cout << "Number # " << numbers - x << " equal: " << arr2[x] << std::endl;
		}
	}

	return 0;
}

// 01 ////////////////////////////////////

void printArr(int** mass, size_t h, size_t w)
{
	for (size_t k = 0; k < h; k++)
	{
		for (size_t j = 0; j < w; j++)
		{
			std::cout << mass[k][j] << ',';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void bubbleSortA(int** mass, size_t h, size_t w)
{
	size_t x = h * w;
	int temp = 0;
	for (size_t j = 0; j < (h * w - 1); j++)
	{
		for (size_t k = 0; k < (x - 1); k++)
		{
			if (mass[k / h][k % h] > mass[k / h][(k % h) + 1])
			{
				temp = mass[k / h][k % h];
				mass[k / h][k % h] = mass[k / h][(k % h) + 1];
				mass[k / h][(k % h) + 1] = temp;
			}
		}
		x--;
		std::cout << " Step: " << j + 1 << std::endl;
		printArr(mass, h, w);
	}
}

void bubbleSortB(int** mass, size_t h, size_t w)  // когда сделал понял что особого смысла в этом нет
{												  // читается конечно легче, но нельзя сортировать
	size_t x = h * w;							  // массивы с разбросанными по куче строками
	int temp = 0;
	for (size_t k = 0; k < (h * w - 1); k++)
	{
		for (size_t k = 0; k < (x - 1); k++)
		{
			if (*(*mass + k) > *(*mass + k + 1))
			{
				temp = *(*mass + k);
				*(*mass + k) = *(*mass + k + 1);
				*(*mass + k + 1) = temp;
			}
		}
		x--;
		std::cout << " Step: " << k + 1 << std::endl;
		printArr(mass, h, w);
	}
}

//////////////////////////////////////////

int** createNewArray(int** arr, size_t arrHeight, size_t arrWidth)
{
	arr = new int*[arrHeight];
	arr[0] = new int[arrHeight*arrWidth];
	for (size_t k = 0; k < arrHeight; k++)
	{
		arr[k] = arr[0] + k * arrWidth;
	}
	return arr;
}

void deleteArray(int** arr)
{
	delete[] arr[0];
	delete[] arr;
	arr = nullptr;
}

void fillArray(int** arr, size_t arrHeight, size_t arrWidth)
{
	for (size_t k = 0; k < arrHeight; k++)
	{
		for (size_t j = 0; j < arrWidth; j++)
		{
			arr[k][j] = (rand() % 99) + 1;
		}
	}
}
