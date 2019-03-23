//
// Created by max on 5/25/18.
//

#include "manageDatabase.h"
#include "functions.h"

void hireEmployee(vector<shared_ptr<Employee>>& sourceEmployee) {

    std::string fillName;
    std::string fillSurname;
    cout << endl;
    cout << "Enter Employee Name: ";
    cin.ignore();
    std::getline(std::cin, fillName);
    cout << "Enter Employee Surname: ";
    std::getline(std::cin, fillSurname);

    int buf = 1;
    while (buf == 1) {
        buf = 0;

        cout << endl << "Set status:\n";
        cout << "Intern  (1)\n";
        cout << "Worker  (2)\n";
        cout << "Manager (3)\n\n";
        cout << "Choice... ";

        int choice = -1;
        cin >> choice;
        switch (choice) {
            case 1:
                sourceEmployee.emplace_back(new Intern(fillName, fillSurname));
                break;
            case 2:
                sourceEmployee.emplace_back(new Worker(fillName, fillSurname));
                break;
            case 3:
                sourceEmployee.emplace_back(new Manager(fillName, fillSurname));
                break;
            default:
                cout << "\n---Wrong input!---" << endl;
                buf = 1;
                clearInput(); // functions.h
                break;
        }
    }
    sourceEmployee.back()->setID();
    sourceEmployee.back()->setHire(true);

    int buf2 = 1;
    while (buf2 == 1) {
        cout << endl << "Set salary: ";
        unsigned int Salary;
        cin >> Salary;
        if(!cin) {
            cout << "\nWrong input" << endl;
            clearInput();
        } else {
            sourceEmployee.back()->setSalary(Salary);
            buf2 = 0;
        }
    }
    while (true) {

        auto it = std::find_if(sourceEmployee.begin(), sourceEmployee.end() - 1,
                               [&sourceEmployee](const auto &obj) {
                                   return obj->getID() == sourceEmployee.back()->getID();
                               });

        if (it != sourceEmployee.end() - 1) {
            sourceEmployee.back()->setID();
        } else {
            break;
        }
    }
    cout << endl <<sourceEmployee.back()->getName() << " " << sourceEmployee.back()->getSurname() << " ("
         << sourceEmployee.back()->getID()
         << ") has been hired\n";

    sortEmployeeIDs(sourceEmployee);
}

void employeeShowcase(const vector<shared_ptr<Employee>>& sourceEmployee) {

    while (true) {

        cout << "Enter ID to showcase an employee: ";
        int id;
        cin >> id;

        if (!cin) {
            clearInput();
            cout << "ID number needed!" << endl;
        } else {
            auto it = std::find_if(sourceEmployee.begin(), sourceEmployee.end(),
                                   [&sourceEmployee, id](const auto &obj) { return obj->getID() == id; });

            if (it != sourceEmployee.end()) {
                auto index = std::distance(sourceEmployee.begin(), it);
                cout << "_____________________";
                cout << "\n\nID: " << sourceEmployee[index]->getID();
                cout << "\nName: " << sourceEmployee[index]->getName() << " " << sourceEmployee[index]->getSurname();

                cout << "\nStatus: ";
                if (auto x = dynamic_cast<Intern *>(it->get())) {
                    cout << "Intern";

                } else if (auto y = dynamic_cast<Worker *>(it->get())) {
                    cout << "Worker";

                } else if (auto z = dynamic_cast<Manager *>(it->get())) {
                    cout << "Manager";
                } else {
                    cout << "Error while printing status";
                }

                cout << "\nSalary: " << sourceEmployee[index]->getSalary() << "$";

                cout << "\nHired: ";
                if (sourceEmployee[index]->hiredStatus()) {
                    cout << "Yes";
                } else {
                    cout << "No";
                }

                cout << "\n_____________________" << endl;
                return;
            } else {

                cout << "No employee with ID:" << id << endl;
                clearInput();
                if (askExit()) { // functions.h
                    return;
                }
            }
        }
    }
}

void showHiredEmployees(const vector<shared_ptr<Employee>>& sourceEmployee) {

    int buf = 0;
    cout << endl << "List of hired employees:\n";
    for (const auto &i : sourceEmployee) {
        if (i->hiredStatus()) {
            cout << "ID: " << i->getID() << endl;
            buf = 1;
        }
    }
    if (buf == 0) {
        cout << "---------empty--------\n";
    }
    cout << "_____________________\n";
}

void showFiredEmployees(const vector<shared_ptr<Employee>>& sourceEmployee) {

    int buf = 0;
    cout << endl << "List of fired employees:\n";
    for (const auto &i : sourceEmployee) {
        if (!i->hiredStatus()) {
            cout << "ID: " << i->getID() << endl;
            buf = 1;
        }
    }
    if (buf == 0) {
        cout << "---------empty--------\n";
    }
    cout << "_____________________\n";
}

