#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"

#include "List.hpp"

TEST_CASE("testing the List constructor") {

    List<int> v;

    REQUIRE(v.size() == 0);
}

TEST_CASE("push_back") {

    List<int> v;

    REQUIRE(v.toStr() == "{}");
    REQUIRE(v.toReverseStr() == "{}");

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");
    REQUIRE(v.toReverseStr() == "{3, 2, 1}");
}
TEST_CASE("pop_back") {

    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);
    
    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");
    REQUIRE(v.toReverseStr() == "{3, 2, 1}");

    v.popBack();
    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 2}");
    v.popBack();
    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{1}");
    v.popBack();
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
}

TEST_CASE("push/pop_front")
{
    List<int> v;

    v.pushFront(1);
    v.pushFront(2);
    v.pushFront(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{3, 2, 1}");
    REQUIRE(v.toReverseStr() == "{1, 2, 3}");

    v.popFront();
    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{2, 1}");
    v.popFront();
    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{1}");
    v.popFront();
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
}

TEST_CASE("List<int>::Iter")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();


    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(it == v.end());

    --it;
    REQUIRE(*it == 3);
    --it;
    REQUIRE(*it == 2);
    --it;
    REQUIRE(*it == 1);

    REQUIRE(it == v.begin());

    REQUIRE(v.toStr() == "{1, 2, 3}");

}

TEST_CASE("List<pair<int, int>>::Iter")
{
    List<std::pair<int, int>> v;

    v.pushBack({1, 1});
    v.pushBack({2, 2});
    v.pushBack({3, 3});

    auto it = v.begin();


    REQUIRE((*it).first == 1);
    REQUIRE(it->first == 1);
    ++it;
    REQUIRE((*it).first == 2);
    REQUIRE(it->first == 2);
    ++it;
    REQUIRE((*it).first == 3);
    REQUIRE(it->first == 3);
    ++it;
    REQUIRE(it == v.end());

    --it;
    REQUIRE((*it).second == 3);
    REQUIRE(it->second == 3);
    --it;
    REQUIRE((*it).second == 2);
    REQUIRE(it->second == 2);
    --it;
    REQUIRE((*it).second == 1);
    REQUIRE(it->second == 1);

    REQUIRE(it == v.begin());

}
TEST_CASE("List<pair<int, int>>::RIter")
{
    List<std::pair<int, int>> v;

    v.pushBack({1, 1});
    v.pushBack({2, 2});
    v.pushBack({3, 3});

    auto it = v.rend();

    --it;
    REQUIRE((*it).first == 1);
    REQUIRE(it->first == 1);
    --it;
    REQUIRE((*it).first == 2);
    REQUIRE(it->first == 2);
    --it;
    REQUIRE((*it).first == 3);
    REQUIRE(it->first == 3);

    REQUIRE(it == v.rbegin());

    REQUIRE((*it).second == 3);
    REQUIRE(it->second == 3);
    ++it;
    REQUIRE((*it).second == 2);
    REQUIRE(it->second == 2);
    ++it;
    REQUIRE((*it).second == 1);
    REQUIRE(it->second == 1);
    ++it;

    REQUIRE(it == v.rend());

    // REQUIRE(v.toStr() == "{1, 2, 3}");
    // REQUIRE(v.toReverseStr() == "{3, 2, 1}");

}

TEST_CASE("insert")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();
    ++it;
    it = v.insert(it, 0);

    REQUIRE(v.size() == 4);
    REQUIRE(v.toStr() == "{1, 0, 2, 3}");   
    REQUIRE(*it == 0);

}

TEST_CASE("erase")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();

    ++it;
    it = v.erase(it);

    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 3}");   
    REQUIRE(*it == 3);

    it = v.erase(it);
    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{1}");   
    REQUIRE(it == v.end());

    --it;
    it = v.erase(it);
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");   
    REQUIRE(it == v.end());
}

TEST_CASE("clear")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();
    it = v.erase(it);
    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{2, 3}");
    REQUIRE(*it == 2);

    v.clear();
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
    REQUIRE(v.toReverseStr() == "{}");
}

TEST_CASE("copy constructor")
{
    // List<double> v;

    // REQUIRE(v.begin() == v.end());    <---- SUCCESS

    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    List<int> p = v;

    REQUIRE(p.size() == 3);
    REQUIRE(p.toStr() == v.toStr());
}

TEST_CASE("copy assignment")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    List<int> p;

    p = v;

    REQUIRE(p.size() == 3);
    REQUIRE(p.toStr() == v.toStr());
}