#pragma once

#include <vector>

void count_sort(std::vector<int>& v)
{
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    int range = max - min + 1;
 
    std::vector<int> count(range), output(v.size());
    
    // Store the count of each element (start with index 0)
    for (int i = 0; i < (int)v.size(); i++)
        count[v[i] - min]++;
 
    // Store the cummulative count of each array
    for (int i = 1; i < (int)count.size(); i++)
        count[i] += count[i - 1];

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        output[count[v[i] - min] - 1] = v[i];
        count[v[i] - min]--;
    }
 
    // Copy the sorted elements into original array
    for (int i = 0; i < (int)v.size(); i++)
        v[i] = output[i];
}
