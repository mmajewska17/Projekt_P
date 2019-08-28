/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* More: https://stackoverflow.com/questions/17904643/error-with-multiple-definitions-of-function */

// CShape.cpp
#include "CommandLine.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*
maly programik
1. tworzy objekt foo z klasy Commandline
2. ustawia dwie wartosci prywatne - dlatego specjalna funkcja potrzebna
3. wyswietla jedna z nich
*/

//pewna funkcja testowa - pokazuje jak przekazywac referencje, nie kopiowac obiekt
void ChangeIt(int &num) {
    num = 5;
}

template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N;	}
};

int main(int argc, char** argv) {

    //initialize command line
    CommandLine cmd;
    cmd.setValues("a","b");
    std::string ret = cmd.getGivenname();
    printf ("Characters: %s \n", ret.c_str());

    //input command and print after throwing to vector
    cout << "Input command: ";
    cmd.parseCommand();

    //test generic array
    Array<std::string, 50> array;
    std:cout << array.GetSize() <<std::endl;
    std::cin.get();

    /*

    //fajny sposob na operowanie na przekazanej zmiennej w funkcji
    int MyNum = 1;
    ChangeIt(MyNum);
    cout << "MyNum = " << MyNum << endl;
    */
    system("pause");
    return 0;
}
