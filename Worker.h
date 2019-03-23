//
// Created by max on 6/23/18.
//

#ifndef PROJEKT_WORKER_H
#define PROJEKT_WORKER_H

#include "Employee.h"
#include "functions.h"

class Worker : public Employee {

public:

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive & ar, const unsigned int file_version) {
        ar & boost::serialization::base_object<Employee>(*this);

    }

    Worker();
    ~Worker();
    Worker(const std::string &, const std::string &);

    explicit Worker(const Employee & person);

};

BOOST_CLASS_EXPORT_KEY(Worker);


#endif //PROJEKT_WORKER_H
