#pragma once
#include "Employee.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class InputHandler {
public:
    static vector<Employee> readDataFromFile(const string& filename) {
        vector<Employee> employees;
        ifstream inFile(filename);
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

class OutputHandler {
public:
    static void writeDataToFile(const vector<Employee>& employees, const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& employee : employees) {
                outFile << employee.getId() << "," << employee.getName() << "," << employee.getAge() << ","
                    << employee.getAddress() << "," << employee.getRole() << "," << employee.getSalary() << endl;
            }
            outFile.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
};
