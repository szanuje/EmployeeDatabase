//
// Created by max on 5/20/18.
//

#include "Employee.h"
#include "functions.h"

Employee::~Employee() = default;

Employee::Employee() = default;

Employee::Employee(const std::string &newName, const std::string &newSurname) : Name(newName), Surname(newSurname) {}

Employee::Employee(const Employee &person) {
    Name = person.Name;
    Surname = person.Surname;
    employeeID = person.employeeID;
    Salary = person.Salary;
    Hired = person.Hired;
}

std::string Employee::getName() const {

    return Name;
}

std::string Employee::getSurname() const {

    return Surname;
}

void Employee::setID() {

    employeeID = getNewID();
}

int Employee::getID() const {

    return employeeID;
}

void Employee::setSalary(int amount) {

    Salary = amount;
}

int Employee::getSalary() const {

    return Salary;
}

void Employee::setHire(bool x) {

    Hired = x;
}

bool Employee::hiredStatus() const {

    return Hired;
}