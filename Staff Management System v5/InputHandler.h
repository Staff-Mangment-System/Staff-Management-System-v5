#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "Employee.h"
#include <fstream>
using namespace std;

class InputHandler {
public:
    void saveDataToFile(const vector<Employee>& employees) {
        ofstream outFile("employee_data.txt");
        if (outFile.is_open()) {
            for (const auto& employee : employees) {
                outFile << employee.getId() << "," << employee.getName() << "," << employee.getAge() << "," << employee.getAddress() << "," << employee.getRole() << "," << employee.getSalary() << endl;
            }
            outFile.close();
            cout << "Data saved to file successfully." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
};
