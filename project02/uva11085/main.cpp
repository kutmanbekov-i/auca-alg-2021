#include <bits/stdc++.h>

using namespace std;

const int BOARD_SIZE = 8;

class Solver
{
    const int n = 8;
    int count;
    vector<bool> mRows;
    vector<bool> mDiag1;
    vector<bool> mDiag2;
    vector<int> solution;
    
    vector<int> positions;
    int minimum = INT_MAX;
    int cnt = 0;

public:
    Solver(vector <int> &pos)
        : count(0)
    {
        for (size_t i = 0; i < pos.size(); ++i)
        {
            positions.push_back(pos[i] - 1);
        }
        
        mRows.resize(n, false);
        mDiag1.resize(n * 2 - 1, false);
        mDiag2.resize(2 * n - 1, false);
        solution.resize(n);
    }
    

    void solve(int col)
    {
        if (col == n)
        {
            conclude();
        }
        else
        {
            for (int row = 0; row < n; ++row)
            {
                if (isFreeSquare(row, col))
                {
                    putQueen(row, col);
                    solve(col + 1);
                    removeQueen(row, col);
                }
            }
        }
    }

    void putQueen(int row, int col)
    {
        mRows[row] = mDiag1[row + col] = mDiag2[col - row + n - 1] = true;
        solution[col] = row;
    }
    void removeQueen(int row, int col)
    {
        mRows[row] = mDiag1[row + col] = mDiag2[col - row + n - 1] = false;
    }

    bool isFreeSquare(int row, int col)
    {
        return !mRows[row] && !mDiag1[row + col] && !mDiag2[col - row + n - 1];
    }

    void run()
    {
        solve(0);
    }
    
    int min() const
    {
        return minimum;
    }

    void conclude()
    {
        // cout << ++count << ":";
        // for (auto e : solution)
        // {
        //     cout << " " << e;
        // }
        // cout << '\n';
        
        for (int i = 0; i < n; ++i)
        {  
            if (solution[i] != positions[i])
            {
                ++cnt;
            }
        }
        if (cnt < minimum)
            minimum = cnt;
        cnt = 0;
    }
};

int main()
{
    int test = 0;
    vector<int> positions(BOARD_SIZE);
    while (cin >> positions[0])
    {
        for (int i = 1; i < BOARD_SIZE; ++i)
        {
            cin >> positions[i];        // i = column, position[i] = row - 1
        }
        cout << "Case " << ++test << ": ";
        
        Solver solver(positions);
        solver.run();
        
        cout << solver.min() << '\n';

    }

}
