#pragma
#include <iostream>
#include "cNode.h"

using namespace std;

cNode::cNode()
{
	data = '\0';
	this->link = NULL;
}

cNode::cNode(char h)
{
	this->data = h;
}


cNode::~cNode()
{

}

void cNode::print()
{
	cout << this->data << " ";
}