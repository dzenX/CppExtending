/*
* file: Employee.cpp
* implementation of Employee class
* written: 12/03/2017
* last modified: 17/03/2017
* by N. Skilkov
*/

#include "Employee.h"
//Classes Implemantation

Employee::Employee(const Employee &e) {
	f_name = e.f_name;
	l_name = e.l_name;
	age = e.age;
	department = e.department;
	salary = e.salary;
	id = e.id;
};

Employee& Employee::operator=(const Employee &e) {
	if (&e == this)
		return *this;
	f_name = e.f_name;
	l_name = e.l_name;
	age = e.age;
	department = e.department;
	salary = e.salary;
	id = e.id;
	return *this;
}

void Employee::SetSalary(int s) {
	if (s >= 0)
		salary = s;
	else
		salary = -1;
}

void Employee::SetDepartment(string dept) {
	if (!dept.empty())
		department = dept;
	else
		department = "No department";
}

void Employee::SetId(int n) {
	if (n >= 0)
		id = n;
	else
		id = -1;
}

int Employee::GetId() {
	return id;
}

string Employee::GetDepartment() {
	return department;
}

void Employee::Display(bool f) {
	if (f)
		cout << "	";
	cout << "Employment type : Employee" << endl;
	if (f)
		cout << "	";
	cout << "ID: " << id << endl;
	if (f)
		cout << "	";
	cout << f_name << " " << l_name << " Age: " << age << " Salary: " << salary << endl;
	if (!f)
		cout << "Department: " << department << endl;
	cout << endl;
}
