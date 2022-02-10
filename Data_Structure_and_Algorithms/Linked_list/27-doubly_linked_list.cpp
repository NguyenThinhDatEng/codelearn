#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next; // a pointer
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *makeNode(int data)
{
    Node *tmp = new Node(data);
    return tmp;
}

void addHead(Node **head, int x)
{
    Node *tmp = new Node(x);
    tmp->next = *head;
    *head = tmp;
}

void addTail(Node **tail, int x)
{
    Node *tmp = new Node(x);
    (*tail)->next = tmp;
    tmp->prev = *tail;
    *tail = tmp;
}

void printList(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    // input
    int n;
    cin >> n;
    int size = 2 * n;

    // get data to the head of list
    Node *head = new Node(1);
    Node *last = head;
    // get data to list
    Node *p = head;
    for (int i = 2; i <= n; i++)
    {
        addHead(&head, i);
        addTail(&last, i);
    }

    // algorithm
    printList(head);

    return 0;
}