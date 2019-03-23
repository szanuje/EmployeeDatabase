//
// Created by max on 5/25/18.
//

#ifndef PROJEKT_MANAGEDATABASE_H
#define PROJEKT_MANAGEDATABASE_H

#include "Employee.h"
#include "Intern.h"
#include "Worker.h"
#include "Manager.h"

void hireEmployee(vector<shared_ptr<Employee>>&);

void employeeShowcase(const vector<shared_ptr<Employee>>&);

void showHiredEmployees(const vector<shared_ptr<Employee>>&);
void showFiredEmployees(const vector<shared_ptr<Employee>>&);

void Promote(vector<shared_ptr<Employee>>&);
void Demote(vector<shared_ptr<Employee>>&);

void changeSalary(vector<shared_ptr<Employee>>&);

void fireEmployee(vector<shared_ptr<Employee>>&);


#endif //PROJEKT_MANAGEDATABASE_H
