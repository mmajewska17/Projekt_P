//#pragma once
#include <iostream>
#include <vector>
#include <string>

//forward declaration because DB and CommandLine are pointing to each other - https://stackoverflow.com/a/4964508
#ifndef COMMANDLINE_H
#define COMMANDLINE_H
// Say DB exists without defining it.
class DB;



//std przestrzen nazw std::
using namespace std;


/// Command Line Interface Class
/// @ db - a handle to DB
///
class CommandLine
{
private:
	//a function for splitting a command into elements of vector
	//and assigning reaction corresponding to that command
    vector<string> split(const string &s, char delim); 
    createTable(vector<string> &objects);
    DB* db;
public:
    CommandLine(DB& dbIn);    //Constructor prototype
    ~CommandLine();   //Destructor prototype
    void parseCommand();
    


};
#endif 
