//
// Created by max on 6/3/18.
//

#include "functions.h"
#include "manageDatabase.h"

void employeeMenu(vector<shared_ptr<Employee>>& sourceEmployee) {

    while (true) {

        cout << endl;
        cout << " PROMOTE EMPLOYEE (1)\n";
        cout << " DEMOTE EMPLOYEE  (2)\n";
        cout << " CHANGE SALARY    (3)\n";
        cout << " FIRE EMPLOYEE    (4)\n\n";
        cout << " EMPLOYEE SHOWCASE (5)\n";
        cout << " LIST OF HIRED     (6)\n";
        cout << " LIST OF FIRED     (7)\n\n";
        cout << " BACK (8)\n\n";
        cout << " Choose option... " << std::flush;
        int option = -1;
        cin >> option;

        switch (option) {

            case 1:
                Promote(sourceEmployee);
                break;
            case 2:
                Demote(sourceEmployee);
                break;
            case 3:
                changeSalary(sourceEmployee);
                break;
            case 4:
                fireEmployee(sourceEmployee);
                break;
            case 5:
                employeeShowcase(sourceEmployee);
                break;
            case 6:
                showHiredEmployees(sourceEmployee);
                break;
            case 7:
                showFiredEmployees(sourceEmployee);
                break;
            case 8:
                return;
            default:
                cout << " \n---Wrong input!---" << endl;
                clearInput();
                break;
        }
    }
}