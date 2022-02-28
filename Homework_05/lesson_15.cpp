#include <iostream>

//// 01 //////////////////////////////

int hash(char* str);

//// 02 //////////////////////////////

const int SIZE = 5;

void calculate(int* nom,int sum);

int main()
{
    //// 01 //////////////////////////////
    std::cout << "######\n# 01 #\n######\n\nHash function:\n\n";
    std::cout << "Enter a string: ";
    char string[80];
    std::cin >> string;

    std::cout << "\nHash = " << hash(string);

    std::cout << std::endl << std::endl;

    //// 02  /////////////////////////////

    std::cout << "######\n# 02 #\n######\n\nGreedy algorithm:\n\n";


    int nominalValues [SIZE] = {50,10,5,2,1};
    int amount = 98;

    std::cout << "Amount: " << amount << std::endl << std::endl;

    calculate(nominalValues, amount);

    std::cout << std::endl;

    return 0;
}

// 01 ////////////////////////////////////

int hash(char* str)
{
    int result = 0;
    for(int k = 0; str[k] != '\0'; k++)
    {
        result += static_cast<int>(str[k]);
    }
    return result;
}

// 02 ////////////////////////////////////

void calculate(int* nom,int sum)
{
    int coins, tmp = 0;
    for (int k = 0; k < SIZE; k++)
    {
        coins = 0;
        tmp = nom[k];
        coins += sum / tmp;
        sum %= tmp;
        std::cout << tmp << "k - " << coins << std::endl;
    }
}
