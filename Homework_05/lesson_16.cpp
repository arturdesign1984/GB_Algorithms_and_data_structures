#include <iostream>
#include <cstring>

//// 01 //////////////////////////////

void encrypt01(char* str, int shift);

void decrypt01(char* str, int shift);

//// 02 //////////////////////////////

char* encrypt02(char* str, int key);

char* decrypt02(char* str, int key);

int main()
{
    //// 01 //////////////////////////////
    std::cout << "######\n# 01 #\n######\n\nCaesar:\n\n";

    char ch[80];
    int key = 0;
    std::cout << "Enter a string:" << std::endl;
    std::cin >> ch;
    std::cout << "Enter a key:" << std::endl;
    std::cin >> key;
    encrypt01(ch, key);
    std::cout << ch << std::endl;
    decrypt01(ch, key);
    std::cout << ch << std::endl << std::endl;

    //// 02  /////////////////////////////
    std::cout << "######\n# 02 #\n######\n\nShuffle:\n\n";

    char msg[] = "thisisasecretmessage";
    std::cout << "Message - " << msg << std::endl;
    char* encr = encrypt02(msg, 6);
    std::cout << "Encrypt - " << encr << std::endl;
    char* decr = decrypt02(encr, 6);
    std::cout << "Decrypt - " << decr << std::endl;

    return 0;
}

// 01 ////////////////////////////////////

void encrypt01(char* str, int shift)
{
    shift %= 26;
    for (int k = 0; k < strlen(str); k++)
    {
        if ((static_cast <int> (str[k]) + shift) < 97 || (static_cast <int> (str[k]) + shift) > 122)
        {
            continue;
        }
        else if ((122 - (static_cast <int> (str[k]) + shift)) >= 0)
        {
            str[k] = str[k] + shift;
        }
        else
        {
            str[k] = str[k] + shift - 26;
        }
    }
}

void decrypt01(char* str, int shift)
{
    shift %= 26;
    for (int k = 0; k < strlen(str); k++)
    {
        if ((static_cast <int> (str[k]) + shift) < 97 || (static_cast <int> (str[k]) + shift) > 122)
        {
            continue;
        }
        else if ((static_cast <int> (str[k]) - shift) >= 97)
        {
            str[k] = str[k] - shift;
        }
        else
        {
            str[k] = str[k] - shift + 26;
        }
    }
}

// 02 ////////////////////////////////////

char* encrypt02(char* str, int key)
{
    int len = key * (1+((strlen(str) - 1) / key));
    char* out = new char[len + 1];
    int idx = 0;
    for (int k = 0; k < key; k++)
    {
        for (int j = k; j < len; j += key)
        {
            out[idx++] = (j < strlen(str)) ? *(str + j) : 'x';
        }
    }
    out[len] = '\0';
    return out;
}

char* decrypt02(char* str, int key)
{
    int len = key * (1+((strlen(str) - 1) / key));
    char* out = new char[len + 1];
    key = len / key;
    int idx = 0;
    for (int k = 0; k < key; k++)
    {
        for (int j = k; j < len; j += key)
        {
            out[idx++] = (j < strlen(str)) ? *(str + j) : 'x';
        }
    }
    out[len] = '\0';
    return out;
}
