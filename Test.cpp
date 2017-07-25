/*
* file: Test.cpp
* test of database
* written: 12/03/2017
* last modified: 17/03/2017
* by N. Skilkov
*/
#include "Database.h"

int main() {
	Database db;
	db.LoadFromFile("list.csv");
	db.DisplayAll();
	cout << endl << endl;
	db.ArrangeSubordinates();
	db.DisplayAll();
	cout << endl << endl;
	db.DisplayDepartmentEmployees("IT");
	cout << endl << endl;
	db.FireEmployee(3);
	db.DisplayAll();
	system("pause");
}
