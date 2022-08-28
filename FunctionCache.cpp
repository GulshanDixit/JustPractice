#include <iostream>
#include <memory>
#include <functional>
#include <unordered_map>


class Parameters
{
private:
    int first;
    int second;
public:
    Parameters(int first, int second) : first(first), second(second) {}

    friend bool operator < (const Parameters& lhs, const Parameters& rhs)
    {
        return lhs.first < rhs.first || lhs.second < rhs.second;
    }

    friend bool operator ==(const Parameters& lhs, const Parameters& rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    int GetFirst() const
    {
        return first;
    }

    int GetSecond() const
    {
        return second;
    }
};


struct ParametersHasher
{
    std::size_t operator()(const Parameters& p) const
    {
        using std::hash;
        using std::size_t;

        return (hash<int>()(p.GetFirst()) ^ (hash<int>()(p.GetSecond()) << 1));
    }
};


class FunctionCache
{
public:

    FunctionCache(std::function<int(int, int)> function) : function(function) {}

    int operator () (int first, int second)
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
    std::unordered_map<Parameters, int, ParametersHasher> calculations;
    std::function<int(int, int)> function;
};



#ifndef RunTests

int modulo(int a, int b)
{
    std::cout << "Function modulo has been called.\n";
    return a % b;
}

//int main()
//{
//    FunctionCache cache(modulo);
//
//    // Function modulo should be called.
//    std::cout << cache(5, 2) << std::endl;
//
//    // Function modulo should be called.
//    std::cout << cache(7, 4) << std::endl;
//
//    // Function modulo shouldn't be called because we have already made a call with arguments (5, 2)!
//    std::cout << cache(5, 2) << std::endl;
//}
#endif