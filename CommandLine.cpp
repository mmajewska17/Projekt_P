#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include "Table.h"


#include "CommandLine.h"
#include "DB.h"

using namespace std;

CommandLine::CommandLine(DB& dbIn)
{
	this->db=&dbIn;
}

CommandLine::~CommandLine()
{
	//nie usuwac dbIn! - DB najpierw usunie commandLine a pozniej siebie
}


//spliting a string line into vector elements
vector<string> CommandLine::split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (ss >> item) {
        tokens.push_back(item);
    }
    return tokens;
}

/*
creating a new table
SYNTAX: CREATE TABLE TABLENAME TYPE1 COLUMNNAME1 TYPE2 COLUMNNAME2 ...
*/
CommandLine::createTable(vector<string> &objects){
	//testowanie czy komenda zosta³a dobrze przekazana do funkcji
	int l=objects.size();
	//omit CREATE TABLE
	int k = 2;
	//TABLENAME
	cout << objects[k] + " <= name "<< endl;
	//create the table with the given name, take pointer to it
	Table* table = this->db->createTable(objects[k]);
	k=k+1;

	for (k; k < l; k=k+2) {
		//TYPE
		cout << objects[k] + " <= type "<< endl;
		//COLUMNNAME
		cout << objects[k+1] + " <= value " << endl;
		string typeColumn = objects[k];
		string nameColumn = objects[k+1];
		this->db->addColumnHandle(table,typeColumn,nameColumn);
	}

}


void CommandLine::parseCommand(){
    char input[100];
    cin.getline(input,sizeof(input));

    string a,b;
    vector<string> objects;

    //split sentence to words in a vector
    objects = split(input, ' ');

    //char(32) = ' '

    // oczekiwane komendy - oczekiwany syntax to nazwy kolumn po przecinku bez spacji
    // select name,surname from users
    if (objects[0].compare("select") == 0) {
        cout << " action to select" << endl;
        //je¿eli jest select to trzeba oczekiwaæ wybierania wierszy z bazy danych
        //po selekcie nastepne oczekiwane lista s³ów to kolumny
    }
    else if (objects[0].compare("insert")== 0){
        cout << " action to insert word" << endl;
    }
    else if (objects[0].compare("delete")== 0){
        cout << " action to delete word" << endl;
    }
    else if (objects[0].compare("create")== 0){
        //reaction for the create word
        cout << "create" << endl;
        if (objects[1].compare("table")== 0){
            cout << "create table" << endl;
            //go to function responsible for creating a new table
            this->createTable(objects);
        }
    }
    else if (objects[0].compare("tables") == 0){
        cout << " Listing all tables" << endl;
        this->db->printTableNames();
    }
    else {
        cout << "wrong command, please use tables, select, insert, delete or create" << endl;
    }

	cin.clear();
	cout << "Done" << endl;

}


