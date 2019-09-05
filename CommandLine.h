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

//friend class of DB
class CommandLine
{
private:
    vector<string> split(const string &s, char delim); // function for splitting a line
    createTable(vector<string> &objects);
    DB* db;
public:
    CommandLine(DB& dbIn);    //Constructor prototype
    ~CommandLine();   //Destructor prototype
    void parseCommand();



};
#endif

