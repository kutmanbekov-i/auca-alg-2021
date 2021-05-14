#include <bits/stdc++.h>

using namespace std;

const string kNil = "no ancestors";

enum class Color
{
    White,
    Red,
    Black
};

int main()
{
    int e;
    cin >> e;

    map<string, vector<string>> graph;

    for (int i = 0; i < e; ++i)
    {
        string v1;
        cin >> v1;
        string v2;
        cin >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    string src;
    cin >> src;
    string dest;
    cin >> dest;

    queue<string> q;

    map<string, Color> states;
    map<string, int> distances;
    map<string, string> ancestor;

    for (const auto &e : graph)
    {
        states[e.first] = Color::White;
        ancestor[e.first] = kNil;
    }

    q.push(src);
    states[src] = Color::Red;
    distances[src] = 0;
    // ancestor[src] = kNil;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        states[u] = Color::Black;
        for (const auto e : graph[u])
        {
            if (states[e] == Color::White)
            {
                states[e] = Color::Red;
                q.push(e);

                distances[e] = distances[u] + 1;
                ancestor[e] = u;
            }
        }
    }

    for (const auto &e : distances)
    {
        cout << e.first << ": " << e.second << '\n';
    }

    cout << "====================================================\n";

    for (const auto &e : ancestor)
    {
        cout << e.first << ": " << e.second << '\n';
    }

    cout << "====================================================\n";

    vector<string> path;
    string curVertex = dest;

    // path.push_back(curVertex);

    while (ancestor[curVertex] != kNil)
    {
        path.push_back(curVertex);
        curVertex = ancestor[curVertex];
    }

    path.push_back(curVertex);

    reverse(path.begin(), path.end());

    for (const auto &e : path)
    {
        cout << " " << e;
    }

    return 0;
}