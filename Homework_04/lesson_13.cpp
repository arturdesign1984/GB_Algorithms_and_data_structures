#include <iostream>

//// 01 //////////////////////////////

struct Node
{
    int data;
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

bool push(Stack* stack, int value);

int pop(Stack* stack);

const int n = 6;
int matrix[n][n] = {
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,1,0},
};
int visited[n];

void depthTravers(int st)
{
    Stack* stack = new Stack;
    initStack(stack);
    int r;
    for (int k = 0; k < n; k++)
    {
        for (r = n - 1; r >= 0; r--)
        {
            if (matrix[st][r] == 1 && !visited[r])
            {
                push(stack, r);
            }
        }
        std::cout << st;
        visited[st] = 1;
        st = pop(stack);
        if (st == -1)
        {
            break;
        }
    }
    while (pop(stack) >= 0)
    {
        pop(stack);
    }
    delete stack;
}

void resetArr()
{
    for (int k = 0; k < n; k++)
    {
        visited[k] = 0;
    }
}

//// 01 //////////////////////////////


int main()
{
    //// 01 //////////////////////////////
    std::cout << "######\n# 01 #\n######\n\nDepth travers:\n\n";

    depthTravers(0);
    resetArr();
    std::cout << std::endl;
    depthTravers(2);
    resetArr();
    std::cout << std::endl;
    depthTravers(1);
    resetArr();
    std::cout << std::endl << std::endl;

    //// 02  /////////////////////////////

    std::cout << "######\n# 02 #\n######\n\nThe task is not done:\n\n";



    std::cout << std::endl;

    return 0;
}

// 01 ////////////////////////////////////

bool push(Stack* stack, int value)
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

int pop(Stack* stack)
{
    if(stack->size == 0)
    {
        //std::cout << "Stack is empty.";
        return -1;
    }
    Node* tmp = stack->head;
    int data = stack->head->data;
    stack->head = stack->head->next;
    delete tmp;
    stack->size--;
    return data;
}

// 02 ////////////////////////////////////

