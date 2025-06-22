#include <iostream>
#include <string>
#include "library.h"

using namespace std;

Library::Library(){};

void Library::add_book(string title, string author, int year){
    book book;
    book.title = title;
    book.author = author;
    book.year = year;
    books.push_back(book);
}


book Library::find_book(string title){
    for(const auto& book : books){
        if(title == book.title) return book;
    }
    return book{"Not found", "", 0}; // default if not found
}



vector<book> Library::find_books(string author){
    vector<book> bookss;
    for(const auto& book : books){
        if(author == book.author) bookss.push_back(book);
    }
    return bookss;
}


vector<book> Library::find_books(int year){
    vector<book> bookss;
    for(const auto& book : books){
        if(year == book.year) bookss.push_back(book);
    }
    return bookss;
}



void Library::print_books(){
    for(const auto& book : books){
        cout << book << std::endl;
    }
}