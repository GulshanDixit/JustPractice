#include <iostream>
#include <string>
#include <vector>
#include <memory>

class WindowManager
{
private:
    std::unique_ptr<std::vector<std::string>> windows;

    std::vector<std::string>::iterator findWindowByName(const std::string windowName)
    {
        auto itr = windows.get()->begin();
        while (itr != windows.get()->end())
        {
            if ((*itr).compare(windowName) == 0)
            {
                return itr;
            }
            itr++;
        }
        return windows.get()->end();
    }

public:

    WindowManager() : windows(std::make_unique<std::vector<std::string>>()) {}
    
    void open(const std::string windowName)
    {
        auto itr = findWindowByName(windowName);
        if (itr != windows.get()->end())
        {
            // if the window is already open no need to add new window
            // assuming each window has a uinque name
            return;
        }
        windows.get()->emplace_back(windowName);
    }

    void close(const std::string windowName)
    {
        auto itr = findWindowByName(windowName);
        if (itr != windows.get()->end())
        {
            windows.get()->erase(itr);
        }
    }

    std::string getTopWindow()
    {
        if (windows.get()->size() > 0)
        {
            return windows.get()->back();
        }
        else 
        {
            return NULL;
        }
    }
};

#ifndef RunTests
//int main()
//{
//    WindowManager wm;
//    wm.open("Calculator");
//    wm.open("Browser");
//    wm.open("Player");
//    wm.close("Browser");
//    std::cout << wm.getTopWindow();
//}
#endif