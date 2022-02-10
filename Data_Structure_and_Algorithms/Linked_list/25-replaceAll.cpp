#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next; // a pointer
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *makeNode(int data)
{
    Node *tmp = new Node(data);
    return tmp;
}

void append(Node *p, int data)
{
    Node *tmp = new Node(data);
    p->next = tmp;
}

void replaceAll(Node *head, int value, int x)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == value)
        {
            p->data = x;
        }
        p = p->next;
    }
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

    // get data to the head of list
    int tmp;
    cin >> tmp;
    Node *head = new Node(tmp);

    // get data to list
    Node *p = head;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        append(p, tmp);
        p = p->next;
    }
    // input
    int value, x; // the value is replaced by x
    cin >> value >> x;
    replaceAll(head, value, x);

    printList(head);

    return 0;
}