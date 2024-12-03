#pragma once
#include <string>
#include <iostream>
#include <fstream>

class EMPLOYEE
{
private:
	std::string fio, post;
	unsigned int year_of_bd, department_code, experience;
public:
	EMPLOYEE() {};
	EMPLOYEE(std::ifstream& file);
	void fill_from_keyboard();
	void print(std::ostream& out = std::cout);
	std::string get_fio() { return fio; };
	std::string get_post() { return post; };
	unsigned int get_year_of_bd() { return year_of_bd; };
	unsigned int get_department_code() { return department_code; };
	unsigned int get_experience() { return experience; };
	int compare(const EMPLOYEE& other);


};

