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
    std::cout << "\n������ �᭮�����: ";
    std::cin >> num;
    std::cout << "������ �⥯���: ";
    std::cin >> exp;
    std::cout << "�����ᨢ�� - " << exponA(num, exp) << std::endl;
    std::cout << "�����ᨢ�� (�-�� �⭮��) - " << exponB(num, exp) << std::endl;

    return 0;
}
