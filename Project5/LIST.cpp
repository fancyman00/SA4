#include "LIST.h"

LIST::LIST(std::ifstream& file)
{
    EMPLOYEE* elem = new EMPLOYEE(file);
    add_to_tail(elem);
    while (!file.eof())
    {
        EMPLOYEE* tmp = new EMPLOYEE(file);
        add_to_tail(tmp);
    }
}

void LIST::clear()
{
    while (head != nullptr)
        delete_by_pointer(head);
    tail = nullptr;
}

void LIST::add_to_head(TInfo elem)
{
    adding_by_pointer(head, elem);
    if (tail == nullptr)
        tail = head;
}


void LIST::add_to_tail(TInfo elem)
{
    if (tail == nullptr)
    {
        adding_by_pointer(head, elem);
        tail = head;
    }
    else
    {
        adding_by_pointer(tail->next, elem);
        tail = tail->next;
    }
}


void LIST::del_from_head()
{
    if (head)
    {
        delete_by_pointer(head);
        if (head == nullptr)
            tail = nullptr;
    }
}

void LIST::del_from_tail()
{
    if (tail)
    {
        if (head == tail)
        {
            delete_by_pointer(head);
            tail = nullptr;
        }
        else
        {
            ptrNODE ptr = head;
            while (ptr->next != tail)
                ptr = ptr->next;
            delete_by_pointer(tail);
            tail = ptr;
            tail->next = nullptr;
        }
    }
}


void LIST::print(std::ostream& stream)
{
    if (head)
    {
        int pos = 0;
        ptrNODE p = head;
        while (p)
        {
            std::cout << "pos = " << pos << '\n';
            (p->info)->print();
            p = p->next;
            ++pos;
        }
        std::cout << '\n';
    }
    else
        std::cout << "List is empty!\n";
}

void LIST::add_after_position(TInfo elem, unsigned int position)
{
    if (position == 0)
        adding_by_pointer(head->next, elem);
    else
    {
        ptrNODE current = head;
        unsigned int index = 0;
        while (current != nullptr && index < position)
        {
            current = current->next;
            index++;
        }
        if (current == nullptr)
            add_to_tail(elem);
        else
        {
            adding_by_pointer(current->next, elem);
            if (current->next == tail)
                tail = current->next;
        }
    }
}

void LIST::del_at_position(unsigned int position)
{
    if (position == 0)
        del_from_head();
    else
    {
        ptrNODE prev = head;
        unsigned int index = 1;
        while (prev && index < position)
        {
            prev = prev->next;
            index++;
        }
        if (prev && prev->next)
        {
            if (prev->next == tail)
                tail = prev;
            delete_by_pointer(prev->next);
        }
    }
}


TInfo LIST::find_at_position(unsigned int position)
{
    ptrNODE current = head;
    unsigned int index = 0;
    while (current != nullptr && index < position)
    {
        current = current->next;
        index++;
    }
    return current ? current->info : nullptr;
}

void LIST::read_from_file(std::ifstream& file)
{
    clear();
    EMPLOYEE* elem = new EMPLOYEE(file);
    add_to_tail(elem);
    while (!file.eof())
    {
        EMPLOYEE* tmp = new EMPLOYEE(file);
        add_to_tail(tmp);
    }
}

void LIST::sorting()
{
    auto switch_pointers = [](ptrNODE q, ptrNODE p)
        {
            ptrNODE tmp = p->next;
            p->next = tmp->next;
            tmp->next = q->next;
            q->next = tmp;
        };
    auto find_place = [this](TInfo elem)->ptrNODE
        {
            ptrNODE result = head;
            while (result->next && result->next->info->compare(*elem) < 0)
                result = result->next;
            return result;
        };
    ptrNODE sorted_last = head;
    ptrNODE unsorted = head->next;
    while (unsorted)
    {
        if (sorted_last->info->compare(*unsorted->info) > 0)
        {
            ptrNODE insertion_point = find_place(unsorted->info);
            if (insertion_point == head && head->info->compare(*unsorted->info) > 0)
            {
                sorted_last->next = unsorted->next;
                unsorted->next = head;
                head = unsorted;
            }
            else
                switch_pointers(insertion_point, sorted_last);
            unsorted = sorted_last->next;
        }
        else
        {
            sorted_last = unsorted;
            unsorted = unsorted->next;
        }
    }
    tail = sorted_last;
}



