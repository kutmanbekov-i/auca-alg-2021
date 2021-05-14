#pragma once

#include <vector>

void count_sort(std::vector<int>& v)
{
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    int range = max - min + 1;
 
    std::vector<int> count(range), output(v.size());
    
    for (int i = 0; i < (int)v.size(); i++)
        count[v[i] - min]++;
 
    for (int i = 1; i < (int)count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        output[count[v[i] - min] - 1] = v[i];
        count[v[i] - min]--;
    }
 
    for (int i = 0; i < (int)v.size(); i++)
        v[i] = output[i];
}
