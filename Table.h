#pragma once

#include <string>
#include <vector>
#include "Column.h"
#include <memory>

class Table
{
private:
    std::string name;
    //Vector of pointers to Column. Need to handle destruction.
    std::vector<ColumnBase*> vectorOfCols;
    //https://stackoverflow.com/a/12009572
    //std::vector<std::unique_ptr<ColumnBase>> vectorOfCols;


protected:
    //the access can be done only with a special setter - to avoid uncontrolled change of table size
    //size = amount of elements in each column
    //int arraySize=0;
public:
    Table();
    ~Table();
    Table(const std::string & name);
    void displayNameAge() const;
    void addColumnToTable(ColumnBase* column);
    void printCols() const;
    void getSize() const;
    //partition table
    void setSize();
    //automatic management/ partitioning
    int arraySize=5;
    //	~Person();

};


