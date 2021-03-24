#include "HashSetStr.hpp"

size_t default_hash_func(const std::string &s)
{
    size_t r = 0;
    for (char c : s)
    {
        r += c * 97 + 31;
    }
    return r;
}

bool HashSetStr::insert(const std::string &k)
{
    size_t ind = default_hash_func(k) % buckets.size();

    for (auto p = buckets[ind]; p != nullptr; p = p->mNext)
    {
        if (p->mData == k)
        {
            return false;
        }
    }

    if (mSize == buckets.size())
    {
        rehash();
        ind = default_hash_func(k) % buckets.size();
    }

    buckets[ind] = new Node(k, buckets[ind]);
    ++mSize;

    return true;
}

void HashSetStr::rehash()
{
    std::vector<Node *> newBuckets(2 * buckets.size() + 1, nullptr);

    for (size_t i = 0; i < buckets.size(); ++i)
    {
        while (buckets[i] != nullptr)
        {
            size_t index = default_hash_func(buckets[i]->mData) % newBuckets.size();

            Node *t = buckets[i];

            buckets[i] = buckets[i]->mNext;

            t->mNext = newBuckets[index];
            newBuckets[index] = t;
        }
    }
    buckets.swap(newBuckets);
}

bool HashSetStr::find(const std::string &k) const
{
    size_t ind = default_hash_func(k) % buckets.size();

    for (auto p = buckets[ind]; p != nullptr; p = p->mNext)
    {
        if (p->mData == k)
        {
            return true;
        }
    }
    return false;
}

bool HashSetStr::erase(const std::string &k)
{
    size_t index = default_hash_func(k) % buckets.size();

    for (Node *prev = nullptr, *cur = buckets[index]; cur != nullptr;)
    {
        if (cur->mData == k)
        {
            if (prev != nullptr)
            {
                prev->mNext = cur->mNext;
            }
            else
            {
                buckets[index] = cur->mNext;
            }

            delete cur;

            --mSize;
            return true;
        }
        prev = cur;
        cur = cur->mNext;
    }

    return false;
}

void HashSetStr::clear()
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        while (buckets[i] != nullptr)
        {
            Node *t = buckets[i];
            buckets[i] = buckets[i]->mNext;

            delete t;
            --mSize;
        }
    }
}


void HashSetStr::debug_print() const
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        std::cout << i << ":";
        for (Node *p = buckets[i]; p; p = p->mNext)
        {
            std::cout << " " << p->mData;
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}