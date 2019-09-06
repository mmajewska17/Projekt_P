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
