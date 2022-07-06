// Just Practise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "VirtualDestructor.cpp"

struct Adam
{
    int age;
    float weight;
};


#pragma region same function with const type

class Mega
{
public:
    int mind() { return 0; }
    int mind() const { return 1; }
};

#pragma endregion

/*
int main()
{
    float f = 1;

    Adam a{};

    // checking default values of variables within structure
    //std::cout << f << " oo " << a.weight;


#pragma region Bit Shifting Operations 
    int mask = 0;

    // 1 0 0 0
    mask = mask ^ (1 << 4);
    // 1 0 0 0 => ~ () => 0 1 1 1 => (1 0 0 0) & (0 1 1 1)
    mask = mask & ~(1 << 4);

    std::cout << mask << endl;
#pragma endregion

    

#pragma region same function with const type : test

    Mega* mega = new Mega();

    cout << mega->mind() << endl;

#pragma endregion


#pragma region strlen vs sizeof

    const char* str{ "hello" };

    cout << strlen(str);
    cout << sizeof(str);

#pragma endregion

}
*/
