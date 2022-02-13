#include <iostream>
#include <cstring>

#define T char
#define SIZE1 10

//// 01 //////////////////////////////

struct Node
{
    T data;
    Node* next;
};

struct Stack
{
    Node* head;
    int size;
};

void initStack(Stack* stack)
{
    stack->head = nullptr;
    stack->size = 0;
}

bool push(Stack* stack, T value);

T pop(Stack* stack);

void bracketCompare(Stack* stack, char* str);

//// 02  /////////////////////////////

void insertToList(Stack* list, T data);

void printList(Stack* list_01);

T getNodeData(Node* n);

void listCpy(Stack* listA, Stack* listB);

//// 03  /////////////////////////////

void isTheListSorted(Stack* list);

//////////////////////////////////////

int main()
{
    //// 01 //////////////////////////////

    std::cout << "######\n# 01 #\n######\n\nEnter string to compare:\n\n";
    char str[80];
    std::cin >> str;
    std::cout << "\nYou have entered: " << strlen(str) << " symbols.\n" << "And..." << std::endl;

    Stack* bracketStack = new Stack;
    initStack(bracketStack);

    bracketCompare(bracketStack, str);

    std::cout << std::endl << std::endl;

    //// 02  /////////////////////////////

    std::cout << "######\n# 02 #\n######\n\nCopying data from list_01 to list_02:\n\n";

    Stack* list_01 = new Stack;
    initStack(list_01);
    Stack* list_02 = new Stack;
    initStack(list_02);

    insertToList(list_01, 'a');
    insertToList(list_01, 'b');
    insertToList(list_01, 'c');
    insertToList(list_01, 'd');
    insertToList(list_01, 'f');

    std::cout << "List_01" << std::endl;
    printList(list_01);
    std::cout << "\nList_02" << std::endl;
    printList(list_02);

    std::cout << "\n\nList copying..." << std::endl;
    listCpy(list_01, list_02);

    std::cout << "\nList_01" << std::endl;
    printList(list_01);
    std::cout << "\nList_02" << std::endl;
    printList(list_02);

    std::cout << std::endl << std::endl;

    //// 03  /////////////////////////////

    std::cout << "######\n# 03 #\n######\n\nIs the list sorted?\n\n";

    Stack* list_03 = new Stack;
    initStack(list_03);
    Stack* list_04 = new Stack;
    initStack(list_04);
    Stack* list_05 = new Stack;
    initStack(list_05);
    Stack* list_06 = new Stack;
    initStack(list_06);

    insertToList(list_03, 'a');
    insertToList(list_03, 'b');
    insertToList(list_03, 'c');
    insertToList(list_03, 'd');
    insertToList(list_03, 'f');

    insertToList(list_04, 'f');
    insertToList(list_04, 'd');
    insertToList(list_04, 'c');
    insertToList(list_04, 'b');
    insertToList(list_04, 'a');

    insertToList(list_05, 'a');
    insertToList(list_05, 'd');
    insertToList(list_05, 'c');
    insertToList(list_05, 'b');
    insertToList(list_05, 'f');

    insertToList(list_06, 'x');

    std::cout << "list_03:";
    isTheListSorted(list_03);
    std::cout << "list_04:";
    isTheListSorted(list_04);
    std::cout << "list_05:";
    isTheListSorted(list_05);
    std::cout << "list_06:";
    isTheListSorted(list_06);

    std::cout << std::endl << std::endl;
    return 0;
}

// 01 ////////////////////////////////////

bool push(Stack* stack, T value)
{
    Node* tmp = new Node;
    if (tmp == nullptr)
    {
        std::cout << "\nStack overflow\n";
        return false;
    }
    tmp->data = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack* stack)
{
    if(stack->size == 0)
    {
        //std::cout << "Stack is empty.";
        return -1;
    }
    Node* tmp = stack->head;
    T data = stack->head->data;
    stack->head = stack->head->next;
    delete tmp;
    stack->size--;
    return data;
}

