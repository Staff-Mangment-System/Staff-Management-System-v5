#pragma once
#include<string>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    int age;
    string address;
    string role;
    double salary;

public:
    Employee(int id = 0, const string& name = "", int age = 0, const string& address = "", const string& role = "", double salary = 0.0)
        : id(id), name(name), age(age), address(address), role(role), salary(salary)
    {
    }

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getAddress() const { return address; }
    string getRole() const { return role; }
    double getSalary() const { return salary; }

    void setId(int id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setAddress(const string& address) { this->address = address; }
    void setRole(const string& role) { this->role = role; }
    void setSalary(double salary) { this->salary = salary; }
};