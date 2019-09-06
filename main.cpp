/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* More: https://stackoverflow.com/questions/17904643/error-with-multiple-definitions-of-function */

// CShape.cpp

#include "CommandLine.h"
#include "DB.h"
#include "templatesDB.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

/*
maly programik
1. tworzy objekt foo z klasy Commandline
2. ustawia dwie wartosci prywatne - dlatego specjalna funkcja potrzebna
3. wyswietla jedna z nich

Possible commands:
list all tables:
	tables
create table:
	create table name typecolumn namecolumn typecolumn2 namecolumn2 ...


*/

int main(int argc, char** argv) {

    DB *db = new DB();

//testing the library from a user defined code
//create table
    string tableName="USERS";
    Table *tableUsers = db->createTable(tableName);

    string tableName2="EMPLOYERS";
    Table *tableEmployers = db->createTable(tableName2);

//add column to table
    string column_1_name = "Name";
    string column_2_age = "Age";
    string column_3_generic = "An generic object";

    int sizeAr=5;

    addColumn<string>(tableUsers, "string", column_1_name);
    addColumn<int>(tableUsers, "integer", column_2_age);


//generic - any type
    addColumn<char>(tableUsers, "generic", column_3_generic);

//nastepny przyklad generic - tym razem struktura
    string column_4_structure = "Structure";
    struct Structure {
        int field_1;
        string field_2;
        char field_3;
    };
    addColumn<Structure>(tableUsers, "generic", column_4_structure);

//printing information about tables and columns of the db
    db->printTableNames();

//add all these elements above into the table as a record
    string name = "Adam Malysz";
    int age = 35;
    char sex = 'M';
    struct Structure exampleStructure;
    exampleStructure.field_1 = 60;
    exampleStructure.field_2 = "bla";
    exampleStructure.field_3 = 'a';

//addRec(int index, tableT& tab, First& arg, const Params&... rest )
//Zly dostep do tablicy tableUsers
    addRec(0,tableUsers,name,age,sex);



/*
string table = "TABLE_POINTER";
char t = {'t'};
int elev = 11;
string abec = "abecadlo";
int tw = 12;
addRec(0,table,t,elev,abec,tw);
*/

//testing the CLI provided with the library
//while(1) {
//db->runCommandLine();
//}

/*
//size of array for each column
int sizeAr=2;

//Table with columns
Table* table1 = new Table("users");

//both ways are working
//char* name = "henryk";
string age = "wiek";
string name = "Henryk";


//Column<int>* aInstance = new Column<int>(sizeAr);
ColumnBase* intInstance = new Column<int>(age, sizeAr);
intInstance->displayColName();
ColumnBase* charInstance = new Column<char>(name, sizeAr);
charInstance->displayColName();

//charInstance->show_data();

//add columns to the table vector
table1->addColumn(intInstance);
table1->addColumn(charInstance);



//cast from base class to derived template class to access the data[]
//https://stackoverflow.com/a/3248354
//set values
static_cast<Column<int>*>(intInstance)->data[0]=32;
static_cast<Column<int>*>(intInstance)->data[1]=44;

static_cast<Column<char>*>(charInstance)->data[0]='a';
static_cast<Column<char>*>(charInstance)->data[1]='b';

//check address
cout<<	 &static_cast<Column<int>*>(intInstance)->data[0]		<<endl;

//check values
cout<<	 static_cast<Column<int>*>(intInstance)->data[0]  		<<endl;
cout<<	 static_cast<Column<int>*>(intInstance)->data[1]		<<endl;
cout<<	 static_cast<Column<char>*>(charInstance)->data[0]		<<endl;
cout<<	 static_cast<Column<char>*>(charInstance)->data[1]		<<endl;


//charInstance->show_data();

//destruct table, columns and data
delete table1;

*/
    return 0;
}


/*

Kolekcjoner [MS]
Opracowanie bazy danych (własny silnik) służącej do przechowywania informacji o
swobodnie definiowanych obiektach, które posiadamy w domu (książki, płyty CD i DVD,
kolekcja figurek porcelanowych, itp.) w postaci biblioteki (np. jak SQLLite). System ma
umożliwić definiowanie różnych typów przedmiotów (opisywanych przez kilka atrybutów
standardowych oraz szereg swobodnie konfigurowalnych) a następnie przechowywać
informacje o poszczególnych egzemplarzach. Dla poszczególnych przedmiotów
zdefiniowanych może być kilka stanów, których się one znajdują (mam, pożyczone,
planowany zakup, ze złomowane, itp.). Oczywiście można dokonywać różnych operacji na
rzeczach oraz dokonywać wyszukiwania według określonych kryteriów

*/

