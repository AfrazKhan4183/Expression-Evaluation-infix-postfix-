#include<iostream>
#include<conio.h>
#include <fstream>
#include"cStack.h"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	ofstream abc;
	abc.open("postfix.txt");
	if (!abc)
	{
		cerr << "file opening error" << endl;
		exit(1);
	}
	else
	{
		abc.clear();
		cStack g;
		cout << endl << endl << endl << "===================----------------------CONVERT POSTFix EXPRESSIONS to INFix--------------------=====================" << endl << endl << endl;
		char *s = new char[100];
		cout << "*.Enter your infix-expression here: ";
		cin >> s;
		int d = strlen(s);
		cout << endl << "*.Length of your entered string is: " << "\"" << d << "\"" << endl;
		cout << endl << "*.Its PostFix-Notation is: ";
		cout << endl << "                        =============================================================================" << endl << "                        ";
		for (int f = 0; f < (d + 1); f++)
		{
			if (isalpha(s[f]))
			{
				cout << s[f];
				abc << s[f];
			}
			else if (s[f] == '+' || s[f] == '-' || s[f] == '*' || s[f] == '/')
			{
				while (!g.isempty() && g.higher_pref(s[f]) && !g.open_pren(g.Top()))
				{
					if (g.Top() != ')' && g.Top() != '(')
					{
						cout << g.Top();
						abc << g.Top();
					}
					g.pop();
				}
				g.push(s[f]);
			}
			else if (g.open_pren(s[f]))
			{
				g.push(s[f]);
			}
			else if (s[f] == ')')
			{
				while (!g.isempty() && !g.open_pren(s[f]))
				{
					if (g.Top() != ')' && g.Top() != '(')
					{
						cout << g.Top();
						abc << g.Top();
					}
					g.pop();
				}
				g.pop();
			}

		}
		while (!g.isempty())
		{
			if (g.Top() != ')' && g.Top() != '(')
			{
				cout << g.Top();
				abc << g.Top();
			}
			g.pop();
		}
		cout << endl << "                        =============================================================================" << endl;

	}
	abc.close();
	_getche();
	return 0;
}