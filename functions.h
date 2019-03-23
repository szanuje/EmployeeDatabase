//
// Created by max on 5/20/18.
//

#ifndef PROJEKT_FUNCTIONS_H
#define PROJEKT_FUNCTIONS_H
#define BOOST_ALL_NO_LIB
#include <vector>
#include <random>
#include <algorithm>
#include <memory>

#include <iostream>
#include "Employee.h"

using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::endl;
using std::shared_ptr;

int getNewID();
void sortEmployeeIDs(vector<shared_ptr<Employee>>&);

void clearInput();

void mainMenu();
void employeeMenu(vector<shared_ptr<Employee>>&);

int askExit();

#endif //PROJEKT_FUNCTIONS_H
