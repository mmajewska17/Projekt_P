/*
#include <iostream>
#include "Table.h"
#include <vector>

//
template <class T>
Column<T>::Column(){
};

//base constructor (size)
template <class T>
Column<T>::Column(int& size):size(size){
	std::cout<<"Column "<< this->name <<" constructor"<<std::endl;
	data = new T[size];
};

//constructor (name, size)
template <class T>
Column<T>::Column(const std::string & name, int& size):Column(size){
	this->name=name;
	std::cout<<"Column(string)"<<std::endl;
};

//destructor
template <class T>
Column<T>::~Column(){
	delete[] data;
	std::cout<<"destructor of column "<< this->name <<std::endl;
};

//display name
template <class T>
void Column<T>::displayColName() const{
	std::cout<<this->name<<std::endl;
};



template <class T>
void Column<T>::show_data(){
};


*/



/*
//char column

c_Column::c_Column():data({'a','b'}),Column("charColumn"){
};

c_Column::c_Column(const std::string & name):data({'a','b'}),Column(name){
};

c_Column::~c_Column(){
};

void c_Column::show_data(){
	std::cout<<data[0]<<std::endl;
	std::cout<<data[1]<<std::endl;
};

//char column

i_Column::i_Column():data(0),Column("intColumn"){
};

i_Column::i_Column(const std::string & name):data(0),Column(name){
};

i_Column::~i_Column(){
};

void i_Column::show_data(){
	std::cout<<data<<std::endl;
};

*/
