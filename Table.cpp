#include <iostream>
#include "Table.h"
#include "Column.h"
#include <vector>
#include "windows.h"

using namespace std;

//initializes name
Table::Table() : name("[UnknownName]"){
		std::cout<< "Table constructed" << std::endl;
};

//initializes name
Table::~Table(){
		std::cout<< "Table destruction" << std::endl;
		//remove all the objects that are pointed from the vector
		for ( vector<ColumnBase*>::iterator i = this->vectorOfCols.begin(); i != this->vectorOfCols.end(); ++i )
    		delete *i;
};
	
//parametrized person constructor
Table::Table(const std::string & name):name(name){
		std::cout<<"Table(string)"<<std::endl;
};
	
void Table::displayNameAge() const{
	std::cout << name << std::endl;
};

//The idea of const functions is not allow them to modify the object on which they are called
void Table::printCols() const{
std::cout<< ">>Information about columns"<< ": \n" << std::endl;
std::cout<< "Amount of columns: "<< vectorOfCols.size() << "\n" << std::endl;
for (unsigned i=0; i<vectorOfCols.size(); i++){
	std::cout<< "Column nr. "<< i << " name : ";
	this->vectorOfCols.at(i)->displayColName();
}
std::cin.get();  
    
}


void Table::addColumnToTable(ColumnBase* column){
	this->vectorOfCols.push_back(column);
}

void Table::getSize() const{
	std::cout<< "getSize"<<endl;
}

/**
*This function partitions the table, namely it changes the size of each column.
**/
void Table::setSize() {
	std::cout<< "setSize"<<endl;
}

//input - vector of strings
//aim - cast and add to columns
bool addRecordToTable(std::vector<string>& vectorOfData){
	//go through all the columns and assing data
	
};


