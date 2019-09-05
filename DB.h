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
    /*for(;;){
    //input command and print after throwing to vector
        cout << "Input command: ";
        commandLine->parseCommand();

        cout << "Enter another command:";
        if (getchar() == 'w')
        {
            break;
        }
    }*/
    Table* createTable(string& name);
    /*
    * The specialisation of the template below allows user to add any type to a table.
    * The handle is used for CLI(Command Line Interface) to supervise what an user adds
    * and accept only the types which have a known treatment. Since this is a library
    * it is a user duty to extend the templates and adjust to his needs.
    */
    //a handle for CLI
    void addColumnHandle(Table* table, string type, string name);
    void addRecord();
    void printTableNames();


};
#endif

//make an adapter to make it easy for command line to just use the functions of DB




