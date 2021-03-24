#pragma once

#include <cstddef>
#include <string>
#include <sstream>
#include <iostream>
// #include <utility>

template <typename T>
class List
{
    struct Node
    {
        T mData;
        Node *mPrev;
        Node *mNext;

        Node(const T &data, Node *prev, Node *next)
            : mData(data), mPrev(prev), mNext(next)
        {
        }
    };

    Node *mHead;
    // Node *mTail;
    size_t mSize;

public:

    // default constructor
    List()
        : mHead(new Node(T(), nullptr, nullptr)), mSize(0)
    {
        mHead->mNext = mHead;
        mHead->mPrev = mHead;
        // mTail->mPrev = mHead;
    }

    // copy constructor
    List(const List &other)
        : mHead(new Node(T(), nullptr, nullptr)), mSize(0)
    {
        mHead->mNext = mHead;
        mHead->mPrev = mHead;
        for (auto it = other.begin(); it != other.end(); ++it)
        {
            pushBack(*it);
        }
    }

    // assignment operator (copy)
    List &operator=(const List &other)
    {
        if (this != &other)
        {
            clear();

            mHead->mNext = mHead;
            mHead->mPrev = mHead;

            for (auto it = other.begin(); it != other.end(); ++it)
            {
                pushBack(*it);
            }
        }
        return *this;
    }


    ~List()
    {
        clear();

        delete mHead;
        // delete mTail;
    }

    void clear()
    {
        while (begin() != end())
        {
            erase(begin());
        }
        
    }

    size_t size() const
    {
        return mSize;
    }

    std::string toStr() const
    {
        std::ostringstream out;

        out << "{";
        Node *p = mHead->mNext;

        for (std::size_t i = 0; i < mSize; ++i)
        {
            if (i)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mNext;
        }
        out << "}";

        return out.str();
    }

    std::string toReverseStr() const
    {
        std::ostringstream out;

        out << "{";
        // Node *p = mTail->mPrev;
        Node *p = mHead->mPrev;

        for (std::size_t i = 0; i < mSize; ++i)
        {
            if (i)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mPrev;
        }
        out << "}";

        return out.str();
    }

    void pushBack(const T &data)
    {
        insert(end(), data);
        // Node *t = new Node(data, mTail->mPrev, mTail);
        // mTail->mPrev->mNext = t;
        // mTail->mPrev = t;
        // ++mSize;
    }

    void popBack()
    {
        Iter r = end();
        erase(--r);
        // mTail->mPrev = mTail->mPrev->mPrev;
        // mTail->mPrev->mNext = mTail;
        // --mSize;
    }

    void pushFront(const T &data)
    {
        insert(begin(), data);
    }
    void popFront()
    {
        erase(begin());
    }

    class Iter;

    Iter begin() const
    {
        Iter r;
        r.mPtr = mHead->mNext;
        return r;
    }

    Iter end() const
    {
        Iter r;
        r.mPtr = mHead;
        return r;
    }

    class RIter;

    RIter rbegin() const
    {
        RIter r;
        r.mPtr = mHead->mPrev;
        return r;
    }

    RIter rend() const
    {
        RIter r;
        r.mPtr = mHead;
        return r;
    }

    Iter insert(Iter p, const T &data)
    {
        Iter r;
        r.mPtr = new Node(data, p.mPtr->mPrev, p.mPtr);

        p.mPtr->mPrev->mNext = r.mPtr;
        p.mPtr->mPrev = r.mPtr;

        // r.mPtr->mNext->mPrev->mNext = r.mPtr;
        // r.mPtr->mPrev->mNext->mPrev = r.mPtr;

        ++mSize;
        return r;
    }

    Iter erase(Iter p)
    {
        Iter r = p;
        ++r;
        p.mPtr->mPrev->mNext = p.mPtr->mNext;
        p.mPtr->mNext->mPrev = p.mPtr->mPrev;
        delete p.mPtr;

        --mSize;

        return r;
    }

};

template <typename T>
class List<T>::Iter
{
    Node *mPtr;
    friend class List<T>;

public:

    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iter() : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }

    T *operator->() const
    {
        return &(mPtr->mData);
    }

    // prefix ---> ++it;
    Iter &operator++()
    {
        mPtr = mPtr->mNext;
        return *this;
    }
    // postfix ---> it++;
    Iter &operator++(int)
    {
        Iter r = *this;
        mPtr = mPtr->mNext;
        return r;
    }
    // pre
    Iter &operator--()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }
    // post
    Iter &operator--(int)
    {
        Iter r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }

    bool operator==(const Iter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const Iter &other) const
    {
        // return !(*this == other);
        return mPtr != other.mPtr;
    }
};

template <typename T>
class List<T>::RIter
{
    Node *mPtr;
    friend class List<T>;

public:

    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    RIter() : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }

    T *operator->() const
    {
        return &(mPtr->mData);
    }

    // prefix ---> ++it;
    RIter &operator++()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }
    // postfix ---> it++;
    RIter &operator++(int)
    {
        Iter r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }
    // pre
    RIter &operator--()
    {
        mPtr = mPtr->mNext;
        return *this;
    }
    // post
    RIter &operator--(int)
    {
        Iter r = *this;
        mPtr = mPtr->mNext;
        return r;
    }

    bool operator==(const RIter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const RIter &other) const
    {
        // return !(*this == other);
        return mPtr != other.mPtr;
    }
};
