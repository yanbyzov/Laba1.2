#pragma once

  
template<typename T>
struct Element{//element spiska
  	T _data; // znachenie elementa
	Element *_next;	//ssilka na sleduyushiy elenet
	Element *_prev;	//ssila na predidushiy elenent
};

template<typename T>
class List {
private:
    Element<T> *_head; //nachalo spiska
	Element<T> *_tail; //konec spiska
    int _size; //razmer
public:
   List();//konstructor
   void add(const T &_data);//zanosim element v konec spiska
   T remove(int index);//udalyaem perviy element
   int size(); //razmer
   T operator[](int index)const;//polucheniye itogo elementa
   T & operator[](int index);//polucheniye itogo elementa
   void clear();
   ~List(); //destructor
};

template<typename T>
void List<T>::clear(){
   for(int i = 0; i < _size; --_size){//prohodim po kashdomu elemntu
		   Element<T> *buf = _head;
		   _head = _head->_next;//perehodim k sleduyushemu
		   delete buf;//udalyaem predidushiy
		}
}

template<typename T>
List<T>::List<T>():_head(nullptr), _tail(nullptr), _size(0){
   }

template<typename T>
void List<T>::add(const T &_data){
	    Element<T> *buf = new Element<T>;
		buf->_data = _data;
		buf->_next = nullptr;
		buf->_prev = _tail;
		if (_tail) {
			_tail->_next = buf;
		}
		if (_head == nullptr) {
			_head = buf;
		}
		_tail = buf;
		++_size;
}

template<typename T>
T List<T>::remove(int index){
	   if(index < 0 || index >= _size){//eski neverniy index
			return T(0);
	   }
		Element<T> *temp = _head;
		for(int i = 0; i < _size && i < index; ++i) {	// poluchaem nushniy element
			temp = temp->_next;
		}

		if (temp == nullptr) {// esli ne nasli
			return T(0); 
		}
		if (temp->_prev) {
			temp->_prev->_next = temp->_next;
		}
		if (temp->_next) {
			temp->_next->_prev = temp->_prev;
		}
		T _data = temp->_data;
 
		if (temp->_prev == nullptr) {
			_head = temp->_next;
		}
		if (temp->_next == nullptr) {
			_tail = temp->_prev;
		}
		delete temp;
		--_size;
		return _data;
}

template<typename T>
int List<T>::size(){ 
	return _size; 
}

template<typename T>
T & List<T>::operator[](int index){
	    Element<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //ishem nushniy element
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
T List<T>::operator[](int index)const{
	    Element<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //ishem nushniy element
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
List<T>::~List(){ //деструктор
		for(int i = 0; i < _size; --_size){//prohodim po kashdomu
		   Element<T> *buf = _head;
		   _head = _head->_next;//perehodim k sleduyushemu
		   delete buf;//udalyaem predidushiy
		}
}
