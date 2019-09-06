/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* More: https://stackoverflow.com/questions/17904643/error-with-multiple-definitions-of-function */
/*

Kolekcjoner [MS]
Opracowanie bazy danych (w³asny silnik) s³u¿¹cej do przechowywania informacji o
swobodnie definiowanych obiektach, które posiadamy w domu (ksi¹¿ki, p³yty CD i DVD,
kolekcja figurek porcelanowych, itp.) w postaci biblioteki (np. jak SQLLite). System ma
umo¿liwiæ definiowanie ró¿nych typów przedmiotów (opisywanych przez kilka atrybutów 
standardowych oraz szereg swobodnie konfigurowalnych) a nastêpnie przechowywaæ
informacje o poszczególnych egzemplarzach. Dla poszczególnych przedmiotów
zdefiniowanych mo¿e byæ kilka stanów, których siê one znajduj¹ (mam, po¿yczone,
planowany zakup, ze z³omowane, itp.). Oczywiœcie mo¿na dokonywaæ ró¿nych operacji na
rzeczach oraz dokonywaæ wyszukiwania wed³ug okreœlonych kryteriów

*/

// CShape.cpp

#include "CommandLine.h"
#include "DB.h"
#include "templatesDB.h"
#include <typeinfo>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

/*
CLI - Possible commands:

1. list all tables:
	tables 
2. create table:
	create table name typecolumn namecolumn typecolumn2 namecolumn2 ...

*/

int main(int argc, char** argv) {
// create a new instance of DB
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

//nastepny przyklad generic - tym razem struktura, dodaje kolumne do tabeli Users
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
//addRec(0,tableUsers,name,age,sex,exampleStructure);
addRec(0,tableUsers,name,age,sex);

//cout << typeid(*tableUsers).name() << endl;

//testing the CLI provided with the library
while(1) {
db->runCommandLine();
}

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




