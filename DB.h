//make it a handle or factory
//#pragma once
#include <iostream>
#include <map>
#include "Table.h"


//forward declaration because DB and CommandLine are pointing to each other - https://stackoverflow.com/a/4964508
#ifndef DB_H
#define DB_H
// Say DB exists without defining it.
class CommandLine;

using namespace std;

/*
* Recursive way of processing a generic number of arguments of different type
* passed into a template.
* https://stackoverflow.com/a/9040913
* This technique is called variadic templates - can be used only with C++11 or above.
*
* Assumption! - no index management has been implemented. New data is always written to 0 index.
*
*/
//last execution of the recursive function
template<typename tableT, typename Last>
void addRec(int cnt, tableT& tab, Last& arg){
	
	//tab->static_cast<Column<Last>*>(vectorOfCols[cnt])->data[0]=arg;
	
    std::cout<<arg<<" "<<cnt<<std::endl;
	std::cout<<tab->name<<std::endl;
    cnt=cnt+1;
    std::cout<<"the record has been added"<<std::endl;
    
}
// ColumnBase intInstance = new ColumnBase();
// static_cast<Column<int>*>(intInstance)->data[0]=32;
template<typename tableT, typename First, typename ... Params >
void addRec(int cnt, tableT& tab, First& arg, const Params&... rest ) {
	//add data to columns
	// 0!- no indexing for data in column - will always overwrite the first record
	//tab->vectorOfCols[cnt]->data[0]=arg;
	//tab->static_cast<Column<First>*>(vectorOfCols[cnt])->data[0]=arg;
    std::cout<<arg<<" "<<cnt<<std::endl;
	std::cout<<tab->name<<std::endl;
    cnt=cnt+1;
    
    addRec(cnt,tab, rest...);
}





/*
* This class manages the container consisting of many tables.
* 
*/
class DB
{
	private:
		map< string, Table* >* mapOfTables;
    	CommandLine* commandLine;
    	friend class CommandLine;
	public:
		DB();
		~DB();
		void runCommandLine();
		Table* createTable(string& name);
		void printTableNames();
		/*
		* The specialisation of the template below allows user to add any type to a table.
		* The handle is used for CLI(Command Line Interface) to supervise what an user adds
		* and accept only the types which have a known treatment. Since this is a library
		* it is a user duty to extend the templates and adjust to his needs.
		*/
		//a handle for CLI
		void addColumnHandle(Table* table, string type, string name);
		
		//template<typename Last>void addRec(Last arg);
		//template<typename First, typename ... Params> void addRec(First arg, const Params&... rest);


	
};
#endif 

//make an adapter to make it easy for command line to just use the functions of DB




