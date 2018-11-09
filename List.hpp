#pragma once

  
template<typename T>
struct Element{//������� ������
  	T _data; // �������� ��������
	Element *_next;	//������ �� �������� �������
	Element *_prev;	//������ �� ���������� �������
};

template<typename T>
class List {
private:
    Element<T> *_head; //������ ������
	Element<T> *_tail; //������ ������
    int _size; //������
public:
   List();//�����������
   void add(const T &_data);//������� ������� � ����� ������
   T remove(int index);//������� i-�� �������
   int size(); //������
   T operator[](int index)const;//��������� i-�� ��������
   T & operator[](int index);//��������� i-�� ��������
   void clear();
   ~List(); //����������
};

template<typename T>
void List<T>::clear(){
   for(int i = 0; i < _size; --_size){//�������� �� ������� ��������
		   Element<T> *buf = _head;
		   _head = _head->_next;//��������� � ����������
		   delete buf;//������� ����������
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
	   if(index < 0 || index >= _size){//���� ��������  ������
			return T(0);
	   }
		Element<T> *temp = _head;
		for(int i = 0; i < _size && i < index; ++i) {	// �������� ������ �������
			temp = temp->_next;
		}

		if (temp == nullptr) {// ���� �� �����
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
		for(int i = 0; i < _size && i < index; ++i) { //���� ������ �������
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
T List<T>::operator[](int index)const{
	    Element<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //���� ������ �������
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
List<T>::~List(){ //����������
		for(int i = 0; i < _size; --_size){//�������� �� ������� ��������
		   Element<T> *buf = _head;
		   _head = _head->_next;//��������� � ����������
		   delete buf;//������� ����������
		}
}


