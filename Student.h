#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
public:
    Student(int id, const std::string& name, const std::string& course);
    const std::string& course() const;
    std::string to_string() const override;

private:
    std::string course_;
};

#endif