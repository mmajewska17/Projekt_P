#include "CommandLine.h"
#include "Table.h"

#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>

CommandLine::CommandLine()
{

}

CommandLine::~CommandLine()
{

}

void CommandLine::setValues(std::string m_givenname_i,std::string m_familyname_i)
{
    m_givenname=m_givenname_i;
    m_familyname=m_familyname_i;
}

std::string CommandLine::getGivenname()
{
    return m_givenname;
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

//creating a new table
CommandLine::createTable(vector<string> &objects){
//testowanie czy komenda została dobrze przekazana do funkcji

int l=objects.size();
for (int k = 0; k < l; k++) {
cout << objects[k] + "<= createtable function scope" << endl;
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
        //jeżeli jest select to trzeba oczekiwać wybierania wierszy z bazy danych
        //po selekcie nastepne oczekiwane lista słów to kolumny
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
            createTable(objects);
        }

    }
    else {
        cout << "wrong command, please use select, insert, delete or create" << endl;
    }





/*
	// print every part of the command separately
    int l=objects.size();
    for (int k = 0; k < l; k++) {

    	if (objects[k].compare("select") == 0) {
    		cout << " action to select word" << endl;
    		//jeżeli jest select to trzeba oczekiwać wybierania wierszy z bazy danych
    		//po selekcie nastepne oczekiwane lista słów to kolumny
		}

		else if (objects[k].compare("from")== 0){
			cout << " action to from word" << endl;
		}


        //cout << objects[k] + "<= react to this part of command" << endl;
    }
    //now every element of vector will determine another action
	*/

}
