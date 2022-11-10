#pragma once
#include <iostream>
#include <string.h>
#include "Schedule.h"
#include "Ticket.h"
#include "CinemaRoom.h"
#include "Film.h"
#include "Director.h"
#include "Staff.h"
#include <fstream>
#include "Salary.h"

using namespace std;

template <class type>

class Manager
{
protected:
	struct Node
	{
		type data;
		Node *next, *back; 
		Node(type data)
        {
            this->data = data;
            this->next = this->back = NULL;
        }
	};
	Node *head;
	Node *tail;
	int length;
public:
	void add(const type);
	void del(const string&);
	void delByIndex(int);
	type* findById(const string&);
	int getLength();
	void setLength(int);
	Manager();
	~Manager();
	Node* constructorNode(const type data);
	type& operator[](int);
	virtual void readFile(fstream&) = 0;
	virtual void writeFile(fstream&) = 0;
	virtual void write() = 0;
};

int getInt();
string getphone();
int checktime(int, int, int);
