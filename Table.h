#pragma once

#include <string>
#include <vector>
#include "Column.h"
#include <memory>

/// This is a class of which objects contain varying number of columns in the vector container vectorOfCols.
/// It is managed by DB object and allows for printing useful information and manages the columns which
/// are pointed from vectorOfCols.
/// @vectorOfCols - vector of pointers to columns
/// @name - the name of the column
class Table
{
	private:
		//Vector of pointers to Column. Need to handle destruction.
		//std::vector<ColumnBase*> vectorOfCols;
		//https://stackoverflow.com/a/12009572
		//std::vector<std::unique_ptr<ColumnBase>> vectorOfCols;
	public:
		std::vector<ColumnBase*> vectorOfCols;
		std::string name;
		Table();
		~Table();
		Table(const std::string & name);
		void displayNameAge() const;
		void addColumnToTable(ColumnBase* column);
		void printCols() const;
		void getSize() const;
		void setSize();
		//TODO: partition table - automatic management/ partitioning, change the size if the amount of data too large
		int arraySize=5;
		//bool to return ture if the record has been added or false otherwise
		bool addRecordToTable(std::vector<string>& vectorOfData);

};



