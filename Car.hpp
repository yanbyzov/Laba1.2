#pragma once
#include "Garazh.hpp"

class Car: public Garazh{
protected:
  std::string color;//����
  std::string type;//��� ���
public:
  Car(const std::string& brand = "", const std::string& model = "", int v = 0, const std::string& color = "", const std::string& type = "");
  Car(const Car& g);
  virtual ~Car();
  /*������� �������*/
  std::string& Color();
  std::string& Type();
  friend std::istream& operator>>(std::istream& in, Car& g);
  friend std::ostream& operator<<(std::ostream& out, const Car& g); 
};