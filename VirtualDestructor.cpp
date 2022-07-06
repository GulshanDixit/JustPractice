#include <iostream>

using namespace std;

class base
{
public:

    base()
    {
        cout << "Base Constructor \n";
    }

    virtual ~base()
    {
        cout << "Base Destructor \n";
    }
};

class derived : public base
{

public:

    derived() : base()
    {
        cout << "Derived Constructor\n";
    }

    ~derived()
    {
        cout << "Derived Destructor\n";
    }
};


