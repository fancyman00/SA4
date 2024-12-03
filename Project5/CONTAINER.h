#pragma once
#include "LIST.h"

class CONTAINER
{
private:
    LIST* list;

public:
    CONTAINER(std::ifstream& file) { list = new LIST(file); }
    CONTAINER() { list = new LIST(); }
    ~CONTAINER() { list->clear(); delete list; list = nullptr; }
    CONTAINER(const CONTAINER& other)
    {
        list = new LIST();
        ptrNODE tmp = other.list->get_head();
        while (tmp != nullptr)
        {
            list->add_to_tail(tmp->get_info());
            tmp = tmp->get_next();
        }
    }
    void clear() { list->clear(); }
    void add_to_head(TInfo elem) { list->add_to_head(elem); }
    void add_to_tail(TInfo elem) { list->add_to_tail(elem); }
    void del_from_head() { list->del_from_head(); }
    void del_from_tail() { list->del_from_tail(); }
    void print(std::ostream& out = std::cout) { list->print(out); }
    void add_after_position(TInfo elem, unsigned int position) { list->add_after_position(elem, position); }
    void del_at_position(unsigned int position) { list->del_at_position(position); }
    TInfo find_at_position(unsigned int position) { return list->find_at_position(position); }
    void read_from_file(std::ifstream& file) { return list->read_from_file(file); };
    CONTAINER task1(unsigned int year);
    CONTAINER task2(unsigned int department_code);
    void task3();
};
