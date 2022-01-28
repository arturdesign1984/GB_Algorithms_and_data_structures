#include <iostream>

int main()
{

    int a,b;
    std::cout << "Введите целое число: ";
    std::cin >> a;
    b = a/2;

    while (a%b != 0)
    {
        b--;
    }

    if (b == 1)
    {
        std::cout << "Число " << a << " является простым" << std::endl;
    } else
    {
        std::cout << "Число " << a << " не является простым" << std::endl;
    }
    return 0;
}
