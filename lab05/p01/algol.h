#pragma once
#include <vector>

int binary_search(const std::vector<int> &v, size_t n, int x)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (v[mid] == x)
        {
            return mid;
        }
        else if (v[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}