#pragma once
#include <string>
#include <iostream>

class Garazh{
protected:
  std::string brand;//�����
  std::string model;//������
  int v;//����� ���������
  void read(std::istream& in);//����������
  void write(std::ostream& out) const;//�����
public:
  Garazh(const std::string& brand = "", const std::string& model = "", int v = 0);
  Garazh(const Garazh& g);
  virtual ~Garazh();
  /*������� �������*/
  std::string& Brand();
  std::string Model();
  int& V();
};