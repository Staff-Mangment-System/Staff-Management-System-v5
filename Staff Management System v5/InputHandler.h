#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
class InputHandler
{
public:
    static int getIntInput()
    {
        int input;
        cin >> input;
        return input;
    }

    static double getDoubleInput()
    {
        double input;
        cin >> input;
        return input;
    }

    static string getStringInput()
    {
        string input;
        cin.ignore();
        getline(cin, input);
        return input;
    }
};

