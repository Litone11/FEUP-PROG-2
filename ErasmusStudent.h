#ifndef ERASMUSSTUDENT_H
#define ERASMUSSTUDENT_H

#include "Student.h"

class ErasmusStudent : public Student {
public:
    ErasmusStudent(int id, const std::string& name, const std::string& course, const std::string& country);
    const std::string& country() const;
    std::string to_string() const override;

private:
    std::string country_;
};

#endif