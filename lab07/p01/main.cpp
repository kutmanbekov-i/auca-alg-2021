#include <bits/stdc++.h>

using namespace std;

enum class State
{
    NotDefined,
    OnBorder,
    InTree
};

const int kDistNotDefined = -1;

int main()
{
    int nVertices; cin >> nVertices;

    vector<vector<pair<int, int>>> graph(9);

    char c1, c2;
    int w;

    map<pair<int, int>, int> weights;

    while (cin >> c1 >> c2 >> w)
    {
        int u = c1 - 'a';
        int v = c2 - 'a';

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);

        weights[{u, v}] = w;
    }

    vector<State> states(nVertices, State::NotDefined);
    vector<int> distances(nVertices, kDistNotDefined);
    vector<int> ancestors(nVertices, kDistNotDefined);


    int totalWeight = 0;

    states[0] = State::InTree;

    for (auto v : graph[0])
    {
        states[v.first] = State::OnBorder;
        distances[v.first] = v.second;
        ancestors[v.first] = 0;
    }

    // O(N*N)
    for (int i = 1; i < nVertices; ++i)
    {
        int index_of_min = nVertices;
        for (int j = 0; j < nVertices; ++j)
        {
            if (states[j] == State::OnBorder and (index_of_min == nVertices or distances[j] < distances[index_of_min]))
            {
                index_of_min = j;
            }
        }

        int u = ancestors[index_of_min];
        int v = index_of_min;

        // int w = weights[{u, v}];
        int w = distances[v];

        cout << char(u + 'a') << " " << char(v + 'a') << " " << w << '\n';

        totalWeight += w;

        states[v] = State::InTree;
        for (auto e : graph[v])
        {
            if (states[e.first] == State::NotDefined)
            {
                states[e.first] = State::OnBorder;
                distances[e.first] = e.second;
                ancestors[e.first] = v;
            }
            else if (states[e.first] == State::OnBorder and e.second < distances[e.first])
            {
                distances[e.first] = e.second;
                ancestors[e.first] = v;
            }
        }
    }

    cout << "Total weight: " << totalWeight << '\n';
    
    return 0;
}