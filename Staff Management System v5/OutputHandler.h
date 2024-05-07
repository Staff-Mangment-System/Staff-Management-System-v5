#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
class OutputHandler
{
public:
    static void displayMessage(const string& message)
    {
        cout << message << endl;
    }

    static void displayEmployeeDetails(const Employee& employee)
    {
        cout << "Employee Details:" << endl;
        cout << "ID: " << employee.getId() << endl;
        cout << "Name: " << employee.getName() << endl;
        cout << "Age: " << employee.getAge() << endl;
        cout << "Address: " << employee.getAddress() << endl;
        cout << "Role: " << employee.getRole() << endl;
        cout << "Salary: " << employee.getSalary() << endl;
        cout << endl;
    }
};
