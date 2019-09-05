

#include "Table.h"
#include "Column.h"

#include <map>
#include <iterator>
#include "DB.h"
#include "CommandLine.h"

//template  - typename interchangeable with column keyword
//these functions are accessible for programmer -> generic container
template<typename T>
void addColumn(Table* table, string type, string name){
    ColumnBase* Instance;
    Instance = new Column<T>(name, table->arraySize,'g');
    cout << "Info: Column of generic type has been added: "<< name <<endl;
    table->addColumnToTable(Instance);
}
//
//specialisation function int
template<>
void addColumn<int>(Table* table, string type, string name){
    ColumnBase* Instance;
    Instance = new Column<int>(name, table->arraySize,'i');
    cout << "Info: Column of type int has been added: "<< name <<endl;
    table->addColumnToTable(Instance);
}
//
//specialisation function string
template<>
void addColumn<string>(Table* table, string type, string name){
    ColumnBase* Instance;
    Instance = new Column<string>(name, table->arraySize,'s');
    cout << "Info: Column of type string has been added: "<< name <<endl;
    table->addColumnToTable(Instance);
}


DB::DB(){
    mapOfTables=new map< string, Table* >();
    //pass DB object itself
    commandLine=new CommandLine(*this);

};


DB::~DB(){
    //delete all elements of the map

    //delete commandLine
    delete commandLine;
};

void DB::runCommandLine(){
    //ask for a new command infinitely
    cout << "Input command: ";
    this->commandLine->parseCommand();
}



Table* DB::createTable(string& name){
    //create new Table
    Table* table = new Table(name);
    //add to the map of tables
    this->mapOfTables->insert({name, table});
    cout << "Table " << name << " created"<<endl;
    return table;
}

/*
* The specialisation of the template below allows user to add any type to a table.
* The handle is used for CLI(Command Line Interface) to supervise what an user adds
* and accept only the types which have a known treatment. Since this is a library
* it is a user duty to extend the templates and adjust to his needs.
*/

//a handle for CLI
void DB::addColumnHandle(Table* table, string type, string name){
    //handle only int and char
    ColumnBase* Instance;
    if(type == "string"){
        addColumn<string>(table, type, name);
    }else if(type == "integer"){
        //int x = atoi(value);
        addColumn<int>(table, type, name);
    }else{
        cout << "Warning: this type is not supported by CLI"<<endl;
    }

}

void DB::printTableNames(){
    //https://thispointer.com/how-to-iterate-over-a-map-in-c/
    std::map< string, Table* >::iterator it = mapOfTables->begin();

    while (it != mapOfTables->end())
    {
        // Accessing KEY from element pointed by it.
        std::string word = it->first;
        // Accessing VALUE from element pointed by it.
        int tableSize = it->second->arraySize;
        std::cout << word  <<" : "<< tableSize <<std::endl;
        // Increment the Iterator to point to next entry
        it++;
    }


}



void DB::addRecord(){

}


