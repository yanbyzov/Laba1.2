#pragma once
#include "Garazh.hpp"

class Bike: public Garazh{
protected:
  std::string place;//местность
  int power;//мощность
public:
  Bike(const std::string& brand = "", const std::string& model = "", int v = 0, const std::string& place = "", int power = 0);
  Bike(const Bike& g);
  virtual ~Bike();
  /*геттеры сеттеры*/
  std::string& Place();
  int& Power();
  friend std::istream& operator>>(std::istream& in, Bike& g);
  friend std::ostream& operator<<(std::ostream& out, const Bike& g); 
};