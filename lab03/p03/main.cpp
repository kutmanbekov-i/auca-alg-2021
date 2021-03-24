#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
    Point(int aX, int aY)
        : x(aX), y(aY)
    {
    }
};

struct CmpPoints
{
    bool operator()(const Point &p1, const Point &p2) const
    {
        if (p1.x != p2.x)
        {
            return p1.x < p2.x;
        }
        return p1.y < p2.y;
    }
};

using MapOfCaches = map<Point, vector<string>, CmpPoints>;

void insert_cache(MapOfCaches &caches, istringstream &sinp)
{
    int x;
    sinp >> x;

    int y;
    sinp >> y;

    for (string item; sinp >> item;)
    {
        caches[{x, y}].push_back(item);
    }
}

void check_cache(const MapOfCaches &caches, istringstream &sinp)
{
    int x;
    sinp >> x;

    int y;
    sinp >> y;

    auto it = caches.find({x, y});
    if (it != caches.end())
    {
        for (const auto &e : it->second)
        {
            cout << " " << e;
        }
        cout << "\n";
    }
    else
    {
        cout << "Cache does not exist\n";
    }
}

void erase_cache(MapOfCaches &caches, istringstream &sinp)
{
    int x;
    sinp >> x;

    int y;
    sinp >> y;

    cout << (caches.erase({x, y}) ? "OK" : "Cache does not exist") << endl;
}

void print_caches(const MapOfCaches &caches)
{
    for (const auto &p : caches)
    {
        cout << "{" << p.first.x << ", " << p.first.y << "}:";
        for (const auto &item : p.second)
        {
            cout << " " << item;
        }
        cout << "\n";
    }
}

int main()
{
    MapOfCaches caches;

    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        string cmd;
        sinp >> cmd;

        if (cmd == "insert")
        {
            insert_cache(caches, sinp);
        }
        else if (cmd == "check")
        {
            check_cache(caches, sinp);
        }
        else if (cmd == "erase")
        {
            erase_cache(caches, sinp);
        }
        else if (cmd == "print")
        {
            print_caches(caches);
        }
        else
        {
            cout << "Unknown command" << endl;
        }
    }
}