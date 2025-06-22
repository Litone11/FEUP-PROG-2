#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "bfeup.h"

BFEUP::BFEUP() {}

void BFEUP::add_movement(action act, int amount, int day, int month, int year) {
    movement m = {act, amount, day, month, year};
    movements.push_back(m);
}

int BFEUP::balance(int month, int year) {
    int total = 0;
    for (const auto& m : movements) {
        if (m.month == month && m.year == year) {
            if (m.act == DEPOSIT) total += m.amount;
            else if (m.act == WITHDRAW) total -= m.amount;
        }
    }
    return total;
}

void BFEUP::print_movements(int month, int year) {
    for (const auto& m : movements) {
        if (m.month == month && m.year == year) {
            std::cout << std::setw(2) << std::setfill('0') << m.day << "-"
                      << std::setw(2) << std::setfill('0') << m.month << "-"
                      << m.year << ": "
                      << (m.act == DEPOSIT ? "+" : "-")
                      << m.amount << std::endl;
        }
    }
}
