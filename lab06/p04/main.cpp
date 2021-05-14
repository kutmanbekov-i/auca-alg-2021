#include <bits/stdc++.h>

using namespace std;

const int kNo_anc = -1;

enum class Color
{
    White,
    Red,
    Black
};

bool inside(const vector<string> &maze, int row, int col)
{
    int h = maze.size();
    int w = maze[0].size();

    return 0 <= row and row < h and 0 <= col and col < w;
}

int main()
{
    int mazeSize; cin >> mazeSize;

    vector<string> maze(mazeSize);

    int start, dest;
    for (int r = 0; r < mazeSize; ++r)
    {
        cin >> maze[r];
        int cStart = maze[r].find('S');
        if (cStart != int(string::npos))     // HUGE INDEX index (-1)
        {
            start = r * mazeSize + cStart;
        }
        int cDest = maze[r].find('D');
        if (cDest != int(string::npos))
        {
            dest = r * mazeSize + cDest;
        }

    }

    static vector<int> dr = {-1, 0, 1, 0};
    static vector<int> dc = {0, 1, 0, -1};

    vector<int> distances(mazeSize * mazeSize);
    vector<int> ancestors(mazeSize * mazeSize, kNo_anc);
    vector<Color> colors(mazeSize * mazeSize, Color::White);

    queue<int> q;
    q.push(start);
    colors[start] = Color::Red;
    distances[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        colors[cur] = Color::Black;

        int r = cur / mazeSize;
        int c = cur % mazeSize;
        for (int i = 0; i < (int)dr.size(); ++i)
        {
            int tr = r + dr[i];
            int tc = c + dc[i];
            int t = tr * mazeSize + tc;

            if (inside(maze, tr, tc) and maze[tr][tc] != '#' and colors[t] == Color::White)
            {
                q.push(t);
                colors[t] = Color::Red;

                ancestors[t] = cur;
                distances[t] = distances[cur] + 1;

                if (t == dest) 
                {
                    q = queue<int>();       // clear the queue, and after breaking for loop - exit from while loop
                    break;
                }
            }
        }

    }

    if (ancestors[dest] == kNo_anc)
    {
        cout << "Unreachable.\n"; 
    }
    else
    {
        cout << distances[dest] << '\n';

        int cur = dest;
        while (cur != start)
        {
            maze[cur / mazeSize][cur % mazeSize] = '*';
            cur = ancestors[cur];
        }

        for (const auto &e : maze)
        {
            cout << e << '\n';
        }
        cout << '\n';
    }



    return 0;
}