void bracketCompare(Stack* stack, char* str)
{
    char tmp = '0';
    bool stackErr = false;
    bool error = false;
    size_t countBracket = 0;
    size_t countChar = 0;
    size_t countSum = 0;
    for (size_t k = 0; k < strlen(str); k++)
    {
        switch (str[k])
        {
            case '(':
                if (push(stack, str[k]) == true)
                {
                    countBracket++;
                    countSum = countBracket + countChar;
                    break;
                }
                else
                {
                    stackErr = true;
                    k = strlen(str);
                    break;
                }

            case '[':
                if (push(stack, str[k]) == true)
                {
                    countBracket++;
                    countSum = countBracket + countChar;
                    break;
                }
                else
                {
                    stackErr = true;
                    k = strlen(str);
                    break;
                }
            case '{':
                if (push(stack, str[k]) == true)
                {
                    countBracket++;
                    countSum = countBracket + countChar;
                    break;
                }
                else
                {
                    stackErr = true;
                    k = strlen(str);
                    break;
                }
            case ')':
                tmp = pop(stack);
                if (tmp != '(')
                {
                    error = true;
                    countBracket++;
                    countSum = countBracket + countChar;
                    std::cout << "Bracket < ) > at position # " << countSum << " is wrong.";
                    k = strlen(str);
                    break;
                }
                else
                {
                    countBracket++;
                    countSum = countBracket + countChar;
                    break;
                }

            case ']':
                tmp = pop(stack);
                if (tmp != '[')
                {
                    error = true;
                    countBracket++;
                    countSum = countBracket + countChar;
                    std::cout << "Bracket < ] > at position # " << countSum << " is wrong.";
                    k = strlen(str);
                    break;
                }
                else
                {
                    countBracket++;
                    countSum = countBracket + countChar;
                    break;
                }
            case '}':
                tmp = pop(stack);
                if (tmp != '{')
                {
                    error = true;
                    countBracket++;
                    countSum = countBracket + countChar;
                    std::cout << "Bracket < } > at position # " << countSum << " is wrong.";
                    k = strlen(str);
                    break;
                }
                else
                {
                    countBracket++;
                    countSum = countBracket + countChar;
                    break;
                }
            default:
                countChar++;
                countSum = countBracket + countChar;
                break;
        }
    }
    if (stackErr == false)
    {
        if (countBracket == 0)
        {
            std::cout << "ERROR! No brackets was found.\n";
        }
        else if (countBracket == 1)
        {
            std::cout << "ERROR! Just one bracket was found.\n";
        }
        else if (error == false && pop(stack) == -1)
        {
            std::cout << "All brackets is right.\n";
        }
        else if (countSum < 1)
        {
            std::cout << "ERROR! Some closing brackets are missing.\n";
        }
    }
    else
    {
        std::cout << "String is too long.\n";
    }
}

// 02 ////////////////////////////////////

void insertToList(Stack* list, T data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* current = list->head;
    if (current == nullptr)
    {
        list->head = newNode;
        list->size++;
        return;
    }
    else
    {
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
        list->size++;
    }
}

Node* removeFromList(Stack* list, T data)
{
    Node* current = list->head;
    Node* parent = nullptr;
    if (current == nullptr)
    {
        return nullptr;
    }
    while (current->next != nullptr && current->data != data)
    {
        parent = current;
        current = current->next;
    }
    if (current->data != data)
    {
        return nullptr;
    }
    if (current == list->head)
    {
        list->head = current->next;
        list->size--;
    }
    parent->next = current->next;
    list->size--;
    return current;
}

T getNodeData(Node* n)
{
    if (n == nullptr)
    {
        return -1;
    }
    return n->data;
}

void printList(Stack* list)
{
    Node* current = list->head;
    if (current == nullptr)
    {
        std::cout << "List is empty.";
    }
    else
    {
        do
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        while (current);
    }
    std::cout << " - List size: " << list->size;
}

void listCpy(Stack* listA, Stack* listB)
{
    Node* current = listA->head;

    if (current == nullptr)
    {
        std::cout << "List is empty.\n";
        return;
    }
    while(current)
    {
        insertToList(listB,getNodeData(current));
        current = current->next;
    }
}

// 03 ////////////////////////////////////

void isTheListSorted(Stack* list)
{
    Node* current = list->head;
    int countUp = 0;
    int countDown = 0;
    int countEqual = 0;
    if (current == nullptr)
    {
        std::cout << "   List is empty.\n";
        return;
    }
    if (current->next == nullptr)
    {
        std::cout << "   List have only one unit.\n";
        return;
    }
    T tmp = getNodeData(current);
    current = current->next;
    while(current)
    {
        if (tmp < getNodeData(current))
        {
            countUp++;
            tmp = getNodeData(current);
            current = current->next;
        }
        else if (tmp > getNodeData(current))
        {
            countDown++;
            tmp = getNodeData(current);
            current = current->next;
        }
        else
        {
            countEqual++;
            tmp = getNodeData(current);
            current = current->next;
        }
    }
    if (countEqual == list->size)
    {
        std::cout << "   All units is equal.\n";
    }
    else if ((countUp+countEqual) == (list->size - 1))
    {
        std::cout << "   List is sorted - down to up.\n";
    }
    else if ((countDown+countEqual) == (list->size - 1))
    {
        std::cout << "   List is sorted - up to down.\n";
    }
    else
    {
        std::cout << "   List is not sorted.\n";
    }
}
