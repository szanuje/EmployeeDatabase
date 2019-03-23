//
// Created by max on 5/30/18.
//

#include "manageDatabase.h"

#define FILENAME "database.txt"

void mainMenu() {

    vector<shared_ptr<Employee>> Firm;

    try {
        std::ifstream ifs(FILENAME);
        ifs.exceptions(std::ifstream::failbit);

        boost::archive::text_iarchive ia(ifs);
        ia >> boost::serialization::make_nvp("root", Firm);  // odczyt z pliku

    } catch (std::ios_base::failure& fail) {
        cout << "Boost failed to read file (may not exist).";
    }

    for (;;) {

        cout << endl << endl;
        cout << "================ EMPLOYEE DATABASE ================\n\n";
        cout << " HIRE NEW EMPLOYEE (1)\n";
        cout << " MANAGE EMPLOYEES  (2)\n";
        cout << " EXIT              (3)\n";
        cout << " Choose option... " << std::flush;
        int option = -1;
        cin >> option;

        switch (option) {
            case 1:
                hireEmployee(Firm);
                break;
            case 2:
                employeeMenu(Firm);
                break;
            case 3:
            {
                std::ofstream ofs(FILENAME);
                boost::archive::text_oarchive oa(ofs);
                oa << boost::serialization::make_nvp("root", Firm); // zapis do pliku
                return;
            }
            default:
                cout << "\n---Wrong input!---" << endl;
                clearInput();
                break;
        }
    }
}