void Promote(vector<shared_ptr<Employee>>& sourceEmployee) {

    while (true) {

        cout << "Enter ID to promote an employee: ";
        int id;
        cin >> id;

        if (!cin) {
            clearInput();
            cout << "ID number is needed!" << endl;
        } else {

            auto it = std::find_if(sourceEmployee.begin(), sourceEmployee.end(),
                                   [&sourceEmployee, id](const auto &obj) { return obj->getID() == id; });

            if (it != sourceEmployee.end()) {

                auto index = std::distance(sourceEmployee.begin(), it);

                if (sourceEmployee[index]->hiredStatus()) {

                    if (auto w = dynamic_cast<Intern *>(it->get())) {

                        auto tmp0 = std::move(*it);
                        *it = std::make_shared<Worker>(*tmp0);
                        cout << "Employee " << id << " has been promoted\n";

                    } else if (auto w = dynamic_cast<Worker *>(it->get())) {

                        auto tmp0 = std::move(*it);
                        *it = std::make_shared<Manager>(*tmp0);
                        cout << "Employee " << id << " has been promoted\n";

                    } else if (auto w = dynamic_cast<Manager *>((*it).get())) {

                        cout << "Can't promote (already manager)\n";

                    } else {

                        cout << "Error while promoting an Employee\n";
                    }

                    return;

                } else {
                    cout << "You can't promote fired employee!\n";
                }


            } else {

                cout << "No employee with ID: " << id << endl;
                clearInput();
                if (askExit()) {
                    return;
                }
            }
        }
    }
}

void Demote(vector<shared_ptr<Employee>>& sourceEmployee) {

    while (true) {

        cout << "Enter ID to demote an employee: ";
        int id;
        cin >> id;

        if (!cin) {
            clearInput();
            cout << "ID number needed!" << endl;
        } else {

            auto it = std::find_if(sourceEmployee.begin(), sourceEmployee.end(),
                                   [&sourceEmployee, id](const auto &obj) { return obj->getID() == id; });

            if (it != sourceEmployee.end()) {

                auto index = std::distance(sourceEmployee.begin(), it);

                if (sourceEmployee[index]->hiredStatus()) {

                    if (auto x = dynamic_cast<Intern *>(it->get())) {

                        cout << "Can't demote (already intern)\n";

                    } else if (auto y = dynamic_cast<Worker *>(it->get())) {

                        auto tmp0 = std::move(*it);
                        *it = std::make_shared<Intern>(*tmp0);
                        cout << "Employee " << id << " has been demoted\n";

                    } else if (auto z = dynamic_cast<Manager *>((*it).get())) {

                        auto tmp0 = std::move(*it);
                        *it = std::make_shared<Worker>(*tmp0);
                        cout << "Employee " << id << " has been demoted\n";

                    } else {

                        cout << "Error while promoting an Employee\n";
                    }

                    return;

                } else {
                    cout << "You can't demote fired employee!\n";
                    if (askExit()) {
                        return;
                    }
                }

            } else {
                cout << "No employee with ID: " << id << endl;
                clearInput();
                if (askExit()) {
                    return;
                }
            }
        }
    }
}

void changeSalary(vector<shared_ptr<Employee>>& sourceEmployee) {

    while (true) {

        cout << "Enter ID to change salary of employee: ";
        int id;
        cin >> id;

        if (!cin) {
            clearInput();
            cout << "ID number is needed!" << endl;
        } else {

            auto it = std::find_if(sourceEmployee.begin(), sourceEmployee.end(),
                                   [&sourceEmployee, id](const auto &obj) { return obj->getID() == id; });
            if (it != sourceEmployee.end()) {
                auto index = std::distance(sourceEmployee.begin(), it);


                int buf = 1;
                while (buf == 1) {
                    cout << endl << "Set salary: ";
                    unsigned int Salary;
                    cin >> Salary;
                    if (!cin) {
                        cout << "\nWrong input" << endl;
                        clearInput();
                    } else {
                        sourceEmployee[index]->setSalary(Salary);
                        buf = 0;
                    }
                }

                cout << "Employee " << id << " salary has been changed" << endl;
                return;
            } else {

                cout << "No employee with ID: " << id << endl;
                clearInput();
                if (askExit()) {
                    return;
                }
            }
        }
    }
}

void fireEmployee(vector<shared_ptr<Employee>>& sourceEmployee) {

    while (true) {

        cout << "Enter ID to fire an employee: ";
        int id;
        cin >> id;

        if (!cin) {
            clearInput();
            cout << "ID number needed!" << endl;
        } else {
            auto it = std::find_if(sourceEmployee.begin(), sourceEmployee.end(),
                              [&sourceEmployee, id](const auto &obj) { return obj->getID() == id; });

            if (it != sourceEmployee.end()) {
                auto index = std::distance(sourceEmployee.begin(), it);
                sourceEmployee[index]->setHire(false);
                sourceEmployee[index]->setSalary(0);
                cout << sourceEmployee[index]->getName() << " " << sourceEmployee[index]->getSurname() << " ("
                     << sourceEmployee[index]->getID() << ") has been fired" << endl;
                return;
            } else {
                cout << "No employee with ID: " << id << endl;
                clearInput();
                if (askExit()) {
                    return;
                }
            }
        }
    }
}