#ifndef RESALEPRODUCT_H
#define RESALEPRODUCT_H

#include "Product.h"
#include <iostream>

class ResaleProduct : public Product {
public:
    ResaleProduct(int id, float price, int profit_margin);
    ~ResaleProduct() override;

    int get_profit_margin() const;
    void set_profit_margin(int margin);
    float get_sell_price() const override;

private:
    int profit_;
};

#endif // RESALEPRODUCT_H