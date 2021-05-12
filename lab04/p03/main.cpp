#include <iostream>
#include <chrono>

int gcd(int64_t a, int64_t b)
{

    if (a == 0 && b == 0)
        throw std::invalid_argument("DIVISION by ZERO");

    // a = abs(a); b = abs(b);
    // everything divides 0
    if (a == 0 || b == 0)
    {
        return a + b;
    }

    return gcd(b, a % b);
}

// gcd(70, 55) = gcd(55, 70 % 55) = gcd(55, 15) = gcd(15, 10) = gcd(10, 5) = gcd(5, 0) = 5

int main()
{
    for (int64_t a, b; std::cin >> a >> b;)
    {
        auto start = std::chrono::high_resolution_clock::now();
        try
        {
            std::cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << '\n';
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
        }
        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  
        // To get the value of duration use the count()
        // member function on the duration object
        std::cout << duration.count() << '\n';
    }
}