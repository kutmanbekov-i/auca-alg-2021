#include "MapStrInt.hpp"

#include <ostream>
#include <utility>
#include <vector>

using namespace std;

int &MapStrInt::operator[](const string &k)
{
    Node *prev = nullptr;
    Node *curr = mRoot;
    bool isLeft = false;
    while (curr != nullptr)
    {
        prev = curr;
        if (k < curr->mData.first)
        {
            isLeft = true;
            curr = curr->mLeft;
        }
        else if (curr->mData.first < k)
        {
            isLeft = false;
            curr = curr->mRight;
        }
        else
        {
            return curr->mData.second;      // if the element existed
        }
    }

    Node *p = new Node(k, 0, nullptr, nullptr);

    ++mSize;

    if (mRoot == nullptr)
    {
        mRoot = p;
    }
    else if (isLeft)
    {
        prev->mLeft = p;
    }
    else
    {
        prev->mRight = p;
    }

    return p->mData.second;
}

void MapStrInt::printInOrder(ostream &out, Node *root) const
{
    if (root != nullptr)
    {
        printInOrder(out, root->mLeft);
        out << root->mData.first << ": " << root->mData.second << '\n';
        printInOrder(out, root->mRight);
    }
}

void MapStrInt::clear(Node *cur)
{
    if (cur != nullptr)
    {
        clear(cur->mLeft);
        clear(cur->mRight);
        delete cur;
        --mSize;
    }
}