#include "Garazh.hpp"
/*protected*/
  void Garazh::read(std::istream& in){//����������
	  in >> brand >> model >> v;
  }
  void Garazh::write(std::ostream& out) const{//�����
	  out << brand << ' '<< model << ' ' << v;
  }
/*public*/
  Garazh::Garazh(const std::string& brand, const std::string& model, int v):brand(brand), model(model), v(v){}
  Garazh::Garazh(const Garazh& g):brand(g.brand), model(g.model), v(g.v){}
  Garazh::~Garazh(){}
  /*������� �������*/
  std::string& Garazh::Brand(){
	   return brand;
  }
  std::string Garazh::Model(){
	   return model;
  }
  int& Garazh::V(){
	   return v;
  }