//
// Created by max on 6/23/18.
//

#include "Worker.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Worker);

Worker::Worker() = default;

Worker::~Worker() = default;

Worker::Worker(const std::string &newName, const std::string &newSurname) : Employee(newName, newSurname) {}

Worker::Worker(const Employee & person) : Employee(person) {}