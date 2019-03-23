//
// Created by max on 6/4/18.
//

#ifndef PROJEKT_SPECIFIEDEMPLOYEE_H
#define PROJEKT_SPECIFIEDEMPLOYEE_H

#include "Employee.h"
#include "functions.h"

class Intern : public Employee {

public:

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive & ar, const unsigned int file_version) {
        ar & boost::serialization::base_object<Employee>(*this);

    }

    Intern();
    ~Intern();
    Intern(const std::string &, const std::string &);

    explicit Intern(const Employee & person);

};

BOOST_CLASS_EXPORT_KEY(Intern);

#endif //PROJEKT_SPECIFIEDEMPLOYEE_H
