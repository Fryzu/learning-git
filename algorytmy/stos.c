#include <iostream>
#include <string>

//First line number of questions, functions PUSH POP TOP

using namespace std;

struct Node {
    int value;
    Node *next;
};

int top(Node *position)
{
    if(position==NULL) cout << "EMPTY" << endl;
    else cout << position->value << endl;

    return 0;
}

int pop(Node **phead)
{
    if(*phead==NULL) return -1;
    
    Node *tmp = (*phead)->next;
    delete(*phead);
    *phead = tmp;

    return 0;
}

int push(Node **phead, int x)
{
    Node *newNode = new Node;
    newNode->next = *phead;
    newNode->value = x;

    *phead = newNode;

    return 0;
}

int main()
{
    Node *head = NULL;

    int z;
    cin >> z;

    string operation;
    int input_value;

    for(int k = 0; k<z; k++)
    {
        cin >> operation;
        if(operation.compare("TOP") == 0)
        {
            top(head);
        }
        else if(operation.compare("PUSH") == 0)
        {
            cin >> input_value;
            push(&head, input_value);
        }   
        else if(operation.compare("POP") == 0)
        {
            pop(&head);
        }
    }

    return 0;
} 
