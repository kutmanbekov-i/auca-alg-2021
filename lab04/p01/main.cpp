#include <iostream>

using namespace std;

void read_and_print()
{
    int x;
    if (cin >> x)
    {
        read_and_print();

        cout << " " << x;
    }
}

int main()
{
    read_and_print();
    cout << endl;
}