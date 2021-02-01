#include <iostream>

using namespace std;

struct Node
{
    int mData;
    Node *mPrev;
    Node *mNext;

    Node(int data, Node *prev, Node *next)
        : mData(data), mPrev(prev), mNext(next)
    {
    }
};

void printInDirectOrder(Node *head)
{
    for (Node *p = head; p; p = p->mNext)
    {
        cout << p->mData << ' ';
    }
    cout << '\n';
}
void printInReversedOrder(Node *tail)
{
    for (Node *p = tail; p; p = p->mPrev)
    {
        cout << p->mData << ' ';
    }
    cout << '\n';
}

void pushBack(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data, nullptr, nullptr);
    }
    else
    {
        tail->mNext = new Node(data, tail, nullptr); // [1] <- [2]
        tail = tail->mNext;
    }
}

void clear(Node **head, Node **tail)
{
    Node *cur = *head;
    Node *next;

    while (cur != NULL)
    {
        next = cur->mNext;
        free(cur);
        cur = next;
    }
    *head = NULL;
    *tail = NULL;
}

void clear(Node *&head, Node *&tail)
{
    for (Node *p = head; p; p = p->mNext)
    {
        Node *temp = p;
        delete p;
        p = temp;
    }
    head = tail = nullptr;
}

void insertBefore(Node *&head, Node *cur, int x)
{
    // before first element
    if (head == cur)
    {
        cur->mPrev = new Node(x, nullptr, cur);
        head = cur->mPrev;
    }
    else
    {
        Node *t = new Node(x, cur->mPrev, cur);
        t->mPrev->mNext = t;
        t->mNext->mPrev = t;
    }
}

Node *erase(Node *&head, Node *&tail, Node *cur)
{
    if (head == cur and head == tail)
    {
        delete head;
        head = tail = nullptr;

        return nullptr;
    }
    else if (head == cur)
    {
        head = head->mNext;
        head->mPrev = nullptr;

        delete cur;

        return head;
    }
    else if (tail == cur)
    {
        tail = head->mPrev;
        head->mNext = nullptr;

        delete cur;
        return nullptr;
    }

    Node* t = cur->mNext;

    cur->mPrev->mNext = cur->mNext;
    cur->mNext->mPrev = cur->mPrev;

    delete cur;

    return t;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int x; cin >> x;)
    {
        pushBack(head, tail, x);
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    for (Node *p = head; p; p = p->mNext)
    {
        if (p->mData % 2 == 0)
        {
            insertBefore(head, p, 0);
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    for (Node *p = head; p != nullptr;)
    {
        if (p->mData % 2 == 0)
        {
            p = erase(head, tail, p);
        }
        else
        {
            p = p->mNext;
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    clear(&head, &tail);
}