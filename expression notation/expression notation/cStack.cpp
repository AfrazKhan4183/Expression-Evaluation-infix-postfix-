#pragma
#include <stdlib.h>
#include <fstream>
#include <string>
#include "cStack.h"
#include <sstream>
#include <iostream>
#include <string.h>

using namespace std;

cStack::cStack()
{
	count = -1;
	top = NULL;
}


cStack::cStack(cNode* &ptr)
{
	count = count + 1;
	this->top = ptr;
	this->top->link = NULL;
	ptr = NULL;
}


void cStack::push(char d)
{
	/*ofstream abc;
	abc.open("stack.dat", ios::app);
	if (!abc)
	{
		cerr << "file opening error..." << endl;
		exit(1);
	}
	else
	{*/


		cNode *ptr = new cNode;
		if (top == NULL)
		{
			ptr->data=d;
			//abc << ptr->data << endl;
			count = count + 1;
			this->top = ptr;
			this->top->link = NULL;
			ptr = NULL;
		}
		else
		{
			cNode *b;
			b = top;
			ptr->data=d;
			//abc << ptr->data << endl;
			this->top = ptr;
			this->top->link = b;
			ptr = NULL;
			count++;
		}

	//abc.close();
}


void cStack::pop()
{

	if (top == NULL)
	{
		cout << "";
	}
	else
	{
		cNode* temp;
		temp = this->top;
		this->top = this->top->link;
		delete temp;
		--count;
	}
}




void cStack::print()
{

	cout << "===================================================" << endl;
	if (this->top == NULL)
	{
		cout << "Stack is Empty";
	}
	else
	{
		cNode *ptr = this->top;
		while (ptr)
		{
			ptr->print();
			ptr = ptr->link;
		}
	}
}


cStack::~cStack()
{
	cNode* temp;
	while (top != NULL)
	{
		temp = top;
		top = top->link;
		delete temp;
	}
	count = -1;
}







bool cStack::isempty()
{
	if (this->top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cStack::higher_pref(char d)
{
	if ( (d == '+' && this->Top() == '-')|| (d == '/' && this->Top() == '-') || (d == '/' && this->Top() == '+')
		|| (d == '/' && this->Top() == '*') || (d == '*' && this->Top() == '-')|| (d == '*' && this->Top() == '+'))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool cStack::open_pren(char d)
{
	if (d == '(')
	{
		return true;
	}
	else
	{
		return false;
	}
}

char cStack::Top()
{
	
		return top->data;
}

void cStack::read()
{
	cout << "Enter name of the file: ";
	string file;
	cin >> file;
	ifstream abc;
	abc.open(file);
	if (!abc)
	{
		cerr << "file opening error" << endl;
		exit(1);
	}

	do
	{
		int i;
		while (abc >> i)
		{

			cNode* ptr = new cNode;
			if (top == NULL)
			{
				ptr->data = i;
				count = count + 1;
				this->top = ptr;
				this->top->link = NULL;
				ptr = NULL;
			}
			else
			{
				cNode *b;
				b = top;
				ptr->data = i;
				this->top = ptr;
				this->top->link = b;
				ptr = NULL;
				count++;
			}

			pop();
		}
	} while (!abc.eof());
}

cStack::cStack(const cStack& src)
{
	this->count = src.count;
	top = src.top;
	if (src.top)
	{
		cNode* dptr;
		cNode* sptr = src.top;
		dptr = top = new cNode(*sptr);
		sptr = sptr->link;
		while (sptr)
		{
			dptr->link = new cNode(*sptr);
			sptr = sptr->link;
		}
	}
}

cStack& cStack::operator=(cStack &obj)
{
	if (true)
	{
		cStack temp;
		temp.top = top;
		if (true)
		{
			cStack temp(obj);
			top = temp.top;
			temp.top = NULL;
			return *this;
		}
	}
}
