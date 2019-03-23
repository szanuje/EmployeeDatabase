//
// Created by max on 6/4/18.
//

#include "Intern.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Intern);

Intern::Intern() = default;

Intern::~Intern() = default;

Intern::Intern(const std::string &newName, const std::string &newSurname) : Employee(newName, newSurname) {}

Intern::Intern(const Employee & person) : Employee(person) {}