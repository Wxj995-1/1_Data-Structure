#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stack>
using namespace std;


#if 0
string MidddleToEndExpr(string expr)
{
	string result;
	stack<char> s;

	for (char ch : expr)
	{
		if (ch >= '0' && ch <= '9')
		{
			result.push_back(ch);
		}
		else
		{
			while(!s.empty())
			{ 
				if (s.empty() || ch == '(')
				{
					s.push(ch);
				}
				else
				{
					char topch = s.top();
					if (Priority(ch, topch))
					{
						s.push(ch);
						break;
					}
					else
					{
						s.pop();
						if (topch == ')')
							breal;
						result.push_back(topch);
					}
				}
			}
		}
	}



	return result;
}

int main()
{



	return 0;
}

#endif