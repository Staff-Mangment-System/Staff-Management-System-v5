#pragma once
#include <string>
#include "Employee.h"
using namespace std;
class EmployeeValidator
{
public:
    static bool validateId(int id)
    {
        return id > 0;
    }

    static bool validateName(const string& name)
    {
        return !name.empty();
    }

    static bool validateAge(int age)
    {
        return age > 0 && age <= 150;
    }

    static bool validateAddress(const string& address)
    {
        return !address.empty();
    }

    static bool validateRole(const string& role)
    {
        return !role.empty();
    }

    static bool validateSalary(double salary)
    {
        return salary >= 0;
    }
};
