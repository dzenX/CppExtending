/*
* file: Database.cpp
* implementation of Database
* written: 12/03/2017
* last modified: 17/03/2017
* by N. Skilkov
*/
#include "Database.h"
#include <fstream>
// Database Class Implemantation

bool Database::LoadFromFile(const char *file) {
	string* buff;
	Person* p;
	int i,k;
	string get,tmp;
	ifstream src(file);
	if (!src.is_open())
		return false;
	buff = new string[7];
	while (!src.eof()) {
		getline(src,get);
		get += ";";
		k = 0;
		for (i = 0; i < get.size(); i++) {
			if (get[i] == ';') {
				buff[k] = tmp;
				tmp.clear();
				k++;
			}
			else
				tmp += get[i];
		}
		if (k != 7)
			return false;
		if (buff[0] == "0") {
			p = new Employee(buff[2], buff[3], stoi(buff[4]), stoi(buff[1]));
			dynamic_cast<Employee*>(p)->SetDepartment(buff[5]);
			dynamic_cast<Employee*>(p)->SetSalary(stoi(buff[6]));
		}
		else if (buff[0] == "1") {
			p = new Manager(buff[2], buff[3], stoi(buff[4]), stoi(buff[1]));
			dynamic_cast<Manager*>(p)->SetDepartment(buff[5]);
			dynamic_cast<Manager*>(p)->SetSalary(stoi(buff[6]));
		}
		else
			p = NULL;
		HireEmployee(p);
	}
}

void Database::ArrangeSubordinates() {
	vector<Person*>::iterator num;
	string dept;
	for (vector<Person*>::iterator iterator = employees.begin(); iterator != employees.end(); iterator++) {
		if (typeid(**iterator) == typeid(Employee)){
			dept = dynamic_cast<Employee*>(*iterator)->GetDepartment();
			for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++)
				if (typeid(**it) == typeid(Manager)) {
					if (dynamic_cast<Manager*>(*it)->GetDepartment() == dept)
						if (*iterator)
							dynamic_cast<Manager*>(*it)->AddSubordinate(*iterator);
				}
		}
	}
}

Person* Database::HireEmployee(Person *p) {
	if (!p)
		return NULL;
	else
		employees.push_back(p);
}

void Database::DisplayDepartmentEmployees(string _department) {
	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
		if (typeid(**it) == typeid(Employee))
			if (dynamic_cast<Employee*>(*it)->GetDepartment() == _department)
				dynamic_cast<Employee*>(*it)->Display(false);
		if (typeid(**it) == typeid(Manager))
			if (dynamic_cast<Manager*>(*it)->GetDepartment() == _department)
				dynamic_cast<Manager*>(*it)->Display();
	}
}

bool Database::FireEmployee(int id) {
	string dept;
	bool fl = false;
	for (vector<Person*>::iterator iterator = employees.begin(); iterator != employees.end(); iterator++) {
		if (typeid(**iterator) == typeid(Employee))
			if (dynamic_cast<Employee*>(*iterator)->GetId() == id) {
				dept = dynamic_cast<Employee*>(*iterator)->GetDepartment();
				iterator = employees.erase(iterator);
				fl = true;
			}
		else if (typeid(**iterator) == typeid(Manager))
			if (dynamic_cast<Manager*>(*iterator)->GetId() == id) {
				iterator = employees.erase(iterator);
				return true;
			}
	}
	for (vector<Person*>::iterator iterator = employees.begin(); iterator != employees.end(); iterator++) {
		if (typeid(**iterator) == typeid(Manager)) {
			if (dynamic_cast<Manager*>(*iterator)->GetDepartment() == dept) 
				dynamic_cast<Manager*>(*iterator)->DeleteSubordinate(id);
		}
	}
	return fl;
}

void Database::DisplayAll() {
	for (vector<Person*>::iterator iterator = employees.begin(); iterator != employees.end(); iterator++) {
		if (typeid(**iterator) == typeid(Employee))
			dynamic_cast<Employee*>(*iterator)->Display(false);
		else if (typeid(**iterator) == typeid(Manager)) {
			dynamic_cast<Manager*>(*iterator)->Display();
			dynamic_cast<Manager*>(*iterator)->DisplaySubordinates();
		}
		else
			cout << "Error type of Person" << endl;
	}
}
