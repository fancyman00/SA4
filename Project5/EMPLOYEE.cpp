#include "EMPLOYEE.h"

EMPLOYEE::EMPLOYEE(std::ifstream& file)
{
	std::string temp;
	getline(file, temp, ':'); file >> std::ws; getline(file, fio);
	getline(file, temp, ':'); file >> year_of_bd; file.ignore();
	getline(file, temp, ':'); file >> department_code; file.ignore();
	getline(file, temp, ':'); file >> std::ws; getline(file, post);
	getline(file, temp, ':'); file >> experience; file.ignore();
	getline(file, temp);
}

void EMPLOYEE::fill_from_keyboard()
{
	std::cout << "Введите ФИО: ";
	std::cin.ignore();
	std::getline(std::cin, fio);

	std::cout << "Введите год рождения: ";
	std::cin >> year_of_bd;


	std::cout << "Введите код отдела (число): ";
	std::cin >> department_code;

	std::cout << "Введите должность: ";
	std::cin >> post;

	std::cout << "Введите стаж работы: ";
	std::cin >> experience;
}


void EMPLOYEE::print(std::ostream& out)
{
	out << "ФИО: " << fio<< '\n';
	out << "Год рождения: " << year_of_bd << '\n';
	out << "Код отдела: " << department_code << '\n';
	out << "Должность: " << post << '\n';
	out << "Стаж: " << experience << '\n';
	out << "========================================================\n";
}

int EMPLOYEE::compare(const EMPLOYEE& other)
{
	int result = 0;
	if (department_code > other.department_code)
		result = 1;
	else if (department_code < other.department_code)
		result = -1;

	if (result == 0)
	{
		if (post > other.post)
			result = 1;
		else if (post < other.post)
			result = -1;
	}

	if (result == 0)
	{
		if (fio > other.fio)
			result = 1;
		else if (fio < other.fio)
			result = -1;

	}

	return result;
}
