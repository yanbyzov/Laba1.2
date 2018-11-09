#include "Bike.hpp"
/*public*/
  Bike::Bike(const std::string& brand, const std::string& model, int v, const std::string& place, int power)
	  :Garazh(brand, model, v), place(place), power(power){}
  Bike::Bike(const Bike& g):Garazh(g.brand, g.model, g.v), place(g.place), power(g.power){}
  Bike::~Bike(){}
/*геттеры сеттеры*/
  std::string& Bike::Place(){
	   return place;
  }
  int& Bike::Power(){
	   return power;
  }

std::istream& operator>>(std::istream& in, Bike& g){
   g.read(in);
   in >> g.place >> g.power;
   return in;
}
std::ostream& operator<<(std::ostream& out, const Bike& g){
	g.write(out);
	out << g.place << ' ' << g.power;
	return out;

}