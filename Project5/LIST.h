#pragma once
#include "EMPLOYEE.h"
using TInfo = EMPLOYEE*;
class NODE
{
public:
	TInfo info;
	NODE* next;

	NODE(TInfo info, NODE* ptr = nullptr) : info(info), next(ptr) {};
	~NODE() { next = nullptr; }

	TInfo get_info() { return info; };
	NODE* get_next() { return next; }
	void set_info(TInfo inf) { info = inf; };
	void set_next(NODE* nxt) { next = nxt; };
};
using ptrNODE = NODE*;

class LIST
{
private:
	ptrNODE head, tail;
	void adding_by_pointer(ptrNODE& ptr, TInfo elem)
	{
		ptr = new NODE(elem, ptr);
	}
	void delete_by_pointer(ptrNODE& ptr)
	{
		ptrNODE p = ptr;
		ptr = p->next;
		delete p;
	}
public:
	LIST() { head = nullptr; tail = nullptr; };
	LIST(std::ifstream& file);
	~LIST() { clear(); };
	void clear();
	void add_to_head(TInfo elem);
	void add_to_tail(TInfo elem);
	void del_from_head();
	void del_from_tail();
	void print(std::ostream& out = std::cout);
	void add_after_position(TInfo elem, unsigned int position);
	void del_at_position(unsigned int position);
	TInfo find_at_position(unsigned int position);
	void read_from_file(std::ifstream& file);

	ptrNODE get_head() { return head; };
	ptrNODE get_tail() { return tail; };
	void set_head(ptrNODE head) { this->head = head; };
	void set_tail(ptrNODE tail) { this->tail = tail; };
	void sorting(); // сортировка вставками


};





