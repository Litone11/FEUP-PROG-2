//
// Created by joaob on 19/04/2025.
//
#include "Product.h"

Product::Product(int id, float price) : id_(id), price_(price) {
};

Product::~Product() {
};

int Product::get_id() const { return id_; }

float Product::get_sell_price() const { return price_; }
