#include "Person.h"
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

Person::Person(int id, const string& name)
  : id_(id), name_(name) { }

Person::~Person() = default;

int Person::id() const { return id_; }
const string& Person::name() const { return name_; }

string Person::to_string() const {
  ostringstream out;
  out << id_ << '/' << name_;
  return out.str();
}

