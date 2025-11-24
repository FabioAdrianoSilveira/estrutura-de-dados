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

int Count(Vector *v)
{
    int count = 0;
    Vector *newVector;
    for (newVector = v; newVector != nullptr; newVector = newVector->next)
    {
        count++;
    }
    return count;
}

int main()
{
    Vector *node = Start();
    node = Insert(node, 1);
    node = Insert(node, 2);
    node = Insert(node, 3);
    node = Insert(node, 4);
    node = Insert(node, 5);

    cout << "Essa lista possui " << Count(node) << " nos";
    return 0;
}