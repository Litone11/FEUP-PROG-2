#include "Student.h"

Student::Student(int id, const std::string& name, const std::string& course)
    : Person(id, name), course_(course) {}

const std::string& Student::course() const {
    return course_;
}

std::string Student::to_string() const {
    return Person::to_string() + "/" + course_;
}