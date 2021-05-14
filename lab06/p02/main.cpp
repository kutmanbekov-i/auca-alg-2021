#include <bits/stdc++.h>

using namespace std;

enum class Color
{
    White,
    Red,
    Black
};

void dfs(int v, vector<vector<int>> &graph, vector<Color> &colors, vector<int> &order)
{
    colors[v] = Color::Red;

    // order.push_back(v); why can't we push it here?

    for (auto e : graph[v])
    {
        if (colors[e] == Color::Red)
        {
            throw runtime_error("Cycle: input is not a Directed Acyclic Graph. The Loop is Found.\nVertex: " + to_string(e + 1));
        }
        if (colors[e] == Color::White)
        {
            dfs(e, graph, colors, order);
        }
    }

    order.push_back(v);
    colors[v] = Color::Black;
}

int main()
try
{
    int nVertices;
    cin >> nVertices;

    string line;
    getline(cin, line);

    vector<vector<int>> graph(nVertices);

    for (int i = 0; i < nVertices; ++i)
    {
        getline(cin, line);

        if (line != "-")
        {
            istringstream sinp(line);
            for (int v; sinp >> v;)
            {
                graph[i].push_back(v - 1);
            }
        }
    }

    // cout << graph.size();

    vector<Color> colors(nVertices, Color::White);
    vector<int> order;

    for (int i = 0; i < nVertices; ++i)
    {
        if (colors[i] == Color::White)
        {
            dfs(i, graph, colors, order);
        }
    }

    reverse(order.begin(), order.end());

    for (auto e : order)
    {
        cout << " " << e + 1;
    }
    cout << '\n';

    return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << '\n';
}