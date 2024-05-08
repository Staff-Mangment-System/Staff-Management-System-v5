#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Employee.h"

using namespace std;

class InputHandler {
public:
    static vector<Employee> readDataFromFile() {
        vector<Employee> employees;
        ifstream inFile("employee_data.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string token;
                int id, age;
                string name, address, role;
                double salary;

                getline(ss, token, ',');
                id = stoi(token);
                getline(ss, name, ',');
                getline(ss, token, ',');
                age = stoi(token);
                getline(ss, address, ',');
                getline(ss, role, ',');
                getline(ss, token, ',');
                salary = stod(token);

                Employee employee(id, name, age, address, role, salary);
                employees.push_back(employee);
            }
            inFile.close();
            cout << "Data read from file successfully." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
        return employees;
    }
};
