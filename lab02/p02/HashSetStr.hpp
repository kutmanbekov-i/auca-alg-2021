#pragma once
#include <vector>
#include <string>
#include <iostream>

class HashSetStr
{
public:
    HashSetStr()
    :   buckets(11), mSize(0)
    {
    }

    ~HashSetStr()
    {
        clear();
    }

    HashSetStr(int size);
    void debug_print() const;

    bool insert(const std::string &k);
    bool find(const std::string &k) const;
    bool erase(const std::string &k);
    void clear();

    // void resize();

    std::size_t size() const
    {
        return mSize;
    }

private:
    struct Node
    {
        std::string mData;
        Node *mNext;

        Node(const std::string &data, Node *next)
            : mData(data), mNext(next)
        {
        }
    };

    void rehash();

    std::size_t mSize;
    std::vector<Node *> buckets;
};