#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include "HashSetStr.hpp"

TEST_CASE("constructor")
{
    HashSetStr s;

    REQUIRE(s.size() == 0);
}

// crashing the VSCode, I fixed

TEST_CASE("insert")
{
    HashSetStr s;

    REQUIRE(s.insert("C++"));
    REQUIRE(s.size() == 1);
    REQUIRE_FALSE(s.insert("C++"));

    // s.debug_print();

    REQUIRE(s.insert("C"));
    REQUIRE(s.size() == 2);

    // s.debug_print();

    REQUIRE(s.insert("Java"));
    REQUIRE(s.size() == 3);

    // s.debug_print();

    REQUIRE(s.insert("Python"));
    REQUIRE(s.size() == 4);

    // s.debug_print();

    REQUIRE(s.insert("C#"));
    REQUIRE(s.size() == 5);

    // s.debug_print();

    REQUIRE(s.insert("JavaScript"));
    REQUIRE(s.size() == 6);

    // s.debug_print();
}

TEST_CASE("find")
{
    HashSetStr s;

    s.insert("C++");
    s.insert("C");
    s.insert("Java");
    s.insert("Python3");
    s.insert("Go");
    s.insert("JavaScript");
    s.insert("C#");
    s.insert("Rust");

    REQUIRE(s.find("C++"));
    REQUIRE(s.find("C"));
    REQUIRE(s.find("Java"));
    REQUIRE(s.find("Python3"));
    REQUIRE(s.find("Go"));
    REQUIRE(s.find("JavaScript"));
    REQUIRE(s.find("C#"));
    REQUIRE(s.find("Rust"));

    REQUIRE_FALSE(s.find("Hello"));
    REQUIRE_FALSE(s.find("World"));
}

TEST_CASE("erase")
{
    HashSetStr s;

    s.insert("C++");
    s.insert("C");
    s.insert("Java");
    s.insert("Python3");
    s.insert("Go");
    s.insert("JavaScript");
    s.insert("C#");
    s.insert("Rust");


    REQUIRE(s.erase("C++"));
    REQUIRE(s.erase("C"));
    REQUIRE(s.erase("C#"));

    REQUIRE_FALSE(s.find("C++"));
    REQUIRE_FALSE(s.find("C#"));

    REQUIRE(s.insert("C++"));

    REQUIRE_FALSE(s.erase("Hello"));
    REQUIRE_FALSE(s.erase("World"));

    // s.debug_print();
}

TEST_CASE("erase")
{
    HashSetStr s;

    s.insert("C++");
    s.insert("C");
    s.insert("Java");
    s.insert("Python3");
    s.insert("Go");
    
    REQUIRE(s.size() == 5);
    s.clear();

    REQUIRE(s.size() == 0);
    s.debug_print();
}