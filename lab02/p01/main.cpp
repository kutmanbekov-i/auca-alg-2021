#include <iostream>
#include <unordered_set>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct WorstHashFunction
{
    std::size_t operator()(const string& s) const
    {
        // return 42;
        size_t r = 0;

        for (char c : s)
        {
            r = r * 31 + c * 97;
        }
        return r;
    }
};

int main()
{
    // WorstHashFunction h;
    // cout << h("Hello\n");
    // cout << h("World\n");
    // cout << h("!!!\n");

    unordered_set<string, WorstHashFunction> set;

    auto hash = set.hash_function();


    for (string line; getline(cin, line); )
    {
        istringstream sinp(line);

        cout << "Bucket count: " << set.bucket_count() << '\n';

        string cmd; sinp >> cmd;

        if (cmd =="+")
        {
            string word; sinp >> word;

            cout << "hash value: " << hash(word) << '\n';
            cout << "bucket's index: " << hash(word) % set.bucket_count() << '\n';
            auto p = set.insert(word);

            cout << (p.second ? "YES" : "NO") << '\n';
        }
        else if (cmd == "?")
        {
            string word; sinp >> word;

            cout << "hash value: " << hash(word) << '\n';
            cout << "bucket's index: " << hash(word) % set.bucket_count() << '\n';
            auto p = set.find(word);

            cout << (p != set.end() ? "YES" : "NO") << '\n';
        }
        else if (cmd == "-")
        {
            string word; sinp >> word;

            cout << "hash value: " << hash(word) << '\n';
            cout << "bucket's index: " << hash(word) % set.bucket_count() << '\n';

            cout << (set.erase(word) ? "YES" : "NO") << '\n';
        }
        else if (cmd == "#")
        {
            for (size_t i = 0; i < set.bucket_count(); ++i)
            {
                cout << setw(4) << i << ":";
                for (auto p = set.begin(i); p != set.end(i); ++p)
                {
                    cout << ' ' << *p;
                }
                cout << '\n';
            }
        }
        
    }
}