#include <iostream>

// 01 ////////////////////////////////////

void decToBin(int x)
{
    if(x < 2)
    {
        std::cout << x;
    }
    else
    {
        decToBin(x/2);
        std::cout << x%2;
    }
}

// 02 A /////////////////////////////////

int exponA(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(b == 1)
    {
        return a;
    }
    else
    {
        b--;
        a *= exponA(a, b);
    }
}

// 02 B /////////////////////////////////////////

int exponB(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(b == 1)
    {
        return a;
    }
    else if(b%2 == 0)
    {
        a *= a;
        b /= 2;
        a = exponB(a, b);
    }
    else
    {
        b--;
        a *= exponB(a, b);
    }

}

//// 03  /////////////////////////////

int ways(int** arr, int x, int y)
{
	if (x == 0 && y == 0)
	{
		return 1;
	}
	else if (x < 0 || y < 0)
	{
		return 0;
	}
	else if (x > 0 && y > 0)
	{
		if (arr[x][y] == 1)
		{
			return 0;
		}
	}
	return ways(arr, x - 1, y) + ways(arr, x, y - 1);
}

int main()
{
//// 01 //////////////////////////////

    int Dec;
    std::cout << "������ �����筮� �᫮: ";
    std::cin >> Dec;
    std::cout << "��� �᫮ � ����筮� ����: ";
    decToBin(Dec);

//// 02  /////////////////////////////

    int num, exp;
    std::cout << "\n\n������ �᭮�����: ";
    std::cin >> num;
    std::cout << "������ �⥯���: ";
    std::cin >> exp;
    std::cout << "�����ᨢ�� - " << exponA(num, exp) << std::endl;
    std::cout << "�����ᨢ�� (�-�� �⭮��) - " << exponB(num, exp) << std::endl;

//// 03  /////////////////////////////

	int x = 0;
	int y = 0;

	std::cout << "\n\n���न���� �����祭��:\n";
	std::cout << "������ X: ";
	std::cin >> x;
	std::cout << "������ Y: ";
	std::cin >> y;

	int** arr = new int*[y+1];
	arr[0] = new int[((x+1)*(y+1))];

	for (size_t i = 0; i <= y; i++)
	{
		arr[i] = arr[0] + (x+1) * i;
	}
	for (size_t i = 0; i <= y; i++)
	{
		for (size_t j = 0; j <= x; j++)
		{
			arr[i][j] = 0;
		}
	}
	arr[1][2] = 1;		// ������ �९���⢨� [Y][X]

	std::cout << "������⢮ ��������� ��⥩ - " << ways(arr, y, x) << std::endl;

	delete[] arr[0];
	delete[] arr;
	arr = nullptr;

    return 0;
}
