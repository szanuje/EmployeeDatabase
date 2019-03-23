//
// Created by max on 5/20/18.
//

#ifndef PROJEKT_EMPLOYEE_H
#define PROJEKT_EMPLOYEE_H

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>

class Employee {

public:

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive & ar, const unsigned int file_version) {
        ar & employeeID;
        ar & Name;
        ar & Surname;
        ar & Salary;
        ar & Hired;

    }

    virtual ~Employee();
    Employee();
    Employee(const std::string &, const std::string &);

    Employee (const Employee &person); // ??

     std::string getName() const;
     std::string getSurname() const;

     void setID();
     int getID() const;

     void setSalary(int amount);
     int getSalary() const;

     void setHire(bool);
     bool hiredStatus() const;

protected:

    int employeeID;
    std::string Name;
    std::string Surname;
    int Salary;
    bool Hired;

};

#endif //PROJEKT_EMPLOYEE_H
