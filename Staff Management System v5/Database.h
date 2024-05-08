#pragma once
#include "Employee.h"
#include "SalaryCalc.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "InputHandler.h"
#include "OutputHandler.h"
#include "EmployeeValidator.h"

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

        if (!EmployeeValidator::validateId(id)) { // Validate ID
            cout << "Invalid ID. Please enter a positive integer." << endl;
            return;
        }

        cout << "Enter Employee Name: ";
        getline(cin, name);

        if (!EmployeeValidator::validateName(name)) { // Validate Name
            cout << "Invalid name. Please enter a non-empty name." << endl;
            return;
        }

        cout << "Enter Employee Age: ";
        cin >> age;
        cin.ignore();

        if (!EmployeeValidator::validateAge(age)) { // Validate Age
            cout << "Invalid age. Please enter an age between 1 and 150." << endl;
            return;
        }

        cout << "Enter Employee Address: ";
        getline(cin, address);

        if (!EmployeeValidator::validateAddress(address)) { // Validate Address
            cout << "Invalid address. Please enter a non-empty address." << endl;
            return;
        }

        cout << "Enter Employee Role: ";
        getline(cin, role);

        if (!EmployeeValidator::validateRole(role)) { // Validate Role
            cout << "Invalid role. Please enter a non-empty role." << endl;
            return;
        }

        cout << "Enter Employee Salary: ";
        cin >> salary;

        if (!EmployeeValidator::validateSalary(salary)) { // Validate Salary
            cout << "Invalid salary. Please enter a non-negative salary." << endl;
            return;
        }

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
    void CalcSalary() {
        int h;
        int pph;
        SalaryCalc x;
        cout << "Enter Employee hours" << endl;
        cin >> h;
        cout << "Enter Employee Pay Per Hour" << endl;
        cin >> pph;
        x.setHour(h);
        x.setpayPerHour(pph);
        cout << "Employee hours = " << x.getHour() << " hours" << endl;
        cout << "Employee pay rate = " << x.getpayPerHour() << " hours" << endl;
        cout << "Employee Salary = " << x.getCalcSal() << " $" << endl;
    }


    void FindEmployeeByHighwage()
    {
        bool found = false;
        cout << "Employees with salary equal to or greater than 25000:" << endl;
        for (const Employee& employee : employees)
        {
            if (employee.getSalary() >= 25000)
            {
                cout << "ID: " << employee.getId() << endl;
                cout << "Name: " << employee.getName() << endl;
                cout << "Age: " << employee.getAge() << endl;
                cout << "Role: " << employee.getRole() << endl;
                cout << "Salary: " << employee.getSalary() << endl;
                cout << "-----------------------" << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No employees found with salary equal to or greater than 25000." << endl;
        }
    }


    void readDataFromFile() {
        InputHandler inputHandler;
        employees = inputHandler.readDataFromFile();
    }

    void writeDataToFile() {
        OutputHandler outputHandler;
        outputHandler.writeDataToFile(employees);
    }
};