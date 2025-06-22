#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>

class Person {
  int id_;
  std::string name_;

public:
  Person(int id, const std::string& name);

  virtual ~Person();

  int id() const;

  const std::string& name() const;

  virtual std::string to_string() const;
};

#endif
