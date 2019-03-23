//
// Created by max on 5/20/18.
//

#include "functions.h"

int getNewID() {

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<int> dis(10000, 99999);
        return dis(gen);
}

void sortEmployeeIDs(vector<shared_ptr<Employee>>& sourceEmployee) {
        sort(sourceEmployee.begin(), sourceEmployee.end(), [&sourceEmployee](const shared_ptr<Employee> &left, const shared_ptr<Employee> &right) {
                return left->getID() < right->getID();
        });
}

void clearInput() {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int askExit() {
    int x = 0;
    cout << "Do you want to exit? [Y/n]  ";
    char close;
    cin >> close;
    if (close == 'Y' || close == 'y') {
        x = 1;
    } else {
        clearInput();
    }
    return x;
}