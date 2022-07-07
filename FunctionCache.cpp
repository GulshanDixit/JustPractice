#include <iostream>
#include <map>
#include <memory>
#include <functional>

class FunctionCache
{
    class Parameters
    {
    public:
        Parameters(int first, int second)
        {
            this->first = first;
            this->second = second;
        }

        friend bool operator < (const Parameters lhs, const Parameters rhs)
        {
            return lhs.first < rhs.first ? true : (lhs.second < rhs.second ? true : false);
        }

        int first;
        int second;
    };

public:
    FunctionCache(std::function<int(int, int)> function) : function(function) {}

    int calculate(int first, int second)
    {
        Parameters parameters(first, second);
        auto it = calculations.find(parameters);

        if (it != calculations.end())
            return it->second;

        int calculation = function(first, second);
        calculations[parameters] = calculation;
        return calculation;
    }


private:
    std::map<Parameters, int> calculations;
    std::function<int(int, int)> function;
};

#ifndef RunTests

int modulo(int a, int b)
{
    std::cout << "Function modulo has been called.\n";
    return a % b;
}

int main()
{
    FunctionCache cache(modulo);

    // Function modulo should be called.
    std::cout << cache.calculate(5, 2) << std::endl;

    // Function modulo should be called.
    std::cout << cache.calculate(7, 4) << std::endl;

    // Function modulo shouldn't be called because we have already made a call with arguments (5, 2)!
    std::cout << cache.calculate(5, 2) << std::endl;
}
#endif