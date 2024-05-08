#pragma once
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <vector>

class OutputHandler {
public:
    static void writeDataToFile(const std::vector<Employee>& employees) {
        std::ofstream outFile("employee_data.txt");
        if (outFile.is_open()) {
            for (const auto& employee : employees) {
                outFile << employee.getId() << ","
                    << employee.getName() << ","
                    << employee.getAge() << ","
                    << employee.getAddress() << ","
                    << employee.getRole() << ","
                    << employee.getSalary() << "\n";
            }
            outFile.close();
            std::cout << "Data written to file successfully." << std::endl;
        }
        else {
            std::cout << "Unable to open file." << std::endl;
        }
    }
};
