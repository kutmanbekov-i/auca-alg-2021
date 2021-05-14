#include <bits/stdc++.h>

using namespace std;

enum class Color
{
    White,
    Red,
    Black
};

void dfs(int v, vector<vector<int>> &graph, vector<Color> &colors, vector<int> &components)
{
    colors[v] = Color::Red;

    components.push_back(v);

    for (auto e : graph[v])
    {
        if (colors[e] == Color::White)
        {
            dfs(e, graph, colors, components);
        }
    }

    colors[v] = Color::Black;
}

int main()
{
    int nVertices;
    cin >> nVertices;

    vector<vector<int>> graph(nVertices);

    for (int r = 0; r < nVertices; ++r)
    {
        for (int c = 0; c < nVertices; ++c)
        {
            char ch;
            cin >> ch;

            if (ch == '1')
            {
                graph[r].push_back(c);
            }
        }
    }

    // cout << graph.size();

    vector<Color> colors(nVertices, Color::White);

    int n = 0;

    for (int i = 0; i < nVertices; ++i)
    {
        if (colors[i] == Color::White)
        {
            ++n;

            vector<int> cur_component;
            dfs(i, graph, colors, cur_component);

            cout << n << ":";

            for (auto e : cur_component)
            {
                cout << " " << e;
            }
            cout << '\n';
        }
    }
    
    return 0;
}