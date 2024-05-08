#pragma once
#include <iostream>
#include <string>
#include "Database.h"
class Menu
{
public:
    void displayMenu() {
        cout << "-----------------------" << endl;
        cout << "Employee Database" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Find Employee by ID" << endl;
        cout << "3. Edit Employee" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Display All Employees" << endl;
        cout << "6. Exit" << endl;
        cout << "7. Calculate Salary" << endl;
        cout << "8. Display All Employees With High Wage" << endl;
        cout << "9. Save data to file" << endl;
        cout << "10. Load Data from file" << endl;
        cout << "-----------------------" << endl;
    }
    void selectOption() {
        Database db;
        int choice;

        do
        {

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                db.addEmployee();
               break;
            case 2:
                db.findEmployeeById();
                break;
            case 3:
                db.editEmployee();
                break;
            case 4:
                db.deleteEmployee();
                break;
            case 5:
                db.displayAllEmployees();
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                return ;
            case 7:
                db.CalcSalary();
                break;
            case 8:
                db.FindEmployeeByHighwage();
                break;
            case 9:
            {
                string saveFilename;
                cout << "Enter filename to save data: ";
                cin >> saveFilename;
                db.saveDataToFile(saveFilename);
            }
            break;
            case 10:
            {
                string loadFilename;
                cout << "Enter filename to load data: ";
                cin >> loadFilename;
                db.loadDataFromFile(loadFilename);
            }
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }

        } while (choice != 6);
    }

    void executeOption() {
        displayMenu();
        selectOption();
    }


};