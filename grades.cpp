#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student(const string& id) : id_(id) {}

string Student::get_id() const {
    return id_;
}

void Student::add(const course& c) {
    courses_.push_back(c);
}

double Student::avg() const {
    if (courses_.empty()) return 0.0;

    double weighted_sum = 0;
    double total_credits = 0;

    for (const auto& c : courses_) {
        weighted_sum += c.grade * c.credits;
        total_credits += c.credits;
    }

    return weighted_sum / total_credits;
}