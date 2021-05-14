#pragma once
#include <vector>

void insertion_sort(std::vector<int> &v, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = v[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 and v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}