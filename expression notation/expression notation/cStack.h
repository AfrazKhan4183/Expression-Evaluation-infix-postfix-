#pragma
#include <string>
#include <iostream>
#include "cNode.h"
using namespace std;

class cStack
{
private:
	int count;
public:
	cNode* top;
	cStack();
	bool higher_pref(char);
	cStack(cNode *&);
	void push(char);
	void pop();
	cStack(const cStack&);
	~cStack();
	bool isempty();
	char Top();
	bool open_pren(char);
	cStack& operator=(cStack&);
	void print();
	void read();
};