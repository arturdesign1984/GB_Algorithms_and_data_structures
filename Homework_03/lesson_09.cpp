#include <iostream>
#include <iomanip>

#define T int
#define SIZE1 10
#define SIZE2 1000

//// 01 //////////////////////////////

struct Node
{
    int priority;
    int data;
};

Node* arr[SIZE1];
int head;
int tail;
int items;

void init();
void ins(int prio, int dat);
Node* rem();
void printQueue();


//// 02  /////////////////////////////

int counter = -1;
T stack[SIZE2];

bool push(T data);
T pop();
void decToBin(int x);

/////////////////////////////////////

int main()
{
    //// 01 //////////////////////////////
    std::cout << "1#\nPriority queue:\n";

    init();
    ins(3,11);
    ins(2,22);
    ins(1,33);
    ins(7,44);
    ins(8,55);
    ins(10,66);
    ins(9,77);
    ins(6,88);
    ins(5,99);
    ins(4,100);
    ins(11,100);

    printQueue();

    for (int i = 0; i < SIZE1-4; i++)
    {
        Node* out = rem();
        if (out != nullptr)
        {
            std::cout << "[" << out->priority << ", " << out->data << "] ";
        }
        else
        {
            std::cout << "\nQueue is empty.";
        }
    }
    ins(9,55);
    ins(5,66);
    ins(1,77);

    for (int i = 0; i < SIZE1+1; i++)
    {
        Node* out = rem();
        if (out != nullptr)
        {
            std::cout << "[" << out->priority << ", " << out->data << "] ";
        }
        else
        {
            std::cout << "\nQueue is empty.";
        }
    }

    std::cout << std::endl;

    //// 02  /////////////////////////////

    std::cout << "2#\nEnter number to convert: ";
    unsigned int dec;
    std::cin >> dec;

    decToBin(dec);

    std::cout << std::endl;
    return 0;
}

// 01 ////////////////////////////////////

void init()
{
    for (int k = 0; k < SIZE1; k++)
    {
        arr[k] = nullptr;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int prio, int dat)
{
    Node* node = new Node;
    node->data = dat;
    node->priority = prio;

    if (items == 0)
    {
        arr[tail] = node;
        tail++;
        items++;
    }
    else if (items == SIZE1)
    {
        std::cout << "\nQueue is full\n";
        return;
    }
    else
    {
        arr[tail] = node;
        tail++;
        items++;
    }
}

Node* rem()
{
    int idx = 0;

    if (items == 0)
    {
        return nullptr;
    }
    else if (items == 1)
    {
        tail--;
        items--;
        Node* temp = arr[idx];
        arr[tail] = nullptr;
        return temp;
    }
    else
    {
        tail--;
        items--;
        int prio = arr[head]->priority;

        for (int k = head; k < tail; k++)
        {
            if (prio > arr[k+1]->priority)
            {
                prio = arr[k+1]->priority;
                idx = k+1;
            }
        }

        Node* temp = arr[idx];

        for (int j = idx; j < tail; j++)
        {
            arr[j] = arr[j+1];
        }
        arr[tail] = nullptr;

        return temp;
    }
}

void printQueue()
{
   for (int k = 0; k < SIZE1; k++)
   {
       if (arr[k] == nullptr)
       {
           std::cout << "[*, *] ";
       }
       else
       {
           std::cout << "[" << arr[k]->priority << ", " << arr[k]->data << "] ";
       }
   }
   std::cout << std::endl;
}

// 02 ////////////////////////////////////

bool push(T data)
{
    if (counter < SIZE2)
    {
        stack[++counter] = data;
        return true;
    }
    else
    {
        std::cout << "\nStack overflow";
        return false;
    }
}

T pop()
{
    if(counter != -1)
    {
        return stack[counter--];
    }
    else
    {
        std::cout << "\nStack is empty";
        return -1;
    }
}

void decToBin(int x)
{
    while (x > 1)
    {
        push(x%2);
        x /= 2;
    }
    push(x);

    while(counter != -1)
    {
        std::cout << pop();
    }
}




