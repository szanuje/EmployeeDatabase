//
// Created by max on 6/23/18.
//

#ifndef PROJEKT_MANAGER_H
#define PROJEKT_MANAGER_H


#include "Employee.h"
#include "functions.h"

class Manager : public Employee {

public:

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive & ar, const unsigned int file_version) {
        ar & boost::serialization::base_object<Employee>(*this);

    }

    Manager();
    ~Manager();
    Manager(const std::string &, const std::string &);

    explicit Manager(const Employee & person);

};

BOOST_CLASS_EXPORT_KEY(Manager);


#endif //PROJEKT_MANAGER_H
