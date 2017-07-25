/*
* file: Manager.cpp
* implementation of Manager class
* written: 12/03/2017
* last modified: 17/03/2017
* by N. Skilkov
*/
#include "Manager.h"

// Manager Class Implemantation

Manager::Manager(const Manager &m) {
	f_name = m.f_name;
	l_name = m.l_name;
	age = m.age;
	department = m.department;
	salary = m.salary;
	id = m.id;
	subordinates = m.subordinates;
}

Manager& Manager::operator=(const Manager &m) {
	if (this == &m)
		return *this;
	f_name = m.f_name;
	l_name = m.l_name;
	age = m.age;
	department = m.department;
	salary = m.salary;
	id = m.id;
	subordinates = m.subordinates;
}

void Manager::Display() {
	cout << "Employment type : Manager" << endl;
	cout << "ID: " << id << endl;
	cout << f_name << " " << l_name << " Age: " << age << " Salary: " << salary << endl;
	cout << "Department: " << department << endl;
	cout << endl;
};

Person* Manager::AddSubordinate(Person *p) {
	if (p) 
		subordinates.push_back(p);
	return p;
}

void Manager::DisplaySubordinates() {
	if (subordinates.empty())
		cout << "No subordinates" << endl;
	else {
		for (list<Person*>::iterator iterator = subordinates.begin(); iterator != subordinates.end(); iterator++) {
			dynamic_cast<Employee*>(*iterator)->Display(true);
		}
	}
}

bool Manager::DeleteSubordinate(int id) {
	for (list<Person*>::iterator it = subordinates.begin(); it != subordinates.end(); it++) {
		if (dynamic_cast<Employee*>(*it)->GetId() == id) {
			it = subordinates.erase(it);
			return true;
		}
	}
	return false;
}
