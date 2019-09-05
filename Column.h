#pragma once

#include <string>
#include <vector>
#include <iostream>
/*
Templates are all about the compiler generating code at compile-time.
Virtual functions are all about the run-time system figuring out which function to call at run-time.
*/
using namespace std;
//it is required to let compiler know what to store in a vector of columns in the Table class objects
class ColumnBase
{
public:
    //std::string name = "X";
    //int size;


    //virtual Column() = 0;
    //virtual	Column(int& size) = 0;
    //virtual	Column(const std::string & name, int& size) = 0;
    virtual ~ColumnBase(){};
    //virtual ColumnBase(){};
    virtual void displayColName() const = 0;
    virtual void show_data() const = 0;
    //virtual void set_data(&T cellData, int index);

    // and possibly other interface functions...
};


//base class Column template
//it is not split to 2 files because - https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
template <class T> class Column: public ColumnBase
{
    //private:
    // i-int, c-char, g - generic
    //char type;
    //protected:
    //	std::string name = "X";
public:
    char type;
    T* data;
    std::string name = "X";

    int size;

    Column(){
        std::cout<<"Column "<< this->name <<" constructor"<<std::endl;
        this->data = new T[0];
        this->size = 0;
    };

    //base constructor (size)
    Column(int& size){
        std::cout<<"Column "<< this->name <<" constructor"<<std::endl;
        this->data = new T[size];
        this->size = size;
    };

    //constructor (name, size)
    Column(const string & name, int & size, char type):Column(size){
        std::cout<<"Column "<< this->name <<" constructor"<<std::endl;
        this->name=name;
        this->type=type;
        std::cout<<"Column(string)"<<std::endl;
    };

    //destructor
    ~Column(){
        delete[] data;
        std::cout<<"destructor of column "<< this->name <<std::endl;
    };

    //display name
    void displayColName() const{
        std::cout<<this->name<<std::endl;
    };

    //show data
    void show_data() const{
        std::cout<<data[0]<<std::endl;
    };

    //set data
    void set_data(T& cellData, int index){
        //checker to find out if the index is existing
        this->data[index]=cellData;
        /**
        |age|
        -----
        [23 ]
        [?  ] <- 54
        [23 ]
        **/
    };



};





/*
derived class char column
show data has to be in each class derived from Column
but depending on type it will work in a different way
*/
/*
class c_Column : public Column
{
	public:
		int lengthOfCharArray;
		char data[2];
		c_Column();
		c_Column(const std::string & name);
    	~c_Column();
    	void show_data() override;
};





//sub-class int column
class i_Column : public Column
{
	public:
		int data;
		i_Column();
		i_Column(const std::string & name);
    	~i_Column();
    	void show_data() override;

};
*/
