#pragma
using namespace std;

class  cNode
{
public:
	char data;
	cNode* link;
public:
	cNode();
	cNode(char);
	void print();
	~cNode();
};