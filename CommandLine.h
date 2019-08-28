#include <iostream>
#include <vector>
#include <string>

//std przestrzen nazw std::
using namespace std;

class CommandLine
{
private:
    string m_givenname;
    string m_familyname;
    vector<string> split(const string &s, char delim); // function for splitting a line
    createTable(vector<string> &objects);
public:
    CommandLine();    //Constructor prototype
    ~CommandLine();   //Destructor prototype
    void setValues(string m_givenname_i,string m_familyname_i); //setter
    string getGivenname(); //getter
    void parseCommand();


};


