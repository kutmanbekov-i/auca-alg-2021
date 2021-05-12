#include <iostream>
#include <vector>

using namespace std;

class Solver
{
    int n;
    int count;
    vector<bool> mRows;
    vector<bool> mDiag1;
    vector<bool> mDiag2;
    vector<int> solution;
    struct Frame
    {
        int mRow;
        int mCol;

        Frame(int r, int c)
            : mRow(r), mCol(c)
        {
        }
    };

public:
    Solver(int temp_n)
        : n(temp_n), count(0)
    {
        if (n < 1)
        {
            throw runtime_error("INcorrect size of puzzle!");
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
        // solve(0);
        // vector <pair <int, int>> stack;
        vector<Frame> stack;
        stack.emplace_back(0, 0);

        while (!stack.empty())
        {
            if (stack.back().mCol == n)
            {
                print();
                stack.pop_back();
                removeQueen(stack.back().mRow, stack.back().mCol);
                ++stack.back().mRow;
            }
            else if (stack.back().mRow == n)
            {
                stack.pop_back();
                if (!stack.empty())
                {
                    removeQueen(stack.back().mRow, stack.back().mCol);
                    ++stack.back().mRow;
                }
            }
            else if (isFreeSquare(stack.back().mRow, stack.back().mCol))
            {
                putQueen(stack.back().mRow, stack.back().mCol);
                stack.emplace_back(0, stack.back().mCol + 1);
            }
            else
            {
                ++stack.back().mRow;
            }
        }
    }

    void print()
    {
        cout << ++count << ":";
        for (auto e : solution)
        {
            cout << " " << e;
        }
        cout << '\n';
    }
};

int main()
{
    int n;
    cin >> n;

    Solver(n).run();
}