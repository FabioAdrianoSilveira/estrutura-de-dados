#include <iostream>

using namespace std;

struct Vector
{
    int info;
    Vector *next;
};

Vector *Start()
{
    return nullptr;
}

Vector *Insert(Vector *v, int i)
{
    Vector *newNode = new Vector;
    newNode->info = i;
    newNode->next = v;

    return newNode;
}

Vector *Reverse(Vector *currentNode)
{
    Vector *previousNode = nullptr;
    Vector *nextNode;

    while (currentNode != nullptr)
    {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
        
    }
    return previousNode;
}

void Print(Vector *v)
{
    Vector *newVector;
    for (newVector = v; newVector != nullptr; newVector = newVector->next)
    {
        cout << newVector->info << " ";
    }
    cout << endl;
}

int main()
{
    Vector *node = Start();
    node = Insert(node, 1);
    node = Insert(node, 2);
    node = Insert(node, 3);
    node = Insert(node, 4);
    node = Insert(node, 5);

    cout << "A Lista criada foi: ";
    Print(node);
    cout << "Quando invertida, a lista será: ";
    Print(Reverse(node));
    return 0;
}