//
// Created by max on 6/23/18.
//

#include "Manager.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Manager);

Manager::Manager() = default;

Manager::~Manager() = default;

Manager::Manager(const std::string &newName, const std::string &newSurname) : Employee(newName, newSurname) {}

Manager::Manager(const Employee & person) : Employee(person) {}