#include "ResaleProduct.h"

ResaleProduct::ResaleProduct(int id, float price, int profit_margin)
    : Product(id, price), profit_(profit_margin) {}

ResaleProduct::~ResaleProduct() = default;

int ResaleProduct::get_profit_margin() const {
    return profit_;
}

void ResaleProduct::set_profit_margin(int margin) {
    profit_ = margin;
}

float ResaleProduct::get_sell_price() const {
    return price_ * (1 + profit_ / 100.0f);
}