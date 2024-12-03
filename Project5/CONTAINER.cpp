#include "CONTAINER.h"


//Получить список всех сотрудников моложе заданного года, стаж работы
//которых более 5 лет
CONTAINER CONTAINER::task1(unsigned int year)
{
    CONTAINER result;
    ptrNODE tmp = list->get_head();
    while (tmp)
    {
        if (tmp->get_info()->get_year_of_bd() > year &&
            tmp->get_info()->get_experience() > 5)
            result.add_to_tail(tmp->info);
        tmp = tmp->next;
    }
    return result;
}




//Получить список всех сотрудников заданного отдела, при этом удалив их
//из исходного Контейнера.
CONTAINER CONTAINER::task2(unsigned int department_code)
{
    CONTAINER result;
    ptrNODE tmp = list->get_head();
    unsigned int position = 0;
    while (tmp)
    {
        if (tmp->get_info()->get_department_code() == department_code)
        {
            result.add_to_tail(tmp->info);
            list->del_at_position(position);
            tmp = list->get_head();
            for (unsigned int i = 0; i < position && tmp; i++)
                tmp = tmp->next;
        }
        else
        {
            tmp = tmp->next;
            position++;
        }
    }
    return result;
}


//Упорядочить сотрудников по отделу, должности и ФИО.
void CONTAINER::task3()
{
    list->sorting();
}




