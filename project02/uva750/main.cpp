#include <iostream>
#include <vector>

using namespace std;

class Solver
{
    const int n = 8;
    int count;
    vector<bool> mRows;
    vector<bool> mDiag1;
    vector<bool> mDiag2;
    vector<int> solution;
    
    int queen_row;
    int queen_col;

public:
    Solver(int temp_r, int temp_c)
        : queen_row(temp_r), queen_col(temp_c), count(0)
    {
        if (n < 1)
        {
            throw runtime_error("Incorrect size of puzzle!");
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
            print();
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

    void print()
    {
        if (solution[queen_col] == queen_row)
        {
            // cout << " " << ++count << "      ";
            printf("%2d      ", ++count);
            for (size_t i = 0; i < solution.size(); ++i)
            {
                if (i) cout << " ";
                cout << solution[i] + 1;
            }
            cout << '\n';
        }
    }
};

int main()
{
    int n;  cin >> n;

    while (n--)
    {
        int row, col; cin >> row >> col;

        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
        
        Solver solver(row - 1, col - 1);
        solver.run();
        
        if (n)
        cout << '\n';
    }

}