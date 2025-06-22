#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

struct book {
  string title;
  string author;
  int year;
};

class Library {
public:
  // Constructor
  Library();

  // Adds a book to the library
  void add_book(string title, string author, int year);

  // Returns a book with a given title
  book find_book(string title);

  // Returns all books from a given author
  vector<book> find_books(string author);

  // Returns all books from a given year
  vector<book> find_books(int year);

  // Prints all books in the library
  void print_books();

private:
  vector<book> books;
};

std::ostream &operator<<(std::ostream &out, const book &b) {
  out << b.title << ": " << b.author << " (" << b.year << ")";
  return out;
}

#endif // LIBRARY_H
