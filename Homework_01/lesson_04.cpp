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
    std::cout << "Введите десятичное число: ";
    std::cin >> Dec;
    std::cout << "Ваше число в двоичном виде: ";
    decToBin(Dec);

//// 02  /////////////////////////////

    int num, exp;
    std::cout << "\nВведите основание: ";
    std::cin >> num;
    std::cout << "Введите степень: ";
    std::cin >> exp;
    std::cout << "Рекурсивно - " << exponA(num, exp) << std::endl;
    std::cout << "Рекурсивно (св-во четности) - " << exponB(num, exp) << std::endl;

    return 0;
}
