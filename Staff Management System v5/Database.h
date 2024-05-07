#pragma once
#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Database
{
private:
    vector<Employee> employees;

public:
    void addEmployee()
    {
        int id;
        string name;
        int age;
        string address;
        string role;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Employee Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Employee Address: ";

        getline(cin, address);

        cout << "Enter Employee Role: ";
        getline(cin, role);

        cout << "Enter Employee Salary: ";
        cin >> salary;

        Employee employee(id, name, age, address, role, salary);
        employees.push_back(employee);

        cout << "Employee inserted successfully." << endl;
    }

    void findEmployeeById()
    {
        int id;
        cout << "Enter Employee ID to search for: ";
        cin >> id;

        bool found = false;

        for (const Employee& employee : employees)
        {
            if (employee.getId() == id)
            {
                cout << "Employee Details:" << endl;
                cout << "ID: " << employee.getId() << endl;
                cout << "Name: " << employee.getName() << endl;
                cout << "Age: " << employee.getAge() << endl;
                cout << "Address: " << employee.getAddress() << endl;
                cout << "Role: " << employee.getRole() << endl;
                cout << "Salary: " << employee.getSalary() << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void editEmployee()
    {
        int id;
        cout << "Enter Employee ID to edit: ";
        cin >> id;

        bool found = false;

        for (Employee& employee : employees)
        {
            if (employee.getId() == id)
            {
                string name;
                int age;
                string address;
                string role;
                double salary;


                cin.ignore();
                cout << "Enter Employee New Name: ";
                getline(cin, name);
                employee.setName(name);

                cout << "Enter Employee New Age: ";
                cin >> age;
                employee.setAge(age);
                cin.ignore();

                cout << "Enter Employee New Address: ";
                getline(cin, address);
                employee.setAddress(address);

                cout << "Enter Employee New Role: ";
                getline(cin, role);
                employee.setRole(role);

                cout << "Enter Employee New Salary: ";
                cin >> salary;
                employee.setSalary(salary);

                cout << "Employee with ID " << id << " successfully updated." << endl;

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void deleteEmployee()
    {
        int id;
        cout << "Enter Employee ID to delete: ";
        cin >> id;

        auto it = find_if(employees.begin(), employees.end(), [id](const Employee& employee) {
            return employee.getId() == id;
            });

        if (it != employees.end())
        {
            employees.erase(it);
            cout << "Employee with ID " << id << " successfully deleted." << endl;
        }
        else
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void displayAllEmployees()
    {
        if (employees.empty())
        {
            cout << "No employees found inthe database." << endl;
        }
        else
        {
            cout << "Employee Details:" << endl;
            for (const Employee& employee : employees)
            {
                cout << "ID: " << employee.getId() << endl;
                cout << "Name: " << employee.getName() << endl;
                cout << "Age: " << employee.getAge() << endl;
                cout << "Role: " << employee.getRole() << endl;
                cout << "Salary: " << employee.getSalary() << endl;
                cout << "-----------------------" << endl;
            }
        }
    }
};