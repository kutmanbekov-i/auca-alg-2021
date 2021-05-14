#include <bits/stdc++.h>

using namespace std;

enum class State
{
    NotDefined,
    OnBorder,
    InTree
};

const int UNDEFINED_WEIGHT = -1;

int main()
{
    int nVertices; cin >> nVertices;

    string source; cin >> source;

    string dest; cin >> dest;

    map <string, vector <pair <string, int>>> graph;

    {   // input
        string u, v;
        int w;

        while (cin >> u >> v >> w)
        {
            graph[u].emplace_back(v, w);
        }
    }

    map<string, State> states;
    map<string, int> weights;
    map<string, string> ancestors;

    for (const auto &e : graph)
    {
        states[e.first] = State::NotDefined;
        weights[e.first] = UNDEFINED_WEIGHT;
    }

    set<pair<int, string>> border;

    states[source] = State::OnBorder;
    weights[source] = 0;
    border.emplace(0, source);

    while (!border.empty())
    {
        auto p = *border.begin();
        border.erase(border.begin());

        string u = p.second;
        states[u] = State::InTree;

        for (const auto &v : graph[u])
        {
            State state = states[v.first];
            if (state == State::NotDefined)
            {
                states[v.first] = State::OnBorder;
                ancestors[v.first] = u;
                
                int w = weights[u] + v.second;
                weights[v.first] = w;

                border.emplace(w, v.first);
            }
            else if (state == State::OnBorder)
            {
                int w1 = weights[v.first];
                int w2 = weights[u] + v.second;

                if (w1 > w2)
                {
                    border.erase({w1, v.first});
                    border.emplace(w2, v.first);

                    weights[v.first] = w2;
                    ancestors[v.first] = u;
                }
            }

        }
    }

    // C++17
    // for (auto [v, w]: weights)
    for (const auto &p : weights)
    {
        cout << p.first << ": " << p.second << '\n';
    }

    if (weights[dest] == UNDEFINED_WEIGHT)
    {
        cout << "Unreachable.\n";
    }
    else
    {
        vector <string> path = {dest};
        while (path.back() != source)
        {
            path.push_back(ancestors[path.back()]);
        }

        reverse(path.begin(), path.end());

        for (const auto &e : path)
        {
            cout << e << ' ';
        }
        cout << '\n' << "The total weight: " << weights[dest] << '\n';
    }

    return 0;
}
