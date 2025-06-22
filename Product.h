#ifndef __Product_h__
#define __Product_h__

class Product {
protected:
  int id_;
  float price_;

public:
  Product(int id, float price);

  virtual ~Product();

  int get_id() const;

  virtual float get_sell_price() const;
};

#endif
