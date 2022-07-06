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

        int first;
        int second;
    };

public:
    FunctionCache(std::function<int(int, int)> function) : function(function) {}

    int calculate(int first, int second)
    {
        Parameters parameters(first, second);
        auto it = findAndCompareElementsInCalculations(parameters);//calculations.find(args);

        if (it != calculations.end())
            return it->second;

        // create the shared pointer only when needed
        auto args = std::make_shared<Parameters>(parameters);
        int calculation = function(first, second);
        calculations[args] = calculation;
        return calculation;
    }


private:
    std::map<std::shared_ptr<Parameters>, int> calculations;
    std::function<int(int, int)> function;

    std::map<std::shared_ptr<Parameters>, int>::iterator findAndCompareElementsInCalculations(const Parameters& parameters)
    {
        for (std::map<std::shared_ptr<Parameters>, int>::iterator itr = calculations.begin(); itr != calculations.end(); ++itr)
        {
            if ((*itr).first->first == parameters.first && (*itr).first->second == parameters.second)
            {
                return itr;
            }
        }

        return calculations.end();
    }
};

#ifndef RunTests

int modulo(int a, int b)
{
    std::cout << "Function modulo has been called.\n";
    return a % b;
}

// one way to improve performance can be using the modulo as the key and share_ptr as the value
// but that would rule out parameters with same modulo value in case we're intereseted in all unique pairs
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