#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Point2d.h"

using namespace std;

Point2d::Point2d(){}

Point2d::Point2d(const Point2d& p) :  p_(p){};

Point2d::Point2d(double x, double y) :  x(x), y(y) {};


double Point2d::get_x() const {
    return x;
}

double Point2d::get_y() const {
    return y;
}


void Point2d::set_x(double x_val) {
    x = x_val;
}

void Point2d::set_y(double y_val) {
    y = y_val;
}


void Point2d::translate(const Point2d& t) {
    x += t.get_x();
    y += t.get_y();
}

double Point2d::distance_to(const Point2d& p) const {
    double dx = x - p.get_x();
    double dy = y - p.get_y();
    return std::sqrt(dx * dx + dy * dy);
}


