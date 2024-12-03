//����������� ����� ��� �������� ���������� �������� �������.
//����������� ����� �������� ������ �� ���������.����� ������ ���������
//��������� ������ :
//� �������� � ������;
//� �������� � �����;
//� �������� �� �������� �������;
//� ������� �� ������;
//� ������� �� �����;
//� ������� ������� �� ������;
//� ����� ������� �� ������;
//� ������� ��� ��������.
//����������� ����� ���������, ����� �������� �������� �������� ������.
//��������� ������������� ����������� �������������� ������, � ����� ������
//�������� �������.
//8. ���������� � ������������� ���������� ������ : ����� �����������, �����
//��������, ����� �����������, ����� ��������, ���������� ���������, ����� �
//����, ��� ��������� ����� �������.
//������ ���������� :
//� �������� ������ ���� ������, �������������� �� ��������� ������,
//����� � ���� � ������� ������ ���������.
//� �������� ������ ���� ������, ����������� � �������� ����� �� �����
//��������� �������, �� ������� �������� �������� � �������� ���.���
//���� ������� ��������� ����� �� ����������.
//� ����������� ����� �� ������ �����������, ������� ����������� �
//���������� ���������.
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
        case 1: // ��������� �� �����
        {
            std::ifstream file("data.txt");
            list.read_from_file(file);
            file.close();
            break;
        }

        case 2: // ������ ������
        {
            list.print();
            break;
        }

        case 3: // �������� � ������
        {
            EMPLOYEE* tmp = new EMPLOYEE();
            tmp->fill_from_keyboard();
            list.add_to_head(tmp);
            break;
        }

        case 4: // �������� � �����
        {
            EMPLOYEE* tmp = new EMPLOYEE();
            tmp->fill_from_keyboard();
            list.add_to_tail(tmp);
            break;
        }

        case 5: // �������� �� �������� �������
        {
            int pos{};
            std::cout << "������� ������� �� ������� �������� �������: ";
            std::cin >> pos;
            EMPLOYEE* tmp = new EMPLOYEE();
            tmp->fill_from_keyboard();
            list.add_after_position(tmp, pos);
            break;
        }

        case 6: // ������� �� ������
        {
            list.del_from_head();
            break;
        }

        case 7: // ������� �� �����
        {
            list.del_from_tail();
            break;
        }

        case 8: // ������� ������� �� ������
        {
            int pos{};
            std::cout << "������� �������, �-��� ����� �������: ";
            std::cin >> pos;
            list.del_at_position(pos);
            break;
        }

        case 9: // ����� ������� �� ������
        {
            int pos{};
            std::cout << "������� ������� ��������, �-��� ����� �����: ";
            std::cin >> pos;
            EMPLOYEE* tmp = list.find_at_position(pos);
            if (tmp)
                tmp->print();
            else
                std::cout << "������� � ����� �������� �� ������!\n";
            break;
        }

        case 10: // ������� ��� ��������
        {
            list.clear();
            break;
        }

        case 11: // �������� ������ ���� ����������� ������ ��������� ����, ���� ������
            //������� ����� 5 ���
        {
            std::cout << "�������� ������ ���� ����������� ������ ��������� ����, ���� ������\n������� ����� 5 ���.\n";
            std::cout << "������� ���: ";
            unsigned int year{};
            std::cin >> year;
            CONTAINER reslist = list.task1(year);
            reslist.print();
            break;
        }

        case 12: // �������� ������ ���� ����������� ��������� ������, ��� ���� ������ ��
            //�� ��������� ����������.
        {
            std::cout << "�������� ������ ���� ����������� ��������� ������, ��� ���� ������ �� �� ��������� ����������.\n";
            std::cout << "������� ��� ������: ";
            unsigned int department{};
            std::cin >> department;

            CONTAINER reslist = list.task2(department);
            reslist.print();
            break;
        }


        case 13: // ����������� ����������� �� ������, ��������� � ���.
        {
            std::cout << "����������� ����� �� ������ �����������, ������� ����������� � ���������� ��������.\n";
            list.task3();
            list.print();
            break;
        }

        default: // �������� �����
        {
            std::cout << "������ ���������!\n";
            break;
        }
        }

        print_menu();
        std::cin >> choice;
    }
}

void print_menu()
{
    std::cout << "���� ������ �� �������:\n";
    std::cout << "1. ��������� �� �����\n";
    std::cout << "2. ������ ������\n";
    std::cout << "3. �������� � ������\n";
    std::cout << "4. �������� � �����\n";
    std::cout << "5. �������� �� �������� �������\n";
    std::cout << "6. ������� �� ������\n";
    std::cout << "7. ������� �� �����\n";
    std::cout << "8. ������� ������� �� ������\n";
    std::cout << "9. ����� ������� �� ������\n";
    std::cout << "10. ������� ��� ��������\n";
    std::cout << "���� ������� �����:\n";
    std::cout << "11. ������ 1\n";
    std::cout << "12. ������ 2\n";
    std::cout << "13. ������ 3\n";
    std::cout << "14. ��������� ������\n";
    std::cout << ">";
}
