//Реализовать класс для хранения информации согласно заданию.
//Реализовать класс Линейный список из элементов.Класс должен содержать
//следующие методы :
//• добавить в начало;
//• добавить в конец;
//• добавить за заданным номером;
//• удалить из начала;
//• удалить из конца;
//• удалить элемент по номеру;
//• найти элемент по номеру;
//• удалить все элементы.
//Реализовать класс Контейнер, полем которого является Линейный список.
//Контейнер предоставляет возможность редактирования списка, а также методы
//согласно заданию.
//8. Информация о междугородних автобусных рейсах : пункт отправления, пункт
//прибытия, время отправления, время прибытия, количество остановок, время в
//пути, ФИО водителей через запятую.
//Методы Контейнера :
//• Получить список всех рейсов, отправляющихся из заданного пункта,
//время в пути у которых меньше заданного.
//• Получить список всех рейсов, прибывающих в заданный пункт не позже
//заданного времени, на которых работает водитель с заданным ФИО.При
//этом удалить выбранные рейсы из Контейнера.
//• Упорядочить рейсы по пункту отправления, времени отправления и
//количеству остановок.
#include "EMPLOYEE.h"
#include "LIST.h"
#include "CONTAINER.h"
#include <Windows.h>
#include <fstream>
#include <iostream>

void print_menu();

void main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    print_menu();
    CONTAINER list;
    int choice{};
    std::cin >> choice;
    while (choice != 14)
    {
        switch (choice)
        {
        case 1: // Заполнить из файла
        {
            std::ifstream file("data.txt");
            list.read_from_file(file);
            file.close();
            break;
        }

        case 2: // Печать списка
        {
            list.print();
            break;
        }

        case 3: // Добавить в начало
        {
            EMPLOYEE* tmp = new EMPLOYEE();
            tmp->fill_from_keyboard();
            list.add_to_head(tmp);
            break;
        }

        case 4: // Добавить в конец
        {
            EMPLOYEE* tmp = new EMPLOYEE();
            tmp->fill_from_keyboard();
            list.add_to_tail(tmp);
            break;
        }

        case 5: // Добавить за заданным номером
        {
            int pos{};
            std::cout << "Введите позицию за которой вставить элемент: ";
            std::cin >> pos;
            EMPLOYEE* tmp = new EMPLOYEE();
            tmp->fill_from_keyboard();
            list.add_after_position(tmp, pos);
            break;
        }

        case 6: // Удалить из начала
        {
            list.del_from_head();
            break;
        }

        case 7: // Удалить из конца
        {
            list.del_from_tail();
            break;
        }

        case 8: // Удалить элемент по номеру
        {
            int pos{};
            std::cout << "Введите позицию, к-рую нужно удалить: ";
            std::cin >> pos;
            list.del_at_position(pos);
            break;
        }

        case 9: // Найти элемент по номеру
        {
            int pos{};
            std::cout << "Введите позицию элемента, к-рый нужно найти: ";
            std::cin >> pos;
            EMPLOYEE* tmp = list.find_at_position(pos);
            if (tmp)
                tmp->print();
            else
                std::cout << "Элемент с таким индексом не найден!\n";
            break;
        }

        case 10: // Удалить все элементы
        {
            list.clear();
            break;
        }

        case 11: // Получить список всех сотрудников моложе заданного года, стаж работы
            //которых более 5 лет
        {
            std::cout << "Получить список всех сотрудников моложе заданного года, стаж работы\nкоторых более 5 лет.\n";
            std::cout << "Задайте год: ";
            unsigned int year{};
            std::cin >> year;
            CONTAINER reslist = list.task1(year);
            reslist.print();
            break;
        }

        case 12: // Получить список всех сотрудников заданного отдела, при этом удалив их
            //из исходного Контейнера.
        {
            std::cout << "Получить список всех сотрудников заданного отдела, при этом удалив их из исходного Контейнера.\n";
            std::cout << "Задайте код отдела: ";
            unsigned int department{};
            std::cin >> department;

            CONTAINER reslist = list.task2(department);
            reslist.print();
            break;
        }


        case 13: // Упорядочить сотрудников по отделу, должности и ФИО.
        {
            std::cout << "Упорядочить рейсы по пункту отправления, времени отправления и количеству становок.\n";
            list.task3();
            list.print();
            break;
        }

        default: // Неверный выбор
        {
            std::cout << "Работа завершена!\n";
            break;
        }
        }

        print_menu();
        std::cin >> choice;
    }
}

void print_menu()
{
    std::cout << "Меню работы со списком:\n";
    std::cout << "1. Заполнить из файла\n";
    std::cout << "2. Печать списка\n";
    std::cout << "3. Добавить в начало\n";
    std::cout << "4. Добавить в конец\n";
    std::cout << "5. Добавить за заданным номером\n";
    std::cout << "6. Удалить из начала\n";
    std::cout << "7. Удалить из конца\n";
    std::cout << "8. Удалить элемент по номеру\n";
    std::cout << "9. Найти элемент по номеру\n";
    std::cout << "10. Удалить все элементы\n";
    std::cout << "Меню решения задач:\n";
    std::cout << "11. Задача 1\n";
    std::cout << "12. Задача 2\n";
    std::cout << "13. Задача 3\n";
    std::cout << "14. Завершить работу\n";
    std::cout << ">";
}
