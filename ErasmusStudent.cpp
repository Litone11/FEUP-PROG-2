#include "ErasmusStudent.h"

ErasmusStudent::ErasmusStudent(int id, const std::string& name, const std::string& course, const std::string& country)
    : Student(id, name, course), country_(country) {}

const std::string& ErasmusStudent::country() const {
    return country_;
}

std::string ErasmusStudent::to_string() const {
    return Student::to_string() + "/" + country_;
